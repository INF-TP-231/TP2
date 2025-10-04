# Insertion dans une Liste Simplement Chaînée Triée

[![Langage](https://img.shields.io/badge/Langage-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Cours](https://img.shields.io/badge/Cours-INF%20231-green.svg)](https://www.example.com)
[![Licence](https://img.shields.io/badge/Licence-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 📋 Informations du Projet

- **Étudiant** : AKANA SIGNING JOSIAS AARON
- **Matricule** : 24H2358
- **Module** : INF 231
- **Enseignant** : Pr. Melatagia
- **Sujet** : Insertion dans une liste simplement chaînée triée

## 📖 Description

Ce projet implémente l'algorithme d'insertion d'un élément dans une liste simplement chaînée tout en maintenant l'ordre trié de celle-ci. L'insertion se fait à la position correcte pour préserver le tri croissant ou décroissant de la liste.

## 🎯 Objectifs

- Comprendre la structure de données "liste simplement chaînée"
- Maîtriser l'insertion ordonnée dans une liste triée
- Gérer correctement la mémoire dynamique
- Maintenir l'intégrité de la structure après insertion

## 🏗️ Structure de Données

### Nœud de la Liste

```c
typedef struct Node {
    int data;           // Données stockées
    struct Node* next;  // Pointeur vers le nœud suivant
} Node;
```

## ⚙️ Fonctionnalités

### 1. Création d'un nouveau nœud
Alloue dynamiquement la mémoire pour un nouveau nœud et initialise ses valeurs.

### 2. Insertion triée
Insère un élément à sa position correcte dans la liste pour maintenir l'ordre trié.

**Cas traités :**
- Insertion dans une liste vide
- Insertion en tête de liste
- Insertion au milieu de la liste
- Insertion en fin de liste

### 3. Affichage de la liste
Parcourt et affiche tous les éléments de la liste.

### 4. Libération de la mémoire
Désalloue proprement toute la mémoire utilisée par la liste.

## 🔍 Algorithme d'Insertion

L'algorithme suit cette logique :

1. **Création du nouveau nœud** avec la valeur à insérer
2. **Vérification de la liste vide** : si oui, le nouveau nœud devient la tête
3. **Vérification d'insertion en tête** : si la valeur est inférieure à la tête actuelle
4. **Parcours de la liste** pour trouver la position correcte
5. **Insertion du nœud** à la position trouvée
6. **Mise à jour des pointeurs** pour maintenir la chaîne

## 💻 Compilation et Exécution

### Prérequis
- Compilateur C (GCC recommandé)
- Système d'exploitation : Windows, Linux, ou macOS

### Compilation

```bash
gcc -o insertion_triee insertion_triee.c
```

### Exécution

```bash
./insertion_triee
```

## 📊 Exemple d'Utilisation

```c
// Création d'une liste vide
Node* head = NULL;

// Insertion de plusieurs éléments
head = insertionTriee(head, 5);
head = insertionTriee(head, 2);
head = insertionTriee(head, 8);
head = insertionTriee(head, 1);
head = insertionTriee(head, 9);

// Affichage : 1 -> 2 -> 5 -> 8 -> 9 -> NULL
```

## 🧪 Tests

Le programme teste différents scénarios :
- Insertion dans une liste vide
- Insertions multiples avec ordre aléatoire
- Vérification de l'ordre trié après chaque insertion
- Gestion de valeurs duplicates (si applicable)

## ⏱️ Complexité

| Opération | Complexité Temporelle | Complexité Spatiale |
|-----------|----------------------|---------------------|
| Insertion | O(n) | O(1) |
| Affichage | O(n) | O(1) |
| Recherche | O(n) | O(1) |

où n est le nombre d'éléments dans la liste.

## 📝 Notes Importantes

- La liste maintient un ordre **croissant** par défaut
- Chaque nœud est alloué dynamiquement (utilisation de `malloc`)
- Il est crucial de libérer la mémoire avec `free` pour éviter les fuites mémoires
- Les pointeurs doivent être manipulés avec précaution pour éviter les erreurs de segmentation

## 🚀 Améliorations Possibles

- [ ] Implémentation de l'ordre décroissant
- [ ] Ajout d'une fonction de suppression d'élément
- [ ] Support de types de données génériques (void*)
- [ ] Implémentation d'une liste doublement chaînée
- [ ] Ajout de fonctions de recherche et de tri

## 📚 Références

- Cours INF 231 - Pr. Melatagia
- "Introduction to Algorithms" - Cormen, Leiserson, Rivest, Stein
- Documentation C Standard Library

## 👤 Auteur

**AKANA SIGNING JOSIAS AARON**
- Matricule : 24H2358
- Module : INF 231
- Année académique : 2024-2025

## 📄 Licence

Ce projet est réalisé dans un cadre pédagogique.

---

⭐ *Projet réalisé dans le cadre du cours INF 231 sous la direction du Pr. Melatagia*
