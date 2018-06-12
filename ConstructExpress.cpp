#include<iostream>
using namespace std;
class Vehicle{
	public:
		Vehicle(int w,int wei){//基类构造函数，用于初始化基类数据 
			wheels = w;
			weight = wei;
		}
		void Show(void) const{
		    cout <<"轮胎数:"<<wheels<<"车重:"<<weight<<"kg"<<endl;
		}
	private:
		int wheels;//轮数
		int weight;//车重 
}; 
class Car : public Vehicle{//定义派生类 
	public:
		Car(int w,int wei,int p):Vehicle(w,wei){//派生类构造函数初始化列表 
			passenger_load = p;//初始化派生类新增数据成员 
		}
/*		派生类名（参数表） ：基类名1（参数表1），。。。，基类名n(参数表n) {//如果基类定义了无参数的构造函数，或者由编译器自动生成的默认构造函数时，在派生类构造函数的定义时可以省略对基类构造函数的调用，即在初始化列表中省略基类名（参数表） 
			派生类新增成员的初始化 
		}*/
		void Show(void) const {
		    cout <<"此轿车最多能载客："<<passenger_load<<"人"<<endl;//访问本类私有数据成员 
		    Vehicle :: Show();//访问基类同名成员函数Show(),需要使用作用域限定符 
		}
    private:
    	int passenger_load;
};
int main(){
	Car car(4,5000,5);//创建一个派生类对象 
	car.Show();
	return 0;
}
