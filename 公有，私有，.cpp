#include<iostream>
#include<cstring> 
/*
private:私有成员，只能在成员函数内部访问
public:公有成员，可以在任何地方访问
protected:保护成员 
*/ 
using namespace std;
class CEmployee{
	private:
		char szName[30];//名字
	public:
	    int salary;
		void setName(char * name);
		void getName(char * name);
		void averageSalary(CEmployee e1,CEmployee e2);
};
void CEmployee :: setName(char * name){
	strcpy(szName,name);//ok
}
void CEmployee :: getName(char * name){
	strcpy(name,szName);//ok
}
void CEmployee :: averageSalary(CEmployee e1,CEmployee e2){
	cout << e1.szName;//ok,访问同类其他对象的私有成员
	salary = (e1.salary + e2.salary ) / 2; 
}
/*
这种设置私有成员的机制叫隐藏
隐藏的目的是强制对成员变量的访问一定要通过成员函数进行，那么以后成员变量的类型等属性修改以后，只需要更改成员函数即可，否则所有直接访问成员变量的语句都需要更改。 
*/ 
int main(){
	CEmployee e;
//	strcpy(e.szName,"Tom1234567889");//编译出错，不能访问私有成员,在main函数里不能调用私有成员 
	e.setName("Tom");//ok
	e.salary = 5000;//ok 
	return 0;
}
