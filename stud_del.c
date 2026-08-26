#include "student.h"

void delete_record(STU ** ptr){
        if(*ptr==0){
                printf("No records found\n");
                return;
        }

        char op,name[50];
        int roll;

        printf("r/R : Enter roll number to delete\n");
        printf("n/N : Enter name to delete\n");
        scanf(" %c",&op);

        switch(op){
                //rollno
                case 'r' :
                case 'R' : printf("Enter roll number : ");
                        scanf("%d",&roll);
                        STU *node=*ptr;
                        if((*ptr)->rollno==roll){       //if first node matches
                                *ptr=(*ptr)->next;
                                free(node);
                                printf("Record deleted\n");
                                return;
                        }
                        else if((*ptr)->next==0){       //single node - not a match
                                printf("Roll number not found\n");
                                return;
                        }
                        else{                           //search for rollno
                                while((node->next) && (node->next->rollno!=roll))
                                        node=node->next;
                                if(node->next==0){      //not found
                                        printf("Roll number not found\n");
                                        return;
                                }
                                STU * del=node->next;                   //found
                                node->next=del->next;
                                free(del);
                                printf("Record deleted\n");
                        }
                        break;

                //name
                case 'n' :
                case 'N' : printf("Enter name : ");
                        scanf(" %s",name);
                        if(strcmp((*ptr)->name,name)==0){       //if first node matches
                                *ptr=(*ptr)->next;
                                free(node);
                                printf("Record deleted\n");
                                return;
                        }
                        else if((*ptr)->next==0){       //single node - not a match
                                printf("Name not found\n");
                                return;
                        }
                        //segmentation fault
                        else{                           //search for name
                                while((node->next) && strcmp(node->next->name,name))
                                        node=node->next;
                                if(node->next==0){      //not found
                                        printf("Name not found\n");
                                        return;
                                }
                                STU * del=node->next;                   //found
                                node->next=del->next;
                                free(del);
                                printf("Record deleted\n");
                        }
                        break;
        }
}

void delete_all(STU ** ptr){

}
