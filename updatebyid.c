/* =========================
   UPDATE BY ID
   ========================= */
#include"header.h"
void updateBookById(void)
{
    int bookId = getInt("\nEnter Book ID to update: ");

    FILE *fp = fopen(BOOK_FILE, "rb+");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    Book book;
    int found = 0;

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        if (book.bookId == bookId) {

            found = 1;

            printf("\nCurrent Book Details:\n");
            printBook(&book);

            printf("\nEnter new title: ");
            readLine(book.title, TITLE_SIZE);

            printf("Enter new author: ");
            readLine(book.author, AUTHOR_SIZE);

            int newQuantity = getInt("Enter new quantity: ");

            if (newQuantity <= 0) {
                printf("Quantity must be greater than 0.\n");
                fclose(fp);
                return;
            }

            book.quantity = newQuantity;

            fseek(fp, -(long)sizeof(Book), SEEK_CUR);

            fwrite(&book, sizeof(Book), 1, fp);

            printf("\nBook updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", bookId);
    }

    fclose(fp);
}


