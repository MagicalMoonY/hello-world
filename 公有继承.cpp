#include<iostream>
using namespace std;
class A{
	public:
		void SetX(int i);
		int GetX(void) const;
		int z;
	protected:
		int y;
	private:
		int x;
}; 
class B :public A{//���̳з�ʽΪpublicʱ������ʾ���м̳С��ڹ��м̳з�ʽ�£�����Ĺ��кͱ�����Ա������������Ȼ�ǹ��кͱ�����Ա��������������ĳ�Ա���������ʡ������������Է��ʹ������ݳ�Ա�����ڻ����˽�г�Ա������������ĳ�Ա������������������޷����� 
	public:
		void SetValue(int,int,int,int,int);//������ʱ�����ֻд���� 
		void Display(void) const;
	protected:
		int m;
	private:
		int n;
};
void A :: SetX(int i){
	x = i;
}
int A :: GetX(void) const {
    return x;
}
void B :: SetValue(int a,int b,int c,int d,int e){
	//x = a'�����˽������x�������಻�ɼ�����ֱ�ӷ��ʷǷ� 
	SetX(a);//ͨ�����г�Ա����SetX()����ӷ��ʻ����˽������x; 
	y = b;
	z = c;
	m = d;
	n = e;
}
void B :: Display(void) const{
	//cout << "x = "<< x << endl;x���������в��ɷ��� 
    cout << "x = "<< GetX() << endl;
    cout << "y = "<< y << endl; 
	cout << "m = "<< m << endl;
	cout << "n = "<< n << endl; //�������˽�г�Ա�ڱ����п��Է��� 
}
int main(){
	B ObjB;
	ObjB.SetValue(1,2,3,4,5);
	ObjB.Display();
	cout << "z = "<< ObjB.z  << endl; 
	//cout << "y = "<< ObjB.y  << endl;����ı������ݣ�������ͨ��������� 
	//cout << "x = "<< ObjB.x  << endl;�����˽�����ݣ����ⲻ���Է��� 
	//cout << "m = "<< ObjB.m  << endl;������ı������ݣ�������ͨ��������� 
	//cout << "n = "<< ObjB.n  << endl;�������˽�����ݣ�������ͨ��������� 
	return 0;
}
