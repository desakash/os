// write round robin algorithm

#include <stdio.h>

int main()
{
    int at[] = {4, 2, 0, 1, 5};
    int bt[] = {10, 3, 5, 7, 2};
    int n = sizeof at / sizeof at[0];
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int quantum = 2;
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
    printf("Processes\tArival Time\tBurst time\tWaiting time\tTurn around time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", (i + 1), at[i], bt[i], wt[i], tat[i]);
    }
    int s = (float)total_wt / (float)n;
    t = (float)total_tat / (float)n;
    printf("Average waiting time = %d", s);
    printf("\n");
    printf("Average turn around time = %d ", t);
}