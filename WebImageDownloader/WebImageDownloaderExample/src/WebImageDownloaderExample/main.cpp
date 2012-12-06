#include <iostream>
#include "ImageDownloader.h"

int main()
{
	ImageDownloader::WebImageDownloader *downloader = new ImageDownloader::WebImageDownloader();
	downloader->DownloadImages("cats");
	delete downloader;
	return 0;
}