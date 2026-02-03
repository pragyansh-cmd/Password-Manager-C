#include <stdio.h>
#include <stdlib.h>

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

int main() {
    struct Password p;
    FILE *fp;
    int choice;

    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fp = fopen("vault.txt", "a");
            if (fp == NULL) {
                printf("File error!\n");
                return 1;
            }

            printf("Enter website name: ");
            scanf("%s", p.website);

            printf("Enter username: ");
            scanf("%s", p.username);

            printf("Enter password: ");
            scanf("%s", p.password);

            fprintf(fp, "%s %s %s\n", p.website, p.username, p.password);
            fclose(fp);

            printf("Password saved successfully!\n");
        }
        else if (choice == 2) {
            fp = fopen("vault.txt", "r");
            if (fp == NULL) {
                printf("No passwords found!\n");
                continue;
            }

            printf("\nSaved Passwords:\n");
            while (fscanf(fp, "%s %s %s", p.website, p.username, p.password) != EOF) {
                printf("Website: %s | Username: %s | Password: %s\n",
                       p.website, p.username, p.password);
            }
            fclose(fp);
        }
        else if (choice == 3) {
            printf("Exiting program...\n");
            exit(0);
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
