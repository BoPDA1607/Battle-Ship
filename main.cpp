#include <iostream>
#include "header\Game.h"
int WIDTH = 1000, HEIGHT = 600;

int main( int argc, char *argv[])
{
    bool GameIsRunning = true, leftButtonDown = false, StartGame = false, PlayGame = false, Option = false,
        endGame = false, win = false, stop = false, save = false, save1 = false, check = false, replay = false, home = false;
    int turn = 0, count = 0, isfirst = 1;
    SDL_Event event;
    SDL_Point mousePos;

    Node* selected_rect = NULL;
    Node* shootNode = NULL;
    //Define buttons
    //In game buttons
    Node start_button = Node(0, 0, 800, 70, 140, 59);
    Node save_button = Node(0, 0, 800, 70, 140, 59);
    Node save_button1 = Node(0, 0, 800, 500, 140, 59);
    Node slide_button1 = Node(0, 0, 95, 152, 30, 30);
    Node slide_button2 = Node(0, 0, 95, 415, 30, 30);
    //Title screen buttons
    Node play_button = Node(0, 0, 100, 450, 300, 125);
    Node option_button = Node(0, 0, 500, 450, 300, 125);
    //End screen buttons
    Node replay_button = Node(0, 0, 275, 380, 300, 123);
    Node home_button = Node(0, 0, 497, 380, 300, 123);
    //Define Screen
    //Define Screen for playing
    Node gameScreen = Node(0, 0, 0, 0, 1290, 600);
    //Define Screen for placing boat
    Node placeScreen = Node(0, 0, 0, 0, 1000, 600);
    //Define Screen for changing difficulty
    Node optionScreen = Node(0, 0, 0, 0, 1000, 600);
    //Define Title screen
    Node titleScreen = Node(0, 0, 0, 0, 1000, 600);
    //Define Turn screen
    Node turn0 = Node(0, 0, 0, 0, 645, 600);
    Node turn1 = Node(0, 0, 645, 0, 645, 600);
    //Define End Screen
    Node endScreen1 = Node(0, 0, 80, 235, 480, 130);
    Node endScreen2 = Node(0, 0, 720, 235, 480, 130);

    //Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = CreateNewWindow(WIDTH, HEIGHT);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    //Define boat for 2 players
    Boat bPlayer1(3, 1, slide_button1.GetX(), slide_button2.GetX());
    Boat bPlayer2(3, 1, slide_button1.GetX(), slide_button2.GetX());
    //Map for playing
    Map m1(1, 1, slide_button1.GetX());
    Map m2(9, 1, slide_button1.GetX());
    //Map for player place boat
    Map m3(3, 1, slide_button1.GetX());

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
                    if(!endGame)
                    {
                        //Check if play button is clicked
                        if(SDL_PointInRect(&mousePos, play_button.getRect()) && !Option)
                        {
                            PlayGame = true;
                            InitGameEntity(bPlayer1, bPlayer2, m1, m2, m3, slide_button1.GetX(), slide_button2.GetX());
                        }
                        if(SDL_PointInRect(&mousePos, option_button.getRect()) && !PlayGame)
                            Option = true;
                        if(SDL_PointInRect(&mousePos, save_button1.getRect()))
                        {
                            Option = false;
                            cout << slide_button1.GetX() << endl;
                            cout << slide_button2.GetX();
                        }
                        
                        if(Option)
                        {
                            if(SDL_PointInRect(&mousePos, slide_button1.getRect()))
                                selected_rect = &slide_button1;
                            else if(SDL_PointInRect(&mousePos, slide_button2.getRect()))
                                selected_rect = &slide_button2;
                        }
                        if(PlayGame)
                        {
                            //Player 1 first
                            if(turn == 0 && isfirst == 1)
                                selected_rect = MoveBoat(bPlayer1, save, mousePos);
                            //Player 2 next
                            else if(turn == 1 && isfirst == 1)
                                selected_rect = MoveBoat(bPlayer2, StartGame, mousePos);
                            //Player 2 first
                            if(turn == 1 && isfirst == 2)
                                selected_rect = MoveBoat(bPlayer2, save, mousePos);
                            //Player 1 next
                            else if(turn == 0 && isfirst == 2)
                                selected_rect = MoveBoat(bPlayer1, StartGame, mousePos);
                        }
                        //Shooting
                        //Player 1 shoot turn
                        if(turn == 0 && StartGame && m1.InRange(mousePos.x, mousePos.y, Node::nodeSize[slide_button1.GetX()]))
                        {
                            cout << "lmao";
                            int updX = mousePos.x/Node::nodeSize[slide_button1.GetX()];
                            int updY = mousePos.y/Node::nodeSize[slide_button1.GetX()];
                            cout << endl << updX << " " << updY << endl;
                            shootNode = m1.getNode(updX, updY, 1, 1, slide_button1.GetX());
                        }
                        //Player 2 shoot turn
                        else if(turn == 1 && StartGame && m2.InRange(mousePos.x, mousePos.y, Node::nodeSize[slide_button1.GetX()]))
                        {
                            int updX = mousePos.x/Node::nodeSize[slide_button1.GetX()];
                            int updY = mousePos.y/Node::nodeSize[slide_button1.GetX()];
                            cout << updX << " " << updY << endl;
                            shootNode = m2.getNode(updX, updY, 9, 1, slide_button1.GetX());
                        }

                        //Check if save button is clicked
                        if(SDL_PointInRect(&mousePos, save_button.getRect()) && !save)
                        {
                            //Update players boat position in map
                            //Player 1 first
                            cout << "lmao";
                            if(isfirst == 1)
                            {
                                UpdateBoatPos(bPlayer1, save, m2, m3, turn, 9, 1, slide_button1.GetX(), slide_button2.GetY());
                            }
                            //Player 2 first
                            else
                            {
                                UpdateBoatPos(bPlayer2, save, m1, m3, turn, 1, 1, slide_button1.GetX(), slide_button2.GetY());
                            }
                            
                        }
                        else if(SDL_PointInRect(&mousePos, start_button.getRect()) && !StartGame)
                        {
                            if(isfirst == 1)
                            {
                                check = UpdateBoatPos(bPlayer2, StartGame, m1, m3, turn, 1, 1, slide_button1.GetX(), slide_button2.GetX());
                                //Destroy current window to create a new window
                                SDL_DestroyRenderer(renderer);
                                SDL_DestroyWindow(window);
                                window = ResizeWindow(check, WIDTH, HEIGHT, leftButtonDown);
                                renderer = SDL_CreateRenderer(window, -1, 0);
                            }
                            else
                            {
                                check = UpdateBoatPos(bPlayer1, StartGame, m2, m3, turn, 9, 1, slide_button1.GetX(), slide_button2.GetX());
                                //Destroy current window to create a new window
                                SDL_DestroyRenderer(renderer);
                                SDL_DestroyWindow(window);
                                window = ResizeWindow(check, WIDTH, HEIGHT, leftButtonDown);
                                renderer = SDL_CreateRenderer(window, -1, 0);
                            }
                        }
                    }
                    else
                    {
                        replay = SDL_PointInRect(&mousePos, replay_button.getRect());
                        home =SDL_PointInRect(&mousePos, home_button.getRect());
                        if(replay || home)
                        {
                            ReplayOrHome(replay, home, PlayGame, StartGame, save, win, endGame, bPlayer1, bPlayer2, m1, m2, slide_button1.GetX(), slide_button2.GetX());
                            //Destroy current window to create a new window
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            window = ResizeWindow(true, WIDTH, HEIGHT, leftButtonDown);
                            renderer = SDL_CreateRenderer(window, -1, 0);
                            Option = false;
                        }
                    }
                    
                }
                
                break;

            case  SDL_MOUSEMOTION:
                mousePos = { event.motion.x, event.motion.y};
                if(!StartGame)
                {
                    int updX = (mousePos.x)/Node::nodeSize[slide_button1.GetX()];
                    int updY = (mousePos.y)/Node::nodeSize[slide_button1.GetX()];

                    if(leftButtonDown && selected_rect != NULL && selected_rect->InRange(updX, updY, slide_button1.GetX()) && !Option)
                    {
                        selected_rect->ChangePos(updX, updY, slide_button1.GetX());
                    }
                }
                if(Option && !PlayGame)
                {
                    int updX = mousePos.x/180;
                    if(leftButtonDown && selected_rect != NULL && selected_rect->InRange(updX))
                    {
                        selected_rect->ChangeXPos(updX);
                        selected_rect->GetX() = updX;
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

        //Title Screen
        titleScreen.ShowTitle(*renderer, PlayGame, Option);
        play_button.ShowPB(*renderer, PlayGame, Option);
        option_button.ShowOB(*renderer, Option);
        save_button1.ShowSB(*renderer, StartGame, Option, save1);
        slide_button1.SlideButton(*renderer, Option);
        slide_button2.SlideButton(*renderer, Option);

        //Play Screen
        if(!StartGame)
            placeScreen.ShowScreen(*renderer, StartGame, PlayGame, save, slide_button1.GetX());
        else if(StartGame)
            gameScreen.ShowScreen(*renderer, StartGame, PlayGame, save, slide_button1.GetX());
        //Show buttons
        save_button.ShowSB(*renderer, StartGame, PlayGame, save);
        start_button.ShowSB(*renderer, StartGame, PlayGame, save);
        //Show player boat in placing mode
        if(!save && isfirst == 1)
            bPlayer1.DrawBoat(*renderer, StartGame, PlayGame);
        else if(!save && isfirst == 2)
            bPlayer2.DrawBoat(*renderer, StartGame, PlayGame);
        if(save && !StartGame && isfirst == 1)
            bPlayer2.DrawBoat(*renderer, StartGame, PlayGame);
        else if(save && !StartGame && isfirst == 2)
            bPlayer1.DrawBoat(*renderer, StartGame, PlayGame);

        //Detect players turn
        if(StartGame && turn == 0)
        {
            Graphics gTurn("images/turn.bmp", *renderer);
            gTurn.Render(*renderer, turn0.getRect());
        }
        else if(StartGame && turn == 1)
        {
            Graphics gTurn("images/turn.bmp", *renderer);
            gTurn.Render(*renderer, turn1.getRect());
        }

        //
        if(shootNode != NULL && turn == 0)
        {
            UpdNodeVal(*shootNode, *selected_rect, turn, bPlayer2, slide_button1.GetX());
            if(selected_rect != NULL) selected_rect = NULL;
            shootNode = NULL;
        }
        else if(shootNode != NULL && turn == 1)
        {
            UpdNodeVal(*shootNode, *selected_rect, turn, bPlayer1, slide_button1.GetX());
            if(selected_rect != NULL) selected_rect = NULL;
            shootNode = NULL;
        }
        
        m1.checkMap(*renderer, slide_button1.GetX(), StartGame);
        m2.checkMap(*renderer, slide_button1.GetX(), StartGame);

        //Check if boat is hit
        bPlayer1.CheckBoat(*renderer, Node::nodeSize[slide_button1.GetX()]);
        bPlayer2.CheckBoat(*renderer, Node::nodeSize[slide_button1.GetX()]);
        //Check if all boat is sink
        if(bPlayer1.GetisSink() == Boat::SinkBoat && !endGame)
        {
            turn = 1;
            win = true;
            isfirst = 2;
            endGame = true;
        }
        else if(bPlayer2.GetisSink() == Boat::SinkBoat && !endGame)
        {
            turn = 0;
            isfirst = 1;
            endGame = true;
        }
        //Check if game is end
        if(endGame)
        {
            Graphics gEScreen1("images/win.bmp", *renderer);
            Graphics gEScreen2("images/lose.bmp", *renderer);
            Graphics gRB("images/replay.bmp", *renderer);
            Graphics gHB("images/home.bmp", *renderer);
            //Player1
            if(!win)
                gEScreen1.Render(*renderer, endScreen1.getRect());
            else
                gEScreen2.Render(*renderer, endScreen1.getRect());
            //Player2
            if(win)
                gEScreen1.Render(*renderer, endScreen2.getRect());
            else
                gEScreen2.Render(*renderer, endScreen2.getRect());
            gRB.Render(*renderer, replay_button.getRect());
            gHB.Render(*renderer, home_button.getRect());
        }

        SDL_RenderPresent(renderer);
        
    }
   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}