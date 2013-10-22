#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;
using namespace sf;

int main(int argc,char* argv[])
{
//param nomfichier nbx nby taille

    if (argc >3)
    {
        int x,y,nbx,nby;
        string nomFichier(argv[1]);
        nbx=atoi(argv[2]);
        nby=atoi(argv[3]);
        string prefix;
        if (argc>4)
            prefix = argv[4];
        sf::Image image_base;
        image_base.loadFromFile(nomFichier);

        x=image_base.getSize().x/nbx;
        y=image_base.getSize().y/nby;

        cout<<"l'image "<<nomFichier<<" va etre decoupée en "<<nbx*nby<<" images de "<<x<<" par "<<y<<" pixels dans le dossier img"<<endl;

        Image image_decoupe;
        image_decoupe.create(x,y,Color(255,255,255));

        stringstream out;


        for (int i=0;i<nby;i++)
            for(int j=0;j<nbx;j++)
            {
                out.str(string());
                image_decoupe.copy(image_base,0,0,IntRect(j*x,i*y,(j+1)*x,(i+1)*y),false);
                out<<"img/"<<prefix<<i+1<<"_"<<j+1<<".png";
                image_decoupe.saveToFile(out.str());
            }
    }
    else
    {
        cout<<"les argument sont: nom de l'image source /nombre verticale / nombre horizontale"<<endl;
    }

    return EXIT_SUCCESS;
};
