#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    float AWT = 0, ATAT = 0;
    int BT[100], AT[100];
    int WT[100], TAT[100], CT[100];
    int temp, i, j;
    
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    
    printf("\nEnter the Arrival Time and Burst Time of the processes:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &AT[i]);
        scanf("%d", &BT[i]);
    }
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(AT[j] > AT[j+1]) {
                temp = AT[j];
                AT[j] = AT[j+1];
                AT[j+1] = temp;
                
                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;
            }
        }
    }
    
    CT[0] = AT[0] + BT[0];
    
    for(i = 1; i < n; i++) {
        if(AT[i] > CT[i-1]) {
            CT[i] = AT[i] + BT[i];
        }
        else {
            CT[i] = CT[i-1] + BT[i];
        }
    }
    
    for(i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        AWT += WT[i];
        ATAT += TAT[i];
        
        printf("\n Process P%d:", i+1);
        printf("\n Arrival Time: %d", AT[i]);
        printf("\n Burst Time: %d", BT[i]);
        printf("\n Completion Time: %d", CT[i]);
        printf("\n Turnaround Time: %d", TAT[i]);
        printf("\n Waiting Time: %d\n", WT[i]);
    }
    
    AWT /= n;
    ATAT /= n;
    
    printf("\nAverage Waiting time is: %.2f", AWT);
    printf("\nAverage TurnAround time is: %.2f\n", ATAT);
    
    return 0;
}