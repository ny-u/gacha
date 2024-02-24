#include "pch.h"

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	return 0;
}