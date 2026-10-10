#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

int main (){
   int N;
   if (!(std::cin>> N)) return 0;
    int lus = 0;
    int mensonges = 0;
    int refuses  = 0;

     for (int i = 0; i<N; i++){
       std::string nom, octets;
       long long taille;
       std::cin>>nom >> taille>> octets;
       std::string format = "";

       if(taille < 4){
          std::cout<<nom<<" REFUSE\n";
          refuses ++;
          continue;
        }
        if(taille >= 8 && octets.size() >= 8 && octets.substr(0, 8)== "89504E47"){
           format = "PNG";
       }else if (octets.size() >= 6 && octets.substr(0, 6) == "FFD8FF"){
    
          format = "JPEG";
       }else if (octets.size() >= 4 && octets.substr(0, 4) == "424D"){
          format = "BMP";
       }else if (octets.size() >= 8 && octets.substr(0, 8) == "716F6966"){
         format = "QOI";
       }else if (octets.size() >= 8 && octets.substr(0, 8) == "47494638"){
         format = "GIF";
       }else if (octets.size() >= 8 && (octets.substr(0, 6) == "000001" || octets.substr(0, 6) == "000002") && octets.substr(6, 2) == "00"){
         format = "ICO";
       }else if (taille >= 10 && octets.size() >= 4 && octets.substr(0, 4) == "233F"){
         format = "HDR";
       }else if (octets.size() >= 8 && octets.substr(0, 8) == "762F3101"){
         format = "EXR";
      }else if (octets.size() >= 4 && octets.substr(0, 2) == "50" && octets[2] >= '1' && octets[2] <= '6' ){
    char v = octets[2];
    if (v == '1' || v == '4') format = "PBM";
    else if (v == '2' || v == '5') format = "PGM";
    else if (v== '3' || v == '6') format = "PPM";

   }else if ( taille >= 18 && octets.size() >= 6){
        std::string b2 = octets.substr(4, 2);
       if (b2 == "00" || b2 == "01" || b2 == "02" || b2 == "03" || b2 == "09" || b2 == "0A" || b2 == "0B"){
        format = "TGA";
       }
   }if (format == "") {
            std::string temp = octets;
            if (temp.size() >= 6 && temp.substr(0, 6) == "EFBBBF") {
                temp = temp.substr(6);
            }

            while (temp.size() >= 2) {
                std::string b0 = temp.substr(0, 2);
                if (b0 == "20" || b0 == "09" || b0 == "0A" || b0 == "0D") {
                    temp = temp.substr(2);
                } else {
                    break;
                }
            }

           if (temp.size() >= 10 && temp.substr(0, 10) == "3C3F786D6C") {
                format = "SVG";
            } else if (temp.size() >= 8 && temp.substr(0, 8) == "3C737667") {
                format = "SVG";
            }
    }
        
    if (format == "") {
            std::cout << nom << " REFUSE\n";
            refuses++;
        } else {
            lus++; 
            
            size_t dot_pos = nom.find_last_of('.');
            std::string extension = "";
            if (dot_pos != std::string::npos) {
                extension = nom.substr(dot_pos + 1);
                std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
            }
           bool extension_valide = false;
            if (format == "PNG" && extension == "png") 
            {
              extension_valide = true;
            } else if (format == "JPEG" && (extension == "jpg" || extension == "jpeg")){
                   extension_valide = true;
            } 
                else if (format == "BMP" && extension == "bmp"){
                     extension_valide = true;
            }
                else if (format == "QOI" && extension == "qoi"){
                     extension_valide = true;
            }
                else if (format == "GIF" && extension == "gif"){
                     extension_valide = true;
            }
                else if (format == "ICO" && (extension == "ico" || extension == "cur")){
                      extension_valide = true;
            }
                else if (format == "HDR" && extension == "hdr"){
                     extension_valide = true;
            }
                else if (format == "EXR" && extension == "exr"){
                     extension_valide = true;
            }         
                else if (format == "PBM" && extension == "pbm"){
                     extension_valide = true;
            }         
                else if (format == "PGM" && extension == "pgm"){
                     extension_valide = true;
            }
                else if (format == "PPM" && extension == "ppm"){
                     extension_valide = true;
            }
                else if (format == "TGA" && extension == "tga"){
                     extension_valide = true;
            }
                else if (format == "SVG" && extension == "svg"){
                     extension_valide = true;
            }
            
            if (extension_valide) {
                std::cout << nom << " " << format << " OK\n";
            } else {
                std::cout << nom << " " << format << " MENT\n";
                mensonges++;
            }
        }
    } 

 std::cout<< " LUS "<< lus<<"\n";
 std::cout<< " MENSONGES "<< mensonges<<"\n";
 std::cout<< " REFUSES "<< refuses<<"\n";

return 0;
}