#include "Graphics.h"

Graphics::Graphics()
{ }
Graphics::Graphics(string filepath, SDL_Renderer& rend)
{ 
    SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
    //SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
    this->m_tex = SDL_CreateTextureFromSurface(&rend, surface);
    SDL_FreeSurface(surface);
}
Graphics::~Graphics()
{ 
    SDL_DestroyTexture(this->m_tex);
}
void Graphics::Render(SDL_Renderer& rend, SDL_Rect* rect, float angle, SDL_RendererFlip flip)
{
   SDL_RenderCopyEx(&rend, this->m_tex, NULL, rect, angle, NULL, flip);
}
// float Graphics::Rotation(float& amount)
// {
//     return (amount += 90);
// }