#include "CApp.h"
#include <iostream>
#include <string>

void intro()
{
    std::cout << "==============================Sorting Visualizer==============================\n\n"
              << "Visualization of different sorting algorithms in C++ with SDL2 Library.\n"
              << "Press ENTER to show controls...";

    std::string s;
    getline(std::cin, s);
    if (s == "\n")
    {
        return;
    }
}

bool controls()
{
    std::cout << "Available Controls inside Sorting Visualizer:-\n"
              << "    Use 0 to Generate a different randomized list.\n"
              << "    Use 1 to start Selection Sort Algorithm.\n"
              << "    Use 2 to start Insertion Sort Algorithm.\n"
              << "    Use 3 to start Bubble Sort Algorithm.\n"
              << "    Use 4 to start Merge Sort Algorithm.\n"
              << "    Use 5 to start Quick Sort Algorithm.\n"
              << "    Use 6 to start Heap Sort Algorithm.\n"
              << "    Use q to exit out of Sorting Visualizer\n\n"
              << "PRESS ENTER TO START SORTING VISUALIZER...\n\n"
              << "press ENTER to quit the program.";
    std::string S;
    getline(std::cin, S);
    if (S == "")
    {
        return false;
    }
    //else if(s=="\n")
    //{
    //    return true;
    //}
    return true;
}

int main(int arg, char *args[])
{
    CApp thisApp;

    intro();
    while (1)
    {
        std::cout << '\n';
        if (controls())
        {
            thisApp.onExecute();
        }
        else
        {
            std::cout << "\nEXITING PROGRAM.\n";
            break;
        }
    }

    return 0;
}