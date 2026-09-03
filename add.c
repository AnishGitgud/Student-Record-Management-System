#include "student.h"

void add_record(STU ** ptr){
        //Create a new node dynamically using malloc().
        STU * new=malloc(sizeof(STU)),*node;

        //Assign the smallest positive integer that is not already used as the roll number. The roll number must be unique.
        int roll=1;
        if(*ptr){
                node=*ptr;
                while(node){
                        if(node->rollno==roll){
                                roll++;
                                node=*ptr;
                        }
                        else
                                node=node->next;
                }
        }
        new->rollno=roll;

        //Ask the user to enter the student's name and percentage(between 0 to 100).
        while(1){
                printf("Enter student's name and percentage : ");
                scanf(" %s %f",new->name,&new->percentage);

                if((new->percentage >= 0) && (new->percentage <= 100))
                        break;

                printf("\033[31mInvalid percentage\033[0m\n");
        }

        //Insert the new node into the singly linked list.
        if(!*ptr || ((*ptr)->rollno > new->rollno)){
                new->next=*ptr;
                *ptr=new;
        }
        else{
                node=*ptr;
                while((node->next) && (node->next->rollno<new->rollno))
                        node=node->next;
                new->next=node->next;
                node->next=new;
        }

        printf("\033[32mRecord added successfully!\033[0m\n");
}
