#include<iostream> 
using namespace std;
class Location{
	private:
		int x,y;
	public:
		void init(int x = 0,int y = 0);
		void valueX(int val){//重载是用一个函数名，只要参数表不同就可以 
			x = val;
		}
		int valueX(){
			return x;
		}
};
void Location :: init(int X,int Y){ 
	x = X;
	y = Y;
}
int main(){
	Location A,B;
	A.init(5);//少了一个参数，则y自动定义为0 
	A.valueX(5);
	cout << A.valueX() << endl;
/*
使用缺省参数的时候要注意避免函数重载时的二义性
 void valueX(int val = 0){//修改在此处 
			x = val;
		}
		int valueX(){
			return x;
		}
	此时在main中如果有A.valueX就会编译出错，因为无法判断是哪一个valueX 
*/
	return 0;
}
