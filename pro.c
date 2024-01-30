#include <stdio.h>
#include <stdlib.h>

void createFile() {
    char fileName[50];
    printf("Enter the name of the file to create: ");
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(file);
}

void readFile() {
    char fileName[50];
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void updateFile() {
    char fileName[50];
    printf("Enter the name of the file to update: ");
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char data[1000];
    printf("Enter data to append to the file (max 1000 characters):\n");
    scanf(" %[^\n]", data);
    fprintf(file, "%s\n", data);
    printf("Data appended successfully.\n");
    fclose(file);
}

void deleteFile() {
    char fileName[50];
    printf("Enter the name of the file to delete: ");
    scanf("%s", fileName);
    
    if (remove(fileName) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nFile Management System\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Update File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                updateFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
