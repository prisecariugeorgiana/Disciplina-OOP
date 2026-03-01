#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int my_atoi(char s[])
{
    int i = 0;
    int nr = 0;

    while (s[i] != '\0' && s[i] != '\n') 
    {
        nr = nr * 10 + (s[i] - '0');
        i++;
    }

    return nr;
}

int main()
{
    FILE* f = fopen("in.txt", "r");
    char linie[100];
    int S = 0;

    if (f == NULL) 
    {
        printf("Fisierul nu exista\n");
        return 1;
    }

    while (fgets(linie, 100, f) != NULL) 
    {
        S = S + my_atoi(linie);
    }

    fclose(f);

    printf("Suma este: %d", S);

    return 0;
}

