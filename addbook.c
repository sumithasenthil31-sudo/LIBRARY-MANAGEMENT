
/* =========================
   ADD BOOK
   ========================= */
#include"header.h"
void addBook(void)
{
    Book book;

    printf("\n========== ADD NEW BOOK ==========\n");

    book.bookId = getInt("Enter Book ID: ");

    if (book.bookId <= 0) {
        printf("Book ID must be positive.\n");
        return;
    }

    if (bookExists(book.bookId)) {
        printf("A book with ID %d already exists.\n", book.bookId);
        return;
    }

    printf("Enter Book Title: ");
    readLine(book.title, TITLE_SIZE);

    if (strlen(book.title) == 0) {
        printf("Book title cannot be empty.\n");
        return;
    }

    printf("Enter Author Name: ");
    readLine(book.author, AUTHOR_SIZE);

    if (strlen(book.author) == 0) {
        printf("Author name cannot be empty.\n");
        return;
    }

    book.quantity = getInt("Enter Quantity: ");

    if (book.quantity <= 0) {
        printf("Quantity must be greater than 0.\n");
        return;
    }

    FILE *fp = fopen(BOOK_FILE, "ab");

    if (fp == NULL) {
        printf("Error opening book file.\n");
        return;
    }

    fwrite(&book, sizeof(Book), 1, fp);

    fclose(fp);

    printf("\nBook added successfully.\n");
}

