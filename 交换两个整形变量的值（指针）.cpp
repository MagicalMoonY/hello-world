#include<stdio.h>
void swap(int *a,int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int main(){
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	swap(&n1,&n2);
	printf("%d %d\n",n1,n2);
	return 0;
} 
