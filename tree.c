/*
** EPITECH PROJECT, 2019
** epitech Pool C
** File description:
** Sapin
*/

#include <unistd.h>
#include <stdlib.h>

void    print_line(int taille, int taille_max, char c)
{
    int espaces = 0;
    int k = 1;
    espaces = (taille_max - taille) / 2;
    while (k <= espaces) {
        my_putchar(' ');
        k++;
    }
    k = 1;
    while (k <= taille) {
        my_putchar(c);
        k++;
    }
    my_putchar('\n');
}

void    print_tree(int size, int size_maxi)
{
    int rang_min = 1;
    int rang_max = 1;
    int i = 1;
    int j = 1;
    int retr = 0;

    while (i <= size) {
        if (size > 1)
            (i % 2 != 0) ? (retr = (i / 2)) : (retr = i / 2);
        rang_min = rang_max  - retr;
        rang_max = rang_min + 2 + i;
        j = rang_min;
        while(j <= rang_max) {
            print_line(((j * 2) - 1), size_maxi, '*');
            j++;
        }
        i++;
    }
}

int     largeur_tree(int size)
{
    int rang_min = 1;
    int rang_max = 1;;
    int i_taille = 1;
    int retr = 0;

    while (i_taille <= size) {
        if (i_taille > 1)
            (i_taille % 2 != 0) ? (retr = (i_taille / 2)) : (retr = i_taille / 2);
        rang_min = rang_max  - retr;
        rang_max = rang_min + 2 + i_taille;
        i_taille++;
    }
    return ((rang_max * 2) - 1);
}

void    creer_pied(int size)
{
    int larg_pied = 0;
    int i = 1;
    
    (size % 2 == 0) ? (larg_pied = size + 1) : (larg_pied = size);
    while(i <= size) {
        print_line(larg_pied, largeur_tree(size), '|');
        i++;
    }
}

void    tree(int size)
{
    if (size < 0) {
        write(2, "84", 2);
        exit(84);
    } else if (size > 0) {
        print_tree(size, largeur_tree(size));
        creer_pied(size);
    } else if (size == 0) {
        write(2, "84", 2);
        exit(84);
    }
}
