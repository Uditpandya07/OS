#include <stdio.h>
#include <limits.h>

struct Process {
    int id, at, bt, rem, ct, wt, tat;
};

int main() {
    int n, quantum, completed = 0, time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    struct Process p[n];
    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rem = p[i].bt;
    }

    int queue[100], front = 0, rear = -1, qsize = 0;
    int in_queue[100] = {0};

    while (completed < n) {
        for (int i = 0; i < n; i++)
            if (p[i].at <= time && p[i].rem > 0 && !in_queue[i]) {
                rear = (rear + 1) % n;
                queue[rear] = i;
                in_queue[i] = 1;
                qsize++;
            }

        if (qsize == 0) {
            int next = INT_MAX;
            for (int i = 0; i < n; i++)
                if (p[i].rem > 0 && p[i].at < next) next = p[i].at;
            time = next;
            continue;
        }

        int idx = queue[front];
        front = (front + 1) % n;
        in_queue[idx] = 0;
        qsize--;

        int run = (p[idx].rem < quantum) ? p[idx].rem : quantum;
        time += run;
        p[idx].rem -= run;

        for (int i = 0; i < n; i++)
            if (p[i].at > time - run && p[i].at <= time && p[i].rem > 0 && !in_queue[i]) {
                rear = (rear + 1) % n;
                queue[rear] = i;
                in_queue[i] = 1;
                qsize++;
            }

        if (p[idx].rem == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            avg_wt += p[idx].wt;
            avg_tat += p[idx].tat;
            completed++;
            printf("\nP%d finished: AT=%d BT=%d CT=%d WT=%d TAT=%d\n",
                   p[idx].id, p[idx].at, p[idx].bt, p[idx].ct, p[idx].wt, p[idx].tat);
        } else {
            rear = (rear + 1) % n;
            queue[rear] = idx;
            in_queue[idx] = 1;
            qsize++;
        }
    }

    printf("\nAverage WT = %.2f\nAverage TAT = %.2f\n", avg_wt / n, avg_tat / n);
    return 0;
}