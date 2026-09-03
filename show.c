#include "student.h"

void show_list(STU * ptr){
        if(ptr==0){
                printf("\033[31mNo records found\033[0m\n");
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

void sort_list(STU * ptr){
        if(ptr==0){
                printf("\033[31mNo records found\033[0m\n");
                return;
        }

        char op;
        int cr;

        retry:
        printf("N/n : Sort with name\nP/p : Sort with percentage\n");
        scanf(" %c",&op);

        switch(op){
                case 'N':
                case 'n':cr=0;break;

                case 'P':
                case 'p':cr=1;break;

                default: printf("Invalid choice\n");
                        goto retry;
        }

	int c=0;
        STU *p1=ptr,*p2,t;
        while(p1){
                p1=p1->next;
                c++;
        }
        p1=ptr;

        for(int i=0 ; i<c-1 ; i++){
                p2=p1->next;
                for(int j=0 ; j<c-i-1 ; j++){
                        if(((cr==1) && (p1->percentage < p2->percentage)) || ((cr==0) && (strcmp(p1->name,p2->name)>0))){
                                t.rollno=p1->rollno;
                                p1->rollno=p2->rollno;
                                p2->rollno=t.rollno;

                                strcpy(t.name,p1->name);
                                strcpy(p1->name,p2->name);
                                strcpy(p2->name,t.name);

                                t.percentage=p1->percentage;
                                p1->percentage=p2->percentage;
                                p2->percentage=t.percentage;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }

        printf("\033[32mList sorted!\033[0m\n");
        show_list(ptr);
}

void reverse_list(STU ** ptr){
        if(ptr==0){
                printf("\033[31mNo records found\033[0m\n");
                return;
        }

        int c=0;
        STU *node=*ptr,**parr;
        while(node){
                node=node->next;
                c++;
        }
        node=*ptr;

        if(c>1){
                parr=malloc(sizeof(STU*)*c);

                for(int i=0;i<c;i++){
                        parr[i]=node;
                        node=node->next;
                }

                for(int i=c-1;i>0;i--)
                        parr[i]->next=parr[i-1];
                parr[0]->next=0;
                *ptr=parr[c-1];
        }

        printf("\033[32mReversed the list successfully!\033[0m\n");
        show_list(*ptr);
}
