#include <limits.h>
void optimal(int pages[], int n, int capacity)
{
    int frames[capacity], faults = 0;
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;
    printf("\nOptimal Page Replacement\n");
    for (int i = 0; i < n; i++)
        {
        int found = 0;
        for (int j = 0; j < capacity; j++)
        {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int opt_index = -1;
            int farthest = i;
            for (int j = 0; j < capacity; j++)
            {
                if (frames[j] == -1)
                {
                    opt_index = j;
                    break;
                }
                int next_use = INT_MAX;
                for (int k = i + 1; k < n; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        next_use = k;
                        break;
                    }
                }
                if (next_use > farthest)
                {
                    farthest = next_use;
                    opt_index = j;
                }
            }
            frames[opt_index] = pages[i];
            faults++;
        }
        printf("Frames: ");
        for (int j = 0; j < capacity; j++)
        {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
}
