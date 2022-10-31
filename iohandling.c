const int MAX_FILE_SIZE = 1024;


char* read_file(char* file_name) {
    // Open file in read mode
    FILE *file = fopen(file_name, "r");

    // Check if file was opened
    if (file == NULL) {
        printf("Error while opening the file %s.\n", file_name);
        exit(0);
    }

    // File content
    char* content = calloc(sizeof(char), MAX_FILE_SIZE);
    // Read char
    char value;
    // Current position
    int i = 0;

    // Read char from file
    while ((content[i] = getc(file)) != EOF) {
        // Check if value is less then max
        if (i == MAX_FILE_SIZE - 1) {
            break;
        }

        // Next value
        i++;
    }

    // Close file
    fclose(file);

    return content;
}