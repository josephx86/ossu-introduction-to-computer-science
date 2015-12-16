/**
 * Joseph Unworried
 * Problem Set 2: Caesar Cipher
 */
 
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
 
const int MOD = 26;
char encrypt_char(char plainChar, int k);
 
int main(int argc, string argv[])
{
    // There should be only one argument
    if (argc != 2)
    {
        printf("\nCorrect usage:\n\tcaesar k\nk - a non-negative integer\n\n");
        return 1;
    }
    
    // Argument must be a non-negative integer
    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("\nArgument must be a non-negative integer!\n\n");
        return 1;
    }
    else
    {
        k %= MOD;
    }
    
    // Get plaintext from user
    string plaintext = GetString();
    
    // Encrypt the plain text taking one char at a time
    int strLength = strlen(plaintext);
    for (int i = 0; i < strLength; i++)
    {
        char currentChar = plaintext[i];
        char newChar = encrypt_char(currentChar, k);
        printf("%c", newChar);
    }
    printf("\n");
    
    // Success
    return 0;
}

/*
 * 1. Get the ASCII code for the char, 
 * 2. Convert it to fit in the 1 - 26 range/scale for each alphabet character,
 * 3. Add constant k, but keep the result as mod 26.
 * 4. Then convert the result back to the ASCII scale.
 */
char encrypt_char(char plainChar, int k)
{
    char newChar = plainChar;
    int floor = 0;

    if ((plainChar >= 'a') && (plainChar <= 'z'))
    {
        floor = (int) 'a';
    }
    else if ((plainChar >= 'A') && (plainChar <= 'Z'))
    {
        floor = (int) 'A';
    }
         
    if (floor != 0)
    {
        int newCharCode = ((int) plainChar) - floor;
        newCharCode = (newCharCode + k) % MOD;
        newCharCode += floor;
        newChar = (char) newCharCode;
    }
    return newChar;
}
