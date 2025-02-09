#include <stdio.h>  
#include <stdlib.h>  

typedef struct {  
    int *seats;  // array to hold available seats  
    int top;     // index of the last available seat  
    int size;    // total number of seats  
} SeatManager;  

SeatManager* seatManagerCreate(int n) {  
    SeatManager* manager = (SeatManager*)malloc(sizeof(SeatManager));  
    manager->seats = (int*)malloc(n * sizeof(int));  
    manager->top = n - 1;  
    manager->size = n;  

    // initialize seats  
    for (int i = 0; i < n; i++) {  
        manager->seats[i] = n - i; // fill with seat numbers in descending order  
    }  
    return manager;  
}  

int seatManagerReserve(SeatManager* obj) {  
    if (obj->top < 0) {  
        return -1; // if no seats  
    } else {  
        return obj->seats[(obj->top)--]; // return the seat number and update the top index  
    }  
}  

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {  
    obj->seats[++(obj->top)] = seatNumber; 
}  

void seatManagerFree(SeatManager* obj) {  
    free(obj->seats);  
    free(obj);  
}  

int main() {  

    SeatManager* manager = seatManagerCreate(5);  

    printf("null\n"); 

    int result;  
    
    result = seatManagerReserve(manager);  
    printf("%d\n", result);

    result = seatManagerReserve(manager);  
    printf("%d\n", result);   

    seatManagerUnreserve(manager, 2);  
    printf("null\n"); 

    result = seatManagerReserve(manager);  
    printf("%d\n", result); 

    result = seatManagerReserve(manager);  
    printf("%d\n", result); 

    result = seatManagerReserve(manager);  
    printf("%d\n", result); 

    result = seatManagerReserve(manager);  
    printf("%d\n", result); 

    seatManagerUnreserve(manager, 5);  
    printf("null\n");  

    seatManagerFree(manager);  
    return 0;  
}