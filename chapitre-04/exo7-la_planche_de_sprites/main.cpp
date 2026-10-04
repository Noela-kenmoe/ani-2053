#include <iostream>
#include <string>

int main (){
    int C,R,W,H,F,D,P;
    std::cin>> C>> R>> W>> H>> F>> D>> P;
    int N;
    std::cin>> N;
    int current = 0;
    int accumulated = 0;
    int advances = 0;
    int plafonnes = 0;
    for(int i = 0; i< N; i++){
        int dt;
        std::cin>> dt;
          if(dt > P){
            dt = P;
            ++plafonnes; 
        }
        accumulated += dt;
      
        while(accumulated >=  D){
                 accumulated -=D;
                 ++advances;
                 current++;
            if(current>=F){
                 current = 0;
            }
        }
        int column = current % C;
        int row = current / C;
    
        int x = column * W;
        int y = row * H;
       std::cout<<current<<" "<<x<<" "<<y<<" "<<W<<" "<<H<<"\n";
    }
    std::cout<<"AVANCES "<< advances<<"\n";
    std::cout<< "PLAFONNES "<< plafonnes<<"\n";
    return 0; 
}