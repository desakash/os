#include <stdio.h>
#define MAX_PAGES 100
#define MAX_REFERENCES 1000

int main()
{
    int pages[MAX_PAGES], references[MAX_REFERENCES];
    int page_faults = 0, num_pages, num_references;

    // Input number of pages and pages
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the pages: ");
    for (int i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }

    // Input number of references and reference string
    printf("Enter the number of references: ");
    scanf("%d", &num_references);

    printf("Enter the reference string: ");
    for (int i = 0; i < num_references; i++)
    {
        scanf("%d", &references[i]);
    }

    int page_index[MAX_PAGES];
    for (int i = 0; i < num_pages; i++)
    {
        page_index[i] = -1;
    }

    for (int i = 0; i < num_references; i++)
    {
        int page = references[i];
        int found = 0;

        // Check if page is in memory
        for (int j = 0; j < num_pages; j++)
        {
            if (page == pages[j])
            {
                found = 1;
                page_index[j] = i;
                break;
            }
        }

        // If page is not in memory, replace page with the one that has the latest next reference
        if (!found)
        {
            int farthest = 0;
            for (int j = 0; j < num_pages; j++)
            {
                if (page_index[j] == -1)
                {
                    farthest = j;
                    break;
                }
                if (page_index[j] > page_index[farthest])
                {
                    farthest = j;
                }
            }
            pages[farthest] = page;
            page_index[farthest] = i;
            page_faults++;
        }
    }

    printf("Page faults: %d\n", page_faults);

    return 0;
}
