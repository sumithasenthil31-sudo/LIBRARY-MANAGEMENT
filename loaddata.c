/* =========================
   LOAD DATA
   ========================= */
#include"header.h"
void loadAllData(void)
{
    /*
       Data is loaded directly from files whenever required.
       No separate memory array is necessary.
    */

    FILE *fp;

    fp = fopen(BOOK_FILE, "rb");
    if (fp != NULL) {
        fclose(fp);
    }

    fp = fopen(ISSUE_FILE, "rb");

    if (fp != NULL) {
        fclose(fp);
    }
}
