#include "student.h"

/*
[DONE]Create a new node dynamically using malloc().
[DONE]Assign the smallest positive integer that is not already used as the roll number. The roll number must be unique.
[DONE]Ask the user to enter the student's name and percentage.
[DONE]Insert the new node into the singly linked list.
        Example: If roll numbers 1, 2, 4 and 5 are present, the next roll number should be 3
*/

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

        //Ask the user to enter the student's name and percentage.
        printf("Enter student's name and percentage : ");
        scanf(" %s %f",new->name,&new->percentage);

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
}
