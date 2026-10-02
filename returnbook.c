
/* =========================
   RETURN BOOK
   ========================= */
#include"header.h"
void returnBook(void)
{
    printf("\n========== RETURN BOOK ==========\n");

    int bookId = getInt("Enter Book ID: ");
    int userId = getInt("Enter User ID: ");

    FILE *issueFile = fopen(ISSUE_FILE, "rb+");

    if (issueFile == NULL) {
        printf("\nNo issued books found.\n");
        return;
    }

    Issue issue;
    int found = 0;

    while (fread(&issue, sizeof(Issue), 1, issueFile) == 1) {

        if (issue.bookId == bookId &&
            issue.userId == userId &&
            issue.returned == 0) {

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo active issue record found for this book and user.\n");
        fclose(issueFile);
        return;
    }

    char returnDate[11];

    getCurrentDate(returnDate);

    strcpy(issue.returnDate, returnDate);

    int lateDays = calculateLateDays(issue.dueDate, issue.returnDate);

    if (lateDays > 0) {
        issue.fineAmount = lateDays * FINE_PER_DAY;
    } else {
        issue.fineAmount = 0.0;
    }

    issue.returned = 1;

    /*
       Update issue record.
    */

    fseek(issueFile, -(long)sizeof(Issue), SEEK_CUR);

    fwrite(&issue, sizeof(Issue), 1, issueFile);

    fclose(issueFile);

    /*
       Increase book quantity.
    */

    updateBookQuantity(bookId, 1);

    printf("\n========================================\n");
    printf("Book returned successfully!\n");
    printf("Book ID       : %d\n", issue.bookId);
    printf("User ID       : %d\n", issue.userId);
    printf("User Name     : %s\n", issue.userName);
    printf("Issue Date    : %s\n", issue.issueDate);
    printf("Due Date      : %s\n", issue.dueDate);
    printf("Return Date   : %s\n", issue.returnDate);
    printf("Late Days     : %d\n", lateDays);
    printf("Fine Amount   : Rs. %.2f\n", issue.fineAmount);
    printf("========================================\n");
}
