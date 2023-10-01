#include <stdio.h>
int main()
{
    int main_mem, cur = 0, i = 0, j, fault = 0;
    static int page[100], page_mem[100], flag, num;
    for (i = 0; i < 100; i++)
        page_mem[i] = -2;
    clrscr();

    printf("\n\t\t\t\t paging->fifo\n");
    printf("\n\n Enter the number of pages in main memory ");
    scanf("%d", &main_mem);
    printf("\n enter no of page references");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("\n Enter page reference:");
        scanf("%d", &page[i]);
    }
    printf("\n\t\t\t\t Fifo-> paging \n\n\n");
    for (i = 0; i < main_mem; i++)
        printf("\t page %d", i + 1);
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < main_mem; j++)
            if (page[i] == page_mem[j])
            {
                flag = 1;
                break;
            }

        if (!flag)
        {
            page_mem[cur] = page[i];
            fault++;
        }
        printf("\n\n");
        for (j = 0; j < main_mem; j++)
            printf("\t%d", page_mem[j]);
        if (!flag && cur < main_mem - 1)
            cur++;
        else if (!flag)
            cur = 0;
        flag = 0;
    }
    printf("\n\n-2 refers to empty blocks\n\n");
    printf("\n\n No of page faults:%d\n", fault);

    getch();
}