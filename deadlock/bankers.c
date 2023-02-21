#include <stdio.h>
#include <stdlib.h>

int main()
{

    int resources, processes;
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    int available[resources], work[resources], finish[processes], safe[processes];
    int max[processes][resources], allocated[processes][resources], need[processes][resources];

    printf("Enter the total resources: ");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    printf("Enter the allocated resources for each process: ");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocated[i][j]);

    printf("Enter the max resources for each process: ");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = max[i][j] - allocated[i][j];

    for (int i = 0; i < processes; i++)
        finish[i] = 0;

    for (int i = 0; i < resources; i++)
    {
        int x = 0;
        for (int j = 0; j < processes; j++)
            x += allocated[j][i];
        work[i] = available[i] - x;
    }

    int count = 0;
    while (count < processes)
    {
        int flag = 0;
        for (int i = 0; i < processes; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < resources; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == resources)
                {
                    for (int k = 0; k < resources; k++)
                        work[k] += allocated[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            printf("System is not in safe state\n]n");
            return 0;
        }
    }

    printf("System is in safe state\n\n");
    printf("Safe sequence is: ");
    for (int i = 0; i < processes; i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return 0;
}