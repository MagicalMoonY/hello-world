#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 510;//��Ŀ���������д�λ�����ĺ����� 
char map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}} ;
int ans,n,m,x1[maxn * maxn],y1[maxn * maxn],top,an[maxn][maxn];
void dfs(int x,int y){
	vis[x][y] = 1;
	if(map[x][y] == 'C'){
		ans++;
	}
	x1[top] = x;
	y1[top++] = y;
	for(int i = 0;i < 4;i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && map[nx][ny] != '#'){
			dfs(nx,ny); 
		}
	}
}
int main(){
	int ca,cas = 1,q;
	scanf("%d",&ca);
	while(ca--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> map[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		memset(an,-1,sizeof(an));//���an[x][y]�Ѿ�������ˣ���ֱ�����
		int x,y;
		printf("Case %d:\n",cas++);
		while(q--){//�ȶ���ͼ��Ȼ��߶��룬����� 
			scanf("%d%d",&x,&y);
			if(an[x - 1][y - 1] == -1){
				top = 0;
				ans = 0;
				dfs(x - 1,y - 1);
			}
			for(int r = 0;r < top;r++){//��������ͨ· 
				an[x1[r]][y1[r]] = ans;
			}
			printf("%d\n",an[x - 1][y -1]);
		}
	}
	return 0;
}
