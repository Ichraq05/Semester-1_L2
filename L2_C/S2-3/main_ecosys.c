#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"



#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000

#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"

#define T_WAIT 40000

int main(void) {
    srand(time(NULL));

    // Initialiser l'écosystème
    Animal *liste_animal = NULL;
    float p_reproduce = 1.0;  // Taux de reproduction à 1 pour tester

    // Créer un animal à une position donnée avec une énergie de 10
    int initial_x = 5;  // Position initiale en x
    int initial_y = 5;  // Position initiale en y
    Animal *animal = creer_animal(initial_x, initial_y, 10);
    liste_animal = ajouter_en_tete_animal(liste_animal, animal);

    // Afficher l'état initial de l'écosystème
    printf("=== État initial de l'écosystème ===\n");
    afficher_ecosys(liste_animal, NULL);

    // Tester la fonction de déplacement
    printf("\n=== Test de déplacement ===\n");
    for (int i = 0; i < 3; i++) {  // Par exemple, effectuez le déplacement 5 fois
        bouger_animaux(liste_animal);

        // Afficher l'état après le déplacement
        printf("État après déplacement %d :\n", i + 1);
        afficher_ecosys(liste_animal, NULL);
    }

    // Tester la fonction de reproduction
    printf("\n=== Test de reproduction ===\n");
    for (int i = 0; i < 3; i++) {  // Par exemple, effectuez la reproduction 5 fois
        reproduce(&liste_animal, p_reproduce);

        // Afficher l'état après la reproduction
        printf("État après reproduction %d :\n", i + 1);
        afficher_ecosys(liste_animal, NULL);
    }

    // Libérer la mémoire de l'écosystème
    liberer_liste_animaux(liste_animal);

    return 0;
}


/* A completer. Part 2:
   * exercice 4, questions 2 et 4 
   * exercice 6, question 2
   * exercice 7, question 3
   * exercice 8, question 1
   */