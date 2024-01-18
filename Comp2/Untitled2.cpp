#include <stdio.h>

int main() {
    // Step 1: Create a text file
    FILE *file = fopen("example.txt", "w");

    // Check if file creation is successful
    if (file == NULL) {
        printf("Error creating the file.\n");
        return 1; // Exit with an error code
    }

    // Step 2: Write some text into the file
    fprintf(file, "Hello, this is a sample text.\n");
    fprintf(file, "This is another line in the file.\n");

    // Close the file
    fclose(file);

    // Step 3: Open the file and output its content on the console
    file = fopen("example.txt", "r");

    // Check if file opening is successful
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Read and print the content of the file
    char buffer[100]; // Assuming a maximum line length of 100 characters
    printf("Content of the file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}

