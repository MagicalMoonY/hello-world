#include<cstdlib>
#include<iostream>
#include<algorithm> //algorithm意为"算法",是C++的标准模版库(STL)中最重要的头文件之一，提供了大量基于迭代器的非成员模板函数。
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
	while(scanf("%d%d",&m,&n),n != -1,m != -1){/*括号内加逗号的表达式属于逗号表达式，逗号表达式的规则是从左往右依次执行语句，
	并返回最后一个语句的结果，如果计算到最后最后一个表达式的值为真，则整个逗号表达式为真，否则为假。*/
		for(i = 0;i < n;i++){
			scanf("%d%d",&node[i].x,&node[i].y);
			node[i].c = node[i].x / node[i].y;
		}
		sort(node,node + n,cmp);// 三个参数的sort：sort(begin,end,compare)
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
	return EXIT_SUCCESS;// EXIT_SUCCESS对应的是EXIT_FAILURE
}
