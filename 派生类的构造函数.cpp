#include<iostream>
using namespace std;
class Vehicle{
	public:
		Vehicle(int w,int wei){//���๹�캯�������ڳ�ʼ���������� 
			wheels = w;
			weight = wei;
		}
		void Show(void) const{
		    cout <<"��̥��:"<<wheels<<"����:"<<weight<<"kg"<<endl;
		}
	private:
		int wheels;//����
		int weight;//���� 
}; 
class Car : public Vehicle{//���������� 
	public:
		Car(int w,int wei,int p):Vehicle(w,wei){//�����๹�캯����ʼ���б� 
			passenger_load = p;//��ʼ���������������ݳ�Ա 
		}
/*		���������������� ��������1��������1������������������n(������n) {//������ඨ�����޲����Ĺ��캯���������ɱ������Զ����ɵ�Ĭ�Ϲ��캯��ʱ���������๹�캯���Ķ���ʱ����ʡ�ԶԻ��๹�캯���ĵ��ã����ڳ�ʼ���б���ʡ�Ի������������� 
			������������Ա�ĳ�ʼ�� 
		}*/
		void Show(void) const {
		    cout <<"�˽γ�������ؿͣ�"<<passenger_load<<"��"<<endl;//���ʱ���˽�����ݳ�Ա 
		    Vehicle :: Show();//���ʻ���ͬ����Ա����Show(),��Ҫʹ���������޶��� 
		}
    private:
    	int passenger_load;
};
int main(){
	Car car(4,5000,5);//����һ����������� 
	car.Show();
	return 0;
}
