// write bankers algorithm in C which accepts allocated and max vectors for 3 different resources for 5 processes from p0 to p4.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k, n, m, x, y, z, flag = 0, count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int available[m], work[m], finish[n], safe[n];
    int max[n][m], allocated[n][m], need[n][m];

    printf("Enter the total resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);

    printf("Enter the allocated resources for each process: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocated[i][j]);

    printf("Enter the max resources for each process: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocated[i][j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    for (i = 0; i < m; i++)
    {
        x = 0;
        for (j = 0; j < n; j++)
            x += allocated[j][i];
        work[i] = available[i] - x;
    }

    while (count < n)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m)
                {
                    for (k = 0; k < m; k++)
                        work[k] += allocated[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            printf("The system is not in safe state. Deadlock may occur. ");
            exit(0);
        }
    }

    printf("The system is in safe state. Safe sequence is: ");
    for (i = 0; i < n; i++)
        printf("p%d ", safe[i]);
    return 0;
}
