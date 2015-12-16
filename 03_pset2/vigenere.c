/**
 * Joseph Unworried
 * Problem Set 2: Vigenere Cipher
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
const int MOD = 26;
char caesar(char, int);
bool is_letter(char);
 
int main(int argc, string argv[])
{
    // There should be only one argument
    if (argc != 2)
    {
        printf("\nCorrect usage:\n\tvigenere k\n");
        printf("k - a string with a-zA-Z characters only\n\n");
        return 1;
    }
    
    // Argument must be a string with a-zA-Z only.
    string key = argv[1];
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        char currentChar = key[i];
        bool isLetter = is_letter(currentChar);
        if (!isLetter)
        {
            printf("\nArgument must have characters a-zA-Z only!\n\n");
            return 1;
        }
    }
         
    // Get plaintext from user
    string plaintext = GetString();
    
    // Encrypt the plain text taking one char at a time
    int strLength = strlen(plaintext);
    int keyLength = strlen(key);
    int kCount = 0;
    for (int i = 0; i < strLength; i++)
    {
        char currentChar = plaintext[i];
        char newChar = currentChar;
        bool isLetter = is_letter(currentChar);
        if (isLetter)
        {
            // Encrypt char
            int kIndex = kCount % keyLength;
            kCount++;
            unsigned char k = tolower((unsigned char) key[kIndex]);
            int kCode = ((int) k) - ((int) 'a');
            newChar = caesar(currentChar, kCode);
        }
        
        printf("%c", newChar);
    }
    printf("\n");
    
    // Success
    return 0;
}

/*
 * Checks if 'c' is a-z A-Z
 */
bool is_letter(char character)
{
    bool isLowerCase = (character >= 'a') && (character <= 'z');
    bool isUpperCase = (character >= 'A') && (character <= 'Z');
    return (isLowerCase || isUpperCase);
}

/*
 * Caesar cipher used by the Vigenere cipher
 * 1. Get the ASCII code for the char, 
 * 2. Convert it to fit in the 1 - 26 range/scale for each alphabet character,
 * 3. Add constant k, but keep the result as mod 26.
 * 4. Then convert the result back to the ASCII scale.
 */
char caesar(char plainChar, int k)
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
