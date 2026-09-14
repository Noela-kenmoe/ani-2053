# Fiche de Référence Architecturale Nkentseu

## 1. Les 5 Couches de l'Architecture

L'architecture du projet est strictement hiérarchisée en cinq couches principales, complétées par le socle plateforme :

| Niveau | Couche | Composants principaux | Rôle & Responsabilités |
| --- | --- | --- | --- |
| **Couche 1** | **Applications cibles** | `Noge` (Éditeur), `PV3DE` (Patient Virtuel) | Applications finales exécutables ; totalement indépendantes l'une de l'autre.

 |
| **Couche 2** | **Framework Application** | `Nkentseu/Core`, `NKScene` | Gestion du cycle de vie (`Application`), boucle principale, `LayerStack`, `EventBus`, système ECS.

 |
| **Couche 3** | **Services Moteur** | `NKFont`, `NKImage`, `NKAudio`, `NKPhysics`, `NKAnimation`, `NKScript`, `NKUI`, `NKRenderer` | Sous-systèmes fonctionnels pour la physique, le rendu, l'interface utilisateur, l'audio et l'animation.

 |
| **Couche 4** | **Abstraction GPU (NKRHI)** | `NkIDevice` (Backends: OpenGL, Vulkan, DX11/12, Metal, Software, WebGL) | Couche d'abstraction matérielle pour les commandes graphiques et les ressources GPU.

 |
| **Couche 5** | **Bibliothèques de Base** | `NKCore`, `NKMath`, `NKTime`, `NKMemory`, `NKContainers`, `NKStream`, `NKThreading`, `NKLogger` | Briques fondamentales sans dépendance externe ni STL (allocateurs, conteneurs custom, maths).

 |
| *(Socle)* | **Platforme & OS** | `NKPlatform`, `NKWindow`, `NKEvent` | Abstraction du système d'exploitation natif et gestion des fenêtres/événements.

 |

---

## 2. Les 10 Modules Principaux du Dépôt

D'après la structure des fichiers du projet, les dix modules constitutifs les plus importants du moteur et des applications sont :

1. **`NKScene`** : Système ECS (Entity Component System) gérant les entités, composants et registres de la scène.


2. **`NKRHI`** : Moteur d'abstraction GPU avec gestion des pipelines, passes de rendu et handles de textures/buffers.


3. **`NKUI`** : Moteur d'interface utilisateur incluant le Dock Manager, le Layout Stack et le rendu des widgets.


4. **`NKDiagnostic`** : Cerveau clinique de PV3DE intégrant la base de données de symptômes, de pathologies et le calcul différentiel.


5. **`NKFace`** : Contrôleur facial implémentant le système FACS (46 Action Units), la gestion des clignements et du regard.


6. **`NKPhysics`** : Moteur de physique gérant les corps rigides, les détections de collisions (AABB, OBB, sphères, capsules) et raycasts.


7. **`NKAnimation`** : Moteur d'animation squelettique, de Blend Trees et de solveurs IK.


8. **`NKContainers`** : Implémentation custom zero-STL des structures de données (`NkVector`, `NkHashMap`, `NkString`, `NkStringView`).


9. **`NKMath`** : Moteur mathématique (`NkVec2/3/4f`, `NkMat4f`, `NkQuat`, interpolations).


10. **`NKCore`** : Types primitifs (`nk_uint32`, `nk_float32`), assertions, macros d'export et gestionnaires de mémoire.



---

## 3. Flèches de Dépendance du Projet

Chaque couche consomme uniquement les fonctionnalités des couches situées en dessous d'elle. Aucune dépendance circulaire ou latérale n'est autorisée entre applications.

```
┌─────────────────────────────────────────────────────────────────────────┐
│                        APPLICATIONS CIBLES                              │
│         ┌──────────────────┐               ┌──────────────────┐         │
│         │   Noge (Éditeur) │               │   PV3DE (App)    │         │
│         └────────┬─────────┘               └────────┬─────────┘         │
└──────────────────┼──────────────────────────────────┼───────────────────┘
                   │                                  │
                   ▼                                  ▼
┌─────────────────────────────────────────────────────────────────────────┐
│                    FRAMEWORK APPLICATION & SCÈNE                        │
│     ┌─────────────────────────────────────────────────────────────┐     │
│     │   Nkentseu/Core (Application, LayerStack, EventBus)         │     │
│     │   NKScene (ECS Registry, Systems, Components)               │     │
│     └──────────────────────────────┬──────────────────────────────┘     │
└────────────────────────────────────┼────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────┐
│                             SERVICES MOTEUR                             │
│   ┌───────────┬───────────┬────────────┬─────────────┬──────────────┐   │
│   │   NKUI    │ NKPhysics │ NKAnimation│ NKDiagnostic│ NKFace / Body│   │
│   └─────┬─────┴─────┬─────┴─────┬──────┴──────┬──────┴──────┬───────┘   │
└─────────┼───────────┼───────────┼─────────────┼─────────────┼───────────┘
          │           │           │             │             │
          └───────────┼───────────┼─────────────┴─────────────┘
                      │           │
                      ▼           ▼
┌─────────────────────────────────────────────────────────────────────────┐
│                        ABSTRACTION GPU (NKRHI)                          │
│     ┌─────────────────────────────────────────────────────────────┐     │
│     │  NkIDevice (Vulkan / OpenGL / Direct3D / Metal / Software)  │     │
│     └──────────────────────────────┬──────────────────────────────┘     │
└────────────────────────────────────┼────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────┐
│                      BIBLIOTHÈQUES DE BASE (ZERO-STL)                   │
│   ┌─────────────────────────────────────────────────────────────────┐   │
│   │ NKContainers ──► NKMemory ──► NKMath ──► NKStream ──► NKCore    │   │
│   └────────────────────────────────┬────────────────────────────────┘   │
└────────────────────────────────────┼────────────────────────────────────┘
                                     │
                                     ▼
┌─────────────────────────────────────────────────────────────────────────┐
│                      PLATEFORME & SYSTÈME NATIVE                        │
│   ┌─────────────────────────────────────────────────────────────────┐   │
│   │ NKPlatform ──► NKWindow ──► NKEvent ──► OS (Win/Linux/macOS...) │   │
│   └─────────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────────────────┘

```

Règles de dépendance directes :

* `Noge` $\rightarrow$ `Nkentseu/Core`, `NKScene`, `NKUI`

* `PV3DE` $\rightarrow$ `Nkentseu/Core`, `NKScene`, `NKDiagnostic`, `NKEmotion`, `NKFace`, `NKBody`, `NKSpeech`, `NKPatientRenderer`

* `NKScene` $\rightarrow$ `NKCore`, `NKContainers`, `NKMath`

* `NKRenderer` / `NKUI` $\rightarrow$ `NKRHI`, `NKFont`, `NKImage`, `NKContainers`

* `NKRHI` $\rightarrow$ `NKPlatform`, `NKWindow`, `NKCore`

* `NKCore` / `NKContainers` / `NKMath` $\rightarrow$ `NKPlatform`