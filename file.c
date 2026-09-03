#include "student.h"

void save_record(STU *ptr){
        if(ptr==0){
                printf("\033[31mNo records to save\033[0m\n");
                return;
        }

        FILE * fp=fopen(FILENAME,"w");

        while(ptr){
                fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }

        printf("\033[32mSaved to file successfully!\033[0m\n");

        fclose(fp);
}

void read_record(STU **ptr){
        FILE * fp=fopen(FILENAME,"r");
        STU *last=*ptr;

	if(fp==0){
		printf("\033[31mFile \"student.dat\" not found.\nEither create the file manually or save a student record.\033[0m\n");
		return;
	}

        while (1)
        {
                STU * new=malloc(sizeof(STU));
                if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==EOF){
                        free(new);
                        break;
                }
                new->next=0;
                if(*ptr==0)
                        *ptr=new;
                else{
                        last=*ptr;
                        while(last->next)
                                last=last->next;
                        last->next=new;
                }
        }

        printf("\033[32mLoaded from file successfully!\033[0m\n");

        fclose(fp);
}
