#pragma once

#include <string_view>
#include <vector>

namespace MikuEngine
{
	class MIKU_API CSVLoader
	{
	  public:
		static std::vector<float> FetchSingleColumnValues( std::string_view filepath );

	  private:
	};
} // namespace MikuEngine