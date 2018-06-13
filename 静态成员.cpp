#include<iostream>
using namespace std;
class Point{
	public:
		Point(){
			x = 0;
			y = 0;
			counter++;//������������ù��캯��ʱ����������ֵ����һ�� 
		}
		Point(float x,float y){
			this ->x = x;
			this ->y = y;
			counter++;//������������ù��캯��ʱ����������ֵ����һ��
		}
		~Point(){
			counter--;//���������������������ʱ����������ֵ����һ�� 
		}
		void move(float x,float y){
			this ->x = x;
			this ->y = y;
		}
		float getX(){
			return x;
		}
		float getY(){
			return y;
		}
		static int getCounter(){//��Ӿ�̬��Ա����getCounter()��ר�Ÿ����ȡcounter��ֵ 
			return counter;
		}
	private:
		float x;
		float y;
	public:
		static int counter;//��̬���ݳ�Ա��ר����ĳ������������������������������ͬ����ˣ���ʹĳ�����������ˣ��������ڳ����м������ڣ���ͬ�������������//��̬���ݳ�Ա��������static �������� ��̬���ݳ�Ա�� 
};
int Point :: counter = 0;//�������ʼ����̬���ݳ�Աcounter//��̬���ݳ�Ա�ĳ�ʼ�������ڹ��캯���н��У�Ӧ��������֮����У���ʽ�� �������� ����������̬���ݳ�Ա�� = ��ʼֵ 
int main(){
	Point *p1 = new Point(1,1);
	Point *p2 = new Point(1,3);
	Point *p3 = new Point(3,3);
	cout << "�Ѵ����ĵ����ǣ�"<< Point :: getCounter()<< endl;//ͨ����������getCounter()����������counter
	cout << "�Ѵ����ĵ����ǣ�"<< Point :: counter<< endl;//ֱ�ӵ��ã�ֻ��counter(��̬���ݳ�Ա��public�ſ���) ����������ú�����������public����private������ //��̬���ݳ�Ա��ν����һ����ͨ���������������޶�������ʽ���ʣ����� ���� ��̬���ݳ�Ա���� 
	delete p1;
	delete p2;
	delete p3; 
/*
�����ͨ��Ա����ʱͨ��thisָ�뾪�ѷ��ʣ�����̬��Ա����û��thisָ�룬������ͨ����ʵ�ַ���
static int Incr(){
   return i + j;//�������̬��Ա������ʵ�־�̬���ݳ�Աj��Ǿ�̬���ݳ�Աi��ӣ����� 
} 
Ҫ���������ֵ����⣬��ֻ�а�i�����Ķ�����Ϊ�������ݵ���̬��Ա������
static int Incr(Point p){
    return p.i + j;//��Ϊi����ncr()��Point�������p����ֱ�ӷ������ݳ�Աi; 
} 
*/ 
	return 0;
} 
