
/* =========================
   ISSUE BOOK
   ========================= */
#include"header.h"
void issueBook(void)
{
    printf("\n========== ISSUE BOOK ==========\n");

    int bookId = getInt("Enter Book ID: ");

    FILE *bookFile = fopen(BOOK_FILE, "rb+");

    if (bookFile == NULL) {
        printf("No books available.\n");
        return;
    }

    Book book;
    int found = 0;

    while (fread(&book, sizeof(Book), 1, bookFile) == 1) {

        if (book.bookId == bookId) {

            found = 1;

            if (book.quantity <= 0) {
                printf("\nBook is currently unavailable.\n");
                fclose(bookFile);
                return;
            }

            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", bookId);
        fclose(bookFile);
        return;
    }

    printf("\nBook Details:\n");
    printBook(&book);

    int userId = getInt("\nEnter User ID: ");

    if (userId <= 0) {
        printf("Invalid User ID.\n");
        fclose(bookFile);
        return;
    }

    char userName[NAME_SIZE];

    printf("Enter User Name: ");
    readLine(userName, NAME_SIZE);

    if (strlen(userName) == 0) {
        printf("User name cannot be empty.\n");
        fclose(bookFile);
        return;
    }

    /*
       Check if this user already has the same book.
    */

    FILE *issueFile = fopen(ISSUE_FILE, "rb");

    if (issueFile != NULL) {

        Issue existing;

        while (fread(&existing, sizeof(Issue), 1, issueFile) == 1) {

            if (existing.bookId == bookId &&
                existing.userId == userId &&
                existing.returned == 0) {

                printf("\nThis user already has this book issued.\n");

                fclose(issueFile);
                fclose(bookFile);

                return;
            }
        }

        fclose(issueFile);
    }

    Issue issue;

    issue.issueId = getNextIssueId();
    issue.bookId = bookId;
    issue.userId = userId;

    strcpy(issue.userName, userName);

    getCurrentDate(issue.issueDate);
    getDueDate(issue.issueDate, issue.dueDate);

    strcpy(issue.returnDate, "N/A");

    issue.fineAmount = 0.0;
    issue.returned = 0;

    /*
       Reduce book quantity.
    */

    fseek(bookFile, -(long)sizeof(Book), SEEK_CUR);

    book.quantity--;

    fwrite(&book, sizeof(Book), 1, bookFile);

    fclose(bookFile);

    /*
       Save issue record.
    */

    issueFile = fopen(ISSUE_FILE, "ab");

    if (issueFile == NULL) {
        printf("Error opening issue file.\n");

        /*
           Ideally rollback quantity here.
        */
        return;
    }

    fwrite(&issue, sizeof(Issue), 1, issueFile);

    fclose(issueFile);

    printf("\n========================================\n");
    printf("Book issued successfully!\n");
    printf("Issue ID   : %d\n", issue.issueId);
    printf("Book ID    : %d\n", issue.bookId);
    printf("User ID    : %d\n", issue.userId);
    printf("User Name  : %s\n", issue.userName);
    printf("Issue Date : %s\n", issue.issueDate);
    printf("Due Date   : %s\n", issue.dueDate);
    printf("========================================\n");
}
