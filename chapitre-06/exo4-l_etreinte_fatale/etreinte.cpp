#include <iostream>
#include "NKWindow/NKMain.h"
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKTime/NkChrono.h>
#include "NKThreading/NkThreadingApi.h"
#include "NKThreading/NkThread.h"

nkentseu::threading::NkMutex m1, m2;
/*void FonctionFilA(){
    nkentseu::threading::NkScopedLock lock1(m1);
    nkentseu::NkChrono::SleepMilliseconds(100);
    nkentseu::threading::NkScopedLock lock2(m2);
}
void FonctionFilB(){
    nkentseu::threading::NkScopedLock lock2(m2);
    nkentseu::NkChrono::SleepMilliseconds(100);
    nkentseu::threading::NkScopedLock lock1(m1);
}*/
/* version corrigé
nkentseu::threading::NkMutex m1, m2;
void FonctionFilA(void* userData){
    nkentseu::NkScopedLock lock1(m1);
    nkentseu::NkChrono::SleepMilliseconds(100);
    nkentseu::NkScopedLock lock2(m2);
}
void FonctionFilsB(void* userData){
    nkentseu::NkScopedLock lock1(m1);
    nkentseu::NkChrono::SleepMilliseconds(100);
    nkentseu::NkScopedLock lock2(m2);   
}*/

int nkmain(const nkentseu::NkEntryState &state){
    nkentseu::threading::NkThread filsa([&](auto&&...){
        nkentseu::threading::NkScopedLock lock1(m1);
        nkentseu::NkChrono::SleepMilliseconds(100);
        nkentseu::threading::NkScopedLock lock2(m2);
    });
    nkentseu::threading::NkThread filsb([&](auto&&...){
        nkentseu::threading::NkScopedLock lock2(m2);
        nkentseu::NkChrono::SleepMilliseconds(100);
        nkentseu::threading::NkScopedLock lock1(m1);
    });
    filsa.Join();
    filsb.Join();
    std::cout<<"Executionterminée sans blocage."<<std::endl;
    return 0;
}