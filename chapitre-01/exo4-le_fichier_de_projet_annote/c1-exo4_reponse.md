

```

from Jenga import * # par ce que jenga est un programme python et que tout ce qui s'y trouve est en python
from jengaconfig import *                                    # noqa: F401,F403
import shutil
import subprocess


def HasLibdecor() -> bool:
    """True si libdecor-0 est disponible (pkg-config) — decorations Wayland."""
    if not shutil.which("pkg-config"):
        return False
    try:
        return subprocess.call(
            ["pkg-config", "--exists", "libdecor-0"],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
        ) == 0
    except Exception:
        return False


WAYLAND_LINKS      = ["pthread", "wayland-client", "wayland-egl", "xkbcommon", "wayland-cursor", "EGL", "GLESv2"]
WAYLAND_TEST_LINKS = ["pthread", "wayland-client", "wayland-egl", "xkbcommon", "EGL", "GLESv2"]
WAYLAND_DEFINES    = ["NKENTSEU_FORCE_WINDOWING_WAYLAND_ONLY"]
if HasLibdecor():
    WAYLAND_LINKS.append("decor-0")
    WAYLAND_TEST_LINKS.append("decor-0")
    WAYLAND_DEFINES.append("NKENTSEU_WAYLAND_LIBDECOR")
```
````cpp
from Jenga import * #par ce que jenga est un programme python et que tout ce qui s'y trouve est en python
from jengaconfig import *
from Jenga.Core.Api import androidallowrotation
import os
import shutil
import subprocess


# Vulkan n'est defini QUE la ou il est cable (Windows / Android). Ailleurs il
# reste a 0, sinon le lien casse sur des symboles absents de ces builds.
_VK_ON  = f"NKENTSEU_ENABLE_VULKAN_BACKEND={1 if WANT_VULKAN else 0}"
_VK_OFF = "NKENTSEU_ENABLE_VULKAN_BACKEND=0"


with project("ConquerorLab"): //il s'agit de la déclaration d'un projet nommé ConquerurLab
    windowedapp() //ce projet est de type windowedApp c'est a dire un programme avec une fenetre sans console
    language("C++") // il utilise le langafe c++
    cppdialect("C++17")
    location(".") //indique dans quel dossier le projet vit

    #L'application + les deux modules de reference compiles a l'interieur.
    files([
        "src/**.cpp",
        "modules/rules/**.cpp",
        "modules/ai/**.cpp",
    ]) /*il donne les sources c'est a dire les dossiers, sous dossiers etc...*/

    
    nkentseudependson(
        ["NKEditorKit", "NKGui", "NKCanvas", "NKImage", "NKFont", "NKGlad",
         "NKWindow", "NKEvent", "NKReflection", "NKSerialization",
         "NKFileSystem", "NKThreading",
         "NKStream", "NKLogger", "NKMath", "NKTime",
         "NKContainers", "NKMemory", "NKCore", "NKPlatform"], // permet de citer les dépendances
        extra_includes=["include", "src", "src/ConquerorLab",
                        "%{NKGlad.location}/include"]
                       + ([VULKAN_INCLUDE] if VULKAN_INCLUDE else []),// permet d'indiquer ou se trouve les fichiers .h, .hpp et permet d'ajouter VULKAN_INCLUDE s'il existe
        # Les modules de reference deviennent des fabriques INTERNES
        # (NkcRulesV2GetFactory / NkcAIRefGetFactory) au lieu de symboles
        # exportes de DLL.
        extra_defines=["NKC_RULES_STATIC=1", "NKC_AI_STATIC=1"],// permet de définir les macros du procrsseur
    )

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}") //il indique le dossier du workplace, le nom du projet courant, debyg ou release, le systeme cible

    apppublisher("Rihen Universe")
    appversion("0.1.0")
    licensefile("../../LICENSE")

    # ===== Windows ============================================================
    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"): // permet d'appliquer les lignes suivantes uniquements pour windows
        windowedapp() // le type du projet
        usetoolchain(TC_WINDOWS) //utilise la toolchain Windows pour compiler le projet
        defines(["WIN32_LEAN_AND_MEAN", "_UNICODE", "UNICODE", _VK_ON]) // permet de définir les macros de compilation
        if VULKAN_LIB: // vérifie si la valeur de VULKAN_LIB est définie ou vrai
            libdirs([VULKAN_LIB]) // ajoute le chemin contenu dans VULKAN_LIB
        _WIN_LINKS = [
            "user32", "gdi32", "opengl32", "dwmapi", "shell32",
            "uuid", "ole32", "dinput8", "dxguid",
            "d3d11", "d3d12", "dxgi", "d3dcompiler",
        ] // lz mon des bibliothèque système a lié
        if WANT_VULKAN: //vérifie si l'option ou la condition WANT_VULKAN est active
            _WIN_LINKS.append("vulkan-1") ?
        links(_WIN_LINKS)

    # ===== Linux XLib (defaut) ================================================
    with filter("system:Linux && options:linux-backend=xlib || system:Linux && !options:linux-backend && !options:headless"): // applique les configuration suivantes uniquement sous linux avec le backend X11/LIB et sans le mode headless
        windowedapp()
        usetoolchain("clang-native") // défini la chaine d'outils de compilation
        defines(["NKENTSEU_FORCE_WINDOWING_XLIB_ONLY", _VK_ON]) //ajoute les préprocesseurs/macros et la valeur de _VK_ON
        # -ldl : l'hote de modules charge les .so des stagiaires (dlopen/dlsym). 
        links(["pthread", "dl", "X11", "Xext", "Xrandr", "GL"]
              + (["vulkan"] if WANT_VULKAN else []))

    # ===== Linux XCB ==========================================================
    with filter("system:Linux && options:linux-backend=xcb"): // applique la configuaration uniquement si le système cible est linux
        windowedapp()
        usetoolchain("clang-native")
        defines(["NKENTSEU_FORCE_WINDOWING_XCB_ONLY", _VK_ON])
        links(["pthread", "dl", "xcb", "xcb-image", "xcb-icccm", // declaration des bibliothèques du système"xcb-randr",
               "xcb-xfixes", "X11", "X11-xcb", "Xext", "xkbcommon",
               "xkbcommon-x11", "GL"]
              + (["vulkan"] if WANT_VULKAN else [])) // concatène dynamiquement la bibliothèque 
        ldflags(["-fuse-ld=lld"]) // passe cette option au compilateur pour utiliser l'éditeur de liens le plus rapide

    # ===== macOS ==============================================================
    with filter("system:macOS"): // FILTRE l'application des instructions suivantes uniquements si l'OS cible est linux et que l'option de backend choisi est XCB
        windowedapp()
        usetoolchain("clang-native")
        defines([_VK_OFF])
        frameworks(["Cocoa", "QuartzCore", "OpenGL"])

    # ===== Android ============================================================
    # Pas de compilateur sur l'appareil : SEULS les modules internes existent.
    # L'atelier reste pleinement jouable et mesurable ; seul le rechargement a
    # chaud disparait (cf. NkcModuleCompiler.h).
    with filter("system:Android"): // uniquement pour les système 
        windowedapp()
        usetoolchain("android-ndk")
        androidapplicationid("com.nkentseu.conquerorlab") // définie l'identifiant unique de l'application 
        androidisgame(True) // déclare l'application comme étant un jeu
        androidminsdk(24)
        androidtargetsdk(34)
        androidcompilesdk(34)
        androidabis(["armeabi-v7a", "arm64-v8a", "x86", "x86_64"]) ?
        androidnativeactivity(True)
        androidscreenorientation("landscape")
        androidallowrotation(False)
        androidstl("c++_shared")
        defines([_VK_ON])
        _ANDROID_LINKS = ["android", "log", "EGL", "GLESv3", "dl"] ?
        if WANT_VULKAN:
            _ANDROID_LINKS.append("vulkan")
        links(_ANDROID_LINKS)

    
    with filter("system:Web"):
        consoleapp()
        usetoolchain("emscripten")
        defines(["NKENTSEU_ENABLE_EMSCRIPTEN", _VK_OFF])
        emscriptencanvasid("canvas")
        emscripteninitialmemory(64)
        emscriptenextraflags([
            "-s", "ASYNCIFY",
            "-s", "ALLOW_MEMORY_GROWTH=1",
            "-s", "FULL_ES3=1",
            "-s", "USE_WEBGL2=1",
            "-s", "NO_EXIT_RUNTIME=1",
            "-s", "PTHREAD_POOL_SIZE=4",
        ]) // déclaration des arguments et drapeaux spécifiques passés au compilateur Emscripten 

    with filter("config:Debug"): // uniquement les configurations debug
        defines(["_DEBUG", "DEBUG"]) // définit les macros de préprocesseur 
        optimize("Off") // désactive toutes les optimisations du compilateur 
        symbols(True) // active la génération des symboles de débogages

    with filter("config:Release"): // applique la configuration release
        defines(["NDEBUG"]) /* définit les macros de preéprocesseur*/
        optimize("Speed") ?
        symbols(False) // désactive la génération des symboles de débogage pour réduire la taille des fichiers binaires finaux
        ```