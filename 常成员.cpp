#include<iostream>
using namespace std;
//C++�涨��������ֻ�ܵ�����ĳ���Ա�����Լ���ľ�̬��Ա���� 
class A{
	public://const�Ǻ������͵�һ���֣�����ڳ���Ա����ʵ�ֲ���ҲҪ����const�ؼ��� 
		int GetValue()const{//����Ա��������ʽ�ǣ�����ֵ���� ��������������) const. ����Ա����ֻ�ܷ��ʶ�������ݳ�Ա���������޸����ǵ�ֵ��Ҳ�����ں������е��÷�const���εĺ��� 
			return w * h;
		}
		int GetValue(){//����Ա���������� ����������ó���Ա��������ͨ���������ͨ��Ա���� 
			return w + h;
		}
		A(int x,int y){
			w = x;
			h = y;
		} 
		A(){
			
		}
	private:
	    int w,h;
};
class C{
	public:
		C(int i):a(i){//��ʼ���б��ȼ���
		/*
		C��int i��{
		    a = i;
		} 
		*/ 

		}
		void Print()const{
			cout<< a<< ":" << b << ":"<<endl;
		}
	private:
		const int a;//�����ݳ�Ա�������ݳ�Ա�ĳ�ʼ��ֻ��ͨ����ʼ���б���� 
		static const int b;
}; 
const int C :: b = 10;
int main(){
	A const a(3,4);
	A c(2,6);
	cout << a.GetValue()<<endl<<c.GetValue()<<endl;//����� 
	C a1(100),a2(0);
	a1.Print();
	a2.Print();
	return 0;
}
