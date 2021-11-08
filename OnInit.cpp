#include "CApp.h"

bool CApp::OnInit() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Could not init SDL. SDL ERROR : %s\n", SDL_GetError());
		return false;
	}
	Window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (Window ==NULL) {
		printf("Could not create Window. SDL_ERROR: %s\n", SDL_GetError());
		return false;
	}
	else {
		Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
		if (Renderer == NULL) {
			printf("Could not create render. SDL_ERROR : %s\n", SDL_GetError());
			return false;
		}
	}
	return true;
}