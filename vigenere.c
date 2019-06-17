#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } 

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i])) //check if keyword's letters are alphabets
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }    
    }
    
    //prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++) //iterate over the length of plaintext
    {   
        char letter = plaintext[i];
        int len = strlen(argv[1]);
        int key = argv[1][j % len]; //apply jth letter of the key to the next plaintext[i]
        
        if (isupper(key)) // treat A or a as 0, Z or z as 25
        {
           key -= 65; 
        }
        else if (islower(key))
        {
           key -= 97;
        }
        if (isupper(letter)) //preserve uppercases of the letter (plaintext[i])
        {
            printf("%c", (((letter + key) - 65) % 26) + 65);
            j++;
        }
        else if (islower(letter)) //same but lowercases
        {
            printf("%c", (((letter + key) - 97) % 26) + 97);
            j++;
        }    
        else
        {
            printf("%c", plaintext[i]); 
        }
    }
    
    printf("\n");
    return 0;
}
