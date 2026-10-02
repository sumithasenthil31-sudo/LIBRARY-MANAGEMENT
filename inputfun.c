/* =========================
   INPUT FUNCTIONS
   ========================= */

#include"header.h"
void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}


void readLine(char *str, int size)
{
    if (fgets(str, size, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}


int getInt(const char *prompt)
{
    int value;

    while (1) {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1) {
            clearInputBuffer();
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
        clearInputBuffer();
    }
}


void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
}

