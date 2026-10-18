#include "NKWindow/NKMain.h"
#include "NKThreading/NkThreadingApi.h"
#include "NKThreading/NkThreadPool.h"
#include "NKLogger/Sinks/NkAsyncSink.h"
#include <iostream>
#include <vector>

long long compteur = 0;


int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::threading::NkThread* threads[8];
    compteur = 0;
    for (int i = 0; i < 8; ++i) {
        
        threads[i] = new nkentseu::threading::NkThread([&](auto&&...){
            for (int i = 0; i < 1000000; ++i) {
             compteur += 1; 
            }
        } );
    }

    for (int i=0; i<8; i++) {
        threads[i]->Join();
        delete threads[i];
        
    }

    std::cout << "Total attendu : 8000000" << std::endl;
    std::cout << "Total obtenu  : " << compteur << std::endl;

    return 0;
}
