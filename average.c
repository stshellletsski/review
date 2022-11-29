// to be used with results.txt
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
float avarageuser(int user[], int n);
float avaragesys(int sys[], int n);
int main(void)
{
    int n = 9;
    int buffer[n * 3];
    int user[n];
    int sys[n];
    char c;
    // Why this array needs to be 4 element
    char value[4];
    FILE * fpointer = fopen("results.txt", "r");
    int x = 0;
    int y = 0;
    int z = 0;
    while (fread(&c, sizeof(char), 1, fpointer))
    {
        if (isdigit(c))
        {
            value[x] = c;
            x++;
            if (x == 5)
            {
                // in order to value be 5 chars?
                printf("%s\n", value);
                buffer[y] = atoi(value);
                x = 0;
                y++;
            }
        }
    }
    fclose(fpointer);
    for (int i = 1, j = 0; i < 27; i = i + 3, j++)
    {
        user[j] = buffer[i];
        sys[j] = buffer[i + 1];
    }
    float auser = avarageuser(user, n);
    float asys = avaragesys(sys, n);
    printf("user: %.1f\nsys: %.1f\n", auser, asys);
}
float avarageuser(int user[], int n)
{
    int sum = 0, i;
    float avarage;
    for (i = 0; i < n; i++)
    {
        sum = sum + user[i];
    }
    avarage = (float)sum / n;
    return avarage;
}

float avaragesys(int sys[], int n)
{
    int sum = 0, i;
    float avarage;
    for (i = 0; i < n; i++)
    {
        sum = sum + sys[i];
    }
    avarage = (float)sum / n;
    return avarage;
}
