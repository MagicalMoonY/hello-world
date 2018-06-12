#include<iostream>
#include<cstring>
using namespace std;
char map[100][100];//��ͼ 
int dir[8][2] = {//8������
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1},
} ;
int vis[100][100];//�������أ�֮ǰ�Ƿ��Ѿ�����
int n,m,ans;
void DFS(int i,int j){//����i,j��ʾ�㣨i,j�� 
	vis[i][j] = 1;
	for(int k = 0;k < 8;k++){
		int x = i + dir[k][0];
		int y = j + dir[k][1];
		if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && map[x][y] == '@'){
			DFS(x,y);
		}
	}
	return;
} 
int main(){
	while(cin >> n >> m){
		if(!n && !m){
			break;
		}
		for(int i = 0;i < n;i++){
			scanf("%s",&map[i]);//���ַ�������ʽ���� 
		}
		ans = 0;//ȫ�ֱ���
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!vis[i][j] && map[i][j] == '@'){
					ans++;
					DFS(i,j);
				}
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
