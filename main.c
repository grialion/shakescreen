#include <stdio.h> // include stdio for writing stuff on console
#include <windows.h> // include windows.h for winapi calls

#define intensity 1 // intensity of the shake
#define duration 10 // seconds; this is not accurate, because this depends on the bitblt speed. also i could implement a timer but whatever
#define speed 1 // speed of the shake

int main(int argc, char *argv[])
{
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN); // get screen width, and height

    printf("Screen props: %d, %d", w, h); // print the screen properties on the console (used for debugging)

    HWND hWnd = NULL; // whole screen
    HDC hdc = GetDC(hWnd); // get dc

    int i;

    // variables in case the shake distorts the screen too much
    int farx = 0;
    int fary = 0;

    ShowWindow(GetConsoleWindow(), HIDE_WINDOW); // hide console before shaking screen

    for (i = 0; i < 1000 / (20 / speed) * duration; i++)
    {
        // get random values for screen bitblt-ing.
        // rand() might be slow, you can use Xorshift or whatever you want, this is just a lazy way to get a random
        int randx = (rand() % (intensity * 20)) - intensity * 10;
        int randy = (rand() % (intensity * 20)) - intensity * 10;

        // check if the screen is too distorted (both x and y)
        if (abs(farx) > intensity * 20)
        {
            RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN); // redraw the screen
            randx = -farx; // reset the bitblt position
        }
        if (abs(fary) > intensity * 20)
        {
            RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
            randy = -fary;
        }

        // add the current shake to farx & y
        farx += randx;
        fary += randy;

        BitBlt(hdc, randx, randy, w, h, hdc, 0, 0, SRCCOPY); // bitblt the screen
        Sleep(20 / speed);
    }

    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN); // redraw screen on exit

    ReleaseDC(hWnd, hdc); // release the dc
    return 0;
}