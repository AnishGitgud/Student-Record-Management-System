#include "student.h"

void show_list(STU * ptr){
        if(ptr==0){
                printf("No records found\n");
                return;
        }

        printf("----------------------------------------------------------\n");
        printf("Roll No.\tName\t\tPercentage\n");
        printf("----------------------------------------------------------\n");
        while(ptr){
                printf("%d\t\t%s\t\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
        printf("----------------------------------------------------------\n");
}

void sort_list(STU ** ptr){

}

void reverse_list(STU ** ptr){

}
