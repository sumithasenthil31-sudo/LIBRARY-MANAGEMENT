/* =========================
   REMOVE BY ID
   ========================= */
#include"header.h"
void removeBookById(void)
{
    int bookId = getInt("\nEnter Book ID to remove: ");

    FILE *fp = fopen(BOOK_FILE, "rb");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");

    if (temp == NULL) {
        fclose(fp);
        printf("Error creating temporary file.\n");
        return;
    }

    Book book;
    int found = 0;

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        if (book.bookId == bookId) {
            found = 1;
        } else {
            fwrite(&book, sizeof(Book), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(BOOK_FILE);
        rename("temp.dat", BOOK_FILE);

        printf("\nBook removed successfully.\n");
    } else {
        remove("temp.dat");
        printf("\nBook with ID %d not found.\n", bookId);
    }
}


