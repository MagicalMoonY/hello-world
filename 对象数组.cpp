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
//	CPoint *p = new CPoint[5];//声明一个对象数组，为其分配内存 
    CPoint p[5];//效果与对象指针数组效果一样 //emmm感觉和结构体很类似 
	for(int i = 0;i < 5;i++){
		p[i].Move(i,i);
	} 
	for(int i = 0;i < 5;i++){
		cout << p[i].x << "," << p[i].y << endl;
	}
//	delete []p;//释放数组所占用的堆内存 
	return 0;
}
