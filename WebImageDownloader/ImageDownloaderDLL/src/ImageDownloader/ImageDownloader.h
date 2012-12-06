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
			std::string imageDownloaderName = WhereIsMyExe();
			int pathRemove = 0;
			for(int i = imageDownloaderName.length() - 1; i > 0; i--)
			{
				if(imageDownloaderName[i] == '\\')
				{
					break;
				}
				pathRemove++;
			}
			imageDownloaderName.erase(imageDownloaderName.end() - pathRemove, imageDownloaderName.end());
			imageDownloaderName += "WebImageDownloader.exe";
			imageDownloaderName = "\"" + imageDownloaderName + "\" " + query;
			system(imageDownloaderName.c_str());
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
