//Q1

#include <stdio.h>

void triangleGauche(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void triangleDroite(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void triangleInverse(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int lignes;
    
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &lignes);
    
    printf("\nTriangle aligné à gauche :\n");
    triangleGauche(lignes);

    printf("\nTriangle aligné à droite :\n");
    triangleDroite(lignes);

    printf("\nTriangle inversé :\n");
    triangleInverse(lignes);

    return 0;
}

//Q2

#include <stdio.h>

// Fonction de recherche dichotomique
int rechercheDichotomique(int tableau[], int taille, int cible) {
    int gauche = 0, droite = taille - 1;
    
    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (tableau[milieu] == cible)
            return milieu; // Retourne la position si trouvé
        else if (tableau[milieu] < cible)
            gauche = milieu + 1; // Recherche dans la moitié droite
        else
            droite = milieu - 1; // Recherche dans la moitié gauche
    }
    
    return -1; // Retourne -1 si la valeur cible n'est pas trouvée
}

int main() {
    int tableau[] = {1, 3, 5, 7, 9}; // Tableau trié
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int cible;

    // Demande à l'utilisateur d'entrer la valeur cible
    printf("Entrez la valeur cible : ");
    scanf("%d", &cible);

    // Recherche de la valeur
    int position = rechercheDichotomique(tableau, taille, cible);

    // Affichage du résultat
    if (position != -1)
        printf("Position : %d\n", position);
    else
        printf("Valeur non trouvée dans le tableau.\n");

    return 0;
}


//Q3

#include <stdio.h>

int sommeChiffres(int nombre) {
    int somme = 0;
    
    // Prendre la valeur absolue pour gérer les nombres négatifs
    nombre = (nombre < 0) ? -nombre : nombre;

    while (nombre > 0) {
        somme += nombre % 10; // Extraire le dernier chiffre et l'ajouter à la somme
        nombre /= 10; // Supprimer le dernier chiffre
    }
    
    return somme;
}

int main() {
    int nombre;

    // Demande à l'utilisateur d'entrer un nombre
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

    // Calcul et affichage du résultat
    printf("La somme des chiffres de %d est : %d\n", nombre, sommeChiffres(nombre));

    return 0;
}

//Q4

#include <stdio.h>

// Fonction pour vérifier si un nombre est premier
int estPremier(int nombre) {
    if (nombre < 2) 
        return 0; // Les nombres inférieurs à 2 ne sont pas premiers

    for (int i = 2; i * i <= nombre; i++) {
        if (nombre % i == 0) 
            return 0; // Trouvé un diviseur autre que 1 et lui-même, donc non premier
    }

    return 1; // Nombre premier
}

int main() {
    int nombre;

    // Demande à l'utilisateur d'entrer un nombre
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

    // Vérification et affichage du résultat
    if (estPremier(nombre))
        printf("%d est un nombre premier.\n", nombre);
    else
        printf("%d n'est pas un nombre premier.\n", nombre);

    return 0;
}

//Q5

#include <stdio.h>

int estPalindrome(int nombre) {
    int original = nombre;
    int inverse = 0;

    // Gérer les nombres négatifs (ils ne peuvent pas être des palindromes)
    if (nombre < 0)
        return 0;

    while (nombre > 0) {
        inverse = inverse * 10 + nombre % 10; // Construire le nombre inversé
        nombre /= 10; // Supprimer le dernier chiffre
    }

    return (original == inverse); // Comparer avec l'original
}

int main() {
    int nombre;

    // Demande à l'utilisateur d'entrer un nombre
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

    // Vérification et affichage du résultat
    if (estPalindrome(nombre))
        printf("%d est un palindrome.\n", nombre);
    else
        printf("%d n'est pas un palindrome.\n", nombre);

    return 0;
}

//Q6

#include <stdio.h>

int longueurChaine(const char *chaine) {
    int longueur = 0;
    
    // Parcourir la chaîne jusqu'au caractère nul '\0'
    while (chaine[longueur] != '\0') {
        longueur++;
    }

    return longueur;
}

int main() {
    char chaine[100];

    // Demande à l'utilisateur d'entrer une chaîne
    printf("Entrez une chaîne de caractères : ");
    scanf("%99s", chaine); // %99s pour éviter le dépassement de tampon

    // Calcul et affichage de la longueur
    printf("La longueur de la chaîne \"%s\" est : %d\n", chaine, longueurChaine(chaine));

    return 0;
}
