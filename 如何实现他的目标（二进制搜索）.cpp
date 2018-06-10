#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int goal[30];//表示N个目标要达到的分数
int f[25][25],g[30];
int main(){
	int n,m,ans1,ans2;
	while(scanf("%d",&n) != EOF){
		ans1 = -1;
		for(int i = 0;i < n;i++){
			scanf("%d",&goal[i]);
		}
		scanf("%d",&m);//习惯数
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				scanf("%d",&f[i][j]);
			}
		} 
		for(int i = 1;i < (1 << m);i++){//利用二进制枚举每个习惯要还是不要 
			memset(g,0,sizeof(g));
			int num = 0;
			for(int j = 0;j < m;j++){
				if(i & (1 << j)){//如果要j这个习惯 
					num++;
					for(int k = 0;k < n;k++){
						g[k] += f[j][k];
					}
				}
			}
			int k1;
			for(k1 = 0;k1 < n;k1++){//判断每个目标是否都达到了给定的分数值 
				if(g[k1] < goal[k1]){
					break;
				} 
			}
			if(k1 >= n){
				if(num > ans1){
					ans1 = num;
					ans2 = i;
				}
				else if(num == ans1 && ans2 > i){
					ans1 = num;
					ans2 = i;
				}
			}
		}
		if(ans1 == -1){
			cout << 0 << endl;
		}
		else{
			printf("%d",ans1);//习惯的数量 
			for(int i = 0;i < n;i++){
				if(ans2 & (1 << i)){
					printf("%d ",i + 1);
				}
			}
			printf("\n");
		}
	}
	return 0;
} 
