#ifndef USER_H
#define USER_H

#define USERNAME_LEN 30
#define PASSWORD_LEN 30

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

void save_user(User user);
void read_users();
void update_user(const char *username, const char *new_password);
void delete_user(const char *username);
int authenticate(const char *username, const char *password);

#endif
