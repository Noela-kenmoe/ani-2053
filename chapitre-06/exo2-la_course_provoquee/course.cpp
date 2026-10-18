#include "NKWindow/NKMain.h"
#include "NKThreading/NkThreadingApi.h"
#include "NKThreading/NkThreadPool.h"
#include "NKLogger/Sinks/NkAsyncSink.h"
#include <iostream>
#include <vector>

long long compteur = 0;
    /*void IncrementTask() {
    for (int i = 0; i < 1000000; ++i) {
        compteur += 1; 
    }
}*/



int nkmain(const nkentseu::NkEntryState &state) {
    //CountExécutor execute;
    
    //threads.reserve(8);
    compteur = 0;
    /*for (int i = 0; i < 8; ++i) {*/
        //threads.emplace_back(new nkentseu::threading::NkThread(nkentseu::NkFunction<void(), CounterTask>(&execute, &CounterTask::IncrementTask)));
        /*threads[i] = new nkentseu::threading::NkThread([&](auto&&...){*/
        nkentseu::threading::NkThread* t = new nkentseu::threading::NkThread([&](auto&&...){;
            for (int i = 0; i < 1000000; ++i) {
             compteur += 1; 
            }
        } );
    //}

    /*for (int i=0; i<8; i++) {
        threads[i]->Join();
        delete threads[i];
        
    }*/
        t->Join();
        delete t;   

    std::cout << "Total attendu : 8000000" << std::endl;
    std::cout << "Total obtenu  : " << compteur << std::endl;

    return 0;
}
