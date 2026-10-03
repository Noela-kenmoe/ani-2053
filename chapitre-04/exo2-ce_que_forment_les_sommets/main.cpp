/*#include <iostream>
#include <string>

int main(){
    int N;
    //std::cin>> N;
    if(!(std::cin >> N)) return 0;
    int points = 0;
    int segments = 0;
    int triangles = 0;
    int refuses = 0;
 
     for(int i =0; i < N; i++){
        std::string type;
        int s;
        std::cin >> type >>s;
        
        if(type=="POINTS"){
            points += s;
            std::cout <<"POINTS "<<s<<" "<<s<< "POINTS 0"<<std::endl;
        
        }else if(type=="LINES"){
            int nombre = s/2;
            int reste = s%2;

            segments += nombre;
            std::cout <<"LINES "<<s<< " "<< nombre <<"SEGMENTS "<< reste<<std::endl;

        }else if (type=="LINES_STRIP"){
            int nombre;
            int reste;
            if(s==2){
                nombre = s-1;
                reste = 0;
            }else {
                nombre =0;
                reste = s;
            }
            int nombre = (s >=2) ? (s-1) : 0;
            int nombre = (s >=2)? 0 : s;
            segments += nombre;
            std::cout<<"LINE_STRIP " <<s <<""<<nombre<< "SEGMENTS"<<reste<<std::endl;
        }else if(type=="TRIANGLES"){
            int nombre=s/3;
            int reste = s % 3;
            triangles += nombre;
            std::cout<<type<<""<<s<<""<<nombre<<"TRIANGLES"<<reste<<std::endl;
        }else if(type=="TRIANGLE_STRIP "||type=="TRIANGLE_FLANT"){
         
            int nombre;
            int reste;

            if (s >= 3)
            {
                nombre = s - 2;
                reste = 0;
            }
            else
            {
                nombre = 0;
                reste = s;
            }

            triangles += nombre;

            std::cout << type << " " << s << " "<< nombre << " TRIANGLES "<< reste << std::endl;
        }
        else
        {
            refuses++;

            std::cout << type << " " << s << " REFUSE" << std::endl;
        }
    }

    std::cout << "POINTS " << points << std::endl;
    std::cout << "SEGMENTS " << segments << std::endl;
    std::cout << "TRIANGLES " << triangles << std::endl;
    std::cout << "REFUSES " << refuses << std::endl;

    return 0;
}*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    if (!(cin >> N)) return 0;

    int points = 0;
    int segments = 0;
    int triangles = 0;
    int refuses = 0;

    for (int i = 0; i < N; i++)
    {
        string type;
        int s;

        cin >> type >> s;

        if (type == "POINTS")
        {
            points += s;
            cout << "POINTS " << s << " " << s << " POINTS 0" << endl;
        }
        else if (type == "LINES")
        {
            int nombre = s / 2;
            int reste = s % 2;

            segments += nombre;
            cout << "LINES " << s << " " << nombre << " SEGMENTS " << reste << endl;
        }
        else if (type == "LINE_STRIP")
        {
            int nombre,reste;
           
            if(s>=2){
                nombre = s-1;
                reste = 0;
            }else {
                nombre =0;
                reste = s;
            }
            
            segments += nombre;
            cout << "LINE_STRIP " << s << " " << nombre << " SEGMENTS " << reste << endl;
        }
        else if (type == "TRIANGLES")
        {
            
            int nombre = s / 3;
            int reste = s % 3;

            triangles += nombre;
            cout << "TRIANGLES " << s << " " << nombre << " TRIANGLES " << reste << endl;
        }
        else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN")
        {
            int nombre, reste;
            if (s >= 3)
            {
                nombre = s - 2;
                reste = 0;
            }
            else
            {
                nombre = 0;
                reste = s;
            }
            
            triangles += nombre;
            cout << type << " " << s << " " << nombre << " TRIANGLES " << reste << endl;
        }
        else
        {
            refuses++;
            cout << type << " " << s << " REFUSE" << endl;
        }
    }

    cout << "POINTS " << points << endl;
    cout << "SEGMENTS " << segments << endl;
    cout << "TRIANGLES " << triangles << endl;
    cout << "REFUSES " << refuses << endl;

    return 0;
}
            