/**
 * Joseph Unworried
 * Problem Set 2: Initials
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(void)
{
    string fullname = GetString();
    int maxIndex = strlen(fullname) - 1;
    bool isFirst = false;
    for (int i = 0; i <= maxIndex; i++)
    {
        unsigned char currentChar = (unsigned char) fullname[i];
        if ((i == 0) || (isFirst))
        {
            printf("%c", toupper(currentChar));
        }
        
        isFirst = (currentChar == ' ');
    }
    printf("\n");
}
