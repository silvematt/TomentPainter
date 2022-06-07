#include "A_Application.h"
#include "U_Utilities.h"
#include "R_Rendering.h"
#include "G_GUIButtons.h"

void A_InitTomentPainter(void)
{
    DrawingApp.quit = false;
    
    SDL_Init(SDL_INIT_EVERYTHING);

    printf("Booting up...\n");
    printf("Resolution: %dx%d\n\n", SCREEN_WIDTH, SCREEN_HEIGHT);

    DrawingApp.window = SDL_CreateWindow("Toment Painter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH + PALETTE_WIDTH, SCREEN_HEIGHT, 0);

    window_surface = SDL_GetWindowSurface(DrawingApp.window);

    pixels = window_surface->pixels;
    width = window_surface->w;

    A_InitPalette();
}

static void A_InitPalette(void)
{
    currentMainColor = SDL_MapRGBA(window_surface->format, 255, 255, 255, 255);
    paletteBrightness = 256;
    bushSize = 1;
    printf("Bush Size: 1\n");

    paletteButtons[0].name = "BrightnessSelector";
    paletteButtons[0].box.x = 775;
    paletteButtons[0].box.y = 10;
    paletteButtons[0].box.w = 16;
    paletteButtons[0].box.h = 64;
    paletteButtons[0].OnClick = G_BrightnessButtonOnClick;

    paletteButtons[1].name = "ColorPicker";
    paletteButtons[1].box.x = 647;
    paletteButtons[1].box.y = 10;
    paletteButtons[1].box.w = 128;
    paletteButtons[1].box.h = 64;
    paletteButtons[1].OnClick = G_ColorPickerOnClick;

    paletteButtons[2].name = "SaveButton";
    paletteButtons[2].box.x = SCREEN_WIDTH + (PALETTE_WIDTH / 2) - 25;
    paletteButtons[2].box.y = 400;
    paletteButtons[2].box.w = 50;
    paletteButtons[2].box.h = 50;
    paletteButtons[2].OnClick = G_SaveButtonOnClick;

    // Bush Sizes
    paletteButtons[2].name = "BushSize1";
    paletteButtons[2].box.x = SCREEN_WIDTH + (PALETTE_WIDTH / 2) - 25;
    paletteButtons[2].box.y = 400;
    paletteButtons[2].box.w = 50;
    paletteButtons[2].box.h = 50;
    paletteButtons[2].OnClick = G_SaveButtonOnClick;
}

void A_GameLoop(void)
{
    // In canvas
    if(mx <= SCREEN_WIDTH) 
    {
        if(drawing || altdrawing)
        {
            R_DrawFixed(omx, omy, mx, my);
        }
    }
    else // In toolbar
    {
        //printf("TOOLBAR ");
    }
}