#include <iostream>
#include "Boat.h"
const int WIDTH = 1000, HEIGHT = 600;

int main( int argc, char *argv[])
{
    bool GameIsRunning = true;
    SDL_Event event;
    bool leftButtonDown = false, rightButtonDown = false;
    SDL_Point mousePos;
    SDL_Point clickOffset;
    SDL_Rect* selected_rect;

    float angle1 = 0;
    float angle2 = 0;
    float angle3 = 0;

    //Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Battle Ship",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // SDL_Surface *Node_map_surface = SDL_LoadBMP("Node.bmp");
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Node_map_surface);
    // SDL_FreeSurface(Node_map_surface);

    SDL_Texture *node_texture;

    // SDL_Texture *boat1_texture;
    // SDL_Texture *boat2_texture;

    Map m1;
    Boat bPlayer;
    int count = 0;

    while (GameIsRunning)
    {
        SDL_Delay(20);
        SDL_PollEvent (&event);
        switch (event.type)
        {
            case SDL_QUIT:
                GameIsRunning = false;
                break;

            case SDL_MOUSEBUTTONUP:
                if(leftButtonDown && event.button.button == SDL_BUTTON_LEFT)
                {
                    leftButtonDown = false;
                    selected_rect = NULL;
                }
                
                break;

            case SDL_MOUSEBUTTONDOWN:
                if(!leftButtonDown && event.button.button == SDL_BUTTON_LEFT)
                {
                    // if(count == 2)
                    // {
                    //     count = 0;
                    // }
                    // else
                    // {
                    //     count += 1;
                    // }
                    leftButtonDown = true;
                    for(int i = 0; i < Boat::boatNums; i++)
                    {
                        if(SDL_PointInRect(&mousePos, bPlayer.GetBoat(i)))
                        {
                            selected_rect = bPlayer.GetBoat(i);
                            clickOffset.x = mousePos.x - bPlayer.GetBoat(i)->x;
                            clickOffset.y = mousePos.y - bPlayer.GetBoat(i)->y;

                            break;
                        }
                    }
                }
                
                break;
            
            case  SDL_MOUSEMOTION:
                mousePos = { event.motion.x, event.motion.y };

                if(leftButtonDown && selected_rect != NULL)
                {
                    if(mousePos.x - clickOffset.x < selected_rect->x && mousePos.y - clickOffset.y < selected_rect->y)
                    {
                        selected_rect->x = (mousePos.x - clickOffset.x - 80);
                        selected_rect->y = (mousePos.y - clickOffset.y - 80);
                    }
                    else
                    {
                        selected_rect->x = (mousePos.x - clickOffset.x + 80);
                        selected_rect->y = (mousePos.y - clickOffset.y + 80);    
                    }
                    
                    
                }

                
                break;

        }
 
        // clear window
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
 
        // TODO rendering code goes here  
        //Draw map to screen
        m1.drawMap(*renderer, node_texture);
        //Draw boat to screen
        bPlayer.DrawBoat(*renderer, *selected_rect, angle1, angle2, angle3);
        //m1.Show();
        // render window
 
        SDL_RenderPresent(renderer);
    }
    // Boat bBOT;
    // Boat bPlayer;
    SDL_DestroyTexture(node_texture);
    // SDL_DestroyTexture(boat1_texture);
    // SDL_DestroyTexture(boat2_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}