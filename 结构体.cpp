#include<stdio.h>
int main(){
	struct Date{
		int year;
		int month;
		int day;
	};
	struct Student{
		int num;//�ֺ� 
		char name[20];//�������� //char *name
		char sex[3];
		struct Date birthday;//�ṹ����ʹ��֮ǰ����Ľṹ�� 
		float score;
	};
	struct Student student1 = {
		10168,
		"ѧ����",//���� 
		"��",
		{1963,6,18},
		99.8
	};
	printf("ѧ�ţ�%d\n",student1.num);
	printf("����: %s\n",student1.name);
	printf("�Ա�: %s\n",student1.sex);
	printf("����: %d��%d��%d��\n",student1.birthday.year,student1.birthday.month,student1.birthday.day);
	printf("�ɼ�: %.1lf\n",student1.score);
	struct Student student2[3]={//�ṹ���� 
		{10102,"�»���","��",{1990,7,30},98.1},
		{10103,"��ӱ��","Ů",{1890,5,29},100}, 
		{10104,"���ɹ�","��",{1000,3,21},0}
	};
	for(int i = 0;i < 3;i++){
		printf("ѧ�ţ�%d\n",student2[i].num);
	    printf("����: %s\n",student2[i].name);
	    printf("�Ա�: %s\n",student2[i].sex);
	    printf("����: %d��%d��%d��\n",student2[i].birthday.year,student2[i].birthday.month,student2[i].birthday.day);
	    printf("�ɼ�: %.1lf\n",student2[i].score);
	}
	return 0;
}
