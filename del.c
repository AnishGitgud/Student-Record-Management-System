#include "student.h"

//feature to be added
void delete_record(STU ** ptr){
        if(*ptr==0){
                printf("\033[31mNo records found\033[0m\n");
                return;
        }

        char op,name[50];
        int roll,found=0;
        STU *node=*ptr;

        printf("r/R : Enter roll number to delete\n");
        printf("n/N : Enter name to delete\n");
        scanf(" %c",&op);

        switch(op){
                //rollno
                case 'r' :
                case 'R' : printf("Enter roll number : ");
                        scanf("%d",&roll);
                        rollno:
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
                        while(node){
                                if(strcmp(node->name,name)==0){
                                        found++;
                                        printf("%d %s %f\n",node->rollno,node->name,node->percentage);
                                }
                                node=node->next;
                        }
                        node=*ptr;

                        if(found==0){
                                printf("Record not found\n");
                                return;
                        }
                        else if(found==1){
                                //only one record foun - delete it
                                if(strcmp((*ptr)->name,name)==0){       //if first node matches
                                        *ptr=(*ptr)->next;
                                        free(node);
                                        printf("Record deleted\n");
                                        return;
                                }
                                else{                           //search for name
                                        while((node->next) && strcmp(node->next->name,name))
                                        node=node->next;
                                        STU * del=node->next;                   //found
                                        node->next=del->next;
                                        free(del);
                                        printf("Record deleted\n");
                                }
                        }
                        else{
                                printf("Which record to delete?(Enter rollno) : ");
                                scanf("%d",&roll);
                                goto rollno;
                        }
        }
}

void delete_all(STU ** ptr){
        if(*ptr==0){
                printf("No records found\n");
                return;
        }

        STU *del=*ptr,*next=del->next;

        while(next){
                free(del);
                del=del->next;
                next=del->next;
        }

        free(del);
        *ptr=0;

        printf("Successfully deleted all records\n");
}