#include<iostream>
using namespace std;
//���캯���������麯�������������������麯�����麯�������ǳ�Ա���� 
/*class ����
{
    virtual ����ֵ���� ������(������)
} */
class CShape{
	public:
		CShape(double x,double y,double z);
		virtual void Show() const;//�����麯�����������е�ĳ������������Ϊ�麯��֮�󣬸ú������������о�Ӧ�����¶��壻 
	protected:
		double m_x;
		double m_y;
		double m_z;
		double m_area;
}; 
class CCircle : public CShape{
	public:
		CCircle(double x,double y,double z,double radius);
		void Show() const;//��ʾ��������Ͱ뾶 
	protected:
		double m_radius;
};
class CRectangle : public CShape{
	public:
		CRectangle(double x,double y,double z,double length,double width);//�����ε��������꣬���Ϳ�
		void Show()const;
	protected:
	    double m_length;
		double m_width; 
};
class CSquare:public CShape{
	public:
		CSquare(double x,double y,double z,double edge);//�����ε���������ͱ߳�
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
	cout << "\n 1:-ͨ����������õ����麯������������----��"<<endl;
	Reference(oCS);
	Reference(oCC);
	Reference(oCR);
	Reference(oCSq);
	cout << "\n 2:-ͨ�������ָ������麯������������----��"<<endl;
	CShape *poCS;
	poCS = &oCS;
	poCS->Show() ;
	poCS= &oCC;
	poCS->Show();
	poCS = &oCR;
	poCS->Show();
	poCS = &oCSq;
	poCS->Show();
	cout << "\n 3:-ͨ��������ò����������ԣ���������ȷ----��"<<endl;
	oCS.Show();
	oCC.Show();
	oCR.Show();
	oCSq.Show(); 
	return 0;
}
