#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <iostream>

class CApp
{

private:
	bool Running;
	const int SCREEN_WIDTH = 910;
	const int SCREEN_HEIGHT = 750;

	const int arrSize = 130;
	const int rectSize = 7;

	bool completed = false;

	int *arr;
	int *Barr;

	SDL_Window *Window = NULL;
	SDL_Renderer *Renderer = NULL;

public:
	CApp();
	int onExecute();

public:
	//handle init and loading of all the data
	bool OnInit();
	//handle all input event from mouse, keyboard, joystick etc.
	void OnEvent(SDL_Event *Event);
	//handle all the data update
	/*void OnLoop();*/
	//handle all the rendring of anything on the screen.
	void OnRender(int x = -1, int y = -1, int z = -1);
	//handle all the cleanup work and ensure peacefull quitting the game.
	void OnCleanup();

public:
	void randomizeAndSaveArray()
	{
		unsigned int seed = (unsigned)time(NULL);
		srand(seed);
		for (int i = 0; i < arrSize; i++)
		{
			int random = rand() % (SCREEN_HEIGHT);
			this->Barr[i] = random;
		}
	}
	void loadArr()
	{
		memcpy(this->arr, this->Barr, sizeof(int) * this->arrSize);
	}
	void bubbleSort()
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			for (int j = 0; j < arrSize - 1 - i; j++)
			{
				if (arr[j + 1] < arr[j])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;

					OnRender(j + 1, j, arrSize - i);
				}
				SDL_Delay(1);
			}
		}
	}

	void selectionSort()
	{
		int minIndex;
		for (int i = 0; i < arrSize - 1; i++)
		{
			minIndex = i;
			for (int j = i + 1; j < arrSize; j++)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
					OnRender(i, minIndex);
				}
				SDL_Delay(1);
			}
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	void merge2SortedArrays(int a[], int si, int ei)
	{
		int size_output = (ei - si) + 1;
		int *output = new int[size_output];

		int mid = (si + ei) / 2;
		int i = si, j = mid + 1, k = 0;
		while (i <= mid && j <= ei)
		{
			if (a[i] <= a[j])
			{
				output[k] = a[i];
				this->OnRender(i, j);
				i++;
				k++;
			}
			else
			{
				output[k] = a[j];
				this->OnRender(i, j);
				j++;
				k++;
			}
		}
		while (i <= mid)
		{
			output[k] = a[i];
			this->OnRender(-1, i);
			i++;
			k++;
		}
		while (j <= ei)
		{
			output[k] = a[j];
			this->OnRender(-1, j);
			j++;
			k++;
		}
		int x = 0;
		for (int l = si; l <= ei; l++)
		{
			a[l] = output[x];
			this->OnRender(l);
			SDL_Delay(15);
			x++;
		}
		delete[] output;
	}

	void mergeSort(int a[], int si, int ei)
	{
		if (si >= ei)
		{
			return;
		}
		int mid = (si + ei) / 2;

		mergeSort(a, si, mid);
		mergeSort(a, mid + 1, ei);

		merge2SortedArrays(a, si, ei);
	}
};

#endif