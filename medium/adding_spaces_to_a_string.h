#include "./../cimports.h"

char* addSpaces(char* s, int* spaces, int spacesSize)
{
    int i = strlen(s) - 1,
        j = spacesSize - 1;
    s = (char*) realloc(s, (strlen(s) + spacesSize));
    s[i + 1] = '\0';
    while (j > -1)
    {
        if (i == (spaces[j] - 1))
        {
            s[i + j + 1] = ' ';
            --j;
        }
        else
        {
            s[i + j + 1] = s[i];
            --i;
        }
    }
    return s;
}