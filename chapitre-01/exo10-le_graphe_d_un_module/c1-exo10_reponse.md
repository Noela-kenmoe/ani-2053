 # il faut construire 15 projets avant de construire NKCanvas

 # le graphe est le suivant :
 ```
                                      ┌─────────────┐
                                      │   NKCanvas  │
                                      └──────┬──────┘
                                             │
        ┌──────────────┬──────────────┬──────┼──────┬──────────────┐
        │              │              │      │      │              │
        ▼              ▼              ▼      ▼      ▼              ▼
 NKContainers       NKEvent       NKImage  NKWindow NKStream  NKFileSystem
        │              │              │      │      │              │
        │              │              │      │      │              │
        ├──────┐       │              │      │      ├──────┐       │
        │      │       │              │      │      │      │       │
        ▼      ▼       ▼              ▼      ▼      ▼      ▼       ▼
     NKCore NKMemory NKLogger      NKMath NKTime NKThreading
        │      │       │              │      │
        └──────┴───────┴──────────────┴──────┘
                       │
                       ▼
                  NKPlatform
```

``` 
 NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  10. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  11. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  13. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  14. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow)




                                          +--------+
                                          |NKCore  |
                                          +--------+
                                          |
                         +------------+   |
                  +------|NKContainers|---+----------+
                  |      +------------+   |NKMemory  |
                  |                       +----------+
                  |
                  |     +------------+
                  +-----|NKcore
                  |     +--------
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
+-----------+     |
| NKCanvas  |-----+
+-----------+     |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |
                  |