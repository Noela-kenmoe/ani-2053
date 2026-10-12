#include <iostream>
#include "NkFont.h"
#include "Core/NkFontTypes.h"
#include "NKContainers/Sequential/NkVector.h"
#include "NKFont/Core/NkFontParser.h"
#include "NKImage/Core/NkImage.h"

using namespace nkentseu;
int main (){
    nkentseu::NkFontAtlas atlas;
    nkentseu::NkFont* font = atlas.AddFontFromFile("C:/Windows/Fonts/arial.ttf", 18.f);
    if(!font){
        std::cout << "Erreur impossible de charger la police\n";
        return 1;
    }
    atlas.Build();
    nkft_uint8* pixels = nullptr;
    nkft_int32 largeur = 0, hauteur = 0;
    atlas.GetTexDataAsRGBA32(&pixels, &largeur, &hauteur); 
    nkentseu::NkImage::Wrap(pixels, largeur, hauteur, nkentseu::NkImagePixelFormat::NK_RGBA32).SavePNG("atlas.png");

    std::cout <<"[SUCCES] Atlas de texture genere (Dimensions : " << largeur << "x" << hauteur << ").\n";
    return 0;
}