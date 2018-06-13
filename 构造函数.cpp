#include<iostream>
using namespace std;
//构造函数的作用是完成对象的初始化,构造函数没有返回值类型，就连void也没有 
class Date{
	public:
		Date();//声明一个无参的构造函数 
		Date(int y,int m,int d);//构造函数的重载//声明一个带有三个参数的构造函数 
		void SetDate(int y,int m,int d); 
		int IsLeapYear();
		void Print();
	private: 
	    int year,month,day;	 
};
Date :: Date(){//定义一个无参的构造函数 
	year = 2000;
	month = 1;
	day = 1;
}
Date :: Date(int y,int m,int d){//定义一个带有三个参数的构造函数 
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
	cout << year << "年" << month << "月" << day << "日" << endl; 
}
class CPoint{
	public:
		CPoint(int x1,int y1); 
		CPoint( const CPoint & obj);//声明拷贝构造函数 ,const可以省略 
		~CPoint(){//这里面可以什么都不写，也可以写标记或者释放内存空间等 
		}//析构函数 
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
CPoint :: CPoint(const CPoint & obj){//拷贝构造函数 
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
	Date date1;//当创建一个新的对象的时候，系统会自动调用构造函数 
	date1.Print();
	Date date2(2012,9,1);
	date2.Print();
	CPoint a(20,50);//系统调用构造函数，创建了一个坐标为（20,50）的点a 
	CPoint b(a);//系统调用拷贝构造函数，利用点a复制点b 
	CPoint c = a;//系统调用拷贝构造函数，利用点a复制点c//这条语句虽然看起来像一条赋值语句，但是由于CPoint c标识着对象c正处在创建过程中，因此这条语句仍然是调用拷贝构造函数 
	cout << "点a的坐标是（"<< a.GetX() << "," << a.GetY()<< ")" << endl;
	cout << "点b的坐标是（"<< b.GetX() << "," << b.GetY()<< ")" << endl;
	cout << "点c的坐标是（"<< c.GetX() << "," << c.GetY()<< ")" << endl; 
	return 0;
}
