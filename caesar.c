#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    //validating inputs
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }
    //convert string to int
    int key = atoi(argv[1]);
    
    if (key < 1) // validating key
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //prompt user for plaintext
        string plaintext = get_string("Enter plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++) //iterate over the length of plaintext
        {   
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }    
            else
            {
                printf("%c", plaintext[i]); 
            }
        }
    }
    printf("\n");
    return 0;
}
