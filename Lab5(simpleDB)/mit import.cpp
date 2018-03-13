#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <fstream>
#include <iostream>

#define MAXSTRLEN 20
#define MAXSTRLEN_ 100
using namespace std;

typedef struct High_rating_t{
                struct full_name_t{
				     char surname[MAXSTRLEN];
				     char name[MAXSTRLEN];
			    } full_name;
                int rating;
            } High_rating;
			
typedef struct Others_t{
                struct full_name_t{
				     char surname[MAXSTRLEN];
				     char name[MAXSTRLEN];
				 } full_name;
                int rating;
            } Others;

typedef struct {
		int chosen; //if any element is chosen then 1
		char nnew[MAXSTRLEN];
		char histor[MAXSTRLEN];
		struct main_info_t{
			High_rating *high_rating;
            Others *others;
			struct workin_t{
                char work_in[MAXSTRLEN];
            } workin;
			struct workaft_t{
                char work_aft[MAXSTRLEN];
            } workaft;
			int sizestud1;//number of high rating students
			int sizestud2;//number of others
		} main_info;
	} university;
	
	
typedef struct operativ{
	university data;
	struct operativ *next;
} university_operativ;

//create new entry in RAM
university create_fun(int n){
	university st1;
	char buff[MAXSTRLEN];
	int i, count, check_str, l;
	st1.chosen=1;
	printf("Fill next fields, please.\nUniversity#%d", n);
	int check, v;
	
	printf("\nNew name: ");
	fgets(st1.nnew, MAXSTRLEN, stdin);
	st1.nnew[strlen(st1.nnew)-1]=0;
	check=0;
	for(v=0; v<strlen(st1.nnew); v++)
		if (st1.nnew[v]==' ') check=0;
		else{
			check=1;
			break;
		}
	while(check==0){
		printf("Incorrect value!  ");
		fgets(st1.nnew, MAXSTRLEN, stdin);
		st1.nnew[strlen(st1.nnew)-1]=0;
		for(v=0; v<strlen(st1.nnew); v++)
		if (st1.nnew[v]==' ') check=0;
		else{
			check=1;
			break;
		}
		fflush(stdin);
	}
	fflush(stdin);
	
	printf("Historical name: ");
	fgets(st1.histor, MAXSTRLEN, stdin);
	st1.histor[strlen(st1.histor)-1]=0;
	check=0;
	for(v=0; v<strlen(st1.histor); v++)
		if (st1.histor[v]==' ') check=0;
		else{
			check=1;
			break;
		}
	while(check==0){
		printf("Incorrect value!  ");
		fgets(st1.histor, MAXSTRLEN, stdin);
		st1.histor[strlen(st1.histor)-1]=0;
		for(v=0; v<strlen(st1.histor); v++)
		if (st1.histor[v]==' ') check=0;
		else{
			check=1;
			break;
		}
		fflush(stdin);
	}
	fflush(stdin);

	printf("\nStudents with high rating (input number of students): ");
	fgets(buff, MAXSTRLEN, stdin);
	while (!(st1.main_info.sizestud1=atoi(buff))){
					printf("Incorrect value!  ");
					fgets(buff, MAXSTRLEN, stdin);	
				}
	st1.main_info.high_rating = (High_rating*) malloc((st1.main_info.sizestud1)*sizeof(High_rating));
	for (i=0; i<st1.main_info.sizestud1; i++){
                printf("Full name:\n ");
				printf("\tName: ");
                fgets(st1.main_info.high_rating[i].full_name.name, MAXSTRLEN, stdin);
				st1.main_info.high_rating[i].full_name.name[strlen(st1.main_info.high_rating[i].full_name.name)-1]=0;
					check=0;
				for(v=0; v<strlen(st1.main_info.high_rating[i].full_name.name); v++)
					if (st1.main_info.high_rating[i].full_name.name[v]==' ') check=0;
					else{
						check=1;
						break;
					}
				while(check==0){
					printf("Incorrect value!  ");
					fgets(st1.main_info.high_rating[i].full_name.name, MAXSTRLEN, stdin);
					st1.main_info.high_rating[i].full_name.name[strlen(st1.main_info.high_rating[i].full_name.name)-1]=0;
					for(v=0; v<strlen(st1.main_info.high_rating[i].full_name.name); v++)
					if (st1.main_info.high_rating[i].full_name.name[v]==' ') check=0;
					else{
						check=1;
						break;
					}
					fflush(stdin);
				}
				fflush(stdin);
                printf("\tSurname: ");
                fgets(st1.main_info.high_rating[i].full_name.surname, MAXSTRLEN, stdin);
				st1.main_info.high_rating[i].full_name.surname[strlen(st1.main_info.high_rating[i].full_name.surname)-1]=0;
				check=0;
				for(v=0; v<strlen(st1.main_info.high_rating[i].full_name.surname); v++)
					if (st1.main_info.high_rating[i].full_name.surname[v]==' ') check=0;
					else{
						check=1;
						break;
					}
				while(check==0){
					printf("Incorrect value!  ");
					fgets(st1.main_info.high_rating[i].full_name.surname, MAXSTRLEN, stdin);
					st1.main_info.high_rating[i].full_name.surname[strlen(st1.main_info.high_rating[i].full_name.surname)-1]=0;
					for(v=0; v<strlen(st1.main_info.high_rating[i].full_name.surname); v++)
					if (st1.main_info.high_rating[i].full_name.surname[v]==' ') check=0;
					else{
						check=1;
						break;
					}
				}
				
				
				
                printf("Rating: ");
                fgets(buff, MAXSTRLEN, stdin);
				while (!(st1.main_info.high_rating[i].rating=atoi(buff))){
					printf("Incorrect value!  ");
					fgets(buff, MAXSTRLEN, stdin);	
				}
				fflush(stdin);
            }
	
	printf("\nOther students (input number of students): ");
	fgets(buff, MAXSTRLEN, stdin);
	while (!(st1.main_info.sizestud2=atoi(buff))){
					printf("Incorrect value!  ");
					fgets(buff, MAXSTRLEN, stdin);	
				}
	st1.main_info.others = (Others*) malloc((st1.main_info.sizestud2)*sizeof(Others));
	for (i=0; i<st1.main_info.sizestud2; i++){
                printf("Full name:\n ");
				printf("\tName: ");
                fgets(st1.main_info.others[i].full_name.name, MAXSTRLEN, stdin);
				st1.main_info.others[i].full_name.name[strlen(st1.main_info.others[i].full_name.name)-1]=0;
				check=0;
				for(v=0; v<strlen(st1.main_info.others[i].full_name.name); v++)
					if (st1.main_info.others[i].full_name.name[v]==' ') check=0;
					else{
						check=1;
						break;
					}
				while(check==0){
					printf("Incorrect value!  ");
					fgets(st1.main_info.others[i].full_name.name, MAXSTRLEN, stdin);
					st1.main_info.others[i].full_name.name[strlen(st1.main_info.others[i].full_name.name)-1]=0;
					for(v=0; v<strlen(st1.main_info.others[i].full_name.name); v++)
					if (st1.main_info.others[i].full_name.name[v]==' ') check=0;
					else{
						check=1;
						break;
					}
					fflush(stdin);
				}
				fflush(stdin);
                printf("\tSurname: ");
                fgets(st1.main_info.others[i].full_name.surname, MAXSTRLEN, stdin);
				st1.main_info.others[i].full_name.surname[strlen(st1.main_info.others[i].full_name.surname)-1]=0;
				check=0;
				for(v=0; v<strlen(st1.main_info.others[i].full_name.surname); v++)
					if (st1.main_info.others[i].full_name.surname[v]==' ') check=0;
					else{
						check=1;
						break;
					}
				while(check==0){
					printf("Incorrect value!  ");
					fgets(st1.main_info.others[i].full_name.surname, MAXSTRLEN, stdin);
					st1.main_info.others[i].full_name.surname[strlen(st1.main_info.others[i].full_name.surname)-1]=0;
					for(v=0; v<strlen(st1.main_info.others[i].full_name.surname); v++)
					if (st1.main_info.others[i].full_name.surname[v]==' ') check=0;
					else{
						check=1;
						break;
					}
					fflush(stdin);
				}
	
                printf("Rating: ");
                fgets(buff, MAXSTRLEN, stdin);
				while (!(st1.main_info.others[i].rating=atoi(buff))){
					printf("Incorrect value!  ");
					fgets(buff, MAXSTRLEN, stdin);	
				}
				fflush(stdin);
            }
	
	printf("\nProfession: ");
	fgets(st1.main_info.workin.work_in, MAXSTRLEN, stdin);
	st1.main_info.workin.work_in[strlen(st1.main_info.workin.work_in)-1]=0;
	check=0;
	for(v=0; v<strlen(st1.main_info.workin.work_in); v++)
		if (st1.main_info.workin.work_in[v]==' ') check=0;
		else{
			check=1;
			break;
		}
	while(check==0){
		printf("Incorrect value!  ");
		fgets(st1.main_info.workin.work_in, MAXSTRLEN, stdin);
		st1.main_info.workin.work_in[strlen(st1.main_info.workin.work_in)-1]=0;
		for(v=0; v<strlen(st1.main_info.workin.work_in); v++)
		if (st1.main_info.workin.work_in[v]==' ') check=0;
		else{
			check=1;
			break;
		}
		fflush(stdin);
	}
	fflush(stdin);
	 
	printf("Speciality field: ");
	fgets(st1.main_info.workaft.work_aft, MAXSTRLEN, stdin);
	st1.main_info.workaft.work_aft[strlen(st1.main_info.workaft.work_aft)-1]=0;
		check=0;
	for(v=0; v<strlen(st1.main_info.workaft.work_aft); v++)
		if (st1.main_info.workaft.work_aft[v]==' ') check=0;
		else{
			check=1;
			break;
		}
	while(check==0){
		printf("Incorrect value!  ");
		fgets(st1.main_info.workaft.work_aft, MAXSTRLEN, stdin);
		st1.main_info.workaft.work_aft[strlen(st1.main_info.workaft.work_aft)-1]=0;
		for(v=0; v<strlen(st1.main_info.workaft.work_aft); v++)
		if (st1.main_info.workaft.work_aft[v]==' ') check=0;
		else{
			check=1;
			break;
		}
		fflush(stdin);
	}
	fflush(stdin);
	
	for (i=0; i<strlen(st1.nnew); i++) (st1.nnew)[i]=toupper((st1.nnew)[i]);
	for (i=0; i<strlen(st1.histor); i++) (st1.histor)[i]=toupper((st1.histor)[i]);
	
	return st1;
}

//help function (new entry)
university_operativ* new_fun(university_operativ* start, int f_univ_number, int t, university st){	//t==0 -> create, t==1 -> import
	university_operativ *current=start;
	if (start==NULL){
		start=(university_operativ*)malloc(sizeof(university_operativ));
		if (!t) start->data=create_fun(f_univ_number+1);
		else start->data=st;
		start->next=NULL;
		if (start&&!t) printf("The record was added successfully!\n");
		else if (!start) printf("ERROR. Not enough memory! :-( )\n");
	} else {
		while (current->next!=NULL) current=(university_operativ*)(current->next);
		current->next=(university_operativ*)malloc(sizeof(university_operativ));
		if (!t) current->next->data=create_fun(f_univ_number+1);
		else current->next->data=st;
		current->next->next=NULL;
		if (current->next&&!t) printf("The record was added successfully!\n");
		else  if (!(current->next)) printf("ERROR. Not enough memory! :-( )\n");
	} 
	return start;
}

//display entries in RAM
void display_fun(university_operativ *start, FILE *f, int chk){
	if (start != NULL){
		int i=1, count;
		int marker, mark;
		if (chk==1){
			fprintf(f, "%3s %20s %20s %20s %20s %20s %20s %20s %20s\n", "###", "New_name", "Historical_name", "Profession", "Speciality_field", "Num_of_HR_studs","Students(HR)", "Num_of_Other_studs", "Students(O)");
		}
		while (start!=NULL){
			if (start->data.chosen){
			fprintf(f, "%3d %20s %20s %20s %20s %20d %12s %s %d %20d %14s %s %d\n", i, start->data.nnew, start->data.histor, start->data.main_info.workin.work_in, start->data.main_info.workaft.work_aft, 
					start->data.main_info.sizestud1, start->data.main_info.high_rating[0].full_name.name, start->data.main_info.high_rating[0].full_name.surname, start->data.main_info.high_rating[0].rating,
	              	start->data.main_info.sizestud2, start->data.main_info.others[0].full_name.name, start->data.main_info.others[0].full_name.surname, start->data.main_info.others[0].rating);
				if ((start->data.main_info.sizestud1)<(start->data.main_info.sizestud2)) {
				marker=(start->data.main_info.sizestud1);
				mark=1;
				}
				if ((start->data.main_info.sizestud2)<=(start->data.main_info.sizestud1)) {
				   marker=(start->data.main_info.sizestud2);
				   mark=2;	
				}
			
			
			    for (count=1; count<marker; count++)
				fprintf(f, "%3s %20s %20s %20s %20s %20s %12s %s %d %20s %14s %s %d\n", " ", " ", " "," "," "," ", start->data.main_info.high_rating[count].full_name.name, start->data.main_info.high_rating[count].full_name.surname, start->data.main_info.high_rating[count].rating,
				" ", start->data.main_info.others[count].full_name.name, start->data.main_info.others[count].full_name.surname, start->data.main_info.others[count].rating);
	    		
				if (mark=1){
	    			for (count=marker; count<(start->data.main_info.sizestud2); count++)
				    fprintf(f, "%3s %20s  %20s %20s %20s %20s %12s %s %s %20s %14s %s %d\n", " ", " ", " "," "," "," "," "," "," "," ", start->data.main_info.others[count].full_name.name, start->data.main_info.others[count].full_name.surname, start->data.main_info.others[count].rating);
				}
				
				if (mark=2){
	    		for (count=marker; count<(start->data.main_info.sizestud1); count++)
				    fprintf(f, "%3s %20s  %20s %20s %20s %20s %12s %s %d\n", " ", " ", " "," "," "," ", start->data.main_info.high_rating[count].full_name.name, start->data.main_info.high_rating[count].full_name.surname, start->data.main_info.high_rating[count].rating);
				}
				
			}	
			start=(start->next);
			i++;
		} 
		fflush(f);
	}
	else  printf("\nThere are no records in RAM. :(\n");
}

//change any entry
university_operativ* change_fun(university_operativ *start, int f_univ_number){
	int num, i=1;
	char buff[MAXSTRLEN];
	printf("Number of university to change information for: ");
	fgets(buff, MAXSTRLEN, stdin);
	fflush(stdin);
	
	while (!(num=atoi(buff))||(num>f_univ_number)){
		printf("Incorrect value! ");
		fgets(buff, MAXSTRLEN, stdin);
		fflush(stdin);	
	}	
	university_operativ* current=start;
	while (i++<num) current=(university_operativ*)(current->next);
	current->data=create_fun(num);
	printf("The record was changed successfully!\n");
	return start;
}

//delete any entry
university_operativ* delete_fun(university_operativ *start, int f_univ_number){
	if (start != NULL){
		int num, i=1;
		char buff[MAXSTRLEN];
		if (f_univ_number!=0){
		printf("Number of university to delete: ");
		fgets(buff, MAXSTRLEN, stdin);
		fflush(stdin);
		
		while (!(num=atoi(buff))||(num>f_univ_number)){
			printf("Incorrect value! ");
			fgets(buff, MAXSTRLEN, stdin);
			fflush(stdin);	
		}
		university_operativ* current=start, *current_1;
		while (++i<num) current=(current->next);
		if (num==1) {
			start=start->next;
			free(current);
		} else {
			current_1=(current->next);
			free(current_1);
			current->next=current->next->next;
		}
		}
		printf("Chosen record was deleted successfully!\n");
	}
	else printf("\nThere are no records to delete. :(\n");
	return start;
}

//delete all entries
university_operativ* delete_fun_all(university_operativ *start, int num_of_entries){
	university_operativ* st=start;
	if (start != NULL)
	{
		if (num_of_entries!=0){
			while (!st) {
				st=start->next;
				free(start);
				start=st;
			}
		}
		printf("\nCongrats!\nAll of the universities profiles in RAM were successfully\ndestroyed & eliminated! (if they existed, of course)\n");
	}
	else printf("\nThere are no records to delete. :(\n");
	return start=NULL;
}

//export current entries to any file
void export_fun(university_operativ *start, int num_of_entries){
	char buff[MAXSTRLEN], buff2[MAXSTRLEN], name_of_file[MAXSTRLEN_];
	FILE *f_univ;
	university_operativ* st=start;
	int i;
	
	printf("Enter name of file, please: ");
	fgets(name_of_file, MAXSTRLEN_, stdin);
	name_of_file[strlen(name_of_file)-1]=0;
	fflush(stdin);
	
	do {
	printf("CREATE or APPEND: ");
	fgets(buff, MAXSTRLEN, stdin);
	buff[strlen(buff)-1]=0;
	for (i=0; i<strlen(buff); i++) (buff)[i]=toupper((buff)[i]);
	fflush(stdin);
	} while (strcmp(buff,"CREATE")&&strcmp(buff,"APPEND"));
	
	
		if (!strcmp(buff,"CREATE")) {
			f_univ=fopen(name_of_file, "w");
			display_fun(start,f_univ, 1);	
		}
		else {
			f_univ=fopen(name_of_file, "a");
			display_fun(start,f_univ, 0);
		}
		
	fclose(f_univ);
	printf("%d Record(s) were successfully ( let's' hope together :-) ) exported!\n",num_of_entries);
}

//import entries from file
university_operativ* import_fun(university_operativ *start, int * num_of_entries){
	FILE *f_univ;
	university st1, st2;
	char name_of_file[MAXSTRLEN_];
	int i=*num_of_entries;
	int mark, marker, count;
	printf("Enter the name of file: ");
	fgets(name_of_file, MAXSTRLEN_, stdin);
	name_of_file[strlen(name_of_file)-1]=0;
	fflush(stdin);
	if (!(f_univ=fopen(name_of_file, "r"))) printf ("File not found!\n");
	else{
	ifstream file( name_of_file );
	char a0[50], a1[50], a2[50], a3[50], a4[50], a5[50], a6[50], a7[50], a8[50], a9[50], a10[50], a11[50], a12[50];
	char b0[200], b1[200], b2[200], b3[200], b4[200], b5[200];
	int size;
	char buffer[2000];
	char tem[4];
	file>>a0;
	strncpy(tem, a0, 3);
	if(strcmp(tem,"###")){
		file>>a1;//temp
		file>>a2;//temp
		file>>a3;//temp
		file>>a4;//temp
		file>>a5;//temp
		file>>a6;//temp
		file>>a7;//temp
		file>>a8;//temp
		file>>a0;
		file>>a1;//nnew
		file>>a2;//histor
		file>>a3;//work_in
		file>>a4;//work_aft
		file>>a5;//num HR
		file>>a6;//name HR
		file>>a7;//surname HR
		file>>a8;//rating HR
		file>>a9;//num Other
		file>>a10;//name Other
		file>>a11;//surname Other
		file>>a12;//rating Other
	}
	else{
		file>>a1;//nnew
		file>>a2;//histor
		file>>a3;//work_in
		file>>a4;//work_aft
		file>>a5;//num HR
		file>>a6;//name HR
		file>>a7;//surname HR
		file>>a8;//rating HR
		file>>a9;//num Other
		file>>a10;//name Other
		file>>a11;//surname Other
		file>>a12;//rating Other
	}	
	if( atoi(a5)>atoi(a9) ) size=(atoi(a5) - 1)*150 + 167;
	else size=atoi(a9) * 157;
	
	while (fread(&buffer,size,1,f_univ)==1) {
			strncpy(st1.nnew, a1, 20);
			st1.nnew[20]='\0';
			strncpy(st1.histor, a2, 20);
			st1.histor[20]='\0';
			strncpy(st1.main_info.workin.work_in, a3, 20);
			st1.main_info.workin.work_in[20]='\0';
			strncpy(st1.main_info.workaft.work_aft, a4, 20);
			st1.main_info.workaft.work_aft[20]='\0';
			
			st1.main_info.sizestud1=(atoi(a5));
			st1.main_info.sizestud2=(atoi(a9));
			st1.main_info.high_rating = (High_rating*) malloc(st1.main_info.sizestud1*sizeof(High_rating));//memory allocation
			st1.main_info.others = (Others*) malloc(st1.main_info.sizestud2*sizeof(Others));//memory allocation

			strncpy(st1.main_info.high_rating[0].full_name.name, a6, MAXSTRLEN);
			st1.main_info.high_rating[0].full_name.name[MAXSTRLEN-1]='\0';
			strncpy(st1.main_info.high_rating[0].full_name.surname, a7, MAXSTRLEN);
			st1.main_info.high_rating[0].full_name.surname[MAXSTRLEN-1]='\0';
			st1.main_info.high_rating[0].rating=atoi(a8);
			
			strncpy(st1.main_info.others[0].full_name.name, a10, MAXSTRLEN);
			st1.main_info.others[0].full_name.name[MAXSTRLEN-1]='\0';
			strncpy(st1.main_info.others[0].full_name.surname, a11, MAXSTRLEN);
			st1.main_info.others[0].full_name.surname[MAXSTRLEN-1]='\0';
			st1.main_info.others[0].rating=atoi(a12);
			
			if ((st1.main_info.sizestud1)<(st1.main_info.sizestud2)) {
			marker=st1.main_info.sizestud1;
			mark=1;
			}
			if ((st1.main_info.sizestud2)<=(st1.main_info.sizestud1)) {
			   marker=(st1.main_info.sizestud2);
			   mark=2;	
			}
	
		    for (count=1; count<marker; count++){
			    file>>b0;//name HR
				file>>b1;//surname HR
				file>>b2;//rating HR
				file>>b3;//name O
				file>>b4;//surname O
				file>>b5;//rating O
				strncpy(st1.main_info.high_rating[count].full_name.name, b0, MAXSTRLEN);
				st1.main_info.high_rating[count].full_name.name[MAXSTRLEN-1]='\0';
				strncpy(st1.main_info.high_rating[count].full_name.surname, b1, MAXSTRLEN);
				st1.main_info.high_rating[count].full_name.surname[MAXSTRLEN-1]='\0';
				st1.main_info.high_rating[count].rating=atoi(b2);
				
				strncpy(st1.main_info.others[count].full_name.name, b3, MAXSTRLEN);
				st1.main_info.others[count].full_name.name[MAXSTRLEN-1]='\0';
				strncpy(st1.main_info.others[count].full_name.surname, b4, MAXSTRLEN);
				st1.main_info.others[count].full_name.surname[MAXSTRLEN-1]='\0';
				st1.main_info.others[count].rating=atoi(b5);
			}
			
			if (mark=1){
    			for (count=marker; count<(st1.main_info.sizestud2); count++){
					file>>b3;//name O
					file>>b4;//surname O
					file>>b5;//rating O
					
					strncpy(st1.main_info.others[count].full_name.name, b3, MAXSTRLEN);
					st1.main_info.others[count].full_name.name[MAXSTRLEN-1]='\0';
					strncpy(st1.main_info.others[count].full_name.surname, b4, MAXSTRLEN);
					st1.main_info.others[count].full_name.surname[MAXSTRLEN-1]='\0';
					st1.main_info.others[count].rating=atoi(b5);
				}
			}
			    	
			if (mark=2){
    			for (count=marker; count<(st1.main_info.sizestud1); count++){
    			file>>b0;//name HR
				file>>b1;//surname HR
				file>>b2;//rating HR
			
				strncpy(st1.main_info.high_rating[count].full_name.name, b0, MAXSTRLEN);
				st1.main_info.high_rating[count].full_name.name[MAXSTRLEN-1]='\0';
				strncpy(st1.main_info.high_rating[count].full_name.surname, b1, MAXSTRLEN);
				st1.main_info.high_rating[count].full_name.surname[MAXSTRLEN-1]='\0';
				st1.main_info.high_rating[count].rating=atoi(b2);
				}
			}
			    
			start=new_fun(start,(*num_of_entries)++,1,st1);
			
			a0[0]='\0'; a1[0]='\0'; a2[0]='\0'; a3[0]='\0'; a4[0]='\0'; a5[0]='\0'; a6[0]='\0'; a7[0]='\0'; a8[0]='\0'; a9[0]='\0'; a10[0]='\0'; a11[0]='\0'; a12[0]='\0'; 

			file>>a0;
			file>>a1;//nnew
			file>>a2;//histor
			file>>a3;//work_in
			file>>a4;//work_aft
			file>>a5;//num HR
			file>>a6;//name HR
			file>>a7;//surname HR
			file>>a8;//rating HR
			file>>a9;//num Other
			file>>a10;//name Other
			file>>a11;//surname Other
			file>>a12;//rating Other
			if( atoi(a5)>atoi(a9) ) size=(atoi(a5) - 1)*150 + 167;
			else size=atoi(a9) * 167;
		}
		printf("%d Record(s) were successfully ( let's' hope together :-) ) imported!\n",*num_of_entries-i);
		buffer[0]='\0';
		fclose(f_univ);
	} 
	return start;
}

//help function for the next function
int compare_fun(university st1, university st2){
	int k=0;
		if ((st1.main_info.sizestud1+st1.main_info.sizestud2)==(st2.main_info.sizestud1+st2.main_info.sizestud2)) {
			k=0;
		} else if ((st1.main_info.sizestud1+st1.main_info.sizestud2)>(st2.main_info.sizestud1+st2.main_info.sizestud2)) k=1;
	
	if (k) return 1;
	else return 0;
}

//sort entries by number of students in each university
university_operativ* sort_fun(university_operativ *start, int num_entries){
	int i, j;
    university_operativ *current=start, *current_1, *current_2;
	for(i=1; i<num_entries; i++){
		for(j=1; j<num_entries; j++){
			if (current==start){
				if (compare_fun(current->data,current->next->data)) {
					current_1=start->next;
					start->next=start->next->next;
					current_1->next=start;
					start=current_1;
					current=start;
				}
			} else {
				if (compare_fun(current->data,current->next->data)) {
					current_1=current->next;
					current->next=current->next->next;
					current_1->next=current;
					current_2->next=current_1;
					current=current_1;
				}
			}
			current_2=current;
			current=current->next;
		}
		current=start;
	}
	if (num_entries!=0) printf("Sorting was made gr8!\n");
	if (num_entries==0) printf("There are no entries in RAM to sort!\n");
	return start;
}

//help structure to return structure for function HistorSearch (see next)
typedef struct NUM_t{
    int* HistSer;
    int histnum;
} NUM;

//search for universities, where hist and new names are the same
NUM sample_fun(university_operativ *start){
    NUM NUMH;
    NUMH.HistSer=(int*)malloc(1*sizeof(int));
    int i, j, count;
    i=0;
    j=0;
	while (start!=NULL){
		if (start->data.chosen){
	        if (strcmp(start->data.nnew, start->data.histor)==0){
	            NUMH.HistSer[j]=i;
	            j++;
	            int *Temp;
	            Temp = (int*) malloc(j*sizeof(int));
	            for (count=0; count<j; count++) Temp[count] = NUMH.HistSer[count];
	            free(NUMH.HistSer);
	            NUMH.HistSer=NULL;
	            NUMH.HistSer=(int*) malloc((j+1)*sizeof(int));
	            for (count=0; count<j; count++) NUMH.HistSer[count] = Temp[count];
	            free(Temp);
	            Temp=NULL;
	        }
		}
		 NUMH.histnum = j;
	    start=(start->next);
	    i++;
    }
    return NUMH;
}


int main(){
	int num_of_entries=0,i=0; // number of entries in RAM
	university_operativ *start=NULL;//entries in RAM; start - pointer to start
	char buff[MAXSTRLEN]={0}; //buffer
	university st;
	printf("Hello, Everybody!!!\nNice to see u today!!\nLet's start our journey! ;-)\n\n");
	do {
		fgets(buff,MAXSTRLEN,stdin);
		fflush(stdin);
		buff[strlen(buff)-1]=0;
		for (i=0; i<strlen(buff); i++) (buff)[i]=toupper((buff)[i]);
		if (!strcmp(buff,"HELP")) printf("\t\t\tAVAILABLE OPTIONS\n\nADD-To add a record to RAM.\nSHOW-To show records in RAM.\nCHANGE-To change any record.\nDEL-To delete any record.\nDEL_A-To delete all of the records.\nEXPORT-To export all records to file.\nIMPORT-To import records from file.\nSAME-To find universities with the same new & historical names.\nSORT-To sort entries by number of students in each university (increasing seq).\nEXIT-To exit (don't leave us ;) ).\n"); 
		else if (!strcmp(buff,"ADD")) {
			start=new_fun(start,num_of_entries,0,st);
				num_of_entries++;
		}
		else if (!strcmp(buff,"SHOW")) {
			printf("Number of records in memory: %d", num_of_entries);
			display_fun(start,stdout, 1); 
		}
		else if (!strcmp(buff,"CHANGE")) {
			if (num_of_entries==0) printf("No records to change!\n");
			else start=change_fun(start,num_of_entries); 
		}
		else if (!strcmp(buff,"DEL")) {
			start=delete_fun(start,num_of_entries);
			num_of_entries--;
		}
		else if (!strcmp(buff,"DEL_A")) {
			start=delete_fun_all(start, num_of_entries);
			num_of_entries=0; 	
		}
		else if (!strcmp(buff,"SORT")) {
			university_operativ *t_start;
			start=sort_fun(start, num_of_entries);
			t_start=start;
			while (t_start!=NULL){
				if (t_start->data.chosen){
					printf("%s %s\n", t_start->data.nnew, t_start->data.histor);
				}
				t_start=(t_start->next);
			}	
		}
		else if (!strcmp(buff,"EXPORT")) export_fun(start,num_of_entries);
		else if (!strcmp(buff,"IMPORT")) start=import_fun(start,&num_of_entries);
		else if (!strcmp(buff,"SAME")){
			int* HistorSear=sample_fun(start).HistSer;
    		int histnum = sample_fun(start).histnum;
    		int count=0;
    		university_operativ *temp_start;
    		temp_start=start;
    		while(temp_start!=NULL)
    		{
				for (i=0; i<histnum; i++) {
					if (count==HistorSear[i]) printf("University #%d. Name: %s.\n", HistorSear[i]+1, temp_start->data.nnew);
				}
			temp_start=(temp_start->next);
			count++;
			}
			if (start==NULL) printf("There are no entries in RAM!\n");
		}
		else if (!strcmp(buff,"EXIT")) start=delete_fun_all(start, num_of_entries);
		else printf("Oops, I don't understand you... Enter HELP for more info.\n");
		printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	} while (strcmp(buff,"EXIT"));
	return 0;
}
