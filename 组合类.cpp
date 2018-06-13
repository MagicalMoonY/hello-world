#include<iostream>
using namespace std;
//A,B����ͬһ������̳У�A,B������ͬһ��������� 
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
	cout << year << "��"<< month << "��"<< day << "��"<< endl; 
}
/*��һ���༴�����������������Ĺ��캯���Ķ�����ʽ
���� ���� ������������������1��������1����....������n��������n��,�Ӷ���1���βα�1��,��������,�Ӷ���n���βα�n��{
    �������������Ա�ĳ�ʼ�� 
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
	cout << "���Ϊ"<< number << "����Ա�ĳ���������";
	birthday.Print();//birthday���ù��г�Ա����Print(),���birthday�������� 
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
