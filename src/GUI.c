#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 600

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

	// draw panel
	roundedBoxRGBA(renderer, 20, 60, 460, 540, 16, 37, 37, 55, 255);

	// render text
	SDL_Color textColor = {170, 170, 170, 255};

	SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, "Calculate", textColor);
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	int texW = 0, texH = 0;
	SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
	SDL_Rect textRect = {600 - texW / 2, 480 - texH / 2, texW, texH};
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);

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
