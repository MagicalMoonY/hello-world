#include<stdio.h>
int main(){
	struct Date{
		int year;
		int month;
		int day;
	};
	struct Student{
		int num;//分号 
		char name[20];//汉字数组 //char *name
		char sex[3];
		struct Date birthday;//结构体内使用之前定义的结构体 
		float score;
	};
	struct Student student1 = {
		10168,
		"学友张",//逗号 
		"男",
		{1963,6,18},
		99.8
	};
	printf("学号：%d\n",student1.num);
	printf("姓名: %s\n",student1.name);
	printf("性别: %s\n",student1.sex);
	printf("生日: %d年%d月%d日\n",student1.birthday.year,student1.birthday.month,student1.birthday.day);
	printf("成绩: %.1lf\n",student1.score);
	struct Student student2[3]={//结构数组 
		{10102,"德华刘","男",{1990,7,30},98.1},
		{10103,"靓颖王","女",{1890,5,29},100}, 
		{10104,"富成郭","男",{1000,3,21},0}
	};
	for(int i = 0;i < 3;i++){
		printf("学号：%d\n",student2[i].num);
	    printf("姓名: %s\n",student2[i].name);
	    printf("性别: %s\n",student2[i].sex);
	    printf("生日: %d年%d月%d日\n",student2[i].birthday.year,student2[i].birthday.month,student2[i].birthday.day);
	    printf("成绩: %.1lf\n",student2[i].score);
	}
	return 0;
}
