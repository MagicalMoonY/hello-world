#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int goal[30];//��ʾN��Ŀ��Ҫ�ﵽ�ķ���
int f[25][25],g[30];
int main(){
	int n,m,ans1,ans2;
	while(scanf("%d",&n) != EOF){
		ans1 = -1;
		for(int i = 0;i < n;i++){
			scanf("%d",&goal[i]);
		}
		scanf("%d",&m);//ϰ����
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				scanf("%d",&f[i][j]);
			}
		} 
		for(int i = 1;i < (1 << m);i++){//���ö�����ö��ÿ��ϰ��Ҫ���ǲ�Ҫ 
			memset(g,0,sizeof(g));
			int num = 0;
			for(int j = 0;j < m;j++){
				if(i & (1 << j)){//���Ҫj���ϰ�� 
					num++;
					for(int k = 0;k < n;k++){
						g[k] += f[j][k];
					}
				}
			}
			int k1;
			for(k1 = 0;k1 < n;k1++){//�ж�ÿ��Ŀ���Ƿ񶼴ﵽ�˸����ķ���ֵ 
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
			printf("%d",ans1);//ϰ�ߵ����� 
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
