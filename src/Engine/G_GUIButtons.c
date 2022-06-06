#include <stdio.h>
#include "U_DataTypes.h"
#include "G_GUIButtons.h"
#include "A_Application.h"
#include "R_Rendering.h"

int G_BrightnessButtonOnClick(struct button_s* btn)
{
    printf("DONE LUL %s", btn->name);

    //Transform mouse relative to box
    int relativeY = my-btn->box.y;
    printf("\n\n mouse relative y is: %d", relativeY);

    paletteBrightness = relativeY * 4;

    R_UpdateColorPicker();
    return 0;
}

int G_ColorPickerOnClick(struct button_s* btn)
{
    currentMainColor = pixels[mx + my * width];
    return 0;
}