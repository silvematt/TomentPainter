#ifndef RENDERING_H_INCLUDED
#define RENDERING_H_INCLUDED

#include "../include/SDL2/SDL.h"

ColorRGB_t HSVtoRGB(ColorHSV_t colorHSV);
void R_DrawFullColumn(int x, int color);
void R_ClearCanvas(void);
void R_DrawPalette(void);
void R_DrawFixed(int x1, int y1, int x2, int y2);
void R_UpdateColorPicker(void);
void R_DrawCurrentColor(void);
void R_DrawCircle(int x0, int y0, int r);
#endif