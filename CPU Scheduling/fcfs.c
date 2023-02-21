// C program for implementation of FCFS
// scheduling
#include <stdio.h>

void waitingTime(int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void turnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void avgTime(int at[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    waitingTime(n, bt, wt);
    turnAroundTime(n, bt, wt, tat);

    printf("Processes\tArival Time\tBurst time\tWaiting time\tTurn around time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", (i + 1), at[i], bt[i], wt[i], tat[i]);
    }
    int s = (float)total_wt / (float)n;
    int t = (float)total_tat / (float)n;
    printf("Average waiting time = %d", s);
    printf("\n");
    printf("Average turn around time = %d ", t);
}

int main()
{
    int at[] = {4, 2, 0, 1, 5};
    int bt[] = {10, 3, 5, 7, 2};

    for (int i = 0; i < sizeof at / sizeof at[0]; i++)
    {
        for (int j = 0; j < sizeof at / sizeof at[0]; j++)
        {
            if (at[i] < at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    int n = sizeof at / sizeof at[0];

    avgTime(at, n, bt);
    return 0;
}