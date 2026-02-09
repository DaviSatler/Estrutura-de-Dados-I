#include <stdio.h>
#include <string.h>
#include "usuario.h"

void cadastrarUsuario(Usuario usuarios[], int *total) {
    if (*total >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido!\n");
        return;
    }

    Usuario *u = &usuarios[*total];

    printf("ID: ");
    scanf("%d", &u->id);
    getchar();

    printf("Nome: ");
    fgets(u->nome, 100, stdin);
    u->nome[strcspn(u->nome, "\n")] = 0;

    (*total)++;
    printf("Usuario cadastrado!\n");
}
