#include "liste.h"

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nombre total de tests exécutés. 
int tests_executes = 0;
// Pour chaque test qui réussi, cette variable sera incrémentée de 1.
// Le but est de la garder égale à test_executes.
int tests_reussis = 0;

#define STRINGIZE_(x) #x
#define STRINGIZE(x) STRINGIZE_(x)

// Incrémente le nombre de test exécutés de 1.
// Si le test réussi, incrémente le nombre de tests réussis de 1.
#define TEST(x) tests_executes += 1;    \
                if(x)                   \
                {                       \
                    tests_reussis += 1; \
                    printf("[SUCCES] ");\
                }                       \
                else                    \
                {                       \
                    printf("[ECHEC ] ");\
                }                       \
                printf(STRINGIZE(__FILE__) ", " STRINGIZE(__LINE__) ": " STRINGIZE(x) "\n");

// Compare le contenu de deux fichiers aux chemins a et b avec la commande diff. Incrémente test_reussis si les fichiers sont pareils.
#define TEST_FILE(a, b) tests_executes += 1;                                                \
                        {                                                                   \
                            int const r = system("diff --text --strip-trailing-cr " a " " b " > /dev/null");    \
                            if(!WEXITSTATUS(r))                                             \
                            {                                                               \
                                tests_reussis += 1;                                         \
                                printf("[SUCCES] ");                                        \
                            }                                                               \
                            else                                                            \
                            {                                                               \
                                printf("[ECHEC ] ");                                        \
                            }                                                               \
                            printf(STRINGIZE(__FILE__) ", " STRINGIZE(__LINE__) ": diff --test --strip-trailing-cr " STRINGIZE(a) " " STRINGIZE(b) "\n");   \
                        }

// Fonction à executer lors d'une segmentation fault.
// On imprime les résultats obtenus jusqu'à lors et on arrête immédiatement le programme.
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    printf("[SEGFAULT]\n");
    printf("%d/%d\n", tests_reussis, tests_executes);
    exit(tests_reussis - tests_executes);
}

int main()
{
    // Mise en place de la fonction à exécuter lors d'une segmentation fault.
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    // Test de la fonction l_make_node
    {
        // // Sans donnée.
        // node *tete = l_make_node(NULL);
        // TEST(tete != NULL);
        // TEST(tete->next == NULL);
        // TEST(tete->data == NULL);
    }
    {
        // // Avec donnée.
        // int *i = malloc(sizeof(int));
        // *i = 22;
        // node *tete = l_make_node(i);
        // TEST(tete != NULL);
        // TEST(tete->next == NULL);
        // TEST(tete->data == i);
        // TEST(*(int*)tete->data == 22);
        // *i = 44;
        // TEST(*(int*)tete->data == 44);
    }


    // Tests de la fonction l_length.
    {
        // // Avec une liste vide.
        // TEST(l_length(NULL) == 0);
    }
    {
        // // Avec une liste d'une seule node.
        // node *tete = l_make_node(NULL);
        // TEST(l_length(tete) == 1);

        // // Après avoir ajouté une deuxième node.
        // node *deuxieme = tete->next = l_make_node(NULL);
        // deuxieme->previous = tete;
        // TEST(l_length(tete) == 2);
        // TEST(l_length(deuxieme) == 2);

        // // Après avoir ajouté une troisième node.
        // node *troisieme = deuxieme->next = l_make_node(NULL);
        // troisieme->previous = deuxieme;
        // TEST(l_length(tete) == 3);
        // TEST(l_length(deuxieme) == 3);
        // TEST(l_length(troisieme) == 3);
    }


    // Tests de la fonction l_tail.
    {
        // // Avec une liste vide.
        // TEST(l_tail(NULL) == NULL);
    }
    {
        // // Avec une liste d'une seule node.
        // node *tete = l_make_node(NULL);
        // TEST(l_tail(tete) == tete);

        // // Après avoir ajouté une deuxième node.
        // node *deuxieme = tete->next = l_make_node(NULL);
        // deuxieme->previous = tete;
        // TEST(l_tail(tete) == deuxieme);
        // TEST(l_tail(deuxieme) == deuxieme);

        // // Après avoir ajouté une troisième node.
        // node *troisieme = deuxieme->next = l_make_node(NULL);
        // troisieme->previous = deuxieme;
        // TEST(l_tail(tete) == troisieme);
        // TEST(l_tail(deuxieme) == troisieme);
        // TEST(l_tail(troisieme) == troisieme);
    }


    // Tests de la fonction l_skip.
    {
        // // Avec une liste vide.
        // TEST(l_skip(NULL, 0) == NULL);
        // TEST(l_skip(NULL, 1) == NULL);
    }
    {
        // // Avec une liste d'une seule node.
        // node *tete = l_make_node(NULL);
        // TEST(l_skip(tete, 0) == tete);
        // TEST(l_skip(tete, 1) == NULL);
        // TEST(l_skip(tete, 2) == NULL);
        // TEST(l_skip(tete, 3) == NULL);

        // // Après avoir ajouté une deuxième node.
        // node *deuxieme = tete->next = l_make_node(NULL);
        // deuxieme->previous = tete;
        // TEST(l_skip(tete, 1) == deuxieme);
        // TEST(l_skip(tete, 2) == NULL);
        // TEST(l_skip(deuxieme, 0) == deuxieme);
        // TEST(l_skip(deuxieme, 1) == NULL);
        // TEST(l_skip(deuxieme, -1) == tete);

        // // Après avoir ajouté une troisième node.
        // node *troisieme = deuxieme->next = l_make_node(NULL);
        // troisieme->previous = deuxieme;
        // TEST(l_skip(tete, 2) == troisieme);
        // TEST(l_skip(tete, 3) == NULL);
        // TEST(l_skip(deuxieme, 1) == troisieme);
        // TEST(l_skip(deuxieme, 2) == NULL);
        // TEST(l_skip(troisieme, 0) == troisieme);
        // TEST(l_skip(troisieme, 1) == NULL);
        // TEST(l_skip(troisieme, -1) == deuxieme);
        // TEST(l_skip(troisieme, -2) == tete);
    }


    // Tests de la fonction l_append.
    {
        // // Partant d'une liste vide.
        // node *tete = NULL;
        // l_append(&tete, l_make_node(NULL));
        // TEST(tete != NULL);
        // TEST(tete->previous == NULL);

        // // Ajoutant une deuxième node.
        // node *deuxieme = l_append(&tete, l_make_node(NULL));
        // TEST(tete->next == deuxieme);
        // TEST(deuxieme->next == NULL);
        // TEST(deuxieme->previous == tete);

        // // Ajoutant une troisième node.
        // node *troisieme = l_append(&tete, l_make_node(NULL));
        // TEST(tete->next == deuxieme);
        // TEST(deuxieme->next == troisieme);
        // TEST(troisieme->next == NULL);
        // TEST(troisieme->previous == deuxieme);
    }


    // Tests de la fonction l_prepend.
    {
        // // Partant d'une liste vide.
        // node *tete = NULL;
        // l_prepend(&tete, l_make_node(NULL));
        // TEST(tete != NULL);
        // TEST(tete->next == NULL);
        // TEST(tete->previous == NULL);

        // // Ajoutant une deuxième node.
        // node *nouvelle_tete = l_prepend(&tete, l_make_node(NULL));
        // TEST(nouvelle_tete->next == tete);
        // TEST(nouvelle_tete->previous == NULL);
        // TEST(tete->previous == nouvelle_tete);

        // // Ajoutant une troisième node.
        // node *tres_nouvelle_tete = l_prepend(&tete, l_make_node(NULL));
        // TEST(tres_nouvelle_tete->next == nouvelle_tete);
        // TEST(tres_nouvelle_tete->previous == NULL);
        // TEST(nouvelle_tete->previous == tres_nouvelle_tete);
    }


    // Tests de la fonction l_insert.
    {
        // // Partant d'une liste vide.
        // node *tete = NULL;
        // l_insert(&tete, l_make_node(NULL));
        // TEST(tete != NULL);
        // TEST(tete->next == NULL);
        // TEST(tete->previous == NULL);

        // // On insère une node après la tête.
        // node *deuxieme = l_insert(&tete, l_make_node(NULL));
        // TEST(tete->next == deuxieme);
        // TEST(deuxieme->next == NULL);
        // TEST(deuxieme->previous == tete);

        // // On insère une autre node entre la tête et la deuxième node.
        // node *un_et_demi = l_insert(&tete, l_make_node(NULL));
        // TEST(tete->next == un_et_demi);
        // TEST(un_et_demi->previous == tete);
        // TEST(un_et_demi->next == deuxieme);
        // TEST(deuxieme->previous == un_et_demi);
    }


    // Tests de la fonction l_remove.
    {
        // // Avec une liste vide.
        // TEST(l_remove(NULL) == NULL);
    }
    {
        // // Avec une liste de une node.
        // node *tete = l_make_node(NULL);
        // TEST(l_remove(tete) == NULL);
    }
    {
        // // Avec une liste de deux nodes.
        // node *tete = l_make_node(malloc(sizeof(int)));
        // *(int*)tete->data = 1;
        // node *deuxieme = tete->next = l_make_node(malloc(sizeof(int)));
        // deuxieme->previous = tete;
        // *(int*)deuxieme->data = 2;

        // // On enlève la tête.
        // TEST(l_remove(tete) == deuxieme);
        // TEST(deuxieme->previous == NULL);
        // TEST(*(int*)deuxieme->data == 2);

        // // On enlève la deuxième node.
        // TEST(l_remove(deuxieme) == NULL);
    }
    {
        // // Avec une liste de trois nodes.
        // node *tete = l_make_node(malloc(sizeof(int)));
        // *(int*)tete->data = 1;
        // node *deuxieme = tete->next = l_make_node(malloc(sizeof(int)));
        // deuxieme->previous = tete;
        // *(int*)deuxieme->data = 2;
        // node *troisieme = deuxieme->next = l_make_node(malloc(sizeof(int)));
        // troisieme->previous = deuxieme;
        // *(int*)troisieme->data = 3;

        // // On enlève la deuxième node.
        // TEST(l_remove(deuxieme) == troisieme);
        // TEST(*(int*)tete->data == 1);
        // TEST(tete->next == troisieme);
        // TEST(troisieme->previous == tete);
        // TEST(*(int*)tete->next->data == 3);

        // // On enlève les deux nodes qui restent d'un coup.
        // TEST(l_remove(l_remove(tete)) == NULL);
    }


    // Tests de lecture d'une DB contenant une erreur, modifications en mémoire et écriture.
    {
#define NOM_SITE_LONGUEUR_MAX 127
#define CODE_POSTAL_LONGUEUR 5

        // typedef struct site_amu
        // {
        //     size_t index;
        //     char nom[NOM_SITE_LONGUEUR_MAX + 1];
        //     char code_postal[CODE_POSTAL_LONGUEUR];
        // } site_amu;

        // // Lecture de la DB vers une liste en mémoire.
        // node *sites = NULL;
        // {
        //     FILE *db_erronee = fopen("test/db_erronee.txt", "r");
        //     site_amu data;
        //     while(fscanf(db_erronee, "%zu,%127[^,],%5s", &data.index, data.nom, data.code_postal) == 3)
        //     {
        //         site_amu *site = malloc(sizeof(site_amu));
        //         *site = data;
        //         l_append(&sites, l_make_node(site));
        //     }
        //     fclose(db_erronee);
        // }

        // // La liste devrait contenir les six sites.
        // TEST(l_length(sites) == 6);
        // TEST(((site_amu*)sites->data)->index == 1);
        // TEST(((site_amu*)l_tail(sites)->data)->index == 6);

        // // On sait que le quatrième site est incorrect. Supprimons-le.
        // node *quatrieme = l_skip(sites, 3);
        // l_remove(quatrieme);

        // // La liste ne devrait plus contenir que cinq sites.
        // TEST(l_length(sites) == 5);

        // // Ajoutons le site manquant.
        // site_amu *luminy = malloc(sizeof(site_amu));
        // luminy->index = ((site_amu*)l_tail(sites)->data)->index + 1;
        // strcpy(luminy->nom, "Luminy");
        // strncpy(luminy->code_postal, "13288", 5);
        // l_append(&sites, l_make_node(luminy));

        // // La liste devrait contenir les six sites.
        // TEST(l_length(sites) == 6);

        // // Écriture de la liste vers un fichier.
        // FILE *db_modifiee = fopen("db_modifiee.txt", "w");
        // for(node *site = sites; site; site = l_skip(site, 1))
        // {
        //     site_amu *data = (site_amu*)site->data;
        //     fprintf(db_modifiee, "%zu,%s,%5s\n", data->index, data->nom, data->code_postal);
        // }

        // fclose(db_modifiee);
        // l_free_list(sites);

        // TEST_FILE("db_modifiee.txt", "test/db_corrigee.txt");
    }

    printf("%d/%d\n", tests_reussis, tests_executes);

    return tests_executes - tests_reussis;
}
