# Liste doublement chaînée triée en C

## Description

Ce projet implémente une **liste doublement chaînée triée** en langage C.
Chaque nouvel élément inséré est automatiquement placé dans la bonne position, de manière à ce que la liste reste **ordonnée en ordre croissant**.

Le programme propose un **menu interactif** permettant :

* d’insérer un élément dans la liste (**insertion triée**),
* d’afficher la liste dans l’ordre croissant (**parcours avant**),
* d’afficher la liste dans l’ordre décroissant (**parcours arrière**),
* de quitter le programme.

---

## Structures de données

### `Noeud`

Représente un élément de la liste :

```c
typedef struct Noeud {
    int donnee;               // valeur stockée
    struct Noeud* suivant;    // pointeur vers le nœud suivant
    struct Noeud* precedent;  // pointeur vers le nœud précédent
} Noeud;
```

### `Liste`

Représente la liste complète :

```c
typedef struct {
    Noeud* tete;   // pointeur vers le premier élément
    Noeud* queue;  // pointeur vers le dernier élément
    int taille;    // nombre d’éléments dans la liste
} Liste;
```

---

## Fonctionnalités principales

1. **Insertion triée**

   * Place l’élément à la bonne position pour garder la liste en ordre croissant.
   * Cas gérés :

     * Liste vide,
     * Insertion avant la tête,
     * Insertion en queue,
     * Insertion au milieu.

2. **Affichage de la liste**

   * **Avant (croissant)** → parcours de la tête à la queue.
   * **Arrière (décroissant)** → parcours de la queue à la tête.

3. **Libération mémoire**

   * Tous les nœuds et la structure de la liste sont désalloués à la fin.

---

## Menu interactif

```
╔═══════════════════════════════════════╗
║   LISTE DOUBLEMENT CHAÎNÉE TRIEE      ║
╚═══════════════════════════════════════╝
1. Insertion TRIÉE
2. Afficher la liste (avant)
3. Afficher la liste (arrière)
0. Quitter
Choix :
```

---

## Exemple d’exécution

```
╔════════════════════════════════════════════╗
║   GESTION LISTE DOUBLEMENT CHAÎNÉE TRIEE   ║
╚════════════════════════════════════════════╝

Choix : 1
Valeur à insérer (triée) : 5
--- INSERTION TRIEE : 5 ---
Liste vide → Premier élément
Taille de la liste : 1

=== LISTE (croissant) ===
[5]

Choix : 1
Valeur à insérer (triée) : 2
--- INSERTION TRIEE : 2 ---
Insertion avant la tête (ancienne tête = 5)
Taille de la liste : 2

=== LISTE (croissant) ===
[2] ⇄ [5]
```

---

## Compilation et exécution

### Compilation :

```bash
gcc liste_triee.c -o liste_triee
```

### Exécution :

```bash
./liste_triee
```