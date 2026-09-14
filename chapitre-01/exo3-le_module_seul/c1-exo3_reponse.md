## ARCHITECTURE DE NKMath
-------------------------
```cpp
                    ┌─────────────┐
                    │   NKMath    │
                    └──────┬──────┘
                           │
             ┌─────────────┼──────────────┐
             │             │              │
             ▼             ▼              ▼
       ┌──────────┐   ┌──────────┐  ┌───────────┐
       │NKMemory  │   │  NKCore  │  │NKPlatform │
       └────┬─────┘   └────┬─────┘  └───────────┘
            │              │
            └──────┬───────┘
                   │
                   ▼
             ┌──────────┐
             │  NKCore  │
             └────┬─────┘
                  │
                  ▼
          ┌─────────────┐
          |   NKPlatform|
          |_____________|
                      
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)
  ```


                   
