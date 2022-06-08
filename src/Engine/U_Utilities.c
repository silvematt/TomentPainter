#include "A_Application.h"
#include "U_Utilities.h"

// ----------------------------------------------------
// Sets an SDL_Rect
// ----------------------------------------------------
void SDL_Rect_Set(SDL_Rect* r, int x, int y, int w, int h)
{
    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;
}

// ----------------------------------------------------
// Flood Fill Stack Operations
// ----------------------------------------------------
void FF_StackPush(transform2d_t stack[], int x, int y, int* top)
{
    (*top)++;
    stack[*top].x = x;
    stack[*top].y = y;
}


transform2d_t FF_StackPop(transform2d_t stack[], int* top)
{
    return stack[(*top)--];
}