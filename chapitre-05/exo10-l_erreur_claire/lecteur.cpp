#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKMedia/Video/NkVideoReader.h"
#include "NKMedia/NkMediaProbe.h"
#include  <iostream>

using namespace nkentseu;
int nkmain(const nkentseu::NkEntryState &state)
{
    const char *fichier[]={
        "vid1.mp4",
        "vid2.mp4",
        "test.mp4",
    };
    for(int i= 0; i< 3; i++){
        const char *chemin = fichier[i];
        nkentseu::media::NkVideoReader lecteur;
        nkentseu::media::NkVideoFrame frame;

        int images = 0;
        bool ouvert = lecteur.Open(chemin);
        std::cout<< "\nFichier : "<< chemin <<"\n";
        std::cout<< "Ouvert :" <<(ouvert? "oui" : "non") << "\n";
        if(ouvert){
            const nkentseu::media::NkVideoReaderInfo &info =lecteur.Info();
            std::cout << "Conteneur : " << info.container.CStr() << '\n';
            std::cout << "Codec : " << info.codec.CStr() << '\n';
            std::cout << "Largeur : " << info.width << '\n';
            std::cout << "Hauteur : " << info.height << '\n';

            while (lecteur.ReadFrame(frame))
            {
                ++images;
            }

            lecteur.Close();
        }

        nkentseu::media::NkMediaInfo infoSonde;
        bool sondeReussie = nkentseu::media::NkMediaProbe::ProbeFile(chemin, infoSonde);

        std::cout << "Images lues : " << images << '\n';

        if (sondeReussie)
        {
            std::cout << "Sonde : " << infoSonde.ContainerName() << '\n';

            for (usize j = 0; j < infoSonde.tracks.Size(); ++j)
            {
                const nkentseu::media::NkMediaTrack &piste = infoSonde.tracks[j];

                std::cout << "Codec de la piste : "<< piste.codec.CStr() << '\n';
            }
        }
        else
        {
            std::cout << "Sonde : inconnu\n";
        }
    }

    return 0;
}
        