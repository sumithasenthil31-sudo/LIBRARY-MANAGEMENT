
/* =========================
   BOOK EXISTS
   ========================= */
#include"header.h"
int bookExists(int bookId)
{
    FILE *fp = fopen(BOOK_FILE, "rb");

    if (fp == NULL) {
        return 0;
    }

    Book book;

    while (fread(&book, sizeof(Book), 1, fp) == 1) {

        if (book.bookId == bookId) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}


