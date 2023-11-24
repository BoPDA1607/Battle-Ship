#include <iostream>
#include "header\bot.h"
#include "header\Stack.h"
const int WIDTH = 1000, HEIGHT = 600;

int main( int argc, char *argv[])
{
    bool GameIsRunning = true, leftButtonDown = false, StartGame = false, PlayGame = false, endGame = false, win = false, stop = false;
    int turn = 0, count = 0;
    Stack HuntList;
    SDL_Event event;
    SDL_Point mousePos;
    Node* selected_rect = NULL;

    Node* shootNode = NULL;

    Node start_button = Node(0, 0, 800, 70, 140, 59);
    Node play_button = Node(0, 0, 350, 450, 300, 125);
    Node replay_button = Node(0, 0, 275, 380, 220, 59);
    Node home_button = Node(0, 0, 497, 380, 228, 59);

    Node screen = Node(0, 0, 0, 0, 1000, 600);
    Node titleScreen = Node(0, 0, 0, 0, 1000, 600);
    Node endScreen = Node(0, 0, 275, 145, 450, 250);

    //Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Battle Ship",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Boat bPlayer(3, 1, Node::nodeSize);
    Boat bBot(1, 1, Node::nodeSize);

    Map m1(1, 1, Node::nodeSize);
    Map m2(18, 2, Node::nodeSize/2);
    Map m3(3, 1, Node::nodeSize);
    

    //Load image
    Graphics gRB("images/replay.bmp", *renderer);
    Graphics gHB("images/Home.bmp", *renderer);
    
    
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
                if(leftButtonDown && event.button.button == SDL_BUTTON_LEFT && turn == 0)
                {
                    leftButtonDown = false;
                    selected_rect = NULL;
                }
                
                break;

            case SDL_MOUSEBUTTONDOWN:
                if(!leftButtonDown && event.button.button == SDL_BUTTON_LEFT && turn == 0)
                {
                    leftButtonDown = true;
                    if(!endGame)
                    {
                        if(SDL_PointInRect(&mousePos, play_button.getRect()))
                        {
                            PlayGame = true;
                        }
                        for(int i = 0; i < Boat::boatNums; i++)
                        {
                            if(!StartGame)
                            {
                                if(SDL_PointInRect(&mousePos, bPlayer.GetBoat(i)->getRect()))
                                {
                                    selected_rect = bPlayer.GetBoat(i);

                                    break;
                                }
                            }
                            else if(m1.InRange(mousePos.x, mousePos.y))
                            {
                                if(SDL_PointInRect(&mousePos, bBot.GetBoat(i)->getRect()))
                                {
                                    selected_rect = bBot.GetBoat(i);
                                    shootNode = m1.getNode(mousePos.x/Node::nodeSize, mousePos.y/Node::nodeSize);

                                    break;
                                }
                            }
                            
                        }
                        if(StartGame && selected_rect == NULL && m1.InRange(mousePos.x, mousePos.y))
                        {
                            shootNode = m1.getNode(mousePos.x/Node::nodeSize, mousePos.y/Node::nodeSize);
                            
                        }
                        if(SDL_PointInRect(&mousePos, start_button.getRect()))
                        {
                            bPlayer.UpdatePos();
                            //Set place value in map
                            bPlayer.PointInBoat(m3);
                            //Check if place boat in map is valid
                            if(m3.PlaceInMap())
                            {
                                StartGame = true;
                                bPlayer = bPlayer;
                                bPlayer.ChangePos(18, 2, Node::nodeSize/2);
                                bPlayer.PointInBoat(m2);
                            }
                            else
                            {
                                cout << "WARNING: DAT TAU` TRUNG` ROI` KIA`";
                                //Set place value to 0
                                m3.SetDefault(0);
                            }          

                        }
                    }
                    else
                    {
                        if(SDL_PointInRect(&mousePos, replay_button.getRect()))
                        {
                            StartGame = false;
                            bPlayer(3, 1, Node::nodeSize);
                            bBot(1, 1, Node::nodeSize);

                            m1(1, 1, Node::nodeSize);
                            m2(18, 2, Node::nodeSize/2);
                            m3.SetDefault(0);
                            count = 0;
                            endGame = false;
                            HuntList.MakeNull();
                        }
                        if(SDL_PointInRect(&mousePos, home_button.getRect()))
                        {
                            PlayGame = false;
                            StartGame = false;
                            bPlayer(3, 1, Node::nodeSize);
                            bBot(1, 1, Node::nodeSize);

                            m1(1, 1, Node::nodeSize);
                            m2(18, 2, Node::nodeSize/2);
                            m3.SetDefault(0);
                            count = 0;
                            endGame = false;
                            HuntList.MakeNull();
                        }
                    }
                    
                }
                
                break;

            case  SDL_MOUSEMOTION:
                mousePos = { event.motion.x, event.motion.y};
                if(!StartGame)
                {
                    int updX = (mousePos.x)/Node::nodeSize;
                    int updY = (mousePos.y)/Node::nodeSize;

                    if(leftButtonDown && selected_rect != NULL && selected_rect->InRange(updX, updY))
                    {
                        selected_rect->ChangePos(updX, updY, Node::nodeSize);
                    }
                }
                            
                break;
            case SDL_KEYDOWN:
                if(!StartGame && selected_rect != NULL && leftButtonDown)
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_r:
                            selected_rect->Rotation();
                            selected_rect->SwapWH();
                            break;
                    }
                }

                break;

        }
 
        // clear window
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        if(count < Boat::boatNums)
        {
            *bBot.GetBoat(count) = InitNodePos(count, m1);
            if(bBot.GetBoat(count)->GetX() != -1)
                count++;
            // cout << "Hi";
        }
        //Title Screen
        titleScreen.DrawTitle(*renderer, PlayGame);
        play_button.DrawPB(*renderer, PlayGame);

        //Play Screen
        screen.DrawScreen(*renderer, StartGame, PlayGame);
        start_button.DrawSB(*renderer, StartGame, PlayGame);
        bPlayer.DrawBoat(*renderer, StartGame, PlayGame);

        if(shootNode != NULL && turn == 0)
        {
            if(selected_rect != NULL && shootNode->GetHit() == -1)
            {
                shootNode->GetHit() = 1;
                selected_rect->GetHit() += 1;
                bBot.GetisSink() += 1;
                turn = 1;
                selected_rect = NULL;
            }
            else if(shootNode->GetHit() == -1)
            {
                shootNode->GetHit() = 0;
                turn = 1;
            }

            shootNode = NULL;
        }
        else if(turn == 1)
        {
            int x, y, seed = 1607;
            if(HuntList.ChechNull())
            {
                shootNode = HuntList.Pop();
                shootNode = m2.getNode(shootNode->GetX(), shootNode->GetY());
            }
            else
            {
                do
                {
                    x = GenPos(seed);
                    seed += 34;
                    y = GenPos(seed);
                    shootNode = m2.getNode(x, y);
                } while (shootNode->GetHit() == 0 || shootNode->GetHit() == 1);
            }
            
            if(shootNode->GetPlace() == 1)
            {
                shootNode->GetHit() = 1;
                bPlayer.GetisSink() += 1;
                for(int i = 0; i < 4; i++)
                    HuntList.Push(*m2.FindNear(*shootNode, i*90));
                HuntList.DisplayStack();
                cout << x << " " << y << endl;
                cout << shootNode->GetX() << " " << shootNode->GetY() << endl;
                cout << endl;
            }
            else
            {
                shootNode->GetHit() = 0;
            }
            
            shootNode = NULL;
            
            turn = 0;
        }

        m1.checkMap(*renderer, Node::nodeSize, StartGame);
        m2.checkMap(*renderer, Node::nodeSize/2, StartGame);

        //Check if boat is hit
        bBot.CheckBoat(*renderer, Node::nodeSize);
        //Check if all boat is sink
        if(bBot.GetisSink() == Boat::SinkBoat && !endGame)
        {
            win = true;
            endGame = true;
        }
        else if(bPlayer.GetisSink() == Boat::SinkBoat && !endGame)
        {
            endGame = true;
        }
        //Check if game is end
        if(endGame)
        {
            Graphics gEScreen;
            if(win)
            {
                gEScreen("images/win.bmp", *renderer);
            }
            else
            {
                gEScreen("images/gameover.bmp", *renderer);
            }
            gEScreen.Render(*renderer, endScreen.getRect());
            gRB.Render(*renderer, replay_button.getRect());
            gHB.Render(*renderer, home_button.getRect());
            turn = 0;
        }

        SDL_RenderPresent(renderer);
        
    }
   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}