#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash = 20;

void drawUI(){

    printf("\n");
    for (int i=0; i<=hash; i++){
        printf("#");
    }
    printf("\n+");
    for (int i=0; i<=hash-14; i++){
        printf(" ");
    }
    printf("CNotes");
    for (int i=0; i<=hash-15; i++){
        printf(" ");
    }
    printf("+\n");
    for (int i=0; i<=hash; i++){
        printf("#");
    }
    printf("\n+");
    for (int i=0; i<=hash-18; i++){
        printf(" ");
    }
    printf("1.Create Note");
    for (int i=0; i<=hash-18; i++){
        printf(" ");
    }
    printf("+\n");
    printf("+");
    for (int i=0; i<=hash-18; i++){
        printf(" ");
    }
    printf("2.Read Note");
    for (int i=0; i<=hash-16; i++){
        printf(" ");
    }
    printf("+\n");
    printf("+");
    for (int i=0; i<=hash-18; i++){
        printf(" ");
    }
    printf("3.Modify Note");
    for (int i=0; i<=hash-18; i++){
        printf(" ");
    }
    printf("+\n");
    for (int i=0; i<=hash; i++){
        printf("#");
    }
    printf("\n\n [::] ");

}

void readNote(){

    char filename[255];
    printf("Enter name of the note: ");
    fgets(filename, 255, stdin);
    filename[strlen(filename) - 1] = '\0';
    strcat(filename, ".txt");
    
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error while reading note!");   
        exit(1);
    }
    char foo[500];
    fgets(foo,500,file);
    printf("%s",foo);
    fclose(file);

}

// void createNote(char filename[255], char content[500]){
void createNote(){
    
    char filename[255];
    printf("Enter name of the note: ");
    fgets(filename, 255, stdin);
    filename[strlen(filename) - 1] = '\0';
    strcat(filename, ".txt");

    char content[500];
    printf("Enter the note:\n");
    fgets(content, 500, stdin);

    FILE *file;
    file = fopen(filename, "w");
    if(file == NULL)
    {
        printf("Error while creating note!");   
        exit(1);             
    }
    fprintf(file, "%s", content);
    fclose(file);

}

int main(){
    
    #ifdef __linux__
        // int os=0;
        char cmnd[5]="clear";
    #elif _WIN32
        // int os=1;
        char cmnd[3]="cls";
    #endif
    
    while(1){
        char option;
        drawUI();
        scanf(" %c",&option);
        getchar();
        system(cmnd);
        switch(option){
            case '1':
                printf("hi");
                printf("%c",option);
                break;
            default:
                printf("\n!!Enter valid option!!\n");
        }
    }
    return 0;
}
