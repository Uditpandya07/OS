// Write a menu driven program which will accept one of the options from the user and perform as per the following:

// IMPLEMENTATION OF SCHEDULING ALGORITHMS
// 1. FCFS
// 2. SJF
// 3. EXIT

// Enter your choice(1-3): 

#include<stdio.h>
#include<stdlib.h>

void fcfs(){
    int n;
    float AWT=0, ATAT =0;
    int BT[100];
    int WT[100];
    int TAT[100];

    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    
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
}

void sjf(){
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
}

int main(){
    int choice;
    printf("\n IMPLEMENTATION OF SCHEDULING ALGORITHMS\n");
    while(1){
        printf("\n1.FCFS\n");
        printf("2.SJF\n");
        printf("3.EXIT\n");

        printf("\n Enter your choice(1-3):\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                fcfs();
                break;
            
            case 2:
                sjf();
                break;
            
            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}