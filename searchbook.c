/* =========================
   SEARCH BOOK
   ========================= */
#include"header.h"
void searchBook(void)
{
    while (1) {

        printf("\n========== SEARCH BOOK ==========\n");
        printf("A. By Book ID\n");
        printf("B. By Book Name\n");
        printf("C. By Author Name\n");
        printf("D. Back to Main Menu\n");

        printf("Enter your choice: ");

        char option;
        scanf(" %c", &option);
        clearInputBuffer();

        option = (char)toupper((unsigned char)option);

        switch (option) {

            case 'A':
                searchById();
                break;

            case 'B':
                searchByName();
                break;

            case 'C':
                searchByAuthor();
                break;

            case 'D':
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}

