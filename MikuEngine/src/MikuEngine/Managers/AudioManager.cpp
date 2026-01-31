#include "AudioManager.h"

#include <fstream>

#include "fmod_common.h"
#include "pch.h"
#include "spdlog/spdlog.h"

static FMOD_RESULT FmodDebugCallback( FMOD_DEBUG_FLAGS flags, const char* file, int line, const char* func, const char* message )
{
	std::ofstream logStream( "logs/fmod.log", std::fstream::app );

	logStream << "INFO @ file: " << file << " line: " << line << " func: " << func << ";";
	logStream << "MESSAGE: " << message << "\n";

	return FMOD_OK;
}

struct MIKU_API SoundLoadContext
{
	AudioManager* audioManager = nullptr;
	std::string_view soundName;
};

AudioManager::~AudioManager()
{
	Destroy();
}

void AudioManager::Init()
{
	FMOD::Debug_Initialize( FMOD_DEBUG_LEVEL_LOG, FMOD_DEBUG_MODE_CALLBACK, FmodDebugCallback, "" );

	FMOD_RESULT systemCreationResult = FMOD::System_Create( &m_System, FMOD_VERSION );

	ASSERT( systemCreationResult == FMOD_OK, "Failed to create FMOD System" );
	spdlog::info( "FMOD System created successfully! VERSION: {}", FMOD_VERSION );

	FMOD_RESULT systemInitResult = m_System->init( 2, FMOD_INIT_NORMAL | FMOD_OUTPUTTYPE_AUTODETECT, nullptr );
	spdlog::info( "FMOD System initialized successfully!" );

	for ( auto& [ identifier, filepath ] : m_StreamsToLoad )
	{
		LoadStream( identifier, filepath );
	}

	spdlog::info( "All Sounds loaded!" );
}

void AudioManager::Destroy()
{
	m_System->release();
}

void AudioManager::LoadSound( const std::string_view& soundName, const std::string_view& filePath )
{
	if ( m_Sounds.find( soundName ) != m_Sounds.end() )
	{
		spdlog::error( "{} is already loaded!", soundName );
		return;
	}

	SoundData data;

	FMOD_RESULT createSoundResult = m_System->createSound( filePath.data(), GetDefaultSoundMode( false ).mode, &data.GetExInfo(), &data.GetSound() );

	ASSERT( createSoundResult == FMOD_OK, "Failed to create System Sound with name " << soundName );

	m_Sounds[ soundName ] = data;
}

void AudioManager::PlaySound( const std::string_view& soundName )
{
	ASSERT( m_Sounds.find( soundName ) != m_Sounds.end(), soundName << " is not loaded!" );

	auto sound = m_Sounds.find( soundName );

	FMOD_RESULT playSoundResult = m_System->playSound( sound->second.GetSound(), nullptr, false, &sound->second.GetChannel() );

	sound->second.GetChannel()->setVolume( sound->second.GetVolume() );

	ASSERT( playSoundResult == FMOD_OK, "Failed to play System Sound with name " << soundName );
}

void AudioManager::SetPauseSound( const std::string_view& soundName, bool setPaused )
{
	ASSERT( m_Streams.find( soundName ) != m_Streams.end(), "Sound not loaded!" );

	auto sound = m_Streams.find( soundName )->second;

	sound.GetChannel()->setPaused( true );
}

void AudioManager::LoadStream( const std::string_view& streamName, const std::string_view& filePath )
{
	if ( m_Sounds.find( streamName ) != m_Sounds.end() )
	{
		spdlog::error( "{} is already loaded!", streamName );
		return;
	}

	SoundData data;

	SoundLoadContext* context = new SoundLoadContext();
	context->audioManager = this;
	context->soundName = streamName;
	data.GetExInfo().userdata = context;
	data.GetExInfo().nonblockcallback = StreamLoaded;

	FMOD_RESULT createSoundResult = m_System->createSound( filePath.data(), GetDefaultSoundMode( true ).mode, &data.GetExInfo(), &data.GetSound() );

	ASSERT( createSoundResult == FMOD_OK, "Failed to create System Sound with name " << streamName );

	m_Streams[ streamName ] = data;

	spdlog::info( "Stream with name {} was loaded successfully!", streamName );
}

void AudioManager::PlayStream( const std::string_view& streamName )
{
	ASSERT( m_Streams.find( streamName ) != m_Streams.end(), "This stream with the name" << streamName << " is not loaded" );

	auto sound = m_Streams.find( streamName )->second;

	bool isAlreadyPlaying = false;
	sound.GetChannel()->isPlaying( &isAlreadyPlaying );

	if ( isAlreadyPlaying )
		return;

	FMOD_RESULT streamPlayResult = m_System->playSound( sound.GetSound(), nullptr, false, &sound.GetChannel() );

	sound.GetChannel()->setVolume( sound.GetVolume() );

	ASSERT( streamPlayResult == FMOD_OK, "Failed to play System Sound with name " << streamName );
}

void AudioManager::SetPauseStream( const std::string_view& streamName, bool setPaused )
{
	ASSERT( m_Streams.find( streamName ) != m_Streams.end(), "Stream not loaded!" );

	auto stream = m_Streams.find( streamName )->second;

	stream.GetChannel()->setPaused( setPaused );
}

FMOD_RESULT AudioManager::StreamLoaded( FMOD_SOUND* sound, FMOD_RESULT result )
{
	ASSERT( result == FMOD_OK, "Stream failed to load!" );

	FMOD::Sound* snd = reinterpret_cast<FMOD::Sound*>( sound );

#pragma region Update m_Streams to reflect that the stream is loaded!

	void* data = nullptr;
	snd->getUserData( &data );

	SoundLoadContext* soundLoadContext = static_cast<SoundLoadContext*>( data );

	auto streams = soundLoadContext->audioManager->GetStreams();
	ASSERT( streams.find( soundLoadContext->soundName ) != streams.end(), "No Stream object is there for the currently loaded stream" );

	streams[ soundLoadContext->soundName ].SetIsLoad( true );

	delete soundLoadContext; // Free the SoundLoadContext once the sound is loaded!

#pragma endregion

	return FMOD_OK;
}
