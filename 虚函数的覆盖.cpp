#include<iostream>
#include<string>
//������ָ�������������¶����ڻ����ж����ͬ���������������ж���ĺ������ܸ��ǵ���ֻ���ڻ����������ĺ���ԭ����ȫһ�£��������������������ĸ����Ͳ������͵���ȫ��ͬ�����������岻ͬ�����һ��ຯ��Ϊ�麯��ʱ����ʵ������ȷ�ĸ��� 
using namespace std;
class CPerson{
	public:
		CPerson(int age,string name);
		//��Show�趨Ϊ�麯���ͷ��麯���ֱ����г���
		virtual void Show(int age)const;//��ʾ�˵����䣬���� 
		virtual void Show()const;//��ʾ�˵����� 
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
	CPerson *poCP;//����ָ���������ָ�� 
	CStudent oCS(8,"Clinton","Grade Two");
	poCP =&oCS;//����ָ��ָ����������� 
	oCS.Show(1);//ͨ�����������ֻ�ܵ������������¶����ͬ������
	//oCS.Show()//ͨ������������ܵ��ñ����صĻ���ͬ������ 
	poCP->Show();//ͨ������ָ����Ե��ñ����صĻ��ຯ��Show() 
	poCP->Show(1);//���麯��ʱ��ͨ������ָ����Ե��ñ����صĻ���Show(),�麯��ʱ���γɸ��ǹ�ϵ�����Ե����������Show(1),���麯���Ͳ����麯��֮��任��ʱ�򣬶Դ���������䲻��Ҫ���и��� 
	return 0;
}
