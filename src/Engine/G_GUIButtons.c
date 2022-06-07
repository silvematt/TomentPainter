#include <stdio.h>
#include "A_Application.h"
#include "U_DataTypes.h"
#include "G_GUIButtons.h"
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
    // Read and store the pixel selected by the mouse
    currentMainColor = pixels[mx + my * width];
    R_DrawCurrentColor();
    return 0;
}

int G_SaveButtonOnClick(struct button_s* btn)
{
    // Save on surface and resize
    exportSurface = SDL_GetWindowSurface(DrawingApp.window);
    exportSurface->w = 640;
    exportSurface->h = 480;

    // Save as bmp
    SDL_SaveBMP(exportSurface, "export.bmp");
    printf("\n Image exported as 'export.bmp'!\n");
    return 0;
}

int G_SetBushSize(struct button_s* btn)
{
    bushSize = btn->data1;
    printf("Bush Size: %d\n", btn->data1);
    return bushSize;
}

int G_ClearScreen(struct button_s* btn)
{
    R_ClearCanvas();
    return 0;
}