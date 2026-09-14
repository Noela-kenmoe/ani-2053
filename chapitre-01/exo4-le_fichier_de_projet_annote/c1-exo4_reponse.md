
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
wayland.jenga — Config partagee : backend de fenetrage Wayland (Linux)
======================================================================
Liens + defines Wayland (avec detection optionnelle de libdecor pour les
decorations cote client). Chargee via useconfig("config/wayland.jenga") ->
WAYLAND_LINKS / WAYLAND_TEST_LINKS / WAYLAND_DEFINES se propagent aux .jenga qui
ciblent Wayland (Sandbox, NKWindow...). Convention : PascalCase fonctions,
UPPER_SNAKE constantes.
"""
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

    # NKSerialization n'est PAS utilise par l'atelier lui-meme : il est ici parce
    # que l'atelier le PROMET au stagiaire. Trois listes le reclamaient deja —
    # `NkcModuleCompiler::StackLibs` (le `-lNKSerialization` du lien), le `$libs`
    # de Distribuer.ps1, et le `-I` de NkcLayout::Includes — mais celle-ci, la
    # SEULE qui construise quoi que ce soit, l'avait oublie. Consequence mesuree
    # le 2026-08-15 : `NKSerialization.lib` n'existait pas, donc
    #   - Distribuer.ps1 s'arretait sur « Bibliotheque introuvable »,
    #   - et tout module de stagiaire echouait au lien sur « cannot find
    #     -lNKSerialization », y compris l'exemple livre.
    nkentseudependson(
        ["NKEditorKit", "NKGui", "NKCanvas", "NKImage", "NKFont", "NKGlad",
         "NKWindow", "NKEvent", "NKReflection", "NKSerialization",
         "NKFileSystem", "NKThreading",
         "NKStream", "NKLogger", "NKMath", "NKTime",
         "NKContainers", "NKMemory", "NKCore", "NKPlatform"],
        extra_includes=["include", "src", "src/ConquerorLab",
                        "%{NKGlad.location}/include"]
                       + ([VULKAN_INCLUDE] if VULKAN_INCLUDE else []),
        # Les modules de reference deviennent des fabriques INTERNES
        # (NkcRulesV2GetFactory / NkcAIRefGetFactory) au lieu de symboles
        # exportes de DLL.
        extra_defines=["NKC_RULES_STATIC=1", "NKC_AI_STATIC=1"],
    )

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}") //il indique le dossier du workplace, le nom du projet courant, debyg ou release, le systeme cible

    apppublisher("Rihen Universe")
    appversion("0.1.0")
    licensefile("../../LICENSE")

    # ===== Windows ============================================================
    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        windowedapp()
        usetoolchain(TC_WINDOWS)
        defines(["WIN32_LEAN_AND_MEAN", "_UNICODE", "UNICODE", _VK_ON])
        if VULKAN_LIB:
            libdirs([VULKAN_LIB])
        _WIN_LINKS = [
            "user32", "gdi32", "opengl32", "dwmapi", "shell32",
            "uuid", "ole32", "dinput8", "dxguid",
            "d3d11", "d3d12", "dxgi", "d3dcompiler",
        ]
        if WANT_VULKAN:
            _WIN_LINKS.append("vulkan-1")
        links(_WIN_LINKS)

    # ===== Linux XLib (defaut) ================================================
    with filter("system:Linux && options:linux-backend=xlib || system:Linux && !options:linux-backend && !options:headless"):
        windowedapp()
        usetoolchain("clang-native")
        defines(["NKENTSEU_FORCE_WINDOWING_XLIB_ONLY", _VK_ON])
        # -ldl : l'hote de modules charge les .so des stagiaires (dlopen/dlsym).
        links(["pthread", "dl", "X11", "Xext", "Xrandr", "GL"]
              + (["vulkan"] if WANT_VULKAN else []))

    # ===== Linux XCB ==========================================================
    with filter("system:Linux && options:linux-backend=xcb"):
        windowedapp()
        usetoolchain("clang-native")
        defines(["NKENTSEU_FORCE_WINDOWING_XCB_ONLY", _VK_ON])
        links(["pthread", "dl", "xcb", "xcb-image", "xcb-icccm", "xcb-randr",
               "xcb-xfixes", "X11", "X11-xcb", "Xext", "xkbcommon",
               "xkbcommon-x11", "GL"]
              + (["vulkan"] if WANT_VULKAN else []))
        ldflags(["-fuse-ld=lld"])

    # ===== macOS ==============================================================
    with filter("system:macOS"):
        windowedapp()
        usetoolchain("clang-native")
        defines([_VK_OFF])
        frameworks(["Cocoa", "QuartzCore", "OpenGL"])

    # ===== Android ============================================================
    # Pas de compilateur sur l'appareil : SEULS les modules internes existent.
    # L'atelier reste pleinement jouable et mesurable ; seul le rechargement a
    # chaud disparait (cf. NkcModuleCompiler.h).
    with filter("system:Android"):
        windowedapp()
        usetoolchain("android-ndk")
        androidapplicationid("com.nkentseu.conquerorlab")
        androidisgame(True)
        androidminsdk(24)
        androidtargetsdk(34)
        androidcompilesdk(34)
        androidabis(["armeabi-v7a", "arm64-v8a", "x86", "x86_64"])
        androidnativeactivity(True)
        androidscreenorientation("landscape")
        androidallowrotation(False)
        androidstl("c++_shared")
        defines([_VK_ON])
        _ANDROID_LINKS = ["android", "log", "EGL", "GLESv3", "dl"]
        if WANT_VULKAN:
            _ANDROID_LINKS.append("vulkan")
        links(_ANDROID_LINKS)

    # ===== Web ================================================================
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
        ])

    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG"])
        optimize("Off")
        symbols(True)

    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)