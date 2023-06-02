#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <SDL2/SDL.h>
#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"

/*Reference: https://www.silbinarywolf.com/post/124379907558/loading-png-files-with-stbimage-and-sdl2*/
SDL_Surface *LoadImage(char* filename)
{
    // Read data
    int32_t width, height, bytesPerPixel;
    void* data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);

    // Calculate pitch
    int pitch;
    pitch = width * bytesPerPixel;
    pitch = (pitch + 3) & ~3;

    // Setup relevance bitmask
    int32_t Rmask, Gmask, Bmask, Amask;
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
    Rmask = 0x000000FF;
    Gmask = 0x0000FF00;
    Bmask = 0x00FF0000;
    Amask = (bytesPerPixel == 4) ? 0xFF000000 : 0;
#else
    int s = (bytesPerPixel == 4) ? 0 : 8;
    Rmask = 0xFF000000 >> s;
    Gmask = 0x00FF0000 >> s;
    Bmask = 0x0000FF00 >> s;
    Amask = 0x000000FF >> s;
#endif
    SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
        data, 
        width, 
        height, 
        bytesPerPixel*8, 
        pitch, Rmask, Gmask,
        Bmask, Amask);

    if (!surface)
    {
        // NOTE: Should free stbi_load 'data' variable here
        free(data);
        return NULL;
    }
    return surface;
}


int main(int argc, char* argv[]) {

    // Read data
    int32_t width, height, bytesPerPixel;
    void* data = stbi_load("gs_team_2000.bmp", &width, &height, &bytesPerPixel, 0);
    printf("image size: %d x %d\n", width, height);
    free(data);

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL2 Image", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        width, height, 
        SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Load image
    SDL_Surface* imageSurface = LoadImage("gs_team_2000.bmp");
    if (!imageSurface) {
        printf("Image could not be loaded! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface); // We don't need the surface anymore

    if (!texture) {
        printf("Texture could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Clear the renderer
    SDL_RenderClear(renderer);

    // Copy the texture to the renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Update the renderer
    SDL_RenderPresent(renderer);

    // Wait for the user to close the window
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
