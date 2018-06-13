#include<iostream>
using namespace std;
//构造函数不能是虚函数，内联函数不能是虚函数，虚函数必须是成员函数 
/*class 类名
{
    virtual 返回值类型 函数名(参数表)
} */
class CShape{
	public:
		CShape(double x,double y,double z);
		virtual void Show() const;//定义虚函数，当基类中的某个函数被定义为虚函数之后，该函数在派生类中就应该重新定义； 
	protected:
		double m_x;
		double m_y;
		double m_z;
		double m_area;
}; 
class CCircle : public CShape{
	public:
		CCircle(double x,double y,double z,double radius);
		void Show() const;//显示重心坐标和半径 
	protected:
		double m_radius;
};
class CRectangle : public CShape{
	public:
		CRectangle(double x,double y,double z,double length,double width);//长方形的重心坐标，长和宽
		void Show()const;
	protected:
	    double m_length;
		double m_width; 
};
class CSquare:public CShape{
	public:
		CSquare(double x,double y,double z,double edge);//正方形的重心坐标和边长
		void Show() const;
	protected:
	    double m_edge; 
};
CShape :: CShape(double x,double y,double z):m_x(x),m_y(y),m_z(z){
	
}
void CShape :: Show() const{
    cout << "x="<<m_x<<",y="<< m_y<<",z="<< m_z<<"."<<endl;
}
CCircle ::CCircle(double x,double y,double z,double radius):CShape(x,y,z),m_radius(radius){
	
}
void CCircle :: Show()const{
	cout << "x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",radius"<<m_radius<<"."<<endl;
}
CRectangle :: CRectangle(double x,double y,double z,double length,double width):CShape(x,y,z),m_length(length),m_width(width){
	
}
void CRectangle::Show() const{
    cout << "x="<<m_x<<",y="<<m_y<<",z="<<",length="<<m_length<<",width="<<m_width<<"."<<endl;
}  
CSquare::CSquare(double x,double y,double z,double edge):CShape(x,y,z),m_edge(edge){
	
}
void CSquare::Show()const{
	cout << "x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",edge="<< m_edge<<"."<<endl;
}
void Reference(const CShape &roCS){
	roCS.Show();
}
int main(){
	CShape oCS(1.1,2.0,3.0);
	CCircle oCC(10.0,20.1,30.0,100.0);
	CRectangle oCR(1.1,1.2,1.3,5.4,5.5);
	CSquare oCSq(2.2,2.3,2.4,10.8);
	cout << "\n 1:-通过基类的引用调用虚函数具有虚特性----。"<<endl;
	Reference(oCS);
	Reference(oCC);
	Reference(oCR);
	Reference(oCSq);
	cout << "\n 2:-通过基类的指针调用虚函数具有虚特性----。"<<endl;
	CShape *poCS;
	poCS = &oCS;
	poCS->Show() ;
	poCS= &oCC;
	poCS->Show();
	poCS = &oCR;
	poCS->Show();
	poCS = &oCSq;
	poCS->Show();
	cout << "\n 3:-通过对象调用不具有虚特性，但调用正确----。"<<endl;
	oCS.Show();
	oCC.Show();
	oCR.Show();
	oCSq.Show(); 
	return 0;
}
