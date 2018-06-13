#include<iostream>
using namespace std;
//引用的格式是 类型名 & 引用名 = 某变量名，某个变量的引用等价于这个变量，相当于该变量的一个别名 
int main(){
	int n = 7;
	int m = 6;
	int &r = n;//r引用了n,r的类型是int & 
	r = 4;
	cout << r << n;//输出都是4对r的改变同时改变了n
	n = 5;
	cout << r;//修改r也可以修改n; 
	int & r1 = r;
	cout << r1;//r1也引用n 
	r = m;//此时是赋值不是引用；
	cout << r; 
	return 0;
}
