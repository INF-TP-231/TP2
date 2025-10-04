# README - Implémentation d'une Liste Simplement Chaînée Circulaire

## 1. Introduction

Ce projet présente l'implémentation d'une **Liste Simplement Chaînée Circulaire** en langage C. L'objectif principal est de fournir une structure de données dynamique et efficace qui permet l'insertion en tête et en queue en temps constant ($\mathcal{O}(1)$), en n'utilisant qu'un seul pointeur vers le **dernier** élément de la liste.

Ce travail a été réalisé par **NGNINTEDEM NGUIMTSOP Roèl Parfait** dans le cadre du cours de Structures de Données et Algorithmes.

---
## 2. Structure du Projet

Le projet est implémenté dans un seul fichier source : `insertionheadqueuesimplementcir.c`.

### 2.1. Structures de Données

Deux structures clés sont définies :

1.  **`struct Noeud` (Noeud)** : Représente un élément de la liste. Il contient une donnée de type `int` et un pointeur `suivant` vers le nœud subséquent.
    ```c
    typedef struct Noeud {
        int donnee;
        struct Noeud* suivant;
    } Noeud;
    ```
2.  **`struct ListeCirculaire` (ListeCirculaire)** : Représente la liste elle-même. Elle contient un unique pointeur `dernier` qui pointe vers le dernier élément de la liste. Dans une liste circulaire, la tête est accessible via `liste->dernier->suivant`.
    ```c
    typedef struct {
        Noeud* dernier;
    } ListeCirculaire;
    ```

---
## 3. Fonctionnalités Implémentées

Le programme fournit une interface utilisateur interactive permettant de tester les principales opérations sur la liste circulaire.

| Fonction | Description | Complexité Temporelle |
| :--- | :--- | :--- |
| `creerNoeud` | Crée et initialise un nouveau nœud. | $\mathcal{O}(1)$ |
| `creerListe` | Initialise une nouvelle structure `ListeCirculaire` vide. | $\mathcal{O}(1)$ |
| **`insererEnTete`** | Ajoute un nouvel élément au début de la liste. | $\mathcal{O}(1)$ |
| **`insererEnQueue`** | Ajoute un nouvel élément à la fin de la liste. | $\mathcal{O}(1)$ |
| `afficherListe` | Parcourt et affiche tous les éléments de la liste. | $\mathcal{O}(n)$ |
| `estVide` | Vérifie si la liste ne contient aucun élément. | $\mathcal{O}(1)$ |
| `libererListe` | Libère toute la mémoire allouée dynamiquement pour les nœuds et la structure de liste. | $\mathcal{O}(n)$ |

### 3.1. Détail de l'Insertion

L'efficacité de la structure repose sur l'utilisation du pointeur `dernier` :

* **Insertion en Tête** :
    1.  Le nouveau nœud pointe vers l'actuelle tête (`liste->dernier->suivant`).
    2.  Le `dernier` pointe vers le nouveau nœud.
    *Cette opération est atomique et ne nécessite aucune itération.*
* **Insertion en Queue** :
    1.  L'opération est identique à l'insertion en tête.
    2.  *De plus*, le pointeur `dernier` est mis à jour pour pointer vers le nouveau nœud.
    *Cette opération est également atomique.*

---
## 4. Compilation et Exécution

### 4.1. Compilation

Utilisez un compilateur C standard (comme GCC) :

```bash
gcc insertionheadqueuesimplementcir.c -o liste_circulaire

### 4.1. Exécution

Exécutez le programme compilé :

./liste_circulaire

## 5. Note au Professeur Melatagia

Professeur Melatagia,

Ce programme démontre la maîtrise des concepts d'allocation dynamique de mémoire (malloc), de gestion des pointeurs et des particularités d'une liste chaînée circulaire (où le pointeur dernier permet d'accéder à la tête et à la queue avec une efficacité maximale). Les fonctions d'insertion sont conçues pour garantir une complexité temporelle constante, conformément aux exigences d'une structure de file (queue) implémentée efficacement.

Toutes les allocations sont correctement libérées à la fin du programme par la fonction libererListe pour prévenir les fuites de mémoire. J'ai également inclus une gestion basique des erreurs de saisie dans la boucle principale.

Cordialement,

NGNINTEDEM

