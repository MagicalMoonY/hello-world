#include<iostream>
using namespace std;
int main(){
	int *pn;//����һ������ P = new T,T��������������P������ΪT*��ָ�롣��̬�����һƬ��СΪsizeof(T)�Ŀռ䣬���ҽ����ڴ�ռ����ʼ��ַ��ֵ��p 
	pn = new int;
	*pn = 5; 
	int *mn;//����һ�����飬P = new T[N] 
	int i = 5;
	mn = new int[i * 20];
	mn[0] = 20;//ʹ�ø����� 
	delete pn;//�ڴ�ռ���ͷţ�delete ָ�룻
	//delete pn ,�����쳣��һƬ�ռ䲻�ܱ�delete���
	delete []mn;//�ͷŶ�̬��������� delete []ָ�� 
	return 0;
}
