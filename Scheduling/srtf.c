#include <stdio.h>
#include <limits.h>

struct Process {
    int id, at, bt, rem, ct, wt, tat, done;
};

int main() {
    int n, completed = 0, time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rem = p[i].bt;
        p[i].done = 0;
    }

    while (completed < n) {
        int idx = -1, min_rem = INT_MAX;
        for (int i = 0; i < n; i++)
            if (!p[i].done && p[i].at <= time && p[i].rem < min_rem) {
                min_rem = p[i].rem;
                idx = i;
            }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].rem--;
        time++;

        if (p[idx].rem == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            avg_wt += p[idx].wt;
            avg_tat += p[idx].tat;
            p[idx].done = 1;
            completed++;

            printf("\nP%d finished:\n", p[idx].id);
            printf("  AT=%d BT=%d CT=%d WT=%d TAT=%d\n",
                   p[idx].at, p[idx].bt, p[idx].ct, p[idx].wt, p[idx].tat);
        }
    }

    printf("\nAverage WT = %.2f\nAverage TAT = %.2f\n", avg_wt / n, avg_tat / n);
    return 0;
}