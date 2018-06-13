#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
#define size 500000
int data[size + 1];
bool inp[size * 10];//设置的很好，避免了从头开始遍历
int main(){
	int n;
	memset(inp,false,sizeof(inp));
	data[0] = 0;
	inp[0] = true;
	for(int i = 1;i <= 500000;i++){
		if(data[i - 1] - i > 0 && inp[data[i - 1] - i] == false){
			data[i] = data[i - 1] - i;
		}
		else{
			data[i] = data[i - 1] + i;
		}
		inp[data[i]] = true;
	}
	while(cin >> n && n != -1){
		cout << data[n] << endl;
	}
	return 0;
} 
