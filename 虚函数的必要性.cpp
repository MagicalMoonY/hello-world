#include<iostream>
using namespace std;
class CShape{
	public:
		CShape(double x,double y,double z);
		void Show()const;
	protected:
		double m_x;
		double m_y;
		double m_z;
		double m_area;
}; 
class CCircle : public CShape{
	public:
		CCircle(double x,double y,double z,double radius);
		void Show()const;
	protected:
		double m_radius;
};
CShape :: CShape(double x,double y,double z):m_x(x),m_y(y),m_z(z){
	
}
void CShape::Show()const{
	cout << "x="<<m_x<<",y="<< m_y<<",z="<<m_z<<"."<<endl;
}
CCircle :: CCircle(double x,double y,double z,double radius):CShape(x,y,z),m_radius(radius){
	
}
void CCircle::Show() const{
	cout << "x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",radius="<<m_radius<<"."<<endl;
}
int main(){
	CShape oCS(1.1,2.0,3.0);
	CShape *poCS;
	CCircle oCC(10.0,20.1,30.0,100.0);
	poCS = &oCS;
	poCS->Show();
	poCS = &oCC;
	poCS->Show();//������������Ӧ����radius,�����ڴ�ʱ�Ĵ����в�������radius,��Ϊ������Show��������Ȼָ�����ǵ���CCIRCLE�ģ��������ڱ�������⣬���ǵ��õĻ���� 
	return 0;
}
