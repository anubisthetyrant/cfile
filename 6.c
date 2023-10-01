#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, z;
    int res[10];
    int resource, process, boolean = 0;
    int
        allocation[10][10],
        sel[10], max[10][10], need[10][10], work[10], work1[10];
    int check = 0;
    int adpro;
    int ar[10];
    clrscr();

    printf("Welcome to Bankers Algorithms");
    printf("\n Enter the no .of processes:");
    scanf("%d", &process);
    printf("\n Enter the number of Resources");
    scanf("%d", &resource);
    for (i = 0; i < resource; i++)
    {
        printf("Enter the instances of Resource %d:", i + 1);
        scanf("%d", &res[i]);
    }
    for (i = 0; i < process; i++)
    {
        printf("\n Enter allocated resources for process %d:", i + 1);
        for (j = 0; j < resource; j++)
        {
            printf("\n Resource %d:", j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }
    for (i = 0; i < 10; i++)
        sel[i] = -1;
    for (i = 0; i < process; i++)
    {
        printf("Enter maximum need of process: %d", i + 1);
        for (j = 0; j < resource; j++)
        {
            printf("\n Resource %d:", j + 1);
            scanf("%d", &max[i][j]);
        }
    }
    for (i = 0; i < process; i++)
        for (j = 0; j < resource; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    printf("\n The Need is \n");
    for (i = 0; i < process; i++)
    {
        for (j = 0; j < resource; j++)
            printf("\t%d", need[i][j]);
        printf("\n");
    }
    printf("\n The Avalilable is ");
    for (i = 0; i < resource; i++)
    {
        work[i] = 0;
        for (j = 0; j < process; j++)
            work[i] = work[i] + allocation[j][i];
        work[i] = res[i] - work[i];
    }
    for (z = 0; z < process; z++)
    {
        for (i = 0; i < process; i++)
        {
            for (j = 0; j < resource; j++)
            {
                if (work[j] >= need[i][j] && sel[i] == -1)
                {
                    boolean = 1;
                }
                else
                {
                    boolean = 0;
                    break;
                }
            }
            if (boolean == 1)
            {
                sel[i] = 1;
                for (j = 0; j < resource; j++)
                {
                    work[j] = work[j] + allocation[i][j];
                }
            }
        }
    }
    if (check == 1)
        printf("\n System is in Unsafe mode");
    else
        printf("\n System is in safe mode");
    getch();
}