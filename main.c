
#include"header.h"
int main(void)
{
    loadAllData();

    printf("\n");
    printf("=============================================\n");
    printf("       LIBRARY MANAGEMENT SYSTEM\n");
    printf("=============================================\n");

    mainMenu();

    return 0;
}


void mainMenu(void)
{
    int choice;

    do {
        printf("\n");
        printf("+-------------------------------------------+\n");
        printf("|          BOOK MANAGEMENT MENU             |\n");
        printf("+-------------------------------------------+\n");
        printf("| 1. Add New Book                           |\n");
        printf("| 2. Update Book Details                    |\n");
        printf("| 3. Remove Book                            |\n");
        printf("| 4. Search Book                            |\n");
        printf("| 5. View All Books                         |\n");
        printf("| 6. Issue Book                             |\n");
        printf("| 7. Return Book                            |\n");
        printf("| 8. List Issued Books                      |\n");
        printf("| 9. Save                                   |\n");
        printf("| 10. Exit                                  |\n");
        printf("+-------------------------------------------+\n");

        choice = getInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                updateBook();
                break;

            case 3:
                removeBook();
                break;

            case 4:
                searchBook();
                break;

            case 5:
                viewAllBooks();
                break;

            case 6:
                issueBook();
                break;

            case 7:
                returnBook();
                break;

            case 8:
                listIssuedBooks();
                break;

            case 9:
                saveAllData();
                break;

            case 10:
                saveAllData();
                printf("\nThank you for using the Library Management System.\n");
                printf("Program closed successfully.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 10);
}


