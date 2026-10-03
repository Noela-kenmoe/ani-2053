#include <iostream>
#include <string>
#include <algorithm>

struct point {
    int x,y;
};

int main (){
    int n;
    std::cin>> n;

    int refus = 0;
    for (int i = 0; i<n; i++){
        std::string nom;
        int w,h,px,py,ox,oy,sy,sx,angle;
        std::cin>> nom >> w>>h >>px >> py >> ox >> oy >> sx>> sy>> angle;

        if (angle % 90 != 0){
            std::cout<< nom<< "ANGLE REFUSE \n";
            ++refus;
            continue;
        }

        int angleNormalise = angle % 360;
        if(angleNormalise<0){
            angleNormalise += 360;

        }
          int cos= 0;
          int sin = 0;
          if (angleNormalise == 0){
            cos = 1;
            sin = 0;
          }else if (angleNormalise == 90){
            cos = -1;
            sin = 0;
          }else if (angleNormalise == 180){
            cos = -1;
            sin = 0;
          }else if(angleNormalise == 270){
            cos = 0;
            sin = -1;
          }

          int coinsX[4]= {0, w ,w ,0};
          int coinsY[4]= {0, 0, h, h};
          point coins[4];

          for (int j = 0; j<4; j++){
              int ax = coinsX[j]-ox;
              int ay = coinsY[j]-oy;

               ax*= sx;
               ay*= sy;
      
               int rx = ax * cos - ay * sin;
               int ry = ax * sin + ay * cos;

              coins[j].x= px + rx;
              coins[j].y= py + ry;

            }
        int minx = coins[0].x;
        int maxx = coins[0].x;
        int miny = coins[0].y;
        int maxy = coins[0].y;

        for (int j = 1; j < 4; ++j)
        {
            minx = std::min(minx, coins[j].x);
            maxx = std::max(maxx, coins[j].x);
            miny = std::min(miny, coins[j].y);
            maxy = std::max(maxy, coins[j].y);
        }

        std::cout << nom << " COINS ";

        for (int j = 0; j < 4; ++j)
        {
            std::cout << coins[j].x << " " << coins[j].y;

            if (j < 3)
            {
                std::cout << " ";
            }
        }

        std::cout << "\n";

        std::cout << nom << " BOITE "<< minx << " "<< miny << " "<< maxx << " "<< maxy << "\n";
    }
    std::cout << "REFUSES " << refus << "\n";

    return 0;
}
