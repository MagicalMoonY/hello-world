#include<cstdlib>
#include<iostream>
#include<algorithm> //algorithm��Ϊ"�㷨",��C++�ı�׼ģ���(STL)������Ҫ��ͷ�ļ�֮һ���ṩ�˴������ڵ������ķǳ�Աģ�庯����
using namespace std;
struct inp{
	int x,y;
	double c;
}node[1005];
int cmp(inp a,inp b){
	return a.c > b.c;
}
int main(){
	int i,n,m;
	double j;
	while(scanf("%d%d",&m,&n),n != -1,m != -1){/*�����ڼӶ��ŵı��ʽ���ڶ��ű��ʽ�����ű��ʽ�Ĺ����Ǵ�����������ִ����䣬
	���������һ�����Ľ����������㵽������һ�����ʽ��ֵΪ�棬���������ű��ʽΪ�棬����Ϊ�١�*/
		for(i = 0;i < n;i++){
			scanf("%d%d",&node[i].x,&node[i].y);
			node[i].c = node[i].x / node[i].y;
		}
		sort(node,node + n,cmp);// ����������sort��sort(begin,end,compare)
		j = 0;
		for(i = 0;i < n;i++){
			if(node[i].y <= m){
				j += node[i].x;
				m -= node[i].y;
			}
			else{
				j += m * node[i].c;
				break;
			}
		}
		printf("%.3lf\n",j);		
//		printf("%d %d\n",EXIT_SUCCESS,EXIT_FAILURE);				
	}
	return EXIT_SUCCESS;// EXIT_SUCCESS��Ӧ����EXIT_FAILURE
}
