#include "CSVLoader.h"

#include "pch.h"

namespace MikuEngine
{
	std::vector<float> CSVLoader::FetchSingleColumnValues( std::string_view filepath )
	{
		std::vector<float> outputVector;
		std::ifstream csvFile( filepath.data() );

		std::string line = "";

		while ( std::getline( csvFile, line ) )
		{
			outputVector.push_back( std::stof( line ) );
		}

		return outputVector;
	}
} // namespace MikuEngine