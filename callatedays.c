
/* =========================
   CALCULATE LATE DAYS
   ========================= */
#include"header.h"
int calculateLateDays(const char *dueDate, const char *returnDate)
{
    time_t due;
    time_t returned;

    double difference;

    due = convertToTime(dueDate);
    returned = convertToTime(returnDate);

    difference = difftime(returned, due);

    if (difference <= 0) {
        return 0;
    }

    return (int)(difference / (24 * 60 * 60));
}
