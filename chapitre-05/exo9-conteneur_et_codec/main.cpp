#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

struct Track 
{
    std::string type;
    std::string code;
};

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int nfiles;
    if(!(std::cin >> nfiles)) return 0;
    int mp4count = 0;
    int lisiblecount = 0;
    int inconnucount = 0;

    std::map<std::string, std::string> codecMap = {
        {"mp4a", "aac"}, {"MP4A", "aac"},
        {"Opus", "oeuvre"}, {"opus", "oeuvre"},
        {"AVC1", "H264"}, {"avc1", "h264"},
        {"AVC3", "H264"}, {"avc3", "h264"},
        {"HVC1", "H265"},{"hvc1", "h265"},
        {"HEV1", "H265"},{"hev1", "h265"},
        {"VP08", "VP8"},{"vp08", "vp8"},
        {"VP09", "VP9"},{"vp09", "vp9"},
        {"MP4V", "mpeg4"}, {"mp4v", "mpeg4"},
        {".mp3", "mp3"},
        {"Deux", "PCM"}, {"deux", "pcm"},
        {"SOWT", "PCM"}, {"sowt", "pcm"},
        {"LPCM", "PCM"},{"lpcm", "pcm"}
    };
    for (int i = 0; i < nfiles; i++){
       std::string name, hexStr;
       int p;
       std::cin >> name >> hexStr >> p;
       std::vector<Track> tracks(p);
        for (int j=0; j < p; j++){
           std::cin>> tracks[j].type >> tracks[j].code;
        }
       std::vector<unsigned char> bytes;
        if(hexStr != "-"){
            for(size_t k = 0; k < hexStr.length(); k +=2){
               std::string byteString = hexStr.substr(k, 2);
               unsigned char byte = static_cast<unsigned char>(std::stoul(byteString, nullptr, 16));
               bytes.push_back(byte);
            }
        }
        std::string container = "INCONNU";
        size_t bsize = bytes.size();
        if (bsize >= 12 && bytes[4] == 0x66 && bytes[5] == 0x74 && bytes[6] == 0x79 && bytes[7] == 0x70) {
            container = "MP4";
        }
        else if (bsize >= 4 && bytes[0] == 0x1A && bytes[1] == 0x45 && bytes[2] == 0xDF && bytes[3] == 0xA3) {
            container = "WEBM";
        }
        else if (bsize >= 12 && bytes[0] == 0x52 && bytes[1] == 0x49 && bytes[2] == 0x46 && bytes[3] == 0x46 &&
                 bytes[8] == 0x57 && bytes[9] == 0x41 && bytes[10] == 0x56 && bytes[11] == 0x45) {
            container = "WAV";
        }
        else if (bsize >= 4 && bytes[0] == 0x4F && bytes[1] == 0x67 && bytes[2] == 0x67 && bytes[3] == 0x53) {
            container = "OGG";
        }
        else if (bsize >= 4 && bytes[0] == 0x66 && bytes[1] == 0x4C && bytes[2] == 0x61 && bytes[3] == 0x43) {
            container = "FLAC";
        }
        else if (bsize >= 3 && bytes[0] == 0x49 && bytes[1] == 0x44 && bytes[2] == 0x33) {
            container = "MP3";
        }
        else if (bsize >= 2 && bytes[0] == 0xFF && bytes[1] >= 0xE0) {
            container = "MP3";
        }
        std::cout << name << " " << container << "\n";
        if (container == "MP4") {
            mp4count++;
            for (int j = 0; j < p; ++j) {
                std::string translatedCode = tracks[j].code;
                if (codecMap.count(translatedCode)) {
                    translatedCode = codecMap[translatedCode];
                }
                std::string displayedType = tracks[j].type;
                if (displayedType == "vide") displayedType = "VIDEO";
                else if (displayedType == "soun") displayedType = "AUDIO";
                std::cout << name << " PISTE " << (j + 1) << " " << displayedType << " " << translatedCode << "\n";
            }
            std::string verdict = "SANS_IMAGE";
            for (int j = 0; j < p; ++j) {
                if (tracks[j].type == "vide") {
                    std::string code = tracks[j].code;
                    if (code == "mjpa" || code == "jpeg" || code == "MJPG" ||
                        code == "avc1" || code == "avc3" || code == "hvc1" || code == "hev1" || code == "av01") {
                        verdict = "LISIBLE";
                    } else {
                        verdict = "ECHEC";
                    }
                    break; 
                }
            }
            std::cout << name << " LECTEUR " << verdict <<"\n";
            if( verdict == "LISIBLE"){
                lisiblecount ++;
            }
        }
        if (container == "INCONNU"){
                inconnucount++;
        }
    }
std::cout << "MP4 " << mp4count << "\n";
std::cout <<"LISIBLES "<< lisiblecount <<"\n";
std::cout <<"INCONNUS "<< inconnucount <<"\n";
return 0;
}