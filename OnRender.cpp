#include "CApp.h"

void CApp::OnRender(int x, int y, int z){
	//setting window color to light black(rgba(32,33,36,40))
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	//clear the entire screen to our color
	SDL_RenderClear(Renderer);


	int j = 0;
	for (int i = 0; i < this->SCREEN_WIDTH - this->rectSize; i += this->rectSize) {
		/*
		* This fuction updates the event queue and internal input devices state.
		* if we are now polling and waiting for the events,then must call @SDL_PumpEvents()
		* insted of @SDL_PollEvent(SDL_Event* Event);
		*/
		SDL_PumpEvents();

		/*
		* A structure that contain the definition of a reactangle, with the origin at the upper-left.
		* @SDL_React react = {x,y,w,h}
		*/
		SDL_Rect rect = { i,0,this->rectSize,this->arr[j] };

		if (completed) {
				SDL_SetRenderDrawColor(Renderer, 110, 204, 110, 0);//green
				SDL_RenderFillRect(Renderer, &rect);
		}
		else if (j == x || j == z) {
			SDL_SetRenderDrawColor(Renderer, 100, 180, 100, 0);//green
			SDL_RenderFillRect(Renderer, &rect);
		}
		else if (j == y)
		{
			SDL_SetRenderDrawColor(Renderer, 255, 93, 93, 0);//red color
			SDL_RenderFillRect(Renderer, &rect);
		}
		else
		{
			SDL_SetRenderDrawColor(Renderer, 205, 205, 205, 0); //light black
			SDL_RenderDrawRect(Renderer, &rect);
		}
		j++;
	}

	/*
	* Uptill now everything was drawn behind the scenes.
	* This will show the new black content on the screen
	*/
	SDL_RenderPresent(Renderer);
}