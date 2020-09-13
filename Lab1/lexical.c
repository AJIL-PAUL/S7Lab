#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// global variables
char inputBuffer[100];
int id = 0, keyword = 1, op = 0;
char fid[10][10];
int key = 0;
int result = -1;
int op_result = -1;

void checkIfIdentifierPresence(char inputBuffer[])
{
    for (int i = 0; i < id; i++)
    {
        if (strcmp(inputBuffer, fid[i]) == 0)
        {
            result = i;
        }
    }
}
int iskeyword(char inputBuffer[])
{
    char keywrd[26][10] = {
        "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short",
        "sizeof", "static", "struct", "switch", "typedef",
        "void", "while"};

    int i, flag = 0;
    for (i = 0; i < 26; ++i)
    {
        if (strcmp(keywrd[i], inputBuffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void concatString(char c)
{
    inputBuffer[key++] = c;
}
int main()
{
    char v[20][20];
    char ch;
    char op[20];
    char bfr[20][20];
    int constant[20];
    int asciivalue[500] = {0};
    int number = 0;
    int i, j = -1, k = -1, l = -1, n = 0, q = 0;
    int pr[10] = {0}, m;
    int counter = 0;
    FILE *fp;
    fp = fopen("input.txt", "r");

    while ((ch = fgetc(fp)) != EOF)
    {
        asciivalue[counter] = (int)ch;
        counter++;
    }
    fclose(fp);
    fp = fopen("input.txt", "r");
    counter = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isdigit(ch))
        {
            while (isdigit(ch))
            {
                number = 10 * number + asciivalue[counter] - '0';
                ch = fgetc(fp);
                counter++;
            }
            j++;
            constant[j] = number;
            number = 0;
        }
        if (isalpha(ch))
        {
            while (isalpha(ch) || isdigit(ch) || ch == '_')
            {
                k++;
                v[m][k] = ch;
                ch = fgetc(fp);
                counter++;
            }
            m++;
            pr[n] = k;
            n++;
            k = -1;
        }
        if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '=' || ch == '^')
        {
            l++;
            op[l] = ch;
        }
        counter++;
    }
    printf("Generated tokens are:\n\n");
    for (i = 0; i <= j; i++)
    {
        printf("\t%d\t\tNumber\n", constant[i]);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j <= pr[i]; j++)
        {
            char temp = v[i][j];
            concatString(temp);
        }
        if (iskeyword(inputBuffer))
        {
            printf("\t%s\t\tKeyword\n", inputBuffer);
            keyword++;
        }
        else
        {
            if (id == 0)
            {
                strcpy(fid[0], inputBuffer);
                printf("\t%s\t\tIdentifier\n", inputBuffer);
                id++;
            }
            else
            {
                checkIfIdentifierPresence(inputBuffer);
                if (result == -1)
                {
                    printf("\t%s\t\tIdentifier\n", inputBuffer);
                    id++;
                }
                else
                {
                    printf("\t%s\t\tIdentifier\n", inputBuffer);
                    id++;
                }
            }
        }
        memset(inputBuffer, 0, 100);
        key = 0;
    }
    fclose(fp);
    return 0;
}