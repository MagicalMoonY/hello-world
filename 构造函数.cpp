#include<iostream>
using namespace std;
//���캯������������ɶ���ĳ�ʼ��,���캯��û�з���ֵ���ͣ�����voidҲû�� 
class Date{
	public:
		Date();//����һ���޲εĹ��캯�� 
		Date(int y,int m,int d);//���캯��������//����һ���������������Ĺ��캯�� 
		void SetDate(int y,int m,int d); 
		int IsLeapYear();
		void Print();
	private: 
	    int year,month,day;	 
};
Date :: Date(){//����һ���޲εĹ��캯�� 
	year = 2000;
	month = 1;
	day = 1;
}
Date :: Date(int y,int m,int d){//����һ���������������Ĺ��캯�� 
	year = y;
	month = m;
	day = d; 
}
void Date ::SetDate(int y,int m,int d){
	year = y;
	month = m;
	day = d;
}
int Date :: IsLeapYear(){
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
void Date :: Print(){
	cout << year << "��" << month << "��" << day << "��" << endl; 
}
class CPoint{
	public:
		CPoint(int x1,int y1); 
		CPoint( const CPoint & obj);//�����������캯�� ,const����ʡ�� 
		~CPoint(){//���������ʲô����д��Ҳ����д��ǻ����ͷ��ڴ�ռ�� 
		}//�������� 
		int GetX(void);
		int GetY(void);
	private:
		int x;
		int y;
};
CPoint :: CPoint(int x1,int y1){
	x = x1;
	y = y1;
} 
CPoint :: CPoint(const CPoint & obj){//�������캯�� 
	x = obj.x;
	y = obj.y;
}
int CPoint :: GetX(void){
	return x;
} 
int CPoint :: GetY(void){
	return  y;
}
int main(){
	Date date1;//������һ���µĶ����ʱ��ϵͳ���Զ����ù��캯�� 
	date1.Print();
	Date date2(2012,9,1);
	date2.Print();
	CPoint a(20,50);//ϵͳ���ù��캯����������һ������Ϊ��20,50���ĵ�a 
	CPoint b(a);//ϵͳ���ÿ������캯�������õ�a���Ƶ�b 
	CPoint c = a;//ϵͳ���ÿ������캯�������õ�a���Ƶ�c//���������Ȼ��������һ����ֵ��䣬��������CPoint c��ʶ�Ŷ���c�����ڴ��������У�������������Ȼ�ǵ��ÿ������캯�� 
	cout << "��a�������ǣ�"<< a.GetX() << "," << a.GetY()<< ")" << endl;
	cout << "��b�������ǣ�"<< b.GetX() << "," << b.GetY()<< ")" << endl;
	cout << "��c�������ǣ�"<< c.GetX() << "," << c.GetY()<< ")" << endl; 
	return 0;
}
