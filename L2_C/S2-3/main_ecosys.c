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

int main(void) {
    srand(time(NULL));
    int initial_x = 5;  // Position initiale en x
    int initial_y = 5;  // Position initiale en y
    int direction_x = 1; // Direction de déplacement en x
    int direction_y = 0; // Direction de déplacement en y

    // Crée un animal à une position donnée avec une énergie de 10
    Animal *animal = creer_animal(initial_x, initial_y, 10);

    // Déplace l'animal dans la direction spécifiée
    animal->dir[0] = direction_x;
    animal->dir[1] = direction_y;

    // Boucle pour effectuer le déplacement et vérifier la toricité
    for (int i = 0; i < 10; i++) {  // Par exemple, effectuez le déplacement 10 fois
        bouger_animaux(animal);

        // Vérifiez les nouvelles coordonnées après le déplacement
        printf("Position de l'animal après déplacement : x=%d, y=%d\n", animal->x, animal->y);

        // Vérifiez que les coordonnées restent dans les limites du monde
        assert(animal->x >= 0 && animal->y >= 0 && animal->x < SIZE_X && animal->y < SIZE_Y);
    }

    // Libère la mémoire de l'animal
    liberer_liste_animaux(animal);

  /* A completer. Part 2:
   * exercice 4, questions 2 et 4 
   * exercice 6, question 2
   * exercice 7, question 3
   * exercice 8, question 1
   */

  return 0;
}

