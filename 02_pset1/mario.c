/**
* Joseph Unworried
* Problem Set 1: Mario
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get height from user
    int height = -1;
    do
    {
        printf("Height: ");
        height = GetInt();
    } while ((height > 23) || (height < 0));
    
    // Draw the half-pyramid
    int maxCount = height + 1;
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < maxCount; column++)
        {
            int limit = maxCount - (row + 2);
            char block = (column >= limit) ? '#' : ' ';
            printf("%c", block);
        }
        printf("\n");
    }
}
