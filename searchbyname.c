/* =========================
   SEARCH BY NAME
   ========================= */
#include"header.h"
void searchByName(void)
{
    char searchName[TITLE_SIZE];

    printf("\nEnter Book Name: ");
    readLine(searchName, TITLE_SIZE);

    FILE *fp = fopen(BOOK_FILE, "rb");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    Book book;
    int found = 0;

    printf("\n================ SEARCH RESULTS ================\n");

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        if (containsIgnoreCase(book.title, searchName)) {
            printBook(&book);
            found = 1;
        }
    }

    fclose(fp);

    if (!found) {
        printf("No matching books found.\n");
    }
}

