#include <stdio.h>

#define MAX_SPACES 50 // maximum number of parking spaces
#define RATE 2.50 // hourly rate for parking

int main() {
    int numSpaces = 0; // number of available parking spaces
    float totalRevenue = 0.0; // total revenue collected
    int menuChoice; // choice selected by user from menu
    int carID; // ID number of car entering or exiting parking lot
    int hoursParked; // number of hours car parked
    float amountDue; // amount due for parking
    int i; // loop variable
    
    // initialize parking lot
    numSpaces = MAX_SPACES;
    
    // display menu and prompt for user choice
    do {
        printf("Parking Management System\n");
        printf("-------------------------\n");
        printf("1. Car Entry\n");
        printf("2. Car Exit\n");
        printf("3. Display Revenue\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &menuChoice);
        
        // execute user choice
        switch(menuChoice) {
            case 1: // car entry
                if (numSpaces == 0) {
                    printf("Sorry, the parking lot is full.\n");
                }
                else {
                    printf("Enter car ID number: ");
                    scanf("%d", &carID);
                    printf("Enter number of hours parked: ");
                    scanf("%d", &hoursParked);
                    amountDue = hoursParked * RATE;
                    printf("Amount due: Rs. %.2f\n", amountDue);
                    totalRevenue += amountDue;
                    numSpaces--;
                    printf("Car %d has entered the parking lot.\n", carID);
                }
                break;
            case 2: // car exit
                if (numSpaces == MAX_SPACES) {
                    printf("Sorry, the parking lot is empty.\n");
                }
                else {
                    printf("Enter car ID number: ");
                    scanf("%d", &carID);
                    for (i = 0; i < MAX_SPACES; i++) {
                        if (carID == i+1) {
                            printf("Enter number of hours parked: ");
                            scanf("%d", &hoursParked);
                            amountDue = hoursParked * RATE;
                            printf("Amount due: $%.2f\n", amountDue);
                            totalRevenue += amountDue;
                            numSpaces++;
                            printf("Car %d has exited the parking lot.\n", carID);
                            break;
                        }
                    }
                    if (i == MAX_SPACES) {
                        printf("Car not found in parking lot.\n");
                    }
                }
                break;
            case 3: // display revenue
                printf("Total revenue collected: $%.2f\n", totalRevenue);
                break;
            case 4: // exit program
                printf("Thank you for using the Parking Management System.\n");
                break;
            default: // invalid menu choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (menuChoice != 4);
    
    return 0;
}
