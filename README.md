# Toment Painter

![alt text](https://i.imgur.com/KTopiRa.png)

A super simple Software Rendering Painting Tool written in C and SDL2.


# Description

I've written this painter over a weekend to get started with Computer Graphics :)

Features:
- Draw at different bushes sizes (1px to 10px)
- Color Picker
- Eraser
- CLS (Clear Screen)
- Export the image (640x480) to a .bmp

There were so many features I would have liked to add, but for the time I gave myself on it I'm pretty ok with the result. I've also deliberaterly choosen to not include any other library other than SDL.


I'm not sure it is the best way to do it, but the way it works is at the start of the program I grab the whole Window Surface and store it into an SDL_Surface, I also have a pointer to the pixels of the surface, so that I can do stuff on them, and then I SDL_UpdateWindowSurface at the end of every tick.


It does what I asked lol!
