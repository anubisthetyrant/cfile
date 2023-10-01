#include <stdio.h>
int p[10] = {0}, m = 0, x = 0, b[10] = {0}, a[10] = {0};
int main()
{
    int j = 0, n = 0, pra[10] = {0}, pro[10] = {0}, z[10], ch, flag, flag2, sum = 0, sum2 = 0;
    int c = 0, i = 0, k = 0;
    clrscr();

    printf("\n\t\tMEMORY MANAGEMENT POLICIES\n");
    printf("\n enter the no of process:\t");
    scanf("%d", &n);
    printf("\n enter the no of partition:\t");
    scanf("%d", &m);
    printf("\nprocess information\n");
    for (i = 0; i < n; i++)
    {
        printf("\n enter the memory required for process P%d:", i + 1);
        scanf("\t%d", &a[i]);
        pro[i] = a[i];
    }
    printf("\n memory partition information\n");
    for (j = 0; j < m; j++)
    {
        printf("\n enter the block size of block B%d:", j + 1);
        scanf("\t%d", &p[j]);
        pra[j] = p[j];
    }
    arrange();
    printf("\n process partition\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] < p[j])
            {
                printf("%d\t%d\n", a[i], p[j]);
                p[j] = 0;
                flag = i;
                break;
            }
        }
        if (flag != i)
            printf("%d\t%s\n", a[i], "waiting");
        arrange();
    }
    getch();
}
arrange()
{
    int i, j, t;
    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - i - 1; j++)
        {
            if (p[j] < p[j + 1])
            {
                t = p[j + 1];
                p[j + 1] = p[j];
                p[j] = t;
            }
        }
}