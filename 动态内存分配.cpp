#include<iostream>
using namespace std;
int main(){
	int *pn;//分配一个变量 P = new T,T是任意类型名，P是类型为T*的指针。动态分配出一片大小为sizeof(T)的空间，并且将该内存空间的起始地址赋值给p 
	pn = new int;
	*pn = 5; 
	int *mn;//分配一个数组，P = new T[N] 
	int i = 5;
	mn = new int[i * 20];
	mn[0] = 20;//使用该数组 
	delete pn;//内存空间的释放：delete 指针；
	//delete pn ,出现异常，一片空间不能被delete多次
	delete []mn;//释放动态分配的数组 delete []指针 
	return 0;
}
