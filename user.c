#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int user_exists(const char *username);

void save_user(User user) {
    if (user_exists(user.username)) {
        printf("Erro: Usuário já existe.\n");
        return;
    }
    
    FILE *file = fopen("users.txt", "a");
    if (file) {
        fprintf(file, "%s %s\n", user.username, user.password);
        fclose(file);
        printf("Usuário criado com sucesso.\n");
    } else {
        perror("Erro ao abrir o arquivo");
    }
}

void read_users() {
    FILE *file = fopen("users.txt", "r");
    if (file) {
        User user;
        printf("Usuários cadastrados:\n");
        while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
            printf("Usuário: %s\n", user.username);
        }
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo");
    }
}

void update_user(const char *username, const char *new_password) {
    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    User user;
    int found = 0;

    if (file && temp) {
        while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
            if (strcmp(user.username, username) == 0) {
                strcpy(user.password, new_password);
                found = 1;
                printf("Senha atualizada com sucesso.\n");
            }
            fprintf(temp, "%s %s\n", user.username, user.password);
        }

        fclose(file);
        fclose(temp);

        remove("users.txt");
        rename("temp.txt", "users.txt");

        if (!found) {
            printf("Erro: Usuário não encontrado.\n");
        }
    } else {
        perror("Erro ao abrir o arquivo");
        if (file) fclose(file);
        if (temp) fclose(temp);
    }
}

void delete_user(const char *username) {
    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    User user;
    int found = 0;

    if (file && temp) {
        while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
            if (strcmp(user.username, username) != 0) {
                fprintf(temp, "%s %s\n", user.username, user.password);
            } else {
                found = 1;
                printf("Usuário deletado com sucesso.\n");
            }
        }

        fclose(file);
        fclose(temp);

        remove("users.txt");
        rename("temp.txt", "users.txt");

        if (!found) {
            printf("Erro: Usuário não encontrado.\n");
        }
    } else {
        perror("Erro ao abrir o arquivo");
        if (file) fclose(file);
        if (temp) fclose(temp);
    }
}

int authenticate(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "r");
    User user;
    int authenticated = 0;

    if (file) {
        while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
            if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
                authenticated = 1;
                break;
            }
        }
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo");
    }
    return authenticated;
}

int user_exists(const char *username) {
    FILE *file = fopen("users.txt", "r");
    User user;
    int exists = 0;

    if (file) {
        while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
            if (strcmp(user.username, username) == 0) {
                exists = 1;
                break;
            }
        }
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo");
    }
    return exists;
}

