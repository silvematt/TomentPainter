#include <stdio.h>
#include "U_DataTypes.h"
#include "G_GUIButtons.h"
#include "A_Application.h"
#include "R_Rendering.h"

int G_BrightnessButtonOnClick(struct button_s* btn)
{
    //Transform mouse relative to box
    int relativeY = my-btn->box.y;
    paletteBrightness = relativeY * 4;

    R_UpdateColorPicker();
    return 0;
}

int G_ColorPickerOnClick(struct button_s* btn)
{
    currentMainColor = pixels[mx + my * width];
    R_DrawCurrentColor();
    return 0;
}

int G_SaveButtonOnClick(struct button_s* btn)
{
    exportSurface = SDL_GetWindowSurface(DrawingApp.window);
    exportSurface->w = 640;
    exportSurface->h = 480;

    SDL_SaveBMP(exportSurface, "export.bmp");
    printf("\n Image exported as 'export.bmp'!\n");
}

int G_SetBushSize(struct button_s* btn)
{
    bushSize = btn->data1;
    printf("Bush Size: %d\n", btn->data1);
}

int G_ClearScreen(struct button_s* btn)
{
    R_ClearCanvas();
}