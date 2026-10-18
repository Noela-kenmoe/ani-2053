/*#include "NKWindow/NKMain.h"
#include "NKThreading/NkThreadingApi.h"
#include "NKThreading/NkThreadPool.h"
#include "NKLogger/Sinks/NkAsyncSink.h"
#include <iostream>
#include <vector>


int nkmain(const nkentseu::NkEntryState &state) {
    long long compteur = 0;
    nkentseu::NkChrono chrono;
    chrono.BeginPreciseTiming();
    std::vector<nkentseu::threading::NkThread*> threads(kNumThreads);
    for(int i= 0; i< kNumThreads; i++){
         threads[i] = new nkentseu::threading::NkThread([&](auto&&...){
            for (int i = 0; i < 1000000; ++i) {
             compteur += 1; 
            }
         });
    }
    for(int i=0; i< kNumThreads; ++i){
         threads[i]->Join();
         delete threads[i];
    }
    double tempsMs = chrono.GetElapsedMilliseconds();
    std::cout<<"Sans protection -> Total : "<< compteur << "| Temps :"<<tempsMs<<" ms"<<std::endl;
    }
}*/

#include <iostream>
#include <vector>
#include "NKWindow/NKMain.h"
#include "NKThreading/NkThreadingApi.h"
#include "NKThreading/NkThreadPool.h"
#include "NKLogger/Sinks/NkAsyncSink.h"
#include <NKThreading/NkMutex.h>
#include "NKTime/NkTime.h"  
#include <NKThreading/NkScopedLock.h>
#include <NKCore/NkAtomic.h>
#include <NKTime/NkChrono.h>

constexpr int kNumThreads = 8;
constexpr int kIterations = 1000000;

int nkmain(const nkentseu::NkEntryState &state){
    
    {
        long long g_compteur = 0;
        nkentseu::NkChrono chrono;
        chrono.BeginPreciseTiming();

        std::vector<nkentseu::threading::NkThread*> threads(kNumThreads);
        for (int i = 0; i < kNumThreads; ++i) {
            threads[i] = new nkentseu::threading::NkThread([&](auto&&...) {
                for (int j = 0; j < kIterations; ++j) {
                    g_compteur += 1;
                }
            });
        }

        for (int i = 0; i < kNumThreads; ++i) {
            threads[i]->Join();
            delete threads[i];
        }

        double  tempsMs = chrono.Elapsed().milliseconds;
        std::cout << "Sans protection -> Total : " << g_compteur << " | Temps : " << tempsMs << " ms" << std::endl;
    }

    {
        long long g_compteur = 0;
        nkentseu::threading::NkMutex g_mutex;
        nkentseu::NkChrono chrono;
        chrono.BeginPreciseTiming();

        std::vector<nkentseu::threading::NkThread*> threads(kNumThreads);
        for (int i = 0; i < kNumThreads; ++i) {
            threads[i] = new nkentseu::threading::NkThread([&](auto&&...) {
                for (int j = 0; j < kIterations; ++j) {
                    nkentseu::threading::NkScopedLock<nkentseu::threading::NkMutex> lock(g_mutex);
                    g_compteur += 1;
                }
            });
        }

        for (int i = 0; i < kNumThreads; ++i) {
            threads[i]->Join();
            delete threads[i];
        }

        double tempsMs = chrono.Elapsed().milliseconds;
        std::cout << "Mutex -> Total : " << g_compteur << " | Temps : " << tempsMs << " ms" << std::endl;
    }
    {
        nkentseu::NkAtomicInt g_compteur_atomique(0);
        nkentseu::NkChrono chrono;
        chrono.BeginPreciseTiming();

        std::vector<nkentseu::threading::NkThread*> threads(kNumThreads);
        for (int i = 0; i < kNumThreads; ++i) {
            threads[i] = new nkentseu::threading::NkThread([&](auto&&...) {
                for (int j = 0; j < kIterations; ++j) {
                    g_compteur_atomique.FetchAdd(1);
                }
            });
        }

        for (int i = 0; i < kNumThreads; ++i) {
            threads[i]->Join();
            delete threads[i];
        }

        double tempsMs = chrono.Elapsed().milliseconds;
        std::cout << "Atomique -> Total : " << g_compteur_atomique.Load() << " | Temps : " << tempsMs << " ms" << std::endl;
    }

    {
        long long totaux_locaux[kNumThreads] = {0};
        nkentseu::NkChrono chrono;
        chrono.BeginPreciseTiming();

        std::vector<nkentseu::threading::NkThread*> threads(kNumThreads);
        for (int i = 0; i < kNumThreads; ++i) {
            threads[i] = new nkentseu::threading::NkThread([i, &totaux_locaux](auto&&...) {
                long long local_val = 0;
                for (int j = 0; j < kIterations; ++j) {
                    local_val += 1;
                }
                totaux_locaux[i] = local_val;
            });
        }

        for (int i = 0; i < kNumThreads; ++i) {
            threads[i]->Join();
            delete threads[i];
        }

        long long total_global = 0;
        for (int i = 0; i < kNumThreads; ++i) {
            total_global += totaux_locaux[i];
        }

        double tempsMs = chrono.Elapsed().milliseconds;
        std::cout << "Local -> Total : " << total_global << " | Temps : " << tempsMs << " ms" << std::endl;
    }

    return 0;
}
