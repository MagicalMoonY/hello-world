#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int Xuefen;
	char name[30];
	char Chinese_name[80];
	int highest_score;
	int lowest_score;
	int N;
	double average_score;
}COURSE; 
typedef struct{
	char number[20];
	char Name[30];
	double Mk;
	int Xuefen;
}STUDENT;
int main(){
	int j = 0;
	COURSE lesson[100];
	STUDENT my_students[100];
	int total_stu = 0;
	int total = 0;
	char reader[500];
	FILE *score,*student,*course;//���ļ� 
	score = fopen("score.tex","r");
	course = fopen("course.tex","r");
	student = fopen("student.tex","r");	
	while(fgets(reader,500,student) != NULL){//¼��ѧ������ //fgets��ָ�����ļ��ж�һ���ַ����������ṩ�Ļ������У�gets�ӱ�׼�����һ���ַ����������ṩ�Ļ������С�
		int m = 0,n = 0;
		char Xuehao[20];
		char Chi_name[50];
		while(reader[n] != '\t'){
			n++;
		}
		m = n + 1;
		while(reader[m] != '\t'){
			m++;
		}
		strncpy(Xuehao,reader,n); //strncpy()������3����������һ��������Ŀ¼�ַ������ڶ���������Դ�ַ�����������������һ������������Ҫ��Դ�ַ���������Ŀ���ַ����е��ַ�����
		Xuehao[n] = '\0';
		strncpy(Chi_name,reader + n + 1,m - n);//strncpy��ʵ��strcpy���ַ�������  sizeof�İ��� //����reader�������Ըı� 
		Chi_name[m - n - 1] = '\0';
		my_students[total_stu].Mk = 0;
		my_students[total_stu].Xuefen = 0;
		strcpy(my_students[total_stu].Name,Chi_name);
		strcpy(my_students[total_stu].number,Xuehao);
		total_stu++;
	}
	while(fgets(reader,500,course) != NULL){//¼��γ̳ɼ� 
		int Xuefen;
		char en_name[30];
		char che_name[80];
		int m = 0,n = 0;
		while(reader[m] != '\t'){
			m++;
		}
		n = m + 1;
		while(reader[n] != '\t'){
			n++;
		}
		strncpy(en_name,reader,m);
		en_name[m] = '\0';
		strncpy(che_name,reader + m + 1,n - m);
		che_name[n - m - 1] = '\0';
		Xuefen = reader[n + 1] - '0';
		lesson[total].Xuefen = Xuefen;
		strcpy(lesson[total].Chinese_name,che_name);
		strcpy(lesson[total].name,en_name);
		lesson[total].highest_score = -1;
		lesson[total].lowest_score = 9999;
		lesson[total].average_score = 0;
		lesson[total].N = 0;
		total++;
	}
	while(fgets(reader,500,score) != NULL){//���������γ���ѧ���ĳɼ����� 
		char stuname[40];
		reader[strlen(reader)] = '\0';
		char Name[50],Mark[20];
		int m = 0,n = 0;//���¶���ÿһ�еĿγ̺� 
		while(reader[n] != 'k' && n < strlen(reader)) {
			n++; 
		}
		if(n == strlen(reader)){
			continue;
		}
		m = n;
		while(reader[m] != '\t'){
			m++;
		}
		strncpy(Mark,&reader[n],m - n);
		Name[m - n] = '\0';
		int Ct = 0;//���¶���ÿһ�пγ̶�Ӧ��һ������
		while(reader[m] != '\0'){
			Ct++;
			m++;
		}
		strncpy(Mark,reader + m - Ct + 1,Ct);
		Mark[Ct - 2] = '\0';
		strncpy(stuname,reader,n);
		stuname[n - 1] = '\0';
		int fs = atoi(Mark);//atoi�ǰ��ַ���ת������������һ������
		for(int i = 0;i < total;i++){
			if(!strcmp(lesson[i].name,Name)){
				if(fs > lesson[i].highest_score){
					lesson[i].highest_score = fs;
				}
				if(fs < lesson[i].lowest_score){
					lesson[i].lowest_score = fs;
				}
				lesson[i].average_score = ((lesson[i]).average_score * lesson[i].N + (double)fs) / (lesson[i].N	+ 1);
				lesson[i].N++;
				j = i;
				break;			
			}
		}
		for(int i = 0;i < total_stu;i++){
			if(!strcmp(my_students[i].number,stuname)){
				my_students[i].Mk = (my_students[i].Mk * my_students[i].Xuefen + (double)fs * lesson[j].Xuefen) / (my_students[i].Xuefen + lesson[j].Xuefen);
				break;
		    }
		}
	}
	printf("���ſγ̵����ƣ���߷֣���ͷ֣�ƽ��������������£�\n");
	for(int i = 0;i < total;i++){
		printf("����ţ�%s\t�γ�����%-20s\t��ߣ�%d\t��ͣ�%d\tƽ����%lf\n",lesson[i].name,lesson[i].Chinese_name,lesson[i].highest_score,lesson[i].lowest_score,lesson[i].average_score);//\t ����������һ�Ʊ�λ�� 
		
	} 
	printf("\n��λͬѧ��������£�\n");
	for(int i = 0;i < total_stu;i++){
		printf("ѧ�ţ�%s\t������%-10s\tѧ�֣�%-5d\tƽ���֣�%lf\n",my_students[i].number,my_students[i].Name,my_students[i].Xuefen,my_students[i].Mk);
	}
	return 0;
}
