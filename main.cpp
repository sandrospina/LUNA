#include <iostream>
#include <SDL.h>
#include "device.h"

using namespace std;

int main() {

    Device dev(320,200);
    if (dev.Initialise() == 1) SDL_Quit();


    //Load BMP
    std::string imagePath = "/Users/sandrospina/ClionProjects/LUNA/images/moon-clouds.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr){
        SDL_DestroyRenderer(dev.ren);
        SDL_DestroyWindow(dev.win);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    //Create Texture
    SDL_Texture *tex = SDL_CreateTextureFromSurface(dev.ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr){
        SDL_DestroyRenderer(dev.ren);
        SDL_DestroyWindow(dev.win);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_RenderClear(dev.ren);
    SDL_RenderCopy(dev.ren, tex, NULL, NULL);
    SDL_RenderPresent(dev.ren);

    SDL_Delay(2000);
    SDL_Quit();
    return 0;
}