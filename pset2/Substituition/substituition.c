
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const int N = 26;
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("CHECAR ARGUMENTO DE COMANDO.\n");
        return 1;
    }
        int letters[N];
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!((argv[1][i] >= 'a' && argv[1][i] <= 'z') || 
                  (argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
            {
                printf("DEVE CONTER SOMENTE LETRAS.\n");
                return 2;
            }
            else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                argv[1][i] = toupper(argv[1][i]);
            }
            for (int j = 0; j < N; j++)
            {
                if (argv[1][i] == letters[j])
                {
                    printf("NÃO REPETIR LETRAS.\n");
                    return 3;
                }
            }

        string plaintext = get_string("TEXTO SIMPLES: ");
        int l = strlen(plaintext);
        char ciphertext[l + 1];
        {
            if (isupper(plaintext[i]) != 0)
            {
                for (int j = 0; j < N; j++)
                {
                    if (plaintext[i] == alphabet[j])
                    {
                        ciphertext[i] = argv[1][j];
                        break;
                    }
                }
            }
            else if (islower(plaintext[i]) != 0)
            {
                for (int j = 0; j < strlen(alphabet); j++)
                {
                    if (plaintext[i] == tolower(alphabet[j]))
                    {
                        ciphertext[i] = tolower(argv[1][j]);
                        break;
                    }
                }
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        ciphertext[l] = '\0';
        
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}
