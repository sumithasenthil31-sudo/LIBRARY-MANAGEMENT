

/* =========================
   CONVERT DATE TO TIME
   ========================= */
#include"header.h"
time_t convertToTime(const char *date)
{
    int day, month, year;

    struct tm dateInfo;

    sscanf(date, "%d-%d-%d", &day, &month, &year);

    memset(&dateInfo, 0, sizeof(struct tm));

    dateInfo.tm_mday = day;
    dateInfo.tm_mon = month - 1;
    dateInfo.tm_year = year - 1900;

    dateInfo.tm_hour = 12;

    return mktime(&dateInfo);
}


