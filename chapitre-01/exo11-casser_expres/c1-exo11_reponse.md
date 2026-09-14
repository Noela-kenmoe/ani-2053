# le temps que met la construction pour s'arreté est : 56.39s
# les projets qui ont été crés sont :
|PROJET| 
|------|
|NKMemory|
|NKCore|
|NKContainers|
|NKPlatform|

# la commande utilisee est  :
```
jenga build --target NKMath
```
# le resultat de la compilation me montre que jenga commence par compiler le projet qui a le moins de dépendances et finit par celui qui a le plus de dépendances de plus pour un projet ciblé seules les dépendances directes et indirectes sont construites , les projets complètement indépendants sont ignorés,
# entre deux projets indépendants : il n'existe aucun ordre logique imposé l'outil choisi l'ordre selon les critères secondaires (ordre de déclaration, ordre alphabétique) ou les exécutables en parrallèle



```cpp
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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkCPUFeatures.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkTraits.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.89s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkFunction.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
✓   [3/14] Compiled: NkGc.cpp
✓   [4/14] Compiled: NkFunctionSIMD.cpp
✓   [5/14] Compiled: NkGlobalOperators.cpp
✓   [6/14] Compiled: NkHash.cpp
✓   [7/14] Compiled: NkMemory.cpp
✓   [8/14] Compiled: NkMultiLevelAllocator.cpp
✓   [9/14] Compiled: NkProfiler.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkTag.cpp
✓   [12/14] Compiled: NkTracker.cpp
✓   [13/14] Compiled: NkAllocator.cpp
✓   [14/14] Compiled: NkUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkBinaryTree.cpp
✓   [3/43] Compiled: NkHashMap.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkPriorityQueue.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkTrie.cpp
✓   [8/43] Compiled: NkUnorderedMap.cpp
✓   [9/43] Compiled: NkUnorderedSet.cpp
✓   [10/43] Compiled: NkArray.cpp
✓   [11/43] Compiled: NkPool.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkFunction.cpp
✓   [14/43] Compiled: NkBind.cpp
✓   [15/43] Compiled: NkFunctional.cpp
✓   [16/43] Compiled: NkTuple.cpp
✓   [17/43] Compiled: NkPair.cpp
✓   [18/43] Compiled: NkInitializerList.cpp
✓   [19/43] Compiled: NkIterator.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDeque.cpp
✓   [22/43] Compiled: NkDoubleList.cpp
✓   [23/43] Compiled: NkList.cpp
✓   [24/43] Compiled: NkVector.cpp
✓   [25/43] Compiled: NkGraph.cpp
✓   [26/43] Compiled: NkQuadTree.cpp
✓   [27/43] Compiled: NkASCII.cpp
✓   [28/43] Compiled: NkEncoding.cpp
✓   [29/43] Compiled: NkBase64.cpp
✓   [30/43] Compiled: NkUTF16.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkString.cpp
✓   [36/43] Compiled: NkStringBuilder.cpp
✓   [37/43] Compiled: NkStringHash.cpp
✓   [38/43] Compiled: NkOptional.cpp
✓   [39/43] Compiled: NkStringUtils.cpp
✓   [40/43] Compiled: NkStringView.cpp
✓   [41/43] Compiled: NkResult.cpp
✓   [42/43] Compiled: NkVariant.cpp
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 15.99s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkEulerAngle.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: NkColor.cpp                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\NOELA\Desktop\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp:136:12:      ║
║ error: expected ';' after expression                                                         ║
║   136 |                                         cr = v                                       ║
║       |                                               ^                                      ║
║       |                                               ;                                      ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\NOELA\Desktop\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
✓   [4/12] Compiled: NkFunctions.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRandom.cpp
✓   [8/12] Compiled: NkRange.cpp
✓   [9/12] Compiled: NkRectangle.cpp
✓   [10/12] Compiled: NkSIMD.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                Time: 20.34s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/5
Failed:         1
Errors:         2
Time:           56.39s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMath
```
# le temps mis pour la construction de NKMath est : 20.34s
# la remise en état du fichier est : 
```cpp
          switch (i % 6) {
				case 0:
					cr = v;
					cg = t;
					cb = p;
					break;
				case 1:
					cr = q;
					cg = v;
					cb = p;
					break;
				case 2:
					cr = p;
					cg = v;
					cb = t;
					break;
				case 3:
					cr = p;
					cg = q;
					cb = v;
					break;
				case 4:
					cr = t;
					cg = p;
					cb = v;
					break;
				case 5:
					cr = v;
					cg = p;
					cb = q;
					break;
			}

```