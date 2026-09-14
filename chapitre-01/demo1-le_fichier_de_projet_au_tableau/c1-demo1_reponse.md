# Analyse de la Spécification de Build NKMath.jenga
# 1. Code Source Réel
module "NKMath" {
    kind            = "StaticLib"
    language        = "C++20"
    cpp_dialect     = "c++20"

    include_dirs {
        public      = ["include"]
        private     = ["src"]
    }

    defines {
        public      = ["NK_MATH_STATIC"]
        private     = ["NK_MATH_BUILD_INTERNAL"]
    }

    files {
        "include/NKMath/**.h",
        "include/NKMath/**.inl",
        "src/**.cpp"
    }

    filter "system:windows" {
        defines    += ["NK_PLATFORM_WINDOWS"]
        files      += ["src/platform/win32/**.cpp"]
    }

    filter "system:linux" {
        defines    += ["NK_PLATFORM_LINUX"]
        files      += ["src/platform/posix/**.cpp"]
    }

    filter "architecture:x86_64" {
        flags      += ["VectorAVX2"]
        files      += ["src/simd/x86/**.cpp"]
    }

    filter "architecture:arm64" {
        flags      += ["VectorNEON"]
        files      += ["src/simd/arm/**.cpp"]
    }

    filter "config:Debug" {
        symbols     = true
        optimize    = "Off"
        defines    += ["NK_DEBUG"]
    }

    filter "config:Release" {
        symbols     = false
        optimize    = "Speed"
        defines    += ["NK_RELEASE", "NK_FAST_MATH"]
    }

    dependencies {
        public      = ["NKCore"]
    }
}


# 2. Synthèse d'Analyse
Ce qu'il déclare
Le fichier identifie le module sous le nom NKMath en standard C++20. Il régit la portée des répertoires d'inclusion en rendant le dossier include public pour les modules dépendants et le dossier src strictement privé. Il isole les macros de préprocesseur en propageant NK_MATH_STATIC à l'extérieur tout en gardant NK_MATH_BUILD_INTERNAL en interne. Enfin, il rassemble l'ensemble des fichiers d'en-têtes, des définitions inline et des sources C++ du module via des motifs de recherche.
Ce qu'il filtre
Les blocs de filtres appliquent une compilation conditionnelle selon l'environnement cible. Les fichiers de plateforme bas niveau sont inclus spécifiquement pour Windows ou Linux. Les jeux d'instructions vectorielles SIMD sont sélectionnés selon l'architecture matérielle hôte, avec l'activation d'AVX2 sur x86_64 ou de NEON sur ARM64. Les configurations de compilation adaptent la génération des symboles de débogage et le niveau d'optimisation du code.
Ce qu'il délègue
Le fichier délègue la gestion des dépendances en déclarant NKCore comme dépendance publique, confiant au moteur de build la tâche d'injecter ses en-têtes de façon transitive. Il délègue également la traduction des directives haut niveau vers les options réelles des compilateurs natifs tels que MSVC, GCC ou Clang.
# 3. Décision du Type de Bibliothèque
La nature statique du module est décidée à la ligne 2 du fichier via l'instruction kind = "StaticLib".
Cette affectation indique au générateur d'ordonner la création d'une archive statique (.lib sous Windows ou .a sous Linux). Elle garantit que le code binaire du module sera directement incorporé dans l'exécutable final lors de l'édition de liens, tout en supprimant la surcharge liée à la gestion des tables d'export dynamique de symboles.
