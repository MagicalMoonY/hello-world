#include<iostream>
#include<cstring>
using namespace std;
void MyPrintf(const char *p){//����������Ϊ����ָ��ʱ�����Ա��⺯���ڲ���С�ĸı����ָ����ָ�ط������� 
//	strcpy(p,"this");//strcpy�ĵ�һ��������char * ����const char *�������� 
	printf("%s",p);
} 
int main(){
	const int MAX_VAL = 24;//������������
	int n = 1,m = 2;
	const int *p = &n;//���峣��ָ��
	//*p = 5;//������ͨ������ָ���޸���ָ�������
	n = 4;//ok,n��ֵ����ֱ���޸�
	p = &m;// ok,����ָ��Ҳ����ָ����������
	const int *p1;
	int * p2;
	p1 = p2;//ok���԰ѷǳ���ָ�븳ֵ������ָ��
	//p2 = p1//���ִ��󣬲��ܰѳ���ָ�븳ֵ���ǳ���ָ�룬����ͨ��ǿ������ת������,���� 
	p2 = (int *)p1;//ok 
	return 0;
}
