#include<iostream>
using namespace std;
class CRectangle{//������һ���࣬���Զ���������ñ������Ƕ��� 
	public:
		int w,h;//��Ա���� 
		int Area(){//��Ա���� 
			return w * h;
		}
		int Perimeter(){
			return 2 * (w + h);
		}
		void Init(int w_,int h_){
			w = w_;
			h = h_;
		}
};
/*
��ĳ�Ա��������Ķ�����Էֿ�д
 class CRectangle{ 
	public:
		int w,h;//��Ա���� 
		int Area()��//��Ա���������ڴ˴����� 
		int Perimeter()�� 
		void Init(int w_,int h_)�� 
};
int CRectangle����Area(){
    return w * h;
}
int CRectangle :: Perimeter(){
    return 2 * (w +��)�� 
}
void CRectangle :: Init(int w_,int h_){
    w = w_;
    h = h_;
}
//CRectangle:: ˵������ĺ���ʱCRectangle��ĳ�Ա��������������ͨ���� 
*/ 
int main(){
	int w,h;
	CRectangle r;
	cin >>w >> h;
	r.Init(w,h);//���ó�Ա��������һ��������.��Ա����
	/*��������ָ��-����Ա��
	CRectangle r1,r2;
	CRectangle *p1 = & r1;
	CRectangle *p2 = &r2; 
	p1 -> w = 5;
	p2 ->Init(5,4);//Init������p2ָ��Ķ����� 
	*/ 
	/*
	��������������.��Ա��
	CRectangle r2;
	CRectangle & rr = r2;
	rr.w = 5;
	rr.Init(5,4);//rr��ֵ���ˣ�r2��ֵҲ��                                                                                                                                                                                                                         
	*/ 
	cout << r.Area() << endl << r.Perimeter() << endl;
	//����֮����ṹ�������ƣ������á�= �� ���ǲ����á�== ���ȣ��������ء� 
	return 0;
} 

