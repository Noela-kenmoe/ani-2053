# le contenu de mon fichier main.cpp est le suivant:
```cpp
#include <iostream>

int main () {
    std::cout<<"Hello wordl";
    return 0 ;
}
```
# le contenu de mon fichier .jenga est le suivant :
```cpp
from Jenga import *
from jengaconfig import *

with project("MonEssai") :
  staticlib()
  language("C++")
  cppdialect("C++17")
  location(".")
  files(["main.cpp"])
  includedirs(["include"])
  

with project("App") :
 consoleapp()
 language("C++")
 cppdialect("C++17")
 location(".")
 files(["./**.cpp"])
 includedirs(["include"])
 dependson(["MonEssai"])
 links(["MonEssai"])
                 
with filter("system :Windows") :
  usetoolchain("clang-mingw")
```
# la ligne d'inclusion dans le workspace est la suivante :
```cpp
with include("Applications/MonEssai/MonEssai.jenga"):
    
            pass
```
# le resultat de jenga info est le suivant :
```cpp
Projects
------------------------------------------------------------
Name                         Kind          Language   Test   External
=====================================================================
__Unitest__                  StaticLib     C++        No     No
NKPlatform                   StaticLib     C++        No     Yes
NKPlatform_Tests             TestSuite     C++        Yes    Yes
NKCore_Tests                 TestSuite     C++        Yes    Yes
NKCore                       StaticLib     C++        No     Yes
NKLogger                     StaticLib     C++        No     Yes
NKLogger_Tests               TestSuite     C++        Yes    Yes
NKMath                       StaticLib     C++        No     Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKMemory                     StaticLib     C++        No     Yes
NKContainers                 StaticLib     C++        No     Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKFont                       StaticLib     C++        No     Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKAudio                      StaticLib     C++        No     Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKTime                       StaticLib     C++        No     Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKThreading                  StaticLib     C++        No     Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKNetwork                    StaticLib     C++        No     Yes
NKSerialization              StaticLib     C++        No     Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent                      StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKCanvas                     StaticLib     C++        No     Yes
NKRHI                        StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKUI                         StaticLib     C++        No     Yes
MonEssai                     StaticLib     C++        No     Yes
App                          ConsoleApp    C++        No     Yes
```
# le resultat obtenu après avoir construit mon projet est le suivant
```


╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (2 projects):
  1. MonEssai [STATIC_LIB] → 
  2. App [CONSOLE_APP] (depends: MonEssai)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\MonEssai\MonEssai.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: App                                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\App\App.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  2/2
Time:           0.77s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
