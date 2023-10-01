#include <stdio.h>
int main()
{
    int n, j, i, size[10], sub[10], f[10], m, x, ch, t;
    int cho;
    clrscr();

    printf("\t\t MEMORY MANAGEMENT \n");
    printf("\t\t =================\n");
    printf("\tENTER THE TOTAL NO OF blocks : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\n Enter the size of blocks : ");
        scanf("%d", &size[i]);
    }
    cho = 0;
    while (cho == 0)
    {
        printf("\n Enter the size of the file : ");
        scanf("%d", &m);
        for (i = 1; i <= n; i++)
        {
            sub[i] = size[i];
            f[i] = i;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++) if (sub[i] > sub[j])
            {
                t = sub[i];
                sub[i] = sub[j];
                sub[j] = t;
                t = f[i];
                f[i] = f[j];
                f[j] = t;
            }
        }
        for (i = 1; i <= n; i++)
        {
            if (size[f[i]] >= m)
            {
                printf("size can occupy %d : ", size[f[i]]);
                size[f[i]] -= m;
                x = i;
                break;
            }
        }
        if (x == 0)
        {
            printf("block can't occupy");
        }
        printf("\n\nSNO\t\t Available Block size\n");
        for (i = 1; i <= n; i++)
            printf("\n%d\t\t%d", i, size[i]);
        printf("\n\n Do u want to continue.....(0-->yes\t/1-->no)");
        scanf("%d", &cho);
        
        }
        getch();
}