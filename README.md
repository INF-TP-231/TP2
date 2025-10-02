# Insertion dans une Liste Simplement Chaînée Triée

## 👤 Informations de l'étudiant
- **Nom:** AKANA SIGNING JOSIAS AARON
- **Matricule:** 24H2358

---

## 📝 Description du projet

Ce projet implémente une structure de données de liste simplement chaînée triée en langage C. Il permet d'insérer des éléments tout en maintenant automatiquement l'ordre croissant de la liste.

## 🎯 Objectifs

- Comprendre et implémenter une liste simplement chaînée
- Maintenir l'ordre trié lors des insertions
- Gérer la mémoire dynamique en C
- Maîtriser les pointeurs et les structures

## 🔧 Fonctionnalités

### Fonctions principales

1. **`creerNoeud(int valeur)`**
   - Crée un nouveau nœud avec la valeur spécifiée
   - Alloue dynamiquement la mémoire nécessaire

2. **`insererTrie(Noeud* tete, int valeur)`**
   - Insère un élément à sa position correcte dans la liste triée
   - Maintient l'ordre croissant
   - Gère tous les cas : liste vide, insertion au début, au milieu, à la fin

3. **`afficherListe(Noeud* tete)`**
   - Affiche tous les éléments de la liste
   - Format : `valeur1 -> valeur2 -> valeur3`

4. **`libererListe(Noeud* tete)`**
   - Libère toute la mémoire allouée pour la liste
   - Évite les fuites mémoire

## 📊 Complexité

- **Insertion:** O(n) dans le pire cas
- **Affichage:** O(n)
- **Espace mémoire:** O(n)

## 🚀 Compilation et exécution

### Compilation
```bash
gcc liste_chainee_triee.c -o liste_triee
```

### Exécution
```bash
./liste_triee
```

## 💡 Exemple d'utilisation

```c
Noeud* liste = NULL;

// Insertions
liste = insererTrie(liste, 5);  // Liste: 5
liste = insererTrie(liste, 2);  // Liste: 2 -> 5
liste = insererTrie(liste, 8);  // Liste: 2 -> 5 -> 8
liste = insererTrie(liste, 1);  // Liste: 1 -> 2 -> 5 -> 8

// Affichage
afficherListe(liste);

// Libération mémoire
libererListe(liste);
```

## 📋 Résultat attendu

```
=== Insertion dans une liste simplement chaînée triée ===

Insertion de 5:
Liste: 5

Insertion de 2:
Liste: 2 -> 5

Insertion de 8:
Liste: 2 -> 5 -> 8

Insertion de 1:
Liste: 1 -> 2 -> 5 -> 8

Insertion de 6:
Liste: 1 -> 2 -> 5 -> 6 -> 8

Insertion de 3:
Liste: 1 -> 2 -> 3 -> 5 -> 6 -> 8

Insertion de 9:
Liste: 1 -> 2 -> 3 -> 5 -> 6 -> 8 -> 9
```

## 🔍 Cas traités

- ✅ Liste vide
- ✅ Insertion au début (valeur minimale)
- ✅ Insertion au milieu
- ✅ Insertion à la fin (valeur maximale)
- ✅ Gestion des doublons

## ⚠️ Points importants

- Toujours libérer la mémoire avec `libererListe()` pour éviter les fuites
- La fonction `insererTrie()` retourne le nouveau pointeur de tête
- La liste est triée par ordre croissant

## 📚 Concepts utilisés

- Structures en C
- Pointeurs et allocation dynamique (`malloc`, `free`)
- Listes chaînées
- Algorithmes de tri et d'insertion

## 🛠️ Améliorations possibles

- Ajouter une fonction de suppression d'élément
- Implémenter la recherche d'un élément
- Créer une fonction de fusion de deux listes triées
- Ajouter le tri par ordre décroissant

---

**Date de création:** Octobre 2025  
**Langage:** C  
**Compilateur testé:** GCC
