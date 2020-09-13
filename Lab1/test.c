#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *fp1, *fp2;
int pos = 0;
int check(char output[25])
{
    char symbol[20], token[20];

    fseek(fp1, 0, SEEK_SET);
    do
    {
        if (feof(fp2))
        {
            return 0;
        }
        fscanf(fp2, "%s %s", symbol, token);
        if (strcmp(output, symbol) == 0)
        {
            if (strcmp(token, "id"))
            {
                printf("%s identifier %d", symbol, pos);
            }
            else
            {
                printf(" %s %s", symbol, token);
            }
            return 1;
        }
        pos++;
    } while (1);
}
void clear(char output[25])
{
    for (int k = 0; k < strlen(output); k++)
    {
        output[k] = 0;
    }
}

int main()
{
    int state = 0, i = 0, j = 0;

    char ch, output[25];
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("symbol_table.txt", "r+");
    do
    {
        if (feof(fp1))
        {
            break;
        }
        ch = fgetc(fp1);
        switch (state)
        {
        case 0:
            if (isalpha(ch))
            {
                state = 1;
                output[i++] = ch;
            }
            else if (isdigit(ch))
            {
                state = 3;
                output[i++] = ch;
            }
            break;
        case 1:
            if (isalnum(ch) || isdigit(ch))
            {
                state = 1;
                output[i++] = ch;
            }
            else
            {
                state = 2;
            }
            break;
        case 2:
            output[i] = '\0';
            j = check(output);
            if (j == 0)
            {
                fprintf(fp2, "%s id", output);
                printf("%s id %d", output, pos);
            }
            if (ch == '=')
            {
                printf("%c assign", ch);
            }
            clear(output);
            state = 0;
            pos = 0;
            i = 0;
            break;
        case 3:
            if (isdigit(ch))
            {
                state = 3;
                output[i++] = ch;
            }
            else if (isalpha(ch))
            {
                printf("Error");
                clear(output);
                state = 0;
                pos = 0;
                i = 0;
            }
            else
            {
                state = 4;
            }
            break;
        case 4:
            output[i] = '\0';
            printf("%s Number", output);
            clear(output);
            state = 0;
            pos = 0;
            i = 0;
        }
        break;
        {
        }
    } while (1);
    return 0;
}