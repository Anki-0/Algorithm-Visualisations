#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event){
	
    if (Event->type == SDL_QUIT)
    {
        this->Running = false;
        this->completed = false;
    }
    else if (Event->type == SDL_KEYDOWN)
    {
        switch (Event->key.keysym.sym)
        {
        case(SDLK_q):
            this->Running = false;
            this->completed = false;
            std::cout << "\nEXITING SORTING VISUALIZER.\n";
            break;
        case(SDLK_0):
            randomizeAndSaveArray();
            this->completed = false;
            loadArr();
            printf("\nNEW RANDOM LIST GENERATED.\n");
            break;
        case(SDLK_1):
            loadArr();
            printf("\nSELECTION SORT STARTED.\n");
            this->completed = false;
            selectionSort();
            this->completed = true;
            printf("\nSELECTION SORT COMPLETE.\n");
            break;
        case(SDLK_2):
            loadArr();
            printf("\nINSERTION SORT STARTED.\n");
            this->completed = false;
            //insertionSort();
            this->completed = true;
            printf("\nINSERTION SORT COMPLETE.\n");
            break;
        case(SDLK_3):
            loadArr();
            printf("\nBUBBLE SORT STARTED.\n");
            this->completed = false;
            bubbleSort();
            this->completed = true;
            printf("\nBUBBLE SORT COMPLETE.\n");
            break;
        case(SDLK_4):
            loadArr();
            printf("\nMERGE SORT STARTED.\n");
            this->completed = false;
            mergeSort(arr, 0, arrSize - 1);
            this->completed = true;
            printf("\nMERGE SORT COMPLETE.\n");
            break;
        case(SDLK_5):
            loadArr();
            printf("\nQUICK SORT STARTED.\n");
            this->completed = false;
            //quickSort(arr, 0, arrSize - 1);
            this->completed = true;
            printf("\nQUICK SORT COMPLETE.\n");
            break;
        case(SDLK_6):
            loadArr();
            printf("\nHEAP SORT STARTED.\n");
           this->completed = false;
            //inplaceHeapSort(arr, arrSize);
            this->completed = true;
            printf("\nHEAP SORT COMPLETE.\n");
            break;
        }
    }
}