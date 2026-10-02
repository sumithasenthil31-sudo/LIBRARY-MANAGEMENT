

/* =========================
   NEXT ISSUE ID
   ========================= */
#include"header.h"
int getNextIssueId(void)
{
    FILE *fp = fopen(ISSUE_FILE, "rb");

    if (fp == NULL) {
        return 1;
    }

    Issue issue;

    int maxId = 0;

    while (fread(&issue, sizeof(Issue), 1, fp) == 1) {

        if (issue.issueId > maxId) {
            maxId = issue.issueId;
        }
    }

    fclose(fp);

    return maxId + 1;
}

