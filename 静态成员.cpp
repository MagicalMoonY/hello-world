#include<iostream>
using namespace std;
class Point{
	public:
		Point(){
			x = 0;
			y = 0;
			counter++;//当创建对象调用构造函数时，计数器的值增加一个 
		}
		Point(float x,float y){
			this ->x = x;
			this ->y = y;
			counter++;//当创建对象调用构造函数时，计数器的值增加一个
		}
		~Point(){
			counter--;//当析构对象调用析构函数时，计数器的值减少一个 
		}
		void move(float x,float y){
			this ->x = x;
			this ->y = y;
		}
		float getX(){
			return x;
		}
		float getY(){
			return y;
		}
		static int getCounter(){//添加静态成员函数getCounter()，专门负责读取counter的值 
			return counter;
		}
	private:
		float x;
		float y;
	public:
		static int counter;//静态数据成员不专属于某个对象，他的生命周期与整个程序相同，因此，即使某个对象消亡了，它还会在程序中继续存在，被同类的其它对象共享//静态数据成员的声明：static 数据类型 静态数据成员名 
};
int Point :: counter = 0;//在类外初始化静态数据成员counter//静态数据成员的初始化不能在构造函数中进行，应在类声明之外进行，格式： 数据类型 类名：：静态数据成员名 = 初始值 
int main(){
	Point *p1 = new Point(1,1);
	Point *p2 = new Point(1,3);
	Point *p3 = new Point(3,3);
	cout << "已创建的点数是："<< Point :: getCounter()<< endl;//通过类名调用getCounter()函数，返回counter
	cout << "已创建的点数是："<< Point :: counter<< endl;//直接调用，只有counter(静态数据成员是public才可以) ，而上面调用函数，无论是public还是private都可以 //静态数据成员所谓访问一般是通过类名和作用域限定符的形式访问，类名 ：： 静态数据成员，名 
	delete p1;
	delete p2;
	delete p3; 
/*
类的普通成员函数时通过this指针惊醒访问，而静态成员函数没有this指针，但可以通过类实现访问
static int Incr(){
   return i + j;//定义体格静态成员函数，实现静态数据成员j与非静态数据成员i相加，出错 
} 
要解决上面出现的问题，就只有把i所属的对象作为参数传递到静态成员函数中
static int Incr(Point p){
    return p.i + j;//因为i函数ncr()在Point类里，所以p可以直接访问数据成员i; 
} 
*/ 
	return 0;
} 
