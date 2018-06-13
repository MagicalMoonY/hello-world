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
		friend double fDist(const CPoint *p1,const CPoint *p2);//friend double fDist(CPoint *p1,CPoint *p2)//��Ԫ�����ùؼ���friend���Σ���Ȼ�������������������ڸ���ĳ�Ա���� //��Ԫ�����ȿ��Է���public����Ҳ���Է���private�� 
	private:
		double x;
		double y;
};
//�������˳����� const ���� �������������� 
double fDist(const CPoint*p1, const CPoint *p2)/*double fDist(CPoint*p1,CPoint *p2)*/{//��Ԫ����fDist������CPoint��ĳ�Ա������ֻ��һ����ͨ���������������⺯��fDist()�Ķ��岻��д�� void CPoint :: fDist(CPoint *p1,CPoint *p2)  
	double x =  double(p1 -> x - p2 -> x);//���û����Ԫ��ϵ���������ͱ���Ѵ���p1->x ��Ϊp1->GetX();,��������Ե��߳�������Ƶ�����ú��������������Ŀ���
	double y = double(p1 -> y - p2 -> y);//��Ԫ����û��thisָ�룬��˱��뽫������Ϊ�������ݸ���Ԫ���� 
	return sqrt(x * x + y * y);
}//;;//���棬���������м����ֺŶ�û��Ӱ�� 
int main(){
	CPoint *p1 = new CPoint(1,1); 
	CPoint *p2 = new CPoint(4,5);
	cout << "The distance is:";
	cout << fDist(p1,p2)<<endl;
	delete p1;
	delete p2;
	return 0;
}

