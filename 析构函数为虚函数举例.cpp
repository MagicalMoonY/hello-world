#include<iostream>
#include<string>
//有继承关系的时候，析构函数就应该设计为虚函数（构造函数不能声明为虚函数） 
using namespace std;
class CPerson{
	public:
		virtual ~CPerson();//必需加virtual,声明为虚函数，否则用delete销毁对象时会出错 
	protected:
		int m_age;
		string m_name;
}; 
class CStudent:public CPerson{
	public:
		~CStudent();//派生类的析构函数也最好加上virtual
	protected:
	    string m_grade; 
};
CPerson :: ~CPerson(){
	cout << "~CPerson!"<<endl;
}
CStudent :: ~CStudent(){
	cout << "~Student!"<<endl;
}
int main(){
	CPerson *poCP = new CStudent;
	if(NULL == poCP){//如果new操作失败，则退出 
		exit(0);//参数0表示非正常退出程序 
	}
	delete poCP;//通过基类指针销毁派生类对象
	cout << "通过delete析构new运算符创建的对象结束!\n"<<endl;
	CStudent oCSt;//构造一个CStudent对象，不使用delete时，对象都能够正确析构 
	return 0;
}

