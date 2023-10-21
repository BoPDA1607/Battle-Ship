#include <iostream>
#include <SDL2\SDL.h>
using namespace std;

class Graphics
{
    protected:
        SDL_Texture* m_tex;
    public:
        Graphics(string, SDL_Renderer&);
        ~Graphics();
        void Render(SDL_Renderer&, SDL_Rect*, float = 0.0f, SDL_RendererFlip = SDL_FLIP_NONE);
        float Rotation(float&);
};