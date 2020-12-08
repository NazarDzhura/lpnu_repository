#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include <cstdlib>
#define  ARRLENGTH 9      
#define  ARRWIDTH ARRLENGTH


int func1(int i, int j, int k)
{
    int a = i - j;
    return a;
}
int func2(int i, int j, int k)
{
    int a = i + j + 1;
    return a;
}

void main(void)
{
    int dates[ARRLENGTH][ARRWIDTH];
    int i;
    int j;
    int a;
    int b;
    int k = 1;
    for (j = 0; j < ARRWIDTH; j++)
    {
        for (i = 0; i < ARRLENGTH; i++)
        {
            a = func1(i, j, k);
            b = func2(i, j, k);
            if ((a > 0 && b < ARRLENGTH) || (a < 0 && b > ARRLENGTH))
            {
                dates[i][j] = k;
                k++;
            }

            else dates[i][j] = 0;
        }
    }
    for (i = 0; i < ARRLENGTH; i++)
    {
        for (j = 0; j < ARRWIDTH; j++)
        {
            printf("%3i ", dates[i][j]);
        }
        printf("\n\n");
    }
    //git hub comment
    system("pause");
}