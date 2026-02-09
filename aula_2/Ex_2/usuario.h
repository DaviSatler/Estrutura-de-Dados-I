#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 100

typedef struct {
    int id;
    char nome[100];
} Usuario;

void cadastrarUsuario(Usuario usuarios[], int *total);

#endif
