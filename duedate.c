
/* =========================
   DUE DATE
   ========================= */
#include"header.h"
void getDueDate(char *issueDate, char *dueDate)
{
    time_t issueTime;
    struct tm dateInfo;

    /*
       Convert DD-MM-YYYY into struct tm.
    */

    int day, month, year;

    sscanf(issueDate, "%d-%d-%d", &day, &month, &year);

    memset(&dateInfo, 0, sizeof(struct tm));

    dateInfo.tm_mday = day;
    dateInfo.tm_mon = month - 1;
    dateInfo.tm_year = year - 1900;
    dateInfo.tm_hour = 12;

    issueTime = mktime(&dateInfo);

    /*
       Add 7 days.
    */

    issueTime += 7 * 24 * 60 * 60;

    dateInfo = *localtime(&issueTime);

    sprintf(dueDate,
            "%02d-%02d-%04d",
            dateInfo.tm_mday,
            dateInfo.tm_mon + 1,
            dateInfo.tm_year + 1900);
}


