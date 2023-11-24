#include <iostream>
#include <SDL2\SDL.h>
using namespace std;

class Graphics
{
    protected:
        SDL_Texture* m_tex;
    public:
        Graphics();
        Graphics(const char*, SDL_Renderer&);
        ~Graphics();
        SDL_Texture* GetTexture();
        Graphics& operator()(const char*, SDL_Renderer&);
        void Render(SDL_Renderer&, SDL_Rect*, float = 0.0f, SDL_RendererFlip = SDL_FLIP_NONE);
        float Rotation(float&);
};
