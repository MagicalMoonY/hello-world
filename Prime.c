#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int sum_bit(int num) {
	int sum1=0;
	while(num!=0){
		sum1+=num%10;
		num/=10;
	}
  return sum1;
}
int multi_bit(int num) {
	int mul=1;
	while(num!=0){
		mul*=num%10;
		num/=10;
	}
  return 0;
}
int square_sum_bit(int num) {
	int sum2=0;
	while(num!=0){
		sum2+=(num%10)*(num%10);
		num/=10;
	}
  return sum2;
}
bool isprime(int num) {
	int x=0;
	int i=0;
	for(i=2;i<num;i++){
		if(num%i==0){
			x=1;
			break;
		}
	}
	if(x==1){
		  return false;
	}
	else{
		return true;
	}
}
int main() {
	int i=0,j=0;
	int flag=0;
	int sum=0;
	int maxin=0;
	long long int allsum=0;
	for(i=100;i<=9999;i++){
	
	if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i))){
		sum++;
		allsum+=i;
		maxin=i;
	}
	}
	printf("%d %lld %d",sum,allsum,maxin);
}
