#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int hash = 20;

#ifdef __linux__
    #include <unistd.h>
    int os=0;
    char clrCmnd[5]="clear";
#elif _WIN32
    #include <Windows.h>
    int os=1;
    char clrCmnd[3]="cls";
#endif

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
    printf("+");
    for (int i=0; i<=hash-18; i++){
        printf(" ");
    }
    printf("4.Exit");
    for (int i=0; i<=hash-11; i++){
        printf(" ");
    }
    printf("+\n");
    for (int i=0; i<=hash; i++){
        printf("#");
    }
    printf("\n\n [::] ");

}

void createNote(){
    
    printf("\n");

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
    system(clrCmnd);
    printf("\nNote created!\n");
    printf("Filename: %s\n",filename);
    fclose(file);

}

void readNote(){

    printf("\n");

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
    system(clrCmnd);
    char foo[500];
    fgets(foo,500,file);
    printf("\nNote Found!\nFilename: %s\nContent:\n\n%s",filename,foo);
    fclose(file);

}

void modifyNote(){
    
    printf("\n");

    char filename[255];
    printf("Enter name of the note: ");
    fgets(filename, 255, stdin);
    filename[strlen(filename) - 1] = '\0';
    strcat(filename, ".txt");

    switch (os)
    {
        case 0:
            char linuxCopyCmnd[500]="cat ";
            strcat(linuxCopyCmnd,filename);
            strcat(linuxCopyCmnd," | xclip -selection clipboard");
            system(linuxCopyCmnd);
            break;
        case 1:
            char winCopyCmnd[500]="type ";
            strcat(winCopyCmnd,filename);
            strcat(winCopyCmnd," | clip");
            system(winCopyCmnd);
            break;
        default:
            break;
    }
    
    FILE *file;
    file = fopen(filename, "w");
    if(file == NULL)
    {
        printf("Error while creating note!");   
        exit(1);
    }

    char content[500];
    printf("Enter the note:");
    printf("\n!!Please press 'Ctrl+Shift+V'!!\n\n");
    scanf("%[^\r\n]s", content);
    fprintf(file, "%s", content);
    system(clrCmnd);
    printf("\nNote created!\n");
    printf("Filename: %s\n",filename);
    fclose(file);

}

int main(){

    // sleep(3);
    system(clrCmnd);
    
    while(1){
        char option;
        drawUI();
        scanf(" %c",&option);
        getchar();
        system(clrCmnd);
        switch(option){
            case '1':
                createNote();
                break;
            case '2':
                readNote();
                break;
            case '3':
                modifyNote();
                break;
            case '4':
                exit(1);
                break;
            default:
                printf("\n!!Enter valid option!!\n");
        }
    }
    return 0;
}
