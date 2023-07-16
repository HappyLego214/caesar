#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string encrypt(string input, int key);

int main(int argCount, string key[])
{

    // printf("Check-1: %s\n", key[1]);
    // printf("Check-2: %i\n", isdigit(key[1][0]));

    if (argCount != 2 || isdigit(key[1][0]) == 0)
    {
        printf("Usage: ./caesar key\n");
    } else {
        string text = get_string("Enter Text: ");
        printf("Message: %s\n", encrypt(text, key[1][0]));
    }
}

string encrypt(string input, int key)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (islower(input[i]) != 0)
        {
            input[i] = (((input[i] - 97) + key) % 26) + 97;
        } 
        else if (isupper(input[i]) != 0)
        {
            input[i] = (((input[i] - 65) + key) % 26) + 65;
        } 
        else
        {
            input[i] = input[i];
        }
    }
    return input;
}