provide a 3 process output of this code:

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    float AWT=0, ATAT =0;
    int BT[100];
    int WT[100];
    int TAT[100];

    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    
    if(n > 100 || n <= 0) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    printf("\nEnter the burst time of the processes: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &BT[i]);
    }
    
    WT[0] = 0;

    for(int i = 1 ; i < n ; i++){
        WT[i] = 0;
        for(int j = 0; j<i ; j++){
            WT[i] += BT[j];
        }
    }

    for(int i = 0; i<n; i++){
        TAT[i] = WT[i] + BT[i];
        AWT += WT[i];
        ATAT += TAT[i];

        printf("\n Process P%d:", i+1);
        printf("\n Burst Time: %d", BT[i]);
        printf("\n Waiting Time: %d", WT[i]);
        printf("\n Turnaround Time: %d\n", TAT[i]);
    }

    AWT /= n;
    ATAT /= n;
    printf("\nAverage Waiting time is: %.2f", AWT);
    printf("\nAverage TurnAround time is: %.2f\n", ATAT);
    
    return 0;
}