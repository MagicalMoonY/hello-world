#include<iostream>
using namespace std;
void swap(int & a,int & b){
	int c;
	c = a;
	a = b;
	b = c;
} 
int main(){
	int n1,n2;
	cin>>n1>>n2;
	swap(n1,n2);
	cout<<n1<<' '<<n2<<endl;
	return 0;
}
