#include<iostream>
#include<string>
//�м̳й�ϵ��ʱ������������Ӧ�����Ϊ�麯�������캯����������Ϊ�麯���� 
using namespace std;
class CPerson{
	public:
		virtual ~CPerson();//�����virtual,����Ϊ�麯����������delete���ٶ���ʱ����� 
	protected:
		int m_age;
		string m_name;
}; 
class CStudent:public CPerson{
	public:
		~CStudent();//���������������Ҳ��ü���virtual
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
	if(NULL == poCP){//���new����ʧ�ܣ����˳� 
		exit(0);//����0��ʾ�������˳����� 
	}
	delete poCP;//ͨ������ָ���������������
	cout << "ͨ��delete����new����������Ķ������!\n"<<endl;
	CStudent oCSt;//����һ��CStudent���󣬲�ʹ��deleteʱ�������ܹ���ȷ���� 
	return 0;
}

