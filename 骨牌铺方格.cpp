#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	int n,i;
	long long a[55];
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	for(i = 3;i<55;i++){
		a[i] = a[i - 1] +a[i - 2];
	}
	while(cin >>n){
		cout <<a[n]<<endl; 
	}
	return 0;
}
