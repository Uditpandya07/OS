#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    float AWT = 0, ATAT = 0;
    int BT[100], P[100];
    int WT[100], TAT[100], CT[100];
    int temp, i, j;
    
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);

    printf("Enter the BT of the processes:\n");
    for(i = 0; i < n; i++) {
        printf("Process P%d: ", i+1);
        scanf("%d", &BT[i]);
        P[i] = i+1;
    }

    for (i = 0; i<n-1 ; i++){
        for(j=0; j<n-i-1; j++){
            if(BT[j] > BT[j+1]){

                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;

                temp = P[j];
                P[j] = P[j+1];
                P[j+1] = temp;
            }
        }
    }
    CT[0] = BT[0];
    for(i = 1; i < n; i++) {
        CT[i] = CT[i-1] + BT[i];
    }

    for(i = 0; i < n; i++) {
        TAT[i] = CT[i];
        WT[i] = TAT[i] - BT[i];
        
        AWT += WT[i];
        ATAT += TAT[i];
    }
     for(i = 0; i < n; i++) {
        printf("Process P%d:", P[i]);
        printf("\n Burst Time: %d", BT[i]);
        printf("\n Completion Time: %d", CT[i]);
        printf("\n Turnaround Time: %d", TAT[i]);
        printf("\n Waiting Time: %d\n", WT[i]);
    }
    
    AWT /= n;
    ATAT /= n;

    printf("Average Waiting time is: %.2f\n", AWT);
    printf("Average TurnAround time is: %.2f\n", ATAT);
    
    return 0;  
}