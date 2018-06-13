#include<iostream>
using namespace std;
class A{
	public:
		void SetX(int i);
		int GetX(void) const;
		int z;
	protected:
		int y;
	private:
		int x;
}; 
class B :public A{//当继承方式为public时，即表示公有继承。在公有继承方式下，基类的公有和保护成员在派生类中仍然是公有和保护成员，可以由派生类的成员函数来访问。派生类对象可以访问公有数据成员；至于基类的私有成员，无论派生类的成员函数还是派生类对象都无法访问 
	public:
		void SetValue(int,int,int,int,int);//声明的时候可以只写类型 
		void Display(void) const;
	protected:
		int m;
	private:
		int n;
};
void A :: SetX(int i){
	x = i;
}
int A :: GetX(void) const {
    return x;
}
void B :: SetValue(int a,int b,int c,int d,int e){
	//x = a'基类的私有数据x对派生类不可见，故直接访问非法 
	SetX(a);//通过公有成员函数SetX()来间接访问基类的私有数据x; 
	y = b;
	z = c;
	m = d;
	n = e;
}
void B :: Display(void) const{
	//cout << "x = "<< x << endl;x在派生类中不可访问 
    cout << "x = "<< GetX() << endl;
    cout << "y = "<< y << endl; 
	cout << "m = "<< m << endl;
	cout << "n = "<< n << endl; //派生类的私有成员在本类中可以访问 
}
int main(){
	B ObjB;
	ObjB.SetValue(1,2,3,4,5);
	ObjB.Display();
	cout << "z = "<< ObjB.z  << endl; 
	//cout << "y = "<< ObjB.y  << endl;基类的保护数据，不可以通过对象访问 
	//cout << "x = "<< ObjB.x  << endl;基类的私有数据，类外不可以访问 
	//cout << "m = "<< ObjB.m  << endl;派生类的保护数据，不可以通过对象访问 
	//cout << "n = "<< ObjB.n  << endl;派生类的私有数据，不可以通过对象访问 
	return 0;
}
