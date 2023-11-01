#include <iostream>
#include "Boat.h"
const int WIDTH = 1000, HEIGHT = 600;

int main( int argc, char *argv[])
{
    bool GameIsRunning = true, leftButtonDown = false, StartGame = false;
    SDL_Event event;
    SDL_Point mousePos;
    SDL_Point clickOffset;
    Node* selected_rect;
    Node start_button = Node(800, 70, 140, 59, 0.0f);
    Node screen = Node(0, 0, 1000, 600, 0.0f);

    //Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Battle Ship",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Map m1;
    Boat bPlayer;
    Boat bBot(1);
    
    Graphics g1("start-button.bmp", *renderer);
    Graphics gScreen;
    
    while (GameIsRunning)
    {
        SDL_Delay(40);
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
                    leftButtonDown = true;
                    for(int i = 0; i < Boat::boatNums; i++)
                    {
                        if(SDL_PointInRect(&mousePos, bPlayer.GetBoat(i)->getRect()))
                        {
                            selected_rect = bPlayer.GetBoat(i);
                            clickOffset.x = mousePos.x - selected_rect->GetX();
                            clickOffset.y = mousePos.y - selected_rect->GetY();

                            break;
                        }
                    }
                    if(SDL_PointInRect(&mousePos, start_button.getRect()))
                    {
                        StartGame = true;
                    }
                }
                
                break;

            case  SDL_MOUSEMOTION:
                if(!StartGame)
                {
                    mousePos = { event.motion.x, event.motion.y };
                    
                    int updX = (mousePos.x - clickOffset.x)/Node::nodeSize;
                    int updY = (mousePos.y - clickOffset.y)/Node::nodeSize;

                    //selected_rect->UpdatePos(updX, updY);

                    if(leftButtonDown && selected_rect != NULL && selected_rect->InRange(updX, updY))
                    {
                        selected_rect->ChangePos(updX, updY);
                    }
                }
                            
                break;
            case SDL_KEYDOWN:
                if(!StartGame && selected_rect != NULL && leftButtonDown)
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                            selected_rect->Rotation(90);
                            break;
                        case SDLK_LEFT:
                            selected_rect->Rotation(-90);
                            break;
                    }
                }
                break;

        }
    
 
        // clear window
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        if(!StartGame)
        {
            gScreen("Map.bmp", *renderer);
        }
        else
        {
            start_button.~Node();
            g1.~Graphics();
            gScreen("Map1.bmp", *renderer);
        }
        //Render background
        gScreen.Render(*renderer, screen.getRect(), screen.GetAngle(), SDL_FLIP_NONE);
        //Draw boat to screen
        bPlayer.DrawBoat(*renderer, *selected_rect);
        g1.Render(*renderer, start_button.getRect(), start_button.GetAngle(), SDL_FLIP_NONE);
        // render window
        SDL_RenderPresent(renderer);
    }
   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}