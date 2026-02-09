#include <stdio.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

int main() {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    Emprestimo emprestimos[MAX_EMPRESTIMOS];

    int totalLiv = 0, totalUsu = 0, totalEmp = 0;
    int op;

    do {
        printf("\n=== Biblioteca ===\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Registrar emprestimo\n");
        printf("4 - Listar emprestimos por usuario\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarLivro(livros, &totalLiv);
                break;
            case 2:
                cadastrarUsuario(usuarios, &totalUsu);
                break;
            case 3:
                registrarEmprestimo(
                    emprestimos, &totalEmp,
                    usuarios, totalUsu,
                    livros, totalLiv
                );
                break;
            case 4:
                listarEmprestimosUsuario(
                    emprestimos, totalEmp,
                    usuarios, totalUsu,
                    livros, totalLiv
                );
                break;
        }

    } while (op != 0);

    return 0;
}
