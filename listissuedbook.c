/* =========================
   LIST ISSUED BOOKS
   ========================= */
#include"header.h"
void listIssuedBooks(void)
{
    FILE *fp = fopen(ISSUE_FILE, "rb");

    if (fp == NULL) {
        printf("\nNo issue records found.\n");
        return;
    }

    Issue issue;
    int count = 0;

    printf("\n================ ISSUED BOOKS ================\n");

    while (fread(&issue, sizeof(Issue), 1, fp) == 1) {

        Book book;

        printf("\n-----------------------------------------------\n");

        printf("Issue ID    : %d\n", issue.issueId);
        printf("Book ID     : %d\n", issue.bookId);

        if (findBookById(issue.bookId, &book)) {
            printf("Book Title  : %s\n", book.title);
        } else {
            printf("Book Title  : [Book Removed]\n");
        }

        printf("User ID     : %d\n", issue.userId);
        printf("User Name   : %s\n", issue.userName);
        printf("Issue Date  : %s\n", issue.issueDate);
        printf("Due Date    : %s\n", issue.dueDate);
        printf("Return Date : %s\n", issue.returnDate);
        printf("Fine Amount : Rs. %.2f\n", issue.fineAmount);

        if (issue.returned) {
            printf("Status      : Returned\n");
        } else {
            printf("Status      : Currently Issued\n");
        }

        count++;
    }

    printf("-----------------------------------------------\n");

    fclose(fp);

    if (count == 0) {
        printf("No issue records found.\n");
    }
}


