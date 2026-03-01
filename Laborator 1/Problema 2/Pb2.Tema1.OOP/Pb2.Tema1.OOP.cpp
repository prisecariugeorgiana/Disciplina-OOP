#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

    char text[200];
    char words[50][50];
    int n = 0;
    int i, j;

    printf("Introduceti propozitia:\n");
    fgets(text, sizeof(text), stdin);

    int k = 0;
    for (i = 0; text[i] != '\0'; i++) 
    {

        if (text[i] != ' ' && text[i] != '\n')
        {
            words[n][k] = text[i];
            k++;
        }
        else {
            if (k > 0)
            {
                words[n][k] = '\0';
                n++;
                k = 0;
            }
        }
    }

    if (k > 0) {
        words[n][k] = '\0';
        n++;
    }

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (strlen(words[i]) < strlen(words[j])) 
            {

                char temp[50];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {

            if (strlen(words[i]) == strlen(words[j]))
            {

                if (strcmp(words[i], words[j]) > 0) 
                {

                    char temp[50];
                    strcpy(temp, words[i]);
                    strcpy(words[i], words[j]);
                    strcpy(words[j], temp);
                }
            }
        }
    }

    printf("\nRezultat:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}
