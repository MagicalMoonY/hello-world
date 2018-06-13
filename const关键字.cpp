#include<iostream>
#include<cstring>
using namespace std;
void MyPrintf(const char *p){//函数参数作为常量指针时，可以避免函数内部不小心改变参数指针所指地方的内容 
//	strcpy(p,"this");//strcpy的第一个类型是char * 遇到const char *会编译出错 
	printf("%s",p);
} 
int main(){
	const int MAX_VAL = 24;//定义整数常量
	int n = 1,m = 2;
	const int *p = &n;//定义常量指针
	//*p = 5;//不可以通过常量指针修改其指向的内容
	n = 4;//ok,n的值可以直接修改
	p = &m;// ok,常量指针也可以指向其他变量
	const int *p1;
	int * p2;
	p1 = p2;//ok可以把非常量指针赋值给常量指针
	//p2 = p1//出现错误，不能把常量指针赋值给非常量指针，但是通过强制类型转换可以,如下 
	p2 = (int *)p1;//ok 
	return 0;
}
