#include<iostream>
using namespace std;
//���õĸ�ʽ�� ������ & ������ = ĳ��������ĳ�����������õȼ�������������൱�ڸñ�����һ������ 
int main(){
	int n = 7;
	int m = 6;
	int &r = n;//r������n,r��������int & 
	r = 4;
	cout << r << n;//�������4��r�ĸı�ͬʱ�ı���n
	n = 5;
	cout << r;//�޸�rҲ�����޸�n; 
	int & r1 = r;
	cout << r1;//r1Ҳ����n 
	r = m;//��ʱ�Ǹ�ֵ�������ã�
	cout << r; 
	return 0;
}
