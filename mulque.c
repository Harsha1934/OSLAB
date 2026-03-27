
#include <stdio.h>

int main() {
    int i;
    int sys_n, user_n;

    int sys_bt[20], sys_wt[20], sys_tat[20];
    int user_bt[20], user_wt[20], user_tat[20];

    printf("Enter number of system processes: ");
    scanf("%d", &sys_n);

    for(i = 0; i < sys_n; i++) {
        printf("Enter system burst time: ");
        scanf("%d", &sys_bt[i]);
    }
    printf("\nEnter number of user processes: ");
    scanf("%d", &user_n);

    for(i = 0; i < user_n; i++) {
        printf("Enter user burst time: ");
        scanf("%d", &user_bt[i]);
    }

    sys_wt[0] = 0;
    for(i = 1; i < sys_n; i++)
        sys_wt[i] = sys_wt[i-1] + sys_bt[i-1];

    for(i = 0; i < sys_n; i++)
        sys_tat[i] = sys_wt[i] + sys_bt[i];

    user_wt[0] = sys_tat[sys_n - 1];

    for(i = 1; i < user_n; i++)
        user_wt[i] = user_wt[i-1] + user_bt[i-1];

    for(i = 0; i < user_n; i++)
        user_tat[i] = user_wt[i] + user_bt[i];

    printf("\nSystem Processes:\n");
    for(i = 0; i < sys_n; i++)
        printf("S%d  BT=%d  WT=%d  TAT=%d\n", i+1, sys_bt[i], sys_wt[i], sys_tat[i]);

    printf("\nUser Processes:\n");
    for(i = 0; i < user_n; i++)
        printf("U%d  BT=%d  WT=%d  TAT=%d\n", i+1, user_bt[i], user_wt[i], user_tat[i]);

    return 0;
}
