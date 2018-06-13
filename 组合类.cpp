#include<iostream>
using namespace std;
//A,B属于同一范畴则继承，A,B不属于同一范畴则组合 
class Date{
	public:
		Date();
		Date(int y,int m,int d);
		void SetDate(int y,int m,int d);
		int IsLeapYear();
		void Print();
	private:
		int year,month,day;
}; 
class People{
	public:
		People(int num,char s,int n,int m,int d);
		~People();
		void SetNum(int n);
		void SetSex(char s);
		int GetNum() const;
		char GetSex() const;
		void Print();
	private:
		int number;
		char sex;
		Date birthday;
};
Date :: Date(){
	year = 2000;
	month = 1;
	day = 1;
}
Date :: Date(int y,int m,int d){
	year = y;
	month = m;
	day = d;
}
void Date :: SetDate(int y,int m,int d){
	year = y;
	month = m;
	day = d;
}
int Date :: IsLeapYear(){
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);  
}
void Date :: Print(){
	cout << year << "年"<< month << "月"<< day << "日"<< endl; 
}
/*当一个类即是组合类又是派生类的构造函数的定义形式
类名 ：： 类名（参数表）：基类1（参数表1），....，基类n（参数表n）,子对象1（形参表1）,。。。。,子对象n（形参表n）{
    本类新增对象成员的初始化 
} */
People :: People(int num,char s,int n,int m,int d):birthday(n,m,d){
	number = num;
	sex = s;
}
People :: ~People(){
	
}
int People :: GetNum()const{
	return number;
}
char People :: GetSex()const{
    return sex;
}
void People :: Print(){
	cout << "编号为"<< number << "的人员的出生日期是";
	birthday.Print();//birthday调用公有成员函数Print(),输出birthday的年月日 
}
void People :: SetNum(int n){
	number = n;
}
void People :: SetSex(char s){
	sex = s;
}
int main(){
	People p1(1001,'F',2000,11,4);
	p1.Print();
	return 0;
}
