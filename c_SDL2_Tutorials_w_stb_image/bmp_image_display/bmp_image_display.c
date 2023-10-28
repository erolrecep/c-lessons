//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char const *argv[])
{
	const char *filename = "gs_team_2012.bmp";

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	    
	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;

	//Screen dimension constants
	const int SCREEN_WIDTH = 1080;
	const int SCREEN_HEIGHT = 1080;
	
    //Start up SDL and create window
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return 1;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    //Load splash image
    gHelloWorld = SDL_LoadBMP( filename );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        return 1;
    }
    else
    {
        //Apply the image
        SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );

        //Hack to get window to stay up
        SDL_Event e; 
        bool quit = false; 
        while( quit == false ){ 
        	while( SDL_PollEvent( &e ) ){
        		if( e.type == SDL_QUIT ) quit = true; 
        	} 
        }
    }

    //Free resources and close SDL
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
