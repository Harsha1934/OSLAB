#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[20],bt[20],rt_bt[20],ct[20],tat[20],wt[20],rt[20];
    int pid[20];
    int completed=0,time=0,min_index;
    int visited[20]={0};

    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;

        printf("Enter arrival time of process %d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&bt[i]);

        rt_bt[i]=bt[i];
        rt[i]=-1;
    }

    while(completed<n)
    {
        int min_bt=999;

        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rt_bt[i]>0)
            {
                if(rt_bt[i] < min_bt)
                {
                    min_bt=rt_bt[i];
                    min_index=i;
                }
            }
        }

        if(min_bt==999)
        {
            time++;
        }
        else
        {
            if(rt[min_index]==-1)
                rt[min_index]=time-at[min_index];

            rt_bt[min_index]--;
            time++;

            if(rt_bt[min_index]==0)
            {
                completed++;
                ct[min_index]=time;

                tat[min_index]=ct[min_index]-at[min_index];
                wt[min_index]=tat[min_index]-bt[min_index];
            }
        }
    }

    printf("\npid\tat\tbt\tct\ttat\twt\trt\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}
