#include <stdio.h>

int main(){
    char filename[255];
    printf("Enter name of the note: ");
    scanf("%[^\n]s", filename);
    printf("%s", filename);

    return 0;
}
