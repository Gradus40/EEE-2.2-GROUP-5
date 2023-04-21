
void patientrecords() {
         // Clear the screen and print the header for the patient records
            clrscr();
            printf("\t\t\t\t======Patient Records======\n\n\n");
            FILE *fp;
            struct patient info;
            // Open the patient_info.txt file in read mode
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

