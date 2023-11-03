#include "D:\PBL2\.header\Graphics.h"

Graphics::Graphics()
{ }
Graphics::Graphics(char* filepath, SDL_Renderer& rend)
{ 
    SDL_Surface* surface = SDL_LoadBMP(filepath);
    this->m_tex = SDL_CreateTextureFromSurface(&rend, surface);
    SDL_FreeSurface(surface);
}
Graphics::~Graphics()
{ 
    SDL_DestroyTexture(this->m_tex);
}
Graphics& Graphics::operator()(char* filepath, SDL_Renderer& rend)
{
    SDL_Surface* surface = SDL_LoadBMP(filepath);
    this->m_tex = SDL_CreateTextureFromSurface(&rend, surface);
    SDL_FreeSurface(surface);

    return (*this);
}
void Graphics::Render(SDL_Renderer& rend, SDL_Rect* rect, float angle, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(&rend, this->m_tex, NULL, rect, angle, NULL, flip);
}