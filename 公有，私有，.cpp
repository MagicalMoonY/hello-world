#include<iostream>
#include<cstring> 
/*
private:˽�г�Ա��ֻ���ڳ�Ա�����ڲ�����
public:���г�Ա���������κεط�����
protected:������Ա 
*/ 
using namespace std;
class CEmployee{
	private:
		char szName[30];//����
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
	cout << e1.szName;//ok,����ͬ�����������˽�г�Ա
	salary = (e1.salary + e2.salary ) / 2; 
}
/*
��������˽�г�Ա�Ļ��ƽ�����
���ص�Ŀ����ǿ�ƶԳ�Ա�����ķ���һ��Ҫͨ����Ա�������У���ô�Ժ��Ա���������͵������޸��Ժ�ֻ��Ҫ���ĳ�Ա�������ɣ���������ֱ�ӷ��ʳ�Ա��������䶼��Ҫ���ġ� 
*/ 
int main(){
	CEmployee e;
//	strcpy(e.szName,"Tom1234567889");//����������ܷ���˽�г�Ա,��main�����ﲻ�ܵ���˽�г�Ա 
	e.setName("Tom");//ok
	e.salary = 5000;//ok 
	return 0;
}
