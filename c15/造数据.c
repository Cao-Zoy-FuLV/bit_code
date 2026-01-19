//
// Created by Administrator on 2026/1/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

int 造数据()
{
    int n = 1000000;
    srand(time(0));
    const char* file = "data.txt";
    FILE* fp = fopen(file, "w");
    if (fp == NULL)
    {
        printf("open file error\n");
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        int x = (rand()+i)%1000000;
        fprintf(fp, "%d\n", x);
    }
    fclose(fp);
}


int main()
{
    造数据();
    return 0;
}
