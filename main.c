#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Criar Usuário\n");
    printf("2. Ler Usuários\n");
    printf("3. Atualizar Usuário\n");
    printf("4. Deletar Usuário\n");
    printf("5. Autenticar Usuário\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int choice;
    User user;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o nome de usuário: ");
                scanf("%s", user.username);
                printf("Digite a senha: ");
                scanf("%s", user.password);
                save_user(user);
                break;
            case 2:
                read_users();
                break;
            case 3:
                printf("Digite o nome de usuário: ");
                scanf("%s", user.username);
                printf("Digite a nova senha: ");
                scanf("%s", user.password);
                update_user(user.username, user.password);
                break;
            case 4:
                printf("Digite o nome de usuário: ");
                scanf("%s", user.username);
                delete_user(user.username);
                break;
            case 5:
                printf("Digite o nome de usuário: ");
                scanf("%s", user.username);
                printf("Digite a senha: ");
                scanf("%s", user.password);
                if (authenticate(user.username, user.password)) {
                    printf("Autenticação bem-sucedida!\n");
                } else {
                    printf("Falha na autenticação.\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (choice != 0);

    return 0;
}
