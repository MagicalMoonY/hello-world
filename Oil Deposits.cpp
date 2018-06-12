#include<iostream>
#include<cstring>
using namespace std;
char map[100][100];//存图 
int dir[8][2] = {//8个方向
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1},
} ;
int vis[100][100];//用来判重，之前是否已经遍历
int n,m,ans;
void DFS(int i,int j){//参数i,j表示点（i,j） 
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
			scanf("%s",&map[i]);//以字符串的形式读入 
		}
		ans = 0;//全局变量
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
