
/* =========================
   CASE-INSENSITIVE SEARCH
   ========================= */
#include"header.h"
void toLowerString(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = (char)tolower((unsigned char)src[i]);
    }

    dest[i] = '\0';
}


int containsIgnoreCase(const char *text, const char *pattern)
{
    char lowerText[500];
    char lowerPattern[500];

    toLowerString(lowerText, text);
    toLowerString(lowerPattern, pattern);

    return strstr(lowerText, lowerPattern) != NULL;
}

