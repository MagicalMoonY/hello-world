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
	this->length = l;//this指针，没有什么作用，出了两个都是xy是提示一下//调用的时候，系统先将指向对象的指针的起始地址赋值给this指针，然后成员函数通过this指针操作 
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
	cout << "长方形的长是" << length << "宽是" << width << "面积是" << GetArea() << endl; 
}
int main(){
	Rectangle *rp = new Rectangle(10,5);//为长方形对象分配堆内存，并让指针rp指向这块内存 //指向对象的指针 
	rp->Print();//调用rp所指向的对象成员函数print() 
	rp->SetSize(45,20);
	cout << "改变后长方形的面积是"<< rp->GetArea()<<endl;
	delete rp;//释放指针rp所指向的堆内存 
	return 0;
}
