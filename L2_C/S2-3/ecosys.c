#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecosys.h"

/* Parametres globaux de l’ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01; //probabilite de changer de direction de deplacement
float p_reproduce_proie=0.4;
float p_reproduce_predateur=0.5;
int temps_repousse_herbe=-15;

/* PARTIE 1*/
/* Fourni: Part 1, exercice 4, question 2 */
Animal *creer_animal(int x, int y, float energie) {
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}


/* Fourni: Part 1, exercice 4, question 3 */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste;
  return animal;
}

/* A faire. Part 1, exercice 6, question 2 */
void ajouter_animal(int x, int y,float energie, Animal **liste_animal) {
  // Vérifie que les coordonnées x et y sont positives et inférieures à SIZE_X et SIZE_Y 
  assert(x >= 0 && x < SIZE_X);
  assert(y >= 0 && y < SIZE_Y);

  // Crée un nouvel animal avec les coordonnées x, y
  Animal *nv_animal = creer_animal(x, y, energie);

  // Ajoute le nouvel animal en tête de la liste chaînée 
  nv_animal->suivant = *liste_animal;
  *liste_animal = nv_animal;
}


/* A Faire. Part 1, exercice 5, question 5 */
void enlever_animal(Animal **liste, Animal *animal) {
  // Vérifie si la liste est vide
  if (*liste == NULL) {
    return; // Rien à faire si la liste est vide
  }

  // Si l'animal à supprimer est le premier de la liste
  if (*liste == animal) {
    // Met à jour la tête de liste pour sauter le premier animal
    *liste = animal->suivant;
    // Libère la mémoire de l'animal à supprimer
    free(animal);
    return;
  }

  /* Si l'animal à supprimer n'est pas le premier de la liste,
  Recherche de l'animal précédent */
  Animal *precedent = *liste;
  while (precedent && precedent->suivant != animal) {
    precedent = precedent->suivant;
  }

  // Si on a trouvé l'animal précédent, on met à jour les pointeurs
  if (precedent) {
    // MAJ des pointeurs pour sauter l'animal à supprimer
    precedent->suivant = animal->suivant;
    // Libère la mémoire de l'animal à supprimer
    free(animal);
  }
}


/* A Faire. Part 1, exercice 6, question 7 */
Animal* liberer_liste_animaux(Animal *liste) {
    while (liste) {
        Animal *temp = liste;  // Stocke l'élément actuel
        liste = liste->suivant;  // Avance dans la liste
        free(temp);  // Libère l'élément actuel
    }
    return NULL;
}

/* Fourni: part 1, exercice 4, question 4 */
unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}

/* Fourni: part 1, exercice 4, question 4 */
unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  while (la) {
    ++cpt;
    la=la->suivant;
  }
  return cpt;
}



/* Part 1. Exercice 5, question 1, ATTENTION, ce code est susceptible de contenir des erreurs... */
void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
  unsigned int i, j;
  char ecosys[SIZE_X][SIZE_Y];
  Animal *pa=NULL;

  /* on initialise le tableau */
  for (i = 0; i < SIZE_X; ++i) {
    for (j = 0; j < SIZE_Y; ++j) {
      ecosys[i][j]=' ';
    }
  }

  /* on ajoute les proies */
  pa = liste_proie;
  while (pa) {
    ecosys[pa->x][pa->y] = '*';
    pa=pa->suivant;
  }

  /* on ajoute les predateurs */
  pa = liste_predateur;
  while (pa) {
    assert(pa->x < SIZE_X && pa->y <SIZE_Y ); /* Vérifie que les coordonnées de l'animal sont à l'intérieur du monde */
    if ((ecosys[pa->x][pa->y] == '@') || (ecosys[pa->x][pa->y] == '*')) { /* proies aussi present */
      ecosys[pa->x][pa->y] = '@';
    } else {
      ecosys[pa->x][pa->y] = 'O';
    }
    pa = pa->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for (j = 0; j < SIZE_Y; ++j) {
    printf("-");
  }  
  printf("+\n");
  for (i = 0; i < SIZE_X; ++i) {
    printf("|");
    for (j = 0; j < SIZE_Y; ++j) {
      putchar(ecosys[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (j = 0; j<SIZE_Y; ++j) {
    printf("-");
  }
  printf("+\n");
  int nbproie=compte_animal_it(liste_proie);
  int nbpred=compte_animal_it(liste_predateur);
  
  printf("Nb proies : %5d\tNb predateurs : %5d\n", nbproie, nbpred);

}

void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

/* PARTIE 2*/

/* A Faire */
void ecrire_ecosys(const char *nom_fichier, Animal *liste_predateur, Animal *liste_proie) {
    // Ouvre le fichier en mode écriture
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s.\n", nom_fichier);
        return;
    }

    // Ecrit les proies
    fprintf(fichier, "<proies>\n");
    Animal *proie = liste_proie;
    while (proie) {
        // Ecrit les coordonnées, la direction et l'énergie de la proie
        fprintf(fichier, "x=%d y=%d dir=[%d %d] e=%f\n", proie->x, proie->y, proie->dir[0], proie->dir[1], proie->energie);
        proie = proie->suivant;
    }
    fprintf(fichier, "</proies>\n");

    // Ecrit les prédateurs
    fprintf(fichier, "<predateurs>\n");
    Animal *predateur = liste_predateur;
    while (predateur) {
        // Ecrit les coordonnées, la direction et l'énergie du prédateur
        fprintf(fichier, "x=%d y=%d dir=[%d %d] e=%f\n", predateur->x, predateur->y, predateur->dir[0], predateur->dir[1], predateur->energie);
        predateur = predateur->suivant;
    }
    fprintf(fichier, "</predateurs>\n");

    // Ferme le fichier
    fclose(fichier);
}

/* A Faire */
void lire_ecosys(const char *nom_fichier, Animal **liste_predateur, Animal **liste_proie) {
    // Ouvre le fichier en mode lecture
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s.\n", nom_fichier);
        return;
    }

    char ligne[256];
    char *type = NULL; // Pour identifier le type de liste (proies ou prédateurs)

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Supprime le caractère de saut de ligne à la fin de la ligne lue
        ligne[strcspn(ligne, "\n")] = '\0';

        // Si la ligne commence par '<', c'est une balise indiquant le type de liste
        if (ligne[0] == '<') {
            // Récupère le type de liste (proies ou prédateurs)
            type = &ligne[1]; // Saute le '<'
            if (ligne[strlen(ligne) - 1] == '>') {
                ligne[strlen(ligne) - 1] = '\0'; // Supprime le '>'
            }
        }
        // Sinon, c'est une ligne de données d'animal
        else if (type != NULL) {
            // Crée un nouvel animal à partir de la ligne lue
            int x, y;
            float energie;
            int dir_x, dir_y;
            sscanf(ligne, "x=%d y=%d dir=[%d %d] e=%f", &x, &y, &dir_x, &dir_y, &energie);
            Animal *animal = creer_animal(x, y, energie);
            animal->dir[0] = dir_x;
            animal->dir[1] = dir_y;

            // Ajoute l'animal à la bonne liste chaînée (proies ou prédateurs)
            if (strcmp(type, "proies") == 0) {
                *liste_proie = ajouter_en_tete_animal(*liste_proie, animal);
            } else if (strcmp(type, "predateurs") == 0) {
                *liste_predateur = ajouter_en_tete_animal(*liste_predateur, animal);
            }
        }
    }

    // Ferme le fichier
    fclose(fichier);
}

/* Part 2. Exercice 4, question 1 */
/* Part 2. Exercice 5, question 1 */
void bouger_animaux(Animal *la) {
    Animal *prev = NULL;
    
    while (la != NULL) {
        // Vérifie si l'animal change de direction avec une probabilité p_ch_dir
        if ((double)rand() / RAND_MAX < p_ch_dir) {
            int old_dir_x = la->dir[0];
            int old_dir_y = la->dir[1];

            // Choisi une nouvelle direction différente de l'ancienne
            while (la->dir[0] == old_dir_x && la->dir[1] == old_dir_y) {
                la->dir[0] = rand() % 3 - 1;  // Nouvelle direction en x : -1, 0 ou 1
                la->dir[1] = rand() % 3 - 1;  // Nouvelle direction en y : -1, 0 ou 1
            }
        }

        // MAJ des coordonnées en appliquant la direction (monde torique)
        la->x = (la->x + la->dir[0] + SIZE_X) % SIZE_X;
        la->y = (la->y + la->dir[1] + SIZE_Y) % SIZE_Y;

        // Vérifie que les coordonnées restent dans les limites du monde
        assert(la->x >= 0 && la->y >= 0 && la->x < SIZE_X && la->y < SIZE_Y);

        // Décrémente l'énergie de l'animal
        la->energie--;

        // Si l'énergie atteint 0, l'animal meurt
        if (la->energie <= 0) {
            // Supprimer l'animal de la liste
            if (prev != NULL) {
                prev->suivant = la->suivant;
                free(la);
                la = prev->suivant;
            } else {
                // Si c'est le 1er animal de la liste, MAJ de la tête de liste
                Animal *temp = la;
                la = la->suivant;
                free(temp);
            }
        } else {
            prev = la;
            la = la->suivant;
        }
    }
}



/* Part 2. Exercice 4, question 3 */
void reproduce(Animal **liste_animal, float p_reproduce) {
    Animal *parent = *liste_animal;
    Animal *nv_ne = NULL;

    while (parent != NULL) {
        // Vérifie si l'animal parent se reproduit avec une probabilité p_reproduce
        if ((double)rand() / RAND_MAX < p_reproduce) {
            // Crée un nouvel animal à la même position que le parent
            nv_ne = creer_animal(parent->x, parent->y, parent->energie / 2);

            // Ajoute le nouvel animal en tête de la liste
            nv_ne->suivant = *liste_animal;
            *liste_animal = nv_ne;
        }

        // Réduit l'énergie de l'animal parent
        parent->energie /= 2;

        // Passe à l'animal suivant dans la liste
        parent = parent->suivant;
    }
}



/* Part 2. Exercice 6, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
    /*A Completer*/

}

/* Part 2. Exercice 7, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
    /*A Completer*/

  return NULL;
} 

/* Part 2. Exercice 7, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
   /*A Completer*/

}

/* Part 2. Exercice 5, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){

   /*A Completer*/


}

