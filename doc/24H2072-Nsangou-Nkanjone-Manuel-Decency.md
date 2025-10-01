# 📚 EXERCICE2 INF231: Implémentation d'une Liste Doublement Chaînée Circulaire en C

---

##  Informations du Projet

- **Nom du fichier** : `insertionheadqueue.c`
- **Superviseur** : Professeur Melatagia
- **Auteur** : Nsangou Nkanjone Manuel Decency

---

##  Description

Ce programme implémente une **liste doublement chaînée circulaire** en langage C, offrant des opérations complètes d’insertion, suppression et affichage dans les deux sens, avec gestion mémoire et menu interactif.

---

##  Structures de Données

```c
// Structure d'un nœud
typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
    struct Noeud* precedent;
} Noeud;

// Structure de la liste
typedef struct {
    Noeud* tete;
    int taille;
} ListeCirculaire;
```

---

##  Fonctionnalités

### 1. Fonctions de Base
- ✅ `creer_liste()` : Crée une nouvelle liste vide
- ✅ `creer_noeud(int valeur)` : Crée un nouveau nœud
- ✅ `est_vide(ListeCirculaire* liste)` : Vérifie si la liste est vide

### 2. Opérations d’Insertion
- ✅ `inserer_en_tete(ListeCirculaire* liste, int valeur)` : Insertion en tête
- ✅ `inserer_en_queue(ListeCirculaire* liste, int valeur)` : Insertion en queue

### 3. Opérations de Suppression
- ✅ `supprimer_en_tete(ListeCirculaire* liste)` : Suppression en tête
- ✅ `supprimer_en_queue(ListeCirculaire* liste)` : Suppression en queue

### 4. Fonctions d’Affichage
- ✅ `afficher_liste_avant(ListeCirculaire* liste)` : Affichage sens direct
- ✅ `afficher_liste_arriere(ListeCirculaire* liste)` : Affichage sens inverse
- ✅ `afficher_details_liaisons(ListeCirculaire* liste)` : Détails des liaisons

### 5. Gestion Mémoire
- ✅ `liberer_liste(ListeCirculaire* liste)` : Libération complète de la mémoire

---

##  Caractéristiques Techniques

- **Circularité** : Le dernier nœud pointe vers la tête, garantissant la circularité.
- **Gestion des pointeurs** : Les pointeurs `suivant` et `précédent` sont toujours cohérents.
- **Gestion d’erreurs** : Vérification des allocations mémoire et gestion des cas limites (liste vide, un seul élément).
- **Affichage détaillé** : Messages pour le débogage et suivi de la taille de la liste.

---

##   Menu Interactif

Le programme propose un menu convivial :

1. Insertion en tête  
2. Insertion en queue  
3. Suppression en tête  
4. Suppression en queue  
5. Affichage sens direct  
6. Affichage sens inverse  
7. Détails des liaisons  
8. Test automatique  
0. Quitter  

---

##   Test Automatique

La fonction de test automatique démontre :
- Insertions multiples en tête et queue
- Suppressions alternées
- Affichages dans les deux sens
- Vérification des liaisons

---

##   Compilation & Exécution

```bash
gcc insertionheadqueue.c -o liste_circulaire
./liste_circulaire
```

---

##   Points Forts

- **Robustesse** : Gestion complète des cas limites
- **Lisibilité** : Code bien commenté et structuré
- **Interactivité** : Menu utilisateur convivial
- **Débogage** : Affichages détaillés pour comprendre le fonctionnement
- **Performance** : Opérations en temps constant O(1) pour insertions/suppressions

---

##   Complexités

- Insertion tête/queue : **O(1)**
- Suppression tête/queue : **O(1)**
- Affichage : **O(n)**
- Libération mémoire : **O(n)**

---

## **📜 Licence**

Projet à but pédagogique, libre d’utilisation pour l’apprentissage.

---
