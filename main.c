#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
    #include <unistd.h>
    int os=0;
    char clrCmnd[5]="clear";
#elif _WIN32
    #include <Windows.h>
    int os=1;
    char clrCmnd[3]="cls";
#endif

void printLine(int type, char content[20]){

    int lineLength = 23, startSpace, endSpace;

    switch (type)
    {
        case 0:
            int startSpace = (lineLength - 8) / 2;
            printf("\n");
            for (int i=0; i<lineLength; i++){
                    printf("-");
            }
            printf("\n");
            printf("|");
            for (int i=0; i<startSpace; i++){
                printf(" ");
            }
            printf(content);
            endSpace = lineLength - ( 2 + startSpace + strlen(content));
            for (int i=0; i<endSpace; i++){
                printf(" ");
            }
            printf("|\n");
            for (int i=0; i<lineLength; i++){
                    printf("-");
            }
            printf("\n");
            break;

        case 1:
            printf("|");
            startSpace = lineLength/5;
            for (int i=0; i<startSpace; i++){
                printf(" ");
            }
            printf(content);
            endSpace = lineLength - ( 2 + startSpace + strlen(content));
            for (int i=0; i<endSpace; i++){
                printf(" ");
            }
            printf("|\n");
            break;
        
        case 2:
            for (int i=0; i<lineLength; i++){
                        printf("-");
            }
            printf("\n\n [::] ");
            break;

        default:
            break;
    }

};

void drawUI(){

    printLine(0,"CNotes");

    printLine(1,"1.Create Note");
    printLine(1,"2.Read Note");
    printLine(1,"3.Modify Note");
    printLine(1,"4.List Notes");
    printLine(1,"q.Exit");

    printLine(2,"");

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
        case 0: ;
            char linuxCopyCmnd[500]="cat ";
            strcat(linuxCopyCmnd,filename);
            strcat(linuxCopyCmnd," | xclip -selection clipboard");
            system(linuxCopyCmnd);
            break;
        case 1: ;
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

void listNotes(){

    switch (os)
    {
        case 0: ;
            char linuxListCmnd[10]="ls *.txt";
            system(linuxListCmnd);
            break;
        case 1: ;
            char winListCmnd[10]="dir *.txt";
            system(winListCmnd);
            break;
        default:
            break;
    }

}

int main(){

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
                listNotes();
                break;
            case 'q':
                exit(1);
                break;
            case 'Q':
                exit(1);
                break;
            default:
                printf("\n!!Enter valid option!!\n");
        }
    }
    return 0;
}
