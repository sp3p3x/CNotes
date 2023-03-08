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
    #include <io.h>
    #define F_OK 0
    #define access _access
    int os=1;
    char clrCmnd[3]="cls";
#endif

char path[] = "./notes/";

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

    char filePath[strlen(filename)];
    strcat(filePath, path);
    strcat(filePath, filename);
    strcat(filePath, ".txt");

    char content[500];
    printf("Enter the note:\n");
    fgets(content, 500, stdin);

    FILE *file;
    file = fopen(filePath, "w");
    if(file == NULL)
    {
        printf("\n!!Failed to create Note!!\nPress 'Enter' to continue...");
        getchar();
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

    char filePath[strlen(filename)];
    strcat(filePath, path);
    strcat(filePath, filename);
    strcat(filePath, ".txt");
    
    FILE *file;
    file = fopen(filePath, "r");
    if(file == NULL)
    {
        printf("\n!!Note doesn't exist!!\nPress 'Enter' to continue...");
        getchar();
        return 0;
    }
    system(clrCmnd);
    char foo[500];
    fgets(foo,500,file);
    printf("\nNote Found!\nFilename: %s\nPath: %s\nContent:\n\n%s",filename,filePath,foo);
    fclose(file);

}

void modifyNote(){
    
    printf("\n");

    char filename[255];
    printf("Enter name of the note: ");
    fgets(filename, 255, stdin);
    filename[strlen(filename) - 1] = '\0';
    strcat(filename, ".txt");

    char filePath[strlen(filename)];
    strcat(filePath, path);
    strcat(filePath, filename);
    strcat(filePath, ".txt");

    if (access(filePath, F_OK) == 0) {

        switch (os)
        {
            case 0: ;
                char linuxCopyCmnd[500]="cat '";
                strcat(linuxCopyCmnd,filePath);
                strcat(linuxCopyCmnd,"' | xclip -selection clipboard");
                system(linuxCopyCmnd);
                break;
            case 1: ;
                char winCopyCmnd[500]="type '";
                strcat(winCopyCmnd,filePath);
                strcat(winCopyCmnd,"' | clip");
                system(winCopyCmnd);
                break;
            default:
                printf("\nSomething went wrong!\nPress 'Enter' to continue...");
                return 0;
                break;
        }
        
        FILE *file;
        file = fopen(filePath, "w");
        if(file == NULL)
        {
            printf("\n!!Failed to create Note!!\nPress 'Enter' to continue...");
            getchar();
        }

        char content[500];
        printf("Enter the note:");
        printf("\n!!Please press 'Ctrl+Shift+V'!!\n\n");
        scanf("%[^\r\n]s", content);
        fprintf(file, "%s", content);
        system(clrCmnd);
        printf("\nNote created!\n");
        printf("Filename: %s\n",filename);
        printf("Path: %s\n",filePath);
        fclose(file);
    }
    else {
        printf("\n!!Note doesn't exist!!\nPress 'Enter' to continue...");
        getchar();
        return 0;
    }
}

void listNotes(){

    switch (os)
    {
        case 0: ;
            char linuxListCmnd[]="ls ./notes/";
            system(linuxListCmnd);
            getchar();
            break;
        case 1: ;
            char winListCmnd[]="dir ./notes/";
            system(winListCmnd);
            getchar();
            break;
        default:
            break;
    }

}

int main(){

    system("mkdir notes &> /dev/null");
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
                system(clrCmnd);
                break;
            case '2':
                readNote();
                system(clrCmnd);
                break;
            case '3':
                modifyNote();
                system(clrCmnd);
                break;
            case '4':
                listNotes();
                system(clrCmnd);
                break;
            case 'q':
                exit(1);
                system(clrCmnd);
                break;
            case 'Q':
                exit(1);
                system(clrCmnd);
                break;
            default:
                break;
                printf("\n!!Enter valid option!!\n");
        }
    }
    return 0;
}
