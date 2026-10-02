/* =========================
   UPDATE BOOK
   ========================= */
#include"header.h"
void updateBook(void)
{
    int choice;

    do {
        printf("\n========== UPDATE BOOK DETAILS ==========\n");
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
                updateBookById();
                break;

            case 'B':
                updateBookByName();
                break;

            case 'C':
                return;

            default:
                printf("Invalid choice.\n");
        }

        choice = option;

    } while (choice != 'C');
}

