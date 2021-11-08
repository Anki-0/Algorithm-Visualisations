#include "CApp.h"

CApp::CApp(){
	this->Running = true;
	this->arr = new int[arrSize];
	this->Barr = new int[arrSize];
	this->randomizeAndSaveArray();
	this->loadArr();
	this->completed = false;
}

int CApp::onExecute(){
	//first init game if fail return -1(quit the game)
	if (this->OnInit() == false) {
		return -1;
	}
	else {
		this->randomizeAndSaveArray();
		this->loadArr();



		SDL_Event Event; //Event object to hold the event

		while (this->Running) {
			/* @SDL_PollEvent(&Event)
			* gran events from the queue and pass them into @OnEvent(SDL_Event* Event())
			*
			* return - false if queue is empty
			*/
			while (SDL_PollEvent(&Event)) {
				this->OnEvent(&Event);
			}
			//this->OnLoop();
			this->OnRender();

		}

		this->OnCleanup();
	}
	return 0;
}
