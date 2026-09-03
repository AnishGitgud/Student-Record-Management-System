#include "student.h"

STU * headptr=0;

int main(){
        printf("a");
        char op;

        read_record(&headptr);

        while(1){
                printf("\033[36mChoose an option : \n");
                printf("a/A : Add a new record\n");
                printf("d/D : Delete a record\n");
                printf("s/S : Show the list\n");
                printf("m/M : Modify a record\n");
                printf("v/V : Save record\n");
                printf("e/E : Exit\n");
                printf("t/T : Sort the list\n");
                printf("l/L : Delete all the records\n");
                printf("r/R : Reverse the list\033[0m\n");
                scanf(" %c",&op);

                switch(op){
                        case 'a':
                        case 'A': add_record(&headptr);break;
                        case 'd':
                        case 'D': delete_record(&headptr);break;
                        case 's':
                        case 'S': show_list(headptr);break;
                        case 'm':
                        case 'M': modify_record(headptr);break;
                        case 'v':
                        case 'V': save_record(headptr);break;
                        case 'e':
                        case 'E': exit(0);
                        case 't':
                        case 'T': sort_list(headptr);break;
                        case 'l':
                        case 'L': delete_all(&headptr);break;
                        case 'r':
                        case 'R': reverse_list(&headptr);break;
                        default: printf("\033[31mInvalid option\033[0m\n");
                }
        }
}
