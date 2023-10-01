#include <stdio.h>
#include <string.h>
int main()
{
    int n, j, i, size[10], sub[10], f[10], m, x, ch, t;
    int cho;
    clrscr();

    printf("\t\t MEMORY MANAGEMENT \n");
    printf("\t\t =================\n");
    printf("\tEnter the total no of blocks: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\n Enter the size of blocks: ");
        scanf("%d", &size[i]);
    }
    cho = 0;
    while (cho == 0)
    {
        printf("\n Enter the size of the file: ");
        scanf("%d", &m);
        x = 0;
        for (i = 1; i <= n; i++)
        {
            if (size[i] >= m)
            {
                printf("\n size can occupy %d", size[i]);
                size[i] -= m;
                x = i;
                break;
            }
        }
        if (x == 0)
        {
            printf("\n\nBlock can't occupy\n\n");
        }
        printf("\n\nSNO\t\tAvailable block list\n");
        for (i = 1; i <= n; i++)
            printf("\n\n%d\t\t\t%d", i, size[i]);
        printf("\n\n Do u want to continue.....(0-->yes/1-->no): ");
        scanf("%d", &cho);
    }
    getch();
}