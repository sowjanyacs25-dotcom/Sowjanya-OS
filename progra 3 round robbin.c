#include <stdio.h>

int main() {
    int n, i, time = 0, remain, time_quantum;
    int wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n];

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    remain = n;

    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {
                if(remaining[i] > time_quantum) {
                    time += time_quantum;
                    remaining[i] -= time_quantum;
                } else {
                    time += remaining[i];
                    wt += time - burst[i];
                    tat += time;
                    remaining[i] = 0;
                    remain--;
                }
            }
        }
    }

    printf("\nAverage Waiting Time = %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat / n);

    return 0;
}
