///
/// eBookReaderNX
/// reworks
/// Apache 2.0 License.
///

#include <switch.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "App.hpp"

App::App()
{
	// Initialize SDL2.
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	TTF_Init();

	// Init console.
	romfsInit();

	// Set up app.
	m_window.create("eBook Reader NX");
}

App::~App()
{
	// Clean up app.
	m_window.destroy();

	// Clean up console.
	romfsExit();

	// Clean up SDL2.
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int App::run()
{
	// homebrew stays open while window is open.
    while(m_window.m_open)
	{
		// libnx loop
		appletMainLoop();
		
		// app loop
		event();
		update();
		render();
	}

	return EXIT_SUCCESS;
}

void App::event()
{
	// Process input.
	hidScanInput();	
	u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

	// Plus key exits app.
	if (kDown & KEY_PLUS)
	{
		m_window.m_open = false;
	}
}

void App::update()
{

}

void App::render()
{
	m_window.beginRender();

	m_window.endRender();
}