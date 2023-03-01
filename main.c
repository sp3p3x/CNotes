#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createNote(char filename[255], char content[500]){
    
    FILE *file;
    file = fopen(filename, "w");
    if(file == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    fprintf(file, "%s", content);
    fclose(file);

}

int main(){
    char filename[255];
    printf("Enter name of the note: ");
    fgets(filename, 255, stdin);

    char content[500];
    printf("Enter the note:\n");
    fgets(content, 500, stdin);
    filename[strlen(filename) - 1] = '\0';

    createNote(filename, content);

    return 0;
}
