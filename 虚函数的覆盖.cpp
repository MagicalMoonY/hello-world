#include<iostream>
#include<string>
//覆盖是指在派生类中重新定义在基类中定义的同名函数，将基类中定义的函数功能覆盖掉，只有在基类和派生类的函数原型完全一致（即函数名、函数参数的个数和参数类型等完全相同，仅仅函数体不同），且基类函数为虚函数时，才实现了正确的覆盖 
using namespace std;
class CPerson{
	public:
		CPerson(int age,string name);
		//将Show设定为虚函数和非虚函数分别运行程序
		virtual void Show(int age)const;//显示人的年龄，姓名 
		virtual void Show()const;//显示人的姓名 
	protected:
		int m_age;
		string m_name;
};
class CStudent : public CPerson{
	public:
		CStudent(int age,string name,string grade);
		void Show(int age) const;
	protected:
		string m_grade;
};
CPerson::CPerson(int age,string name):m_age(age),m_name(name){
	
}
void CPerson :: Show(int age) const{
	cout <<"CPerson :: Show(age):"<<m_age<<",name:"<<m_name<<"."<<endl;
}
void CPerson :: Show()const{
	cout<<"CPerson :: Show(no age):"<<"name :"<<m_name<<"."<<endl;
}
CStudent::CStudent(int age,string name,string grade):CPerson(age,name),m_grade(grade){
	
} 
void CStudent :: Show(int age)const{
	cout << "CSsudent::Show(age):"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<"."<<endl;
}
int main(){
	CPerson *poCP;//定义指向基类对象的指针 
	CStudent oCS(8,"Clinton","Grade Two");
	poCP =&oCS;//基类指针指向派生类对象 
	oCS.Show(1);//通过派生类对象只能调用派生类重新定义的同名函数
	//oCS.Show()//通过派生类对象不能调用被隐藏的基类同名函数 
	poCP->Show();//通过基类指针可以调用被隐藏的基类函数Show() 
	poCP->Show(1);//非虚函数时，通过基类指针可以调用被隐藏的基类Show(),虚函数时，形成覆盖关系，可以调用派生类的Show(1),在虚函数和不是虚函数之间变换的时候，对此条调用语句不需要进行更改 
	return 0;
}
