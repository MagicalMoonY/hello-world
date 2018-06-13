#include<iostream>
using namespace std;
class CRectangle{//定义了一个类，可以定义变量，该变量就是对象 
	public:
		int w,h;//成员变量 
		int Area(){//成员函数 
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
类的成员函数和类的定义可以分开写
 class CRectangle{ 
	public:
		int w,h;//成员变量 
		int Area()；//成员函数仅仅在此处声明 
		int Perimeter()； 
		void Init(int w_,int h_)； 
};
int CRectangle：：Area(){
    return w * h;
}
int CRectangle :: Perimeter(){
    return 2 * (w +ｈ)； 
}
void CRectangle :: Init(int w_,int h_){
    w = w_;
    h = h_;
}
//CRectangle:: 说明后面的函数时CRectangle类的成员函数，而不是普通函数 
*/ 
int main(){
	int w,h;
	CRectangle r;
	cin >>w >> h;
	r.Init(w,h);//调用成员函数方法一：对象名.成员名；
	/*方法二：指针-〉成员名
	CRectangle r1,r2;
	CRectangle *p1 = & r1;
	CRectangle *p2 = &r2; 
	p1 -> w = 5;
	p2 ->Init(5,4);//Init作用在p2指向的对象上 
	*/ 
	/*
	方法三：引用名.成员名
	CRectangle r2;
	CRectangle & rr = r2;
	rr.w = 5;
	rr.Init(5,4);//rr的值变了，r2的值也变                                                                                                                                                                                                                         
	*/ 
	cout << r.Area() << endl << r.Perimeter() << endl;
	//对象之间与结构变量类似，可以用“= ” 但是不能用“== ”等，除非重载。 
	return 0;
} 

