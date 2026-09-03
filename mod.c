#include "student.h"

void modify_record(STU * ptr){
	if(ptr==0){
		printf("No records found\n");
			return;
	}

        char op;
        int cr;

        int rn=0;
        char name[50];
        float perc=0;

        retry:
        printf("R/r : Search by roll number\nN/n : Search by name\nP/p : Search by percentage\n");
        scanf(" %c",&op);

        switch(op){
                case 'R':
                case 'r':cr=0;
                        printf("Enter the roll number to search and modify : ");
                        scanf("%d",&rn);
                        break;

                case 'N':
                case 'n':cr=1;
                        printf("Enter the name to search and modify : ");
                        scanf("%s",name);
                        break;

                case 'P':
                case 'p':cr=2;
                        printf("Enter the percentage to search and modify : ");
                        scanf("%f",&perc);
                        break;

                default:printf("Invalid choice\n");
                        goto retry;
        }


        STU *node=ptr;
        int found=0;
        while(node){
                if(((cr==0) && (node->rollno==rn)) || ((cr==1) && (strcmp(name,node->name)==0)) || ((cr==2) && (node->percentage==perc))){
                        found=1;
                        printf("%d %s %f\n",node->rollno,node->name,node->percentage);
                }

                node=node->next;
        }

        if(!found){
                printf("No records found\n");
                return;
        }

        printf("Which record to modify?(Enter rollno) : ");
        scanf("%d",&rn);

        node=ptr;
        while(node->rollno != rn)
                node=node->next;

        printf("Enter new name and percentage for this record : \n");
        scanf(" %s %f",node->name,&node->percentage);

        printf("Record updated successfully!\n");
}
