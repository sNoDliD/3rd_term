#include <stdio.h>


//#include <sys/stat.h>
//mkdir("/some/directory", 0700);

void printHelp();
void processCommands();


int main() {
    printHelp();
    processCommands();

    return 0;
}


void printHelp() {
    FILE* help_file = NULL;
    help_file = fopen("run/help.txt", "r");

    if (help_file){
        char buff[255];
        while (1){
            fgets(buff, sizeof(buff), (FILE*)help_file);
            if (feof(help_file)){
                break;
            }
            printf("%s", buff );
        }
        fclose(help_file);
    } else{
        printf("%s", "can't find help file\n");
    }
}

void processCommands(){
    char command[8];
    char table[16];

    while (1){
        int count = scanf("%s %s", command, table);
        if (count != 2){
            break;
        }
    }
}
