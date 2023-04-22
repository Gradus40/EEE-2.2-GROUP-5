// Hospital Admission Management System

#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define clrscr()

// function declarations
void addpatient();
void patientrecords();
void searchpatient();
void deletepatient();
void editrecord();

// define the struct to hold patient information
struct patient {
    char name[50];
    char gender[10];
    int age;
    int height;
    int weight;
    int id;
    int bcn;
    char hospital_admitted[20];
    char wing_admitted[20];
    int doctor_fee;
    int lab_test_fee;
    int drug_fee;
    int arrival_date;
    int discharge_date;
};
int main() {
    int choice;
        // display the menu until the user chooses to exit
    do {
        clrscr();
        printf("\n\n\t\t\t\t====== Hospital Management System ======\n\n");
        printf("\t\t\t1. Add Patient Information\n");
        printf("\t\t\t2. List Patient Information\n");
        printf("\t\t\t3. Search Patient Information\n");
        printf("\t\t\t4. Delete Patient Information\n");
        printf("\t\t\t5. edit record\n");
        printf("\t\t\t6. Exit\n");
        printf("\n\t\t\tEnter your choice: ");
        // get user's choice
        scanf("%d", &choice);

        // switch case to perform the selected operation
        switch (choice) {
            case 1:
                addpatient();
                break;
            case 2:
                patientrecords();
                break;
            case 3:
                searchpatient();
                break;
            case 4:
                deletepatient();
                break;
            case 5:
                editrecord();
            case 6:
                exit(0);
            default:
                printf("\n\t\t\tWrong input! Please enter a valid choice.");
        }
        printf("\n\t\t\tPress any key to continue...");
        getch();
    } while (choice != 6);

    return 0;
}
// function to add a patient to the file
void addpatient() {
            char another;
            FILE *fp;
            struct patient info;

            do {
                    // Clear the console screen
                clrscr();
                printf("\t\t\t\t======Add Patient Info======\n\n\n");
              // Open the file in append mode
                fp = fopen("patient_info.txt", "a");
            // Prompt the user to input patient information
                printf("\t\t\tEnter name: ");
                scanf("%s", info.name);
                printf("\t\t\tEnter gender: ");
                scanf("%s", info.gender);
                printf("\t\t\tEnter age: ");
                scanf("%d", &info.age);
                printf("\t\t\tEnter height: ");
                scanf("%d", &info.height);
                printf("\t\t\tEnter weight: ");
                scanf("%d", &info.weight);
                int choice;
                printf("\nEnter 1 to enter ID, 2 to enter birth certificate number: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Enter the person's ID: ");
                    scanf("%d", &info.id);
                    info.bcn = 0;
                } else if (choice == 2) {
                    printf("\nEnter the person's birth certificate number: ");
                    scanf("%d", &info.bcn);
                    info.id = 0;
                }

                // Prompt the user to input hospital admission details//
                printf("\n\t\t\tEnter Hospital Admitted: ");
                scanf("%s", info.hospital_admitted);
                printf("\n\t\t\tEnter wing admitted: ");
                scanf("%s", info.wing_admitted);
                // Prompt the user to input fees for doctor, lab tests and drugs//
                printf("\n\t\t\tEnter doctor fee: ");
                scanf("%d", &info.doctor_fee);
                printf("\n\t\t\tEnter lab test fee: ");
                scanf("%d", &info.lab_test_fee);
                printf("\n\t\t\tEnter drug fee: ");
                scanf("%d", &info.drug_fee);
                // Prompt the user to input the arrival and discharge dates//
                printf("\n\t\t\tEnter arrival date(DD/MM/YYYY): ");
                scanf("%d", &info.arrival_date);
                printf("\n\t\t\tEnter discharge date(DD/MM/YYYY): ");
                scanf("%d", &info.discharge_date);
                printf("\n\t\t\t_______________________________________\n");

                 // Check if the file was opened successfully//
                if (fp == NULL) {
                    printf("\t\t\tCan't Open File\n");
                } else {
                    // Write the patient information to the file//
                    fprintf(fp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n",
                   info.name, info.gender, info.age, info.height, info.weight, info.id,
                   info.bcn, info.hospital_admitted, info.wing_admitted,
                   info.doctor_fee, info.lab_test_fee, info.drug_fee,
                   info.arrival_date, info.discharge_date);

                // Ask the user if they want to add another patient//
             printf("\n\t\t\tPatient information added successfully!\n");
             fclose(fp);
        }
            printf("\n\t\t\tDo you want to add another record? (y/n): ");
            // Clear the input buffer before reading the user's response//
            fflush(stdin);
            scanf("%c", &another);
            // Continue looping and prompting the user for input until they indicate they do not want to add another record//
        } while (another == 'y' || another == 'Y');

        patientrecords();
}
void patientrecords() {
         // Clear the screen and print the header for the patient records//
            clrscr();
            printf("\t\t\t\t======Patient Records======\n\n\n");
            FILE *fp;
            struct patient info;
            // Open the patient_info.txt file in read mode//
            fp = fopen("patient_info.txt", "r");
            // Check if the file was successfully opened
            if (fp == NULL) {
                printf("\t\t\tCan't Open File\n");
            } else {
                 // If the file was successfully opened, print the header for the patient records table
                printf("_________________________________________________________________________________________________________\n");
                printf("%-20s| %-8s| %-4s| %-6s| %-6s| %-8s| %-10s  | %-20s| %-20s| %-10s| %-12s| %-10s| %-15s| %-15s\n", "Name", "Gender", "Age", "Height", "Weight", "ID", "Birth Cert No", "Hospital Admitted", "Wing Admitted", "Doctor Fee", "Lab Test Fee", "Drug Fee", "Arrival Date", "Discharge Date");
                printf("_________________________________________________________________________________________________________\n");

              // Read the contents of the patient_info.txt file line by line and print them in a table format

                while (fscanf(fp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n", info.name, info.gender, &info.age, &info.height, &info.weight, &info.id, &info.bcn, info.hospital_admitted, info.wing_admitted, &info.doctor_fee, &info.lab_test_fee, &info.drug_fee, &info.arrival_date, &info.discharge_date) != EOF) {
                    printf("%-20s| %-8s| %-4d| %-6d| %-6d| %-8d| %-10d| %-20s| %-20s| %-10d| %-12d| %-10d| %-15d| %-15d\n", info.name, info.gender, info.age, info.height, info.weight, info.id, info.bcn, info.hospital_admitted, info.wing_admitted, info.doctor_fee, info.lab_test_fee, info.drug_fee, info.arrival_date, info.discharge_date);
                }
                printf("\n");
                 // Close the file
                fclose(fp);
            }
            // Wait for user input and go back to the main menu when a key is pressed
            printf("\n\t\t\tPress any key to go back to Main Menu.");
            getch();
