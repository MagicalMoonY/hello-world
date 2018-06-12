#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 50;
char map[maxn][maxn][maxn];
int L,R,W;
bool vis[maxn][maxn][maxn];
struct Node{
	int x,y,z;
	int step;
}q[maxn * maxn * maxn];//这个大小很值得研究 
int dir[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int bfs(int sx,int sy,int sz){
	int l = 0;
	int r = 0;
	q[r].x = sx,q[r].y = sy,q[r].z = sz,q[r++].step = 0;
	vis[sz][sx][sy] = 1;
	while(l < r){
		Node cur = q[l++],next;//结构体可以直接赋值 
		for(int i = 0;i < 6;i++){
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.z = cur.z + dir[i][2];
			next.step = cur.step + 1;
			if(next.x >= 1 && next.x <= R && next.y >= 1 && next.y <= W&& next.z >= 1 && next.z <= L &&map[next.z][next.x][next.y ]!= '#' && !vis[next.z][next.x][next.y]){
				if(map[next.z][next.x][next.y] == 'E'){//结束 
					return next.step;
				}
				vis[next.z][next.x][next.y] = 1;
				q[r++] = next;
			}
		}
	}
	return -1;
}
int main(){
	int sx,sy,sz;
	while(scanf("%d%d%d",&L,&R,&W) == 3 && (L || R || W)){//不要手贱在%d中间加上逗号 
		for(int i = 1;i <= L;i++){
			for(int j = 1;j <= R;j++){
				for(int r = 1;r <= W;r++){
					cin >> map[i][j][r];
					if(map[i][j][r] == 'S'){
						sz = i;
						sx = j;
						sy = r;
					}
				}
			}
		}
		memset(vis,0,sizeof(vis));
		int step = bfs(sx,sy,sz);
		if(step == -1){
			cout << "Trapped!"<<endl;
		}
		else{
			cout << "Escaped in " << step << " minute(s)." << endl;
		}
	}
	return 0;
}
