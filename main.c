// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Driver code
int main()
{
    FILE* ptr;
    char str[50];
    ptr = fopen("test.txt", "a+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    while (fgets(str, 50, ptr) != NULL) {
        printf("%s", str);
    }
 
    fclose(ptr);


    splitLine(str);

    return 0;
}


void splitLine(char strPar[]){
	char str[] = "strtok needs to be called several times to split a string";
	int init_size = strlen(str);
	char delim[] = "ai";

	char *ptr = strtok(str, delim);

	while (ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}
}