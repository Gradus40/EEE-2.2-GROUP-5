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
    }

void searchpatient() {
            clrscr();// Clear the screen and print the header for the patient records
            printf("\t\t\t\t======Search Patient Record======\n\n\n");
             // Declare a file pointer and a patient struct variable
            FILE *fp;
            struct patient info;
            char name[50];
            printf("\t\t\tEnter name to search: ");
            scanf("%s", name);
            int found = 0;

             // Open the patient_info.txt file in read mode
            fp = fopen("patient_info.txt", "r");

            // Check if the file was successfully opened
            if (fp == NULL) {
            // If the file was not successfully opened, print an error message
                printf("\t\t\tCan't Open File\n");
            } else {
                while (fscanf(fp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n", info.name, info.gender, &info.age, &info.height, &info.weight, &info.id, &info.bcn, info.hospital_admitted, info.wing_admitted, &info.doctor_fee, &info.lab_test_fee, &info.drug_fee, &info.arrival_date, &info.discharge_date) != EOF) {
            if (strcmp(name, info.name) == 0) {
                    printf("\n\t\t\t_______________________________________\n");
                    printf("\t\t\tPatient Name : %s\n", info.name);
                    printf("\t\t\tGender : %s\n", info.gender);
                    printf("\t\t\tAge : %d\n", info.age);
                    printf("\t\t\tHeight : %d cm\n", info.height);
                    printf("\t\t\tWeight : %d kg\n", info.weight);
                    if (info.id != 0) {
                    printf("\t\t\tID : %d\n", info.id);
                    } else {
                    printf("\t\t\tBirth Certificate Number : %d\n", info.bcn);
                    }
                    printf("\t\t\tHospital Admitted : %s\n", info.hospital_admitted);
                    printf("\t\t\tWing Admitted : %s\n", info.wing_admitted);
                    printf("\t\t\tDoctor Fee : %d\n", info.doctor_fee);
                    printf("\t\t\tLab Test Fee : %d\n", info.lab_test_fee);
                    printf("\t\t\tDrug Fee : %d\n", info.drug_fee);
                    printf("\t\t\tArrival Date : %d\n", info.arrival_date);
                    printf("\t\t\tDischarge Date : %d\n", info.discharge_date);
                    printf("\n\t\t\t_______________________________________\n");
                    found = 1;
                    break;
                  }
                }
            if (!found) {
                 printf("\n\t\t\tPatient not found.\n");
                }
            }
                fclose(fp);
          {
            printf("\t\t\tPress any key to continue...\n");
            getch();
    }
}
void deletepatient() {
        FILE *fp, *tempfp;
        struct patient info;
        char name[50];
            // print header and prompt for patient name input
        printf("\t\t\t\t======Delete Patient======\n\n\n");

        printf("\t\t\tEnter the name of the patient: ");
        scanf("%s", name);

        fp = fopen("patient_info.txt", "r");
        tempfp = fopen("temp.txt", "w");

        if (fp == NULL) {
            printf("\t\t\tCan't Open File\n");
        } else {
              // loop through each line of the file
            while (fscanf(fp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n",info.name, info.gender, &info.age, &info.height, &info.weight, &info.id,&info.bcn, info.hospital_admitted, info.wing_admitted,&info.doctor_fee, &info.lab_test_fee, &info.drug_fee,&info.arrival_date, &info.discharge_date) != EOF) {
               // if the patient name doesn't match the input, write the line to the temporary file
                if (strcmp(info.name, name) != 0) {
                    fprintf(tempfp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n",
                            info.name, info.gender, info.age, info.height, info.weight, info.id,
                            info.bcn, info.hospital_admitted, info.wing_admitted,
                            info.doctor_fee, info.lab_test_fee, info.drug_fee,
                            info.arrival_date, info.discharge_date);
                }
            }
            fclose(fp);// close the original file
            fclose(tempfp);// close the temporary file
            remove("patient_info.txt");// delete the original file
            rename("temp.txt", "patient_info.txt");// rename the temporary file to the original file name
            printf("\t\t\tRecord Deleted\n");// print a message indicating successful deletion
        }

        printf("\t\t\tPress any key to continue...\n");
        getch(); // wait for user input before continuing
}

void editrecord() {
        FILE *fp, *tempfp; // declare two file pointers

        struct patient info; // declare a struct for patient info

        char name[50];// declare a char array for patient name input

        int found = 0;

        printf("\t\t\t\t======Edit Record======\n\n\n");
        printf("\t\t\tEnter the name of the patient: ");
        scanf("%s", name);
         // open the file for reading
        fp = fopen("patient_info.txt", "r");
        // open a temporary file for writing

        tempfp = fopen("temp.txt", "w");
       // check if the file was successfully opened
           if (fp == NULL) {
            printf("\t\t\tCan't Open File\n");
                } else {
                  //reads the contents of the patient_info.txt file and assigns them to the struct patient object info
                while (fscanf(fp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n",info.name, info.gender, &info.age, &info.height, &info.weight, &info.id,&info.bcn, info.hospital_admitted, info.wing_admitted,&info.doctor_fee, &info.lab_test_fee, &info.drug_fee,&info.arrival_date, &info.discharge_date) != EOF) {

                if (strcmp(info.name, name) == 0) {
                    found = 1;
                    printf("\n\t\t\tWhat do you want to edit?\n");
                    printf("\t\t\t1. Age\n");
                    printf("\t\t\t2. Height\n");
                    printf("\t\t\t3. Weight\n");
                    printf("\t\t\t4. Hospital Admitted\n");
                    printf("\t\t\t6. Wing Admitted\n");
                    printf("\t\t\t7. Doctor Fee\n");
                    printf("\t\t\t8. Lab Test Fee\n");
                    printf("\t\t\t9. Drug Fee\n");
                    printf("\t\t\t10. Arrival Date\n");
                    printf("\t\t\t11. Discharge Date\n");
                    printf("\t\t\t12. Go Back to Main Menu\n");
                    printf("\n\t\t\tEnter your choice: ");
                    int choice;
                    scanf("%d", &choice);
                   // allows the user to choose which field to edit.
                    switch(choice) {
                             // Update patient's age
                          case 1:
                                  printf("\t\t\tEnter new age: ");
                                  scanf("%d", &info.age);
                                  break;
                                   // Update patient's height
                          case 2:
                                  printf("\t\t\tEnter new height: ");
                                  scanf("%d", &info.height);
                                  break;
                                  // Update patient's weight
                          case 3:
                                  printf("\t\t\tEnter new weight: ");
                                  scanf("%d", &info.weight);
                                  break;
                                  // Update patient's hospital admission information
                          case 4:
                                  printf("\t\t\tEnter new Hospital Admitted: ");
                                  scanf("%s", info.hospital_admitted);
                                  break;
                                   // Update patient's wing admission information
                          case 5:
                                  printf("\t\t\tEnter new Wing Admitted: ");
                                  scanf("%s", info.wing_admitted);
                                  break;
                                    //update patient's Doctor Fee
                          case 6:
                                  printf("\t\t\tEnter new Doctor Fee: ");
                                  scanf("%d", &info.doctor_fee);
                                  break;
                                  // Update patient's Lab Test Fee
                          case 7:
                                  printf("\t\t\tEnter new Lab Test Fee: ");
                                  scanf("%d", &info.lab_test_fee);
                                  break;
                                  // Update patient's Drug Fee
                          case 8:
                                  printf("\t\t\tEnter new Drug Fee: ");
                                  scanf("%d", &info.drug_fee);
                                  break;
                          case 9:
                                  printf("\t\t\tEnter new Arrival Date: ");
                                  scanf("%d", &info.arrival_date);
                                  break;
                          case 10: // Update patient's Discharge Date
                                  printf("\t\t\tEnter new Discharge Date: ");
                                  scanf("%d", &info.discharge_date);
                                  break;
                          case 11:
                                  printf("\t\t\tReturning to Main Menu\n");
                                  break;
                          default:
                                printf("\t\t\tInvalid Choice!\n");
                                break;
                }
                   fprintf(tempfp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n",info.name, info.gender, info.age, info.height, info.weight, info.id,info.bcn, info.hospital_admitted, info.wing_admitted, info.doctor_fee, info.lab_test_fee, info.drug_fee,info.arrival_date, info.discharge_date);

                   } else {

                   fprintf(tempfp, "%s %s %d %d %d %d %d %s %s %d %d %d %d %d\n",info.name, info.gender, info.age, info.height, info.weight, info.id,info.bcn, info.hospital_admitted, info.wing_admitted,info.doctor_fee, info.lab_test_fee, info.drug_fee,info.arrival_date, info.discharge_date);
                   }
           }
            fclose(fp);
            fclose(tempfp);

            remove("patient_info.txt");
            rename("temp.txt", "patient_info.txt");

          if (found == 0) {
            printf("\t\t\tRecord Not Found!\n");
          } else {
            printf("\t\t\tRecord Updated Successfully!\n");
         }
        fclose(fp);
        fclose(tempfp);

        remove("patient_info.txt");
        rename("temp.dat", "patient_info.txt");

        if (found == 0) {
            printf("\t\t\tRecord Not Found!\n");
        } else {
            printf("\t\t\tRecord Updated Successfully!\n");
          }
    }

        printf("\n\t\t\tPress any key to return to Main Menu");
        getch(); // waits for user input
}
    
             
