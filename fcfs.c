
#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[20],bt[20],ct[20],tat[20],wt[20],rt[20],pid[20];

    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;
        printf("Enter arrival time of process %d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[i] > at[j])
            {
                int temp;

                temp=at[i]; at[i]=at[j]; at[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=pid[i]; pid[i]=pid[j]; pid[j]=temp;
            }
        }
    }
    ct[0] = at[0] + bt[0];

    for(int i=1;i<n;i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];
    }

    printf("\npid\tat\tbt\tct\ttat\twt\trt\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}
