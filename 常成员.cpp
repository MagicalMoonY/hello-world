#include<iostream>
using namespace std;
//C++规定，常对象只能调用类的常成员函数以及类的静态成员函数 
class A{
	public://const是函数类型的一部分，因此在常成员函数实现部分也要带有const关键字 
		int GetValue()const{//常成员函数，格式是：返回值类型 函数名（参数表) const. 常成员函数只能访问对象的数据成员，而不能修改他们的值，也不能在函数体中调用非const修饰的函数 
			return w * h;
		}
		int GetValue(){//常成员函数的重载 ，常对象调用常成员函数，普通对象调用普通成员函数 
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
		C(int i):a(i){//初始化列表，等价于
		/*
		C（int i）{
		    a = i;
		} 
		*/ 

		}
		void Print()const{
			cout<< a<< ":" << b << ":"<<endl;
		}
	private:
		const int a;//常数据成员，该数据成员的初始化只能通过初始化列表完成 
		static const int b;
}; 
const int C :: b = 10;
int main(){
	A const a(3,4);
	A c(2,6);
	cout << a.GetValue()<<endl<<c.GetValue()<<endl;//输出和 
	C a1(100),a2(0);
	a1.Print();
	a2.Print();
	return 0;
}
