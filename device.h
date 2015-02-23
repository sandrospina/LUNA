#include <SDL.h>
#include <SDL2/SDL_events.h>

class Device
{
 public:
    SDL_Window *win;
    SDL_Renderer *ren;
    int width;
    int height;
    Device(int p_width, int p_height);
    int Initialise();
};