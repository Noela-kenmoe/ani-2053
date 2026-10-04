#include <iostream>
#include <string>

int main (){
    int v, n;
    std::cin>> v >>n;
    int xe =0;
    int xi = 0;
    int sautsEvenements =0;
    int sautsInterrogations =0;
    int manques =0;
    bool space = false;
    bool left = false;
    bool right = false;

       for (int image = 1; image<= n; ++image){
        int k;
        std::cin>> k;
        //bool spacePressedThisFrame = true;
        int pullspace = 0;
        for (int j = 0; j< k; ++j){

            std::string event;
            std::cin>> event;
              if(event == "+SPACE"){
                  space = true;
                  //spacePressedThisFrame = true;
                  ++pullspace;
                  ++sautsEvenements;
              }else if(event == "-SPACE"){
                space = false;
              }
              else if(event =="+RIGHT"){
                right = true;
                xe += v;
              }else if (event == "-RIGHT" ){
                right = false;
              }else if (event == "+LEFT"){
                left = true;
                xe -= v;
              }else if (event== "-LEFT"){
                left = false;
              }
            }
              if (pullspace >0 && ! space){
                manques += pullspace; 
              }
              if (space){
                ++sautsInterrogations;
              }
              if(right){
                xi +=v;
              }
              if (left){
                xi -= v;
              }
            std::cout<<image<< " " << xe <<" "<<xi<<"\n";
            
        }
        std::cout<<"SAUTS EVENEMENTS "<<sautsEvenements <<"\n";
        std::cout<<"SAUTS INTERROGATIONS "<< sautsInterrogations<< "\n";
        std::cout<<"MANQUES "<<manques<<"\n";
        return 0;
}

