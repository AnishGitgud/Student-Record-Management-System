#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "student.dat"

typedef struct student{
        int rollno;
        char name[50];
        float percentage;
        struct student * next;
}STU;

void add_record(STU **);
void delete_record(STU **);
void show_list(STU *);
void modify_record(STU *);
void save_record(STU *);
void read_record(STU **);
void sort_list(STU *);
void delete_all(STU **);
void reverse_list(STU **);
