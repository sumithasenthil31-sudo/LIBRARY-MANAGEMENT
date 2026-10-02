
/* =========================
   CURRENT DATE
   ========================= */
#include"header.h"
void getCurrentDate(char *date)
{
    time_t now;
    struct tm *current;

    now = time(NULL);
    current = localtime(&now);

    if (current == NULL) {
        strcpy(date, "01-01-1970");
        return;
    }

    sprintf(date,
            "%02d-%02d-%04d",
            current->tm_mday,
            current->tm_mon + 1,
            current->tm_year + 1900);
}

