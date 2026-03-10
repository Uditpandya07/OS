#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process {
    int pid;         
    int at;          
    int bt;          
    int priority;    
    int ct;          
    int wt;          
    int tat;         
    int completed;   
};

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("\nEnter Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].completed = 0;
    }

    int completed_count = 0;
    int current_time = 0;

    printf("\n=== PRIORITY SCHEDULING (Variable Arrival) ===\n");

    while (completed_count < n) {
        int selected = -1;
        int highest_priority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= current_time) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    selected = i;
                }
                else if (p[i].priority == highest_priority && p[i].at < p[selected].at) {
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            int next_arrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!p[i].completed && p[i].at < next_arrival) {
                    next_arrival = p[i].at;
                }
            }
            current_time = next_arrival;
            continue;
        }

        p[selected].ct = current_time + p[selected].bt;
        p[selected].tat = p[selected].ct - p[selected].at;
        p[selected].wt = p[selected].tat - p[selected].bt;

        avg_wt += p[selected].wt;
        avg_tat += p[selected].tat;

        p[selected].completed = 1;
        completed_count++;

        printf("\nProcess P%d finished:", p[selected].pid);
        printf("\n  Arrival Time: %d", p[selected].at);
        printf("\n  Burst Time: %d", p[selected].bt);
        printf("\n  Priority: %d", p[selected].priority);
        printf("\n  Completion Time: %d", p[selected].ct);
        printf("\n  Waiting Time: %d", p[selected].wt);
        printf("\n  Turnaround Time: %d\n", p[selected].tat);

        current_time = p[selected].ct;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}