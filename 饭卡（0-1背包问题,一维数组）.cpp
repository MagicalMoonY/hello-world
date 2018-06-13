#include<stdio.h>
#include<stdlib.h>
int ZeroOnePack(int price[],int money,int n,int pos){
	int f[1024] = {0};
	for(int i = 1;i <= n;i++){
		if(i != pos){
			for(int j = money;j >= price[i];j--){
				if(f[j] < f[j - price[i]] + price[i]){
					f[j] = f[j - price[i]] + price[i];
				}
			}
		}
	}
	return money - f[money];
} 
int main(){
	int n,money,price[1024];
	while(scanf("%d",&n) == 1 && n){
		int max = 0;
		int pos;
		for(int i = 1;i <= n;i++){
			scanf("%d",&price[i]);
			if(max < price[i]){
				pos = i;
				max = price[i];
			}
		}
		scanf("%d",&money);
		if(money >= 5){
			printf("%d\n",ZeroOnePack(price,money - 5,n,pos) + 5 - max);
		}
		else{
			printf("%d\n",money);
		}
	}
	return 0;
}
