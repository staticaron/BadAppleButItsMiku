#pragma once

#include <string>
#include <unordered_map>

#include <fmod.hpp>

struct MIKU_API SoundData
{
  public:
	SoundData( float vol = 10.0f )
	{
		volume = vol;
		memset( &exinfo, 0, sizeof( FMOD_CREATESOUNDEXINFO ) );
		exinfo.cbsize = sizeof( FMOD_CREATESOUNDEXINFO );
	}

	FMOD::Sound*& GetSound() { return sound; }
	void SetSound( FMOD::Sound* snd ) { sound = snd; }

	FMOD::Channel*& GetChannel() { return channel; }
	FMOD_CREATESOUNDEXINFO& GetExInfo() { return exinfo; }

	float GetVolume() const { return volume; }
	void SetVolume( float vol ) { volume = vol; }

	bool IsLoaded() const { return isLoaded; }
	void SetIsLoad( bool state ) { isLoaded = state; }

  private:
	FMOD::Sound* sound = nullptr;
	FMOD::Channel* channel = nullptr;
	FMOD_CREATESOUNDEXINFO exinfo;
	float volume = 10.0f;
	bool isLoaded = false;
};

struct MIKU_API SoundMode
{
	FMOD_MODE mode = FMOD_DEFAULT;

	void ApplyMode( FMOD_MODE newMode ) { mode |= newMode; }
};

class MIKU_API AudioManager
{
  public:
	AudioManager() = default;
	~AudioManager();

	void Init();
	void Destroy();

	void LoadSound( const std::string_view& soundName, const std::string_view& filePath );
	void PlaySound( const std::string_view& soundName );
	void SetPauseSound( const std::string_view& soundName, bool setPaused );

	void LoadStream( const std::string_view& streamName, const std::string_view& filePath );
	void PlayStream( const std::string_view& streamName );
	void SetPauseStream( const std::string_view& streamName, bool setPaused );

	static FMOD_RESULT StreamLoaded( FMOD_SOUND* sound, FMOD_RESULT result );

	SoundMode GetDefaultSoundMode( bool isStream ) const
	{
		SoundMode mode;
		mode.ApplyMode( FMOD_2D );
		mode.ApplyMode( FMOD_LOOP_OFF );

		if ( !isStream )
			mode.ApplyMode( FMOD_CREATESAMPLE );
		else
		{
			mode.ApplyMode( FMOD_NONBLOCKING );
			mode.ApplyMode( FMOD_CREATESTREAM );
		}

		return mode;
	}

	std::unordered_map<std::string_view, SoundData>& GetSounds() { return m_Sounds; }
	std::unordered_map<std::string_view, SoundData>& GetStreams() { return m_Streams; }

  private:
	FMOD::System* m_System = nullptr;

	std::unordered_map<std::string_view, SoundData> m_Sounds;
	std::unordered_map<std::string_view, SoundData> m_Streams;

	std::unordered_map<std::string_view, std::string_view> m_StreamsToLoad = {
		{ "bad", RESOURCE_DIR "audio/bad.mp3" }
	};
};