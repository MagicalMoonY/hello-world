#include<iostream> 
using namespace std;
class Location{
	private:
		int x,y;
	public:
		void init(int x = 0,int y = 0);
		void valueX(int val){//��������һ����������ֻҪ������ͬ�Ϳ��� 
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
	A.init(5);//����һ����������y�Զ�����Ϊ0 
	A.valueX(5);
	cout << A.valueX() << endl;
/*
ʹ��ȱʡ������ʱ��Ҫע����⺯������ʱ�Ķ�����
 void valueX(int val = 0){//�޸��ڴ˴� 
			x = val;
		}
		int valueX(){
			return x;
		}
	��ʱ��main�������A.valueX�ͻ���������Ϊ�޷��ж�����һ��valueX 
*/
	return 0;
}
