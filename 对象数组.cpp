#include<iostream>
using namespace std;
class CPoint{
	public:
		CPoint(){
			
		}
		~CPoint(){
			
		}
		CPoint(float x1,float y1);
		void Move(float x1,float y1);
		float x;
		float y;
}; 
CPoint :: CPoint(float x1,float y1){
	x = x1;
	y = y1;
}
void CPoint :: Move(float x1,float y1){
	x = x1;
	y = y1;
}
int main(){
//	CPoint *p = new CPoint[5];//����һ���������飬Ϊ������ڴ� 
    CPoint p[5];//Ч�������ָ������Ч��һ�� //emmm�о��ͽṹ������� 
	for(int i = 0;i < 5;i++){
		p[i].Move(i,i);
	} 
	for(int i = 0;i < 5;i++){
		cout << p[i].x << "," << p[i].y << endl;
	}
//	delete []p;//�ͷ�������ռ�õĶ��ڴ� 
	return 0;
}
