#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <map>
#include <string>
#include <SDL.h>

class TextureManager
{
public:
    static TextureManager* Instance()
    {
        if (s_pInstance == 0) {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }

        return s_pInstance;
    }

    bool load(std::string fileName, std::string id,
        SDL_Renderer* pRenderer);

    void clearFromTextureMap(std::string id);

    //draw
    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    //fraw frame
    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame, SDL_Renderer* pRenderer,
        SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager() {}
    ~TextureManager() {}

    std::map<std::string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif