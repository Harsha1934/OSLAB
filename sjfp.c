
#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[20],bt[20],ct[20],tat[20],wt[20],rt[20];
    int done[20]={0};
    int pid[20];

    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;

        printf("Enter arrival time of process %d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&bt[i]);
    }

    int completed=0,time=0,min_index;

    while(completed<n)
    {
        int min_bt=999;

        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0)
            {
                if(bt[i]<min_bt)
                {
                    min_bt=bt[i];
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
            ct[min_index]=time+bt[min_index];
            time=ct[min_index];

            tat[min_index]=ct[min_index]-at[min_index];
            wt[min_index]=tat[min_index]-bt[min_index];
            rt[min_index]=wt[min_index];

            done[min_index]=1;
            completed++;
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
