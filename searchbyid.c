
/* =========================
   SEARCH BY ID
   ========================= */
#include"header.h"
void searchById(void)
{
    int bookId = getInt("\nEnter Book ID: ");

    Book book;

    if (findBookById(bookId, &book)) {
        printf("\nBook Found:\n");
        printBook(&book);
    } else {
        printf("\nBook not found.\n");
    }
}

