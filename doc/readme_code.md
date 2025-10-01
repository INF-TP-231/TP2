# 📚 Exercice INF 231 - Listes Chaînées en C

## 👤 Informations Personnelles
- **Nom:** AKANA SIGNING JOSIAS AARON
- **Matricule:** 24H2358
- **Date:** Jeudi 25 septembre 2025
- **Professeur:** Pr. Melatagia

---

## 📋 Description du Projet

Ce projet contient l'implémentation complète de 5 exercices sur les listes chaînées en langage C, couvrant les structures de données suivantes :
- Listes simplement chaînées
- Listes doublement chaînées
- Listes circulaires (simples et doubles)

---

## 🎯 Exercices Implémentés

### Exercice 1 : Suppression d'occurrences
**Fonction:** `supprimerOccurrences()`
- Lit un élément et supprime toutes ses occurrences dans la liste
- Gère correctement les suppressions en tête et dans le corps de la liste
- Libère la mémoire des nœuds supprimés

### Exercice 2 : Insertion triée (liste simple)
**Fonction:** `insertionTrieeSimple()`
- Insère un élément dans une liste simplement chaînée triée
- Maintient l'ordre croissant des éléments
- Gère les cas particuliers (liste vide, insertion en tête)

### Exercice 3 : Insertion triée (liste double)
**Fonction:** `insertionTrieeDouble()`
- Insère un élément dans une liste doublement chaînée triée
- Maintient les liens bidirectionnels (next et prev)
- Préserve l'ordre croissant

### Exercice 4 : Liste circulaire simple
**Fonctions:** 
- `insertionTeteCirculaire()` - Insertion en tête
- `insertionQueueCirculaire()` - Insertion en queue
- Maintient la circularité de la liste

### Exercice 5 : Liste circulaire double
**Fonctions:**
- `insertionTeteCirculaireDouble()` - Insertion en tête
- `insertionQueueCirculaireDouble()` - Insertion en queue
- Maintient les liens bidirectionnels et la circularité

---

## 🛠️ Compilation et Exécution

### Compilation
```bash
gcc -o listes exercice_inf231.c
```

### Exécution
```bash
./listes
```

---

## 📊 Structures de Données

### Liste Simplement Chaînée
```c
typedef struct NodeSimple {
    int data;
    struct NodeSimple* next;
} NodeSimple;
```

### Liste Doublement Chaînée
```c
typedef struct NodeDouble {
    int data;
    struct NodeDouble* next;
    struct NodeDouble* prev;
} NodeDouble;
```

---

## ✅ Fonctionnalités Auxiliaires

- `creerNodeSimple()` - Création d'un nœud simple
- `creerNodeDouble()` - Création d'un nœud double
- `afficherListeSimple()` - Affichage d'une liste simple
- `afficherListeDouble()` - Affichage d'une liste double
- `afficherCirculaireSimple()` - Affichage d'une liste circulaire simple
- `afficherCirculaireDouble()` - Affichage d'une liste circulaire double

---

## 🧪 Tests Inclus

Le programme `main()` contient des tests pour chaque exercice avec des exemples concrets :
- Test de suppression multiple
- Test d'insertion triée avec plusieurs valeurs
- Test d'insertion en tête et en queue pour les listes circulaires

---

## 📝 Notes Importantes

- Toutes les fonctions gèrent correctement la mémoire (malloc/free)
- Les cas limites sont traités (listes vides, insertion en tête/queue)
- Le code est commenté pour faciliter la compréhension
- Les fonctions retournent le nouveau pointeur de tête/queue quand nécessaire

---

## 🎓 Compétences Développées

✔️ Manipulation de pointeurs en C  
✔️ Gestion dynamique de la mémoire  
✔️ Structures de données chaînées  
✔️ Algorithmes de tri et d'insertion  
✔️ Gestion de listes circulaires  

---

## 📧 Contact

**AKANA SIGNING JOSIAS AARON**  
Matricule: 24H2358  
Cours: INF 231

---

*Travail réalisé dans le cadre du cours INF 231 avec le Pr. Melatagia*