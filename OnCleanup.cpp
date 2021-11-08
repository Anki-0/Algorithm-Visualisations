#include "CApp.h"

void CApp::OnCleanup() {
	SDL_DestroyRenderer(Renderer);
	Renderer = NULL;
	SDL_DestroyWindow(Window);
	Window = NULL;
	
	SDL_Quit();
}