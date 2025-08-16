#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 600

void addText(SDL_Renderer *renderer, TTF_Font *font, const char *msg, SDL_Color color, int x, int y) {
	SDL_Surface *surface = TTF_RenderUTF8_Blended(font, msg, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_Rect dstRect = {x, y, surface->w, surface->h};
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

int main() {

// init window and everything
SDL_Init(SDL_INIT_VIDEO);
SDL_Window *window = SDL_CreateWindow("Mechanics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
TTF_Init();
TTF_Font *font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 24);

// start running
bool running = true;
SDL_Event event;

// main game loop
while (running) {

	// checks for main commands such as quiting
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
		}
	}


	// set render to black and fill screen with black
	SDL_SetRenderDrawColor(renderer, 30, 30, 46, 255);
	SDL_RenderClear(renderer);
// void addText(SDL_Renderer *renderer, TTf_Font *font, const char *msg, SDL_Color color, int x, int y)

	// draw panel
	roundedBoxRGBA(renderer, 20, 60, 460, 540, 16, 37, 37, 55, 255);

	// draw title image
	SDL_Color white = {255, 255, 255, 255};
	addText(renderer, font, "calculator", white, 170, 15);

	SDL_Color grey = {170, 170, 170, 255};
	addText(renderer, font, "Mass 1", grey, 30, 70);

	// actually makes the renderer visible and so is drawn
	SDL_RenderPresent(renderer);

}

// fully quit everything once termintated
TTF_CloseFont(font);
TTF_Quit();
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;

}
