#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;         
    int bt;          
    int priority;    
    int wt;          
    int tat;         
};

int main(){
    int n;
    float avg_wt=0;
    float avg_tat=0;

    printf("Enter the number of processes:");
    scanf("%d",&n);

    struct Process p[n];
     printf("\nEnter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process P%d: ", p[i].pid);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }
       for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

       printf("\nPriority Scheduling Results-\n");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;

        printf("\nProcess P%d:", p[i].pid);
        printf("\n  Burst Time: %d", p[i].bt);
        printf("\n  Priority: %d", p[i].priority);
        printf("\n  Waiting Time: %d", p[i].wt);
        printf("\n  Turnaround Time: %d\n", p[i].tat);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}