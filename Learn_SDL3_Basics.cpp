#include <iostream>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

using namespace std;


int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* Window = SDL_CreateWindow("BROTHA", 1152, 648, 0);
    if (Window == nullptr) {
        printf("%s", "Error Creating Window");
        SDL_DestroyWindow(Window);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* Renderer = SDL_CreateRenderer(Window, NULL);
    if (Renderer == nullptr) {
        printf("%s", "Error Creating Renderer");
        SDL_DestroyRenderer(Renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
        return 1;
    }
    
    SDL_Surface* Image = SDL_LoadPNG("assets/kiba.png");
    if (Image == nullptr) {
        printf("%s", "Error Loading Image");
        SDL_DestroySurface(Image);
        SDL_DestroyRenderer(Renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* Texture = SDL_CreateTextureFromSurface(Renderer, Image);
    if (Texture == nullptr) {
        printf("%s", "Error Creating Texture");
        SDL_DestroySurface(Image);
        SDL_DestroyTexture(Texture);
        SDL_DestroyRenderer(Renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
        return 1;
    }

    SDL_DestroySurface(Image);

    SDL_Event Event;

    while (1) {

        SDL_PollEvent(&Event);

        if (Event.type == SDL_EVENT_QUIT) {
            break;
        }
        
        SDL_RenderClear(Renderer);
        SDL_RenderTexture(Renderer, Texture, NULL, NULL);
        SDL_RenderPresent(Renderer);
    }

    SDL_DestroyTexture(Texture);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();

    return 0;
}