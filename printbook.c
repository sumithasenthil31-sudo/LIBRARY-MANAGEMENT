
/* =========================
   PRINT BOOK
   ========================= */
#include"header.h"
void printBook(const Book *book)
{
    printf("----------------------------------------\n");
    printf("Book ID  : %d\n", book->bookId);
    printf("Title    : %s\n", book->title);
    printf("Author   : %s\n", book->author);
    printf("Quantity : %d\n", book->quantity);
    printf("----------------------------------------\n");
}

