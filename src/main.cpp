/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU General Public License version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3 requirements will be
** met: https://www.gnu.org/licenses/gpl-3.0.html.
****************************************************************************/

#include <AuroraFW/Aurora.h>
#include <AuroraFW/Math/Algorithm.h>

#include <exception>

using namespace AuroraFW;
using namespace ImageManager;

int width = 255, height = 255, bpp = 24;

Application *app;

//Image *image1;
Image *image2;

void printRWInfo()
{
	//AuroraFW::Debug::Log("The image \"output.jpg\" is read-only, (", image1->isReadOnly(),
	//						") and write-only. (", image1->isWriteOnly(), ")");

	//AuroraFW::Debug::Log("Also, the image \"output.jpg\" is read-and-write. (", image1->isReadAndWrite(), ").");

	AuroraFW::Debug::Log("The image \"output.png\" is read-only, (", image2->isReadOnly(),
							") and write-only. (", image2->isWriteOnly(), ")");
	
	AuroraFW::Debug::Log("Also, the image \"output.png\" is read-and-write. (", image2->isReadAndWrite(), ").");
}

afwslot appMainFunction()
{
	//Debug::enableDebug();
	try {
		// Opens two images
		//CLI::Log(CLI::Information, "Opening output.jpg as read-only.");
		//image1 = new Image(FIF_JPEG, "output.jpg", ImageFlags::Read);
		CLI::Log(CLI::Information, "Opening output.png as write-only.");
		image2 = new Image(FIF_PNG, "output.png", ImageFlags::Write, width, height, bpp);

		// Prints wheter they are read/write
		printRWInfo();

		// Closes image1
		//delete image1;
		//image1 = nullptr;

		AuroraFW::Debug::Log("Creating color");
		GEngine::Color color(0, 0, 0);

		image2->convertTo32Bits();
		CLI::Log(CLI::Information, "Converted the image to 32-bit.");

		// Prepares to edit image2
<<<<<<< HEAD
		CLI::Log(CLI::Information, "Preparing to edit image2.");
		for(int x = 0; x < width; x++) {
		    for(int y = 0; y < height; y++) {
		        color.setRed((uint8_t)Math::clamp(y-x, 0, height));
		        color.setGreen((uint8_t)abs(y-height));
				color.setBlue((uint8_t)x);
				
				// DEBUG purposes
				color.setAlpha((uint8_t)128);

				image2->drawPixel(x, y, color);
			}
=======
		AuroraFW::Debug::Log("Draw");
		for(int x = 0; x < width; x++) {
		    for(int y = 0; y < height; y++) {
		        color.setRed((float)Math::clamp(y-x, 0, height)*255.0f);
		        color.setGreen((float)abs(y-height)*255.0f);
		        color.setBlue((float)x*255.0f);

				//AuroraFW::Debug::Log("Draw pixel");
		        image2->drawPixel(x, y, color);
		    }
>>>>>>> cacb9403147f0138a16f5993def423f444b9de7d
		}

		CLI::Log(CLI::Information, "The image was drawn, saving it...");
		image2->saveImage();
		CLI::Log(CLI::Information, "The image was saved to \"output.png\"");

	} catch(ImageNotFoundException& e1) {
		CLI::Log(CLI::Error, e1.what());
	} catch(ImageAllocationFailedException& e2) {
		CLI::Log(CLI::Error, e2.what());
	}

	

	// Initializes FreeImage
	/*FreeImage_Initialise();
	CLI::Log(CLI::Information, "FreeImage has successfully initialized.");
	CLI::Log(CLI::Information, "FreeImage's version: ", FreeImage_GetVersion());
	CLI::Log(CLI::Information, "FreeImage's Copyright message: ", FreeImage_GetCopyrightMessage());

	// Prepares to dray a PNG image
	FIBITMAP *image = FreeImage_Allocate(width, height, bpp);
	RGBQUAD color;

	if(image == nullptr)
		return;
	CLI::Log(CLI::Information, "Allocated space for new image");

	// Starts drawing the puke image

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			color.rgbRed = (float)Math::clamp(j-i, 0, height) / width * 255.0f;
			color.rgbGreen = (float)abs(j-height) / width * 255.0f;
			color.rgbBlue = (float)i / width * 255.0f;
			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}

	CLI::Log(CLI::Information, "The image was drawn. Saving it now to 'output.png'");

	if(FreeImage_Save(FIF_PNG, image, "output.png", 0))
		CLI::Log(CLI::Information, "Success! The image was saved!");
	else
		CLI::Log(CLI::Information, "Error! The image couldn't be saved!");
	
	FreeImage_DeInitialise();
	CLI::Log(CLI::Information, "FreeImage was deinitialised.");
	
	return;*/

	return;
}

int main(int argc, char *argv[])
{
	app = new Application(appMainFunction, argc, argv);
	delete app;
	delete image2;
	image2 = nullptr;

	return EXIT_SUCCESS;
}