#include <stdio.h>
#include <stdlib.h>
#define max 100
int frame[10], count[10], cstr[max], tot, nof, fault;
int main()
{   
    clrscr();

    getdata();
    push();
    getch();
}
int getdata()
{
    int pno, i = 0;
    printf("\n\t\tL R U - Page Replacement Algorithm\n");
    printf("\nEnter No. of Pages in main memory:");
    scanf("%d", &nof);
    printf("\nEnter the no of page references:\n");
    scanf("%d", &pno);
    for (i = 0; i < pno; i++)
    {
        printf("Enter page reference%d:", i);
        scanf("%d", &cstr[i]);
    }
    tot = i;
    for (i = 0; i < nof; i++)
        printf("\tpage%d\t", i);
}
int push()
{
    int x, i, j, k, flag = 0, fault = 0, nc = 0, mark = 0, maximum, maxpos = -1;
    for (i = 0; i < nof; i++)
    {
        frame[i] = -1;
        count[i] = mark--;
    }
    for (i = 0; i < tot; i++)
    {
        flag = 0;
        x = cstr[i];
        nc++;
        for (j = 0; j < nof; j++)
        {
            for (k = 0; k < nof; k++)

                count[k]++;
            if (frame[j] == x)
            {
                flag = 1;
                count[j] = 1;
                break;
            }
        }
        if (flag == 0)
        {
            maximum = 0;
            for (k = 0; k < nof; k++)
            {
                if (count[k] > maximum && nc > nof)
                {
                    maximum = count[k];
                    maxpos = k;
                }
            }
            if (nc > nof)
            {
                frame[maxpos] = x;
                count[maxpos] = 1;
            }
            else
                frame[nc - 1] = x;
            fault++;
            dis();
        }
    }
    printf("\nTotal Page Faults :%d", fault);
}
int dis()
{
    int i = 0;
    printf("\n\n");
    while (i < nof)
    {
        printf("\t%d\t", frame[i]);
        i++;
    }
}