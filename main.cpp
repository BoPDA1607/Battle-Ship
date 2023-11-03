#include <iostream>
#include ".header\Boat.h"
const int WIDTH = 1000, HEIGHT = 600;

int main( int argc, char *argv[])
{
    bool GameIsRunning = true, leftButtonDown = false, StartGame = false;
    SDL_Event event;
    SDL_Point mousePos;
    SDL_Point clickOffset;
    Node* selected_rect;

    Node hitNode = Node(0.0f, 0.0f, 80, 80, Node::nodeSize, Node::nodeSize);
    Node* missNode = NULL;

    Node start_button = Node(0.0f, 0.0f, 800, 70, 140, 59);
    Node screen = Node(0.0f, 0.0f, 0, 0, 1000, 600);

    //Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Battle Ship",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Boat bPlayer;
    Boat bBot(1);

    Map m1(Node::nodeSize);
    
    Graphics gMissNode("Miss.bmp", *renderer);
    Graphics gHitNode("hitNode.bmp", *renderer);
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
                        if(!StartGame)
                        {
                            if(SDL_PointInRect(&mousePos, bPlayer.GetBoat(i)->getRect()))
                            {
                                selected_rect = bPlayer.GetBoat(i);
                                clickOffset.x = mousePos.x - selected_rect->GetX();
                                clickOffset.y = mousePos.y - selected_rect->GetY();

                                break;
                            }
                        }
                        else
                        {
                            if(SDL_PointInRect(&mousePos, bBot.GetBoat(i)->getRect()))
                            {
                                selected_rect = bBot.GetBoat(i);
                                cout << "hit";

                                break;
                            }
                        }
                        
                    }
                    if(StartGame && selected_rect == NULL)
                    {
                        cout << "Miss";
                        missNode = m1.getNode(mousePos.x/Node::nodeSize, mousePos.y/Node::nodeSize);
                        if(!missNode->GetHit())
                        {
                            missNode->GetHit() = true;
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
                else
                {
                    mousePos = { event.motion.x, event.motion.y };
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
            //Render background
            gScreen("Map.bmp", *renderer);
            gScreen.Render(*renderer, screen.getRect(), screen.GetAngle(), SDL_FLIP_NONE);
            //Render Boat to screen
            bPlayer.DrawBoat(*renderer);
            
            g1.Render(*renderer, start_button.getRect(), start_button.GetAngle(), SDL_FLIP_NONE);
        }
        else
        {
            start_button.~Node();
            g1.~Graphics();
            gScreen("Map1.bmp", *renderer);
            gScreen.Render(*renderer, screen.getRect(), screen.GetAngle(), SDL_FLIP_NONE);
            //bBot.DrawBoat(*renderer, *selected_rect);

            if(selected_rect!= NULL && selected_rect->getRect()->w == Node::nodeSize*2)
            {
                if((mousePos.x - selected_rect->getRect()->x) <= (selected_rect->getRect()->w/2))
                {
                    hitNode(selected_rect->getRect()->x, selected_rect->getRect()->y);
                }
                else
                {
                    hitNode(selected_rect->getRect()->x + Node::nodeSize, selected_rect->getRect()->y);
                }
                gHitNode.Render(*renderer, hitNode.getRect(), hitNode.GetAngle(), SDL_FLIP_NONE);
            }
            else if(selected_rect != NULL)
            {
                if((mousePos.x - selected_rect->getRect()->x) <= (selected_rect->getRect()->w/3))
                {
                    hitNode(selected_rect->getRect()->x, selected_rect->getRect()->y);
                }
                else if((mousePos.x - selected_rect->getRect()->x) <= (selected_rect->getRect()->w/3*2))
                {
                    hitNode(selected_rect->getRect()->x + Node::nodeSize, selected_rect->getRect()->y);
                }
                else
                {
                    hitNode(selected_rect->getRect()->x + 2*Node::nodeSize, selected_rect->getRect()->y);
                }
                gHitNode.Render(*renderer, hitNode.getRect(), hitNode.GetAngle(), SDL_FLIP_NONE);
            }
            else if(missNode != NULL && missNode->GetHit())
            {
                gMissNode.Render(*renderer, missNode->getRect(), missNode->GetAngle(), SDL_FLIP_NONE);
            }


        }
        SDL_RenderPresent(renderer);
    }
   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}