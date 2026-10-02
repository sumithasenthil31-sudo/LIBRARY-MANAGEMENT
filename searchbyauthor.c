
/* =========================
   SEARCH BY AUTHOR
   ========================= */
#include"header.h"
void searchByAuthor(void)
{
    char searchAuthor[AUTHOR_SIZE];

    printf("\nEnter Author Name: ");
    readLine(searchAuthor, AUTHOR_SIZE);

    FILE *fp = fopen(BOOK_FILE, "rb");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    Book book;
    int found = 0;

    printf("\n================ SEARCH RESULTS ================\n");

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        if (containsIgnoreCase(book.author, searchAuthor)) {
            printBook(&book);
            found = 1;
        }
    }

    fclose(fp);

    if (!found) {
        printf("No matching books found.\n");
    }
}


