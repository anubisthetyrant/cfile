#include <stdio.h>
char state[10], self[10], spoon[10];
void test(int k)
{
    if ((state[(k + 4) % 5] != 'e') && (state[k] == 'h') && (state[(k + 1) % 5] != 'e'))
    {
        state[k] = 'e';
        self[k] = 's';
        spoon[k] = 'n';
        spoon[(k + 4) % 5] = 'n';
    }
}
void pickup(int i)
{
    state[i] = 'h';
    test(i);
    if (state[i] == 'h')
    {
        self[i] = 'w';
    }
}
void putdown(int i)
{
    state[i] = 't';
    spoon[i] = 's';
    spoon[i - 1] = 's';
    test((i + 4) % 5);
    test((i + 1) % 5);
}
int main()
{
    
    int ch, a, n, i;
    clrscr();

    printf("\t\t Dining Philosopher Problem\n");
    for (i = 0; i < 5; i++)
    {
        state[i] = 't';
        self[i] = 's';
        spoon[i] = 's';
    }
    printf("\t\t Initial State of Each Philosopher\n");
    printf("\n\t Philosopher No.\t Think/Eat \tStatus \tspoon");
    for (i = 0; i < 5; i++)
    {
        printf("\n\t\t %d\t\t%c\t\t%c\t%c\n", i + 1, state[i], self[i], spoon[i]);
    }
    printf("\n 1.Exit \n 2.Hungry\n3.Thinking\n");
    printf("\n Enter your choice\n");
    printf("\t\t");
    scanf("%d", &ch);
    while (ch != 1)
    {
        switch (ch)
        {
        case 2:
        {
            printf("\n\t Enter which philosopher is hungry\n");
            printf("\t\t");
            scanf("%d", &n);
            n = n - 1;
            pickup(n);
            break;
        }
        case 3:
        {
            printf("\n\t Enter which philosopher is thinking\n");
            printf("\t\t");
            scanf("%d", &n);
            n = n - 1;
            putdown(n);
            break;
        }
        }
        printf("\n\t State of Each philosopher\n\n");
        printf("\n\t Philosoper No.\t Thinking\t Hungry");

        for (i = 0; i < 5; i++)
        {
            printf("\n\t\t %d\t\t%c\t\t%c\t%c\n", i + 1, state[i], self[i], spoon[i]);
        }
        printf("\n 1.Exit\n 2.Hungry\n 3.Thinking\n");
        printf("\n Enter your choice\n");
        printf("\t\t");
        scanf("%d", &ch);
    }
    getch();
}