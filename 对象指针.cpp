#include<iostream>
using namespace std;
class Rectangle{
	public:
		Rectangle();
		Rectangle(double l,double w);
		~Rectangle(){
			
		}
		void SetSize(double l,double w);
		double GetLength();
		double GetWidth();
		double GetArea();
		void Print();
	private:
		double length;
		double width;
}; 
Rectangle :: Rectangle(double l,double w){
	length = l;
	width = w;
}
void Rectangle :: SetSize(double l,double w){
	this->length = l;//thisָ�룬û��ʲô���ã�������������xy����ʾһ��//���õ�ʱ��ϵͳ�Ƚ�ָ������ָ�����ʼ��ַ��ֵ��thisָ�룬Ȼ���Ա����ͨ��thisָ����� 
	this->width = w;
}
double Rectangle :: GetLength(){
	return length;
}
double Rectangle :: GetWidth(){
	return width;
}
double Rectangle :: GetArea(){
	return length * width;
}
void Rectangle :: Print(){
	cout << "�����εĳ���" << length << "����" << width << "�����" << GetArea() << endl; 
}
int main(){
	Rectangle *rp = new Rectangle(10,5);//Ϊ�����ζ��������ڴ棬����ָ��rpָ������ڴ� //ָ������ָ�� 
	rp->Print();//����rp��ָ��Ķ����Ա����print() 
	rp->SetSize(45,20);
	cout << "�ı�󳤷��ε������"<< rp->GetArea()<<endl;
	delete rp;//�ͷ�ָ��rp��ָ��Ķ��ڴ� 
	return 0;
}
