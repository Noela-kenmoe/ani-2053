#include <iostream>

namespace module_a {
    struct  NkExemple {
        int id = 1;
    };    
}

namespace module_b {
    struct NkExemple
    {
        int id =2;
    };
    
}

using namespace module_a;
using namespace module_b;
int main(){
    //erreur potentielle
    //NkExemple obj;
    //correction par qualifaication explicite des espaces de noms
    module_a::NkExemple obj1;
    module_b::NkExemple obj2;
    std::cout<<"Objet A ID :" << obj1.id <<std::endl;
    std::cout<<"Objet B ID :"<< obj2.id <<std::endl;

    return 0;
}