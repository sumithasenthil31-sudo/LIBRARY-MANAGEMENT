
/* =========================
   UPDATE BOOK QUANTITY
   ========================= */
#include"header.h"
int updateBookQuantity(int bookId, int change)
{
    FILE *fp = fopen(BOOK_FILE, "rb+");

    if (fp == NULL) {
        return 0;
    }

    Book book;

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        if (book.bookId == bookId) {

            book.quantity += change;

            if (book.quantity < 0) {
                book.quantity = 0;
            }

            fseek(fp, -(long)sizeof(Book), SEEK_CUR);

            fwrite(&book, sizeof(Book), 1, fp);

            fclose(fp);

            return 1;
        }
    }

    fclose(fp);

    return 0;
}

