#include<iostream>
#include<cstring>
using namespace std;
class A{
	private:
		friend class B;
		char *name;
		int age;
	public:
		A(char *str,int n){
			name = new char[strlen(str) + 1];
			strcpy(name,str);
			age = n;
		}
}; 
class B{
	public:
		void show(A x){
			cout << "����:" << x.name << endl;
			cout << "����:" << x.age << endl; 
		}
};
/*class B;������ʽ 
class A{
	...
	friend class B;
	....//B��ΪA����Ԫ�� 
};*/
int main(){
	A a("����",19);
	B b;
	b.show(a); //������A����B����Ϊ������Ԫ�࣬������B�ĳ�Ա������Ӧ�Ķ���Ϊ����A����Ԫ�������������ɷ�����A��˽�����ݳ�Աname��age 
	return 0;
}
