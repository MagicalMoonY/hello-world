#include<iostream>
#include<math.h>
using namespace std;
class CPoint{
	public:
		CPoint(double xx = 0,double yy = 0){
			x = xx;
			y = yy;
		}
		double GetX(){
			return x;
		}
		double GetY(){
			return y;
		}
		friend double fDist(const CPoint *p1,const CPoint *p2);//friend double fDist(CPoint *p1,CPoint *p2)//友元函数用关键字friend修饰，虽然在类中声明，但不属于该类的成员函数 //友元函数既可以放在public区，也可以放在private区 
	private:
		double x;
		double y;
};
//下面用了常对象： const 类名 对象名（参数表） 
double fDist(const CPoint*p1, const CPoint *p2)/*double fDist(CPoint*p1,CPoint *p2)*/{//友元函数fDist并不是CPoint类的成员函数，只是一个普通函数，所以在类外函数fDist()的定义不能写成 void CPoint :: fDist(CPoint *p1,CPoint *p2)  
	double x =  double(p1 -> x - p2 -> x);//如果没有友元关系的声明，就必须把代码p1->x 改为p1->GetX();,这样表达显得冗长，而且频繁调用函数还会带来更多的开销
	double y = double(p1 -> y - p2 -> y);//友元函数没有this指针，因此必须将对象作为参数传递给友元函数 
	return sqrt(x * x + y * y);
}//;;//神奇，在这外面有几个分号都没有影响 
int main(){
	CPoint *p1 = new CPoint(1,1); 
	CPoint *p2 = new CPoint(4,5);
	cout << "The distance is:";
	cout << fDist(p1,p2)<<endl;
	delete p1;
	delete p2;
	return 0;
}

