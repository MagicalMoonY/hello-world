#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
long long data[21][21][21];
long long inf(int x,int y,int z){
	if(x <= 0 || y <= 0 || z <= 0){
		return 1;
	}
	if(x > 20 || y > 20 || z > 20){
		return inf(20,20,20);
	}
	if(x < y && y < z){
		if(data[x][y][z] == -1){
			data[x][y][z] = inf(x,y,z - 1) + inf(x,y - 1,z - 1) - inf(x,y - 1,z);
		}
		return data[x][y][z];
	}
	else{
		if(data[x][y][z] == -1){
			data[x][y][z] = inf(x - 1,y,z) + inf(x - 1,y - 1,z) + inf(x - 1,y,z - 1) - inf(x - 1,y - 1,z - 1);
		}
		return data[x][y][z];
	}
}
int main(){
	int x,y,z;
	while(cin >> x >> y >> z){
		if(x == -1 && y == -1 && z == -1){
			break;
		}
		memset(data,-1,sizeof(data));
		cout << "w("<< x <<","<< y <<","<< z <<")"<< "=" << inf(x,y,z) << endl;//稍加注意一下这里的输出 
	}
	return 0;
}
