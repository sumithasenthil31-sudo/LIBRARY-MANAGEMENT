/* =========================
   VIEW ALL BOOKS
   ========================= */
#include"header.h"
void viewAllBooks(void)
{
    FILE *fp = fopen(BOOK_FILE, "rb");

    if (fp == NULL) {
        printf("\nNo books available.\n");
        return;
    }

    Book book;
    int count = 0;

    printf("\n================ ALL BOOKS ================\n");

    printf("%-8s %-30s %-25s %-10s\n",
           "ID", "Title", "Author", "Quantity");

    printf("--------------------------------------------------------------------------\n");

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        printf("%-8d %-30s %-25s %-10d\n",
               book.bookId,
               book.title,
               book.author,
               book.quantity);

        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("No books available.\n");
    }
}

