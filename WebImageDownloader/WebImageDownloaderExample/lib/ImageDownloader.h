// ImageDownloader.h

#pragma once
#include <Windows.h>
#include <string>

namespace ImageDownloader {

	class WebImageDownloader
	{
	public:
		void DownloadImages(char *query)
		{
			std::string imageDownloader = WhereIsMyExe();
			imageDownloader.erase(imageDownloader.end() - 10, imageDownloader.end());
			imageDownloader += "WebImageDownloader.exe";
			imageDownloader = "\"" + imageDownloader + "\" " + query;
			system(imageDownloader.c_str());
		}
	private:
		std::string WhereIsMyExe()
		{
			char filename[ MAX_PATH ];
			DWORD length = GetModuleFileNameA( NULL, filename, MAX_PATH );
			return std::string( filename, length );
		}
	};
}
