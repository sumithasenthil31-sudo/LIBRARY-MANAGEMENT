/* =========================
   REMOVE BOOK
   ========================= */
#include"header.h"
void removeBook(void)
{
    while (1) {

        printf("\n========== REMOVE BOOK ==========\n");
        printf("A. By Book ID\n");
        printf("B. By Book Name\n");
        printf("C. Back to Main Menu\n");

        printf("Enter your choice: ");

        char option;
        scanf(" %c", &option);
        clearInputBuffer();

        option = (char)toupper((unsigned char)option);

        switch (option) {

            case 'A':
                removeBookById();
                break;

            case 'B':
                removeBookByName();
                break;

            case 'C':
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}

