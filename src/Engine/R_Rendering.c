#include "A_Application.h"
#include "R_Rendering.h"
#include <math.h>

void R_DrawFullColumn(int x, int color)
{
    for(int y = 0; y < SCREEN_HEIGHT; y++)
        pixels[x + y * width] = color;
}

void R_ClearCanvas(void)
{
    for(int y = 0; y < SCREEN_HEIGHT; y++)
    for(int x = 0; x < SCREEN_WIDTH; x++)
        pixels[x + y * width] = SDL_MapRGBA(window_surface->format, 0, 0, 0, 0);
}

void R_DrawPalette()
{
    // Draw line and background
    R_DrawFullColumn(SCREEN_WIDTH+1, SDL_MapRGBA(window_surface->format, 255, 255, 255, 255));
    int paletteX = SCREEN_WIDTH+2;
    
    while(paletteX < SCREEN_WIDTH + PALETTE_WIDTH)
        R_DrawFullColumn(paletteX++, SDL_MapRGBA(window_surface->format, 128, 128, 128, 128));

    R_UpdateColorPicker();
}

void R_UpdateColorPicker(void)
{
    // Draw RGB scheme
    int startingPixelXOffset = SCREEN_WIDTH + 7;
    int startingPixelYOffset = 10;

    static ColorRGB_t color;
    for(int x = 0; x <128; x++)
    for(int y = 0; y < 64; y++)
    {
        ColorHSV_t hsv;
        hsv.h = x*2;
        hsv.s = y * 4;
        hsv.v = paletteBrightness;

        color = HSVtoRGB(hsv);
        pixels[(x+startingPixelXOffset) + (y + startingPixelYOffset) * width] = SDL_MapRGB(window_surface->format, color.r, color.g, color.b);
    }
    for(int x = 128; x < 144; x++)
    for(int y = 0; y < 64; y++)
    {
        pixels[(x+startingPixelXOffset) + (y + startingPixelYOffset) * width] = SDL_MapRGB(window_surface->format, y * 4, y * 4, y * 4);
    }

    R_DrawCurrentColor();
}

void R_DrawCurrentColor(void)
{
    // Draw current color
    int startingPixelXOffset = SCREEN_WIDTH + 7 + 46;
    int startingPixelYOffset = 102;

    for(int x = 0; x < 48; x++)
        for(int y = 0; y < 48; y++)
            pixels[(x+startingPixelXOffset) + (y + startingPixelYOffset) * width] = currentMainColor;
}

void R_DrawFixed(int x1, int y1, int x2, int y2)
{
    // Draw a simple line if bushSize is 1
        if(bushSize <= 1)
            pixels[x1 + y1 * width] = currentMainColor;
        else // Otherwise keep drawing circles
            R_DrawCircle(x1, y1, bushSize);
            
    while(x1 != x2 || y1 != y2)
    {
        if(x1 != x2)
            if(x1 > x2)
                x1--;
            else if (x1 < x2)
                x1++;

        if(y1 != y2)
            if(y1 > y2)
                y1--;
            else if(y1 < y2)
                y1++;

        // Draw a simple line if bushSize is 1
        if(bushSize <= 1)
            pixels[x1 + y1 * width] = currentMainColor;
        else // Otherwise keep drawing circles
            R_DrawCircle(x1, y1, bushSize);
    }
}

void R_DrawCircle(int x0, int y0, int r)
{
    for(int y=-r; y<=r; y++)
        for(int x=-r; x<=r; x++)
            if(x*x+y*y <= r*r)
                if( x0+x > 0 && x0+x < SCREEN_WIDTH && y0+y > 0 && y0+y < SCREEN_HEIGHT)    // To not go outside of boundaries
                    pixels[(x0+x) + (y0+y) * width] = currentMainColor;
}


ColorRGB_t HSVtoRGB(ColorHSV_t colorHSV)
{
    float r, g, b, h, s, v; //this function works with floats between 0 and 1
    h = colorHSV.h / 256.0;
    s = colorHSV.s / 256.0;
    v = colorHSV.v / 256.0;

    //If saturation is 0, the color is a shade of gray
    if(s == 0) r = g = b = v;
    //If saturation > 0, more complex calculations are needed
    else
    {
        float f, p, q, t;
        int i;
        h *= 6; //to bring hue to a number between 0 and 6, better for the calculations
        i = (int)(floor(h));  //e.g. 2.7 becomes 2 and 3.01 becomes 3 or 4.9999 becomes 4
        f = h - i;  //the fractional part of h
        p = v * (1 - s);
        q = v * (1 - (s * f));
        t = v * (1 - (s * (1 - f)));
        switch(i)
        {
            case 0: r = v; g = t; b = p; break;
            case 1: r = q; g = v; b = p; break;
            case 2: r = p; g = v; b = t; break;
            case 3: r = p; g = q; b = v; break;
            case 4: r = t; g = p; b = v; break;
            case 5: r = v; g = p; b = q; break;
        }
    }

    
    ColorRGB_t colorRGB;
    colorRGB.r = (int)(r * 255.0);
    colorRGB.g = (int)(g * 255.0);
    colorRGB.b = (int)(b * 255.0);
    return colorRGB;
}