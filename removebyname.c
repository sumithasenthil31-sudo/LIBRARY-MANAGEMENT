
/* =========================
   REMOVE BY NAME
   ========================= */
#include"header.h"
void removeBookByName(void)
{
    char searchName[TITLE_SIZE];

    printf("\nEnter Book Name to remove: ");
    readLine(searchName, TITLE_SIZE);

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

        if (!found && containsIgnoreCase(book.title, searchName)) {

            found = 1;

            printf("\nBook removed:\n");
            printBook(&book);

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
        printf("\nBook not found.\n");
    }
}


