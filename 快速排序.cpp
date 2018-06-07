#include "stdio.h"
#include "stdlib.h"
#include "time.h"//���ڻ�ȡ��������ʱ��  

void quick_sort(int s[],int l,int r)
{
    if(l < r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]>=x)//���ҵ����ҵ���һ��С��x����  
                j--;
            if(i<j)
                s[i++]=s[j];
            
            while(i<j && s[i]<=x)//���������ҵ���һ������x����  
                i++;
            if(i<j)
                s[j--]=s[i]; 
            
        }
        
        s[i]=x;//i = j��ʱ�򣬽�x�����м�λ��  
        quick_sort(s,l,i-1);//�ݹ���� 
        quick_sort(s,i+1,r);        
    }
}


int main()
{
    clock_t start,finish;
    double totaltime;
    start=clock();
    
    /****����Ϊ��Ҫ���е�������****/ 
    
    int a[] = {1,8,44,77,35,65,78,12,25,455,20,15,45};
    int length = sizeof(a)/sizeof(int);//������ĳ���  
    
    printf("ԭ����Ϊ�� ");
    for(int i=0;i<length;i++)
    {
        printf("%3d",a[i]);
    }
    
    quick_sort(a,0,length);
    
    printf("\n����������Ϊ��");
    for(int i=0;i<length;i++)
    {
        printf("%3d",a[i]);
    }

    /********************************/
        
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   
   printf("\n�������е�ʱ��Ϊ: %.5f ��",totaltime);

}
