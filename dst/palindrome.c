#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[32],tp=0;
	while(n)a[tp++]=n%10,n/=10;
	int i=0;for(;i<=(tp>>1);++i)if(a[i]!=a[tp-i-1]){
		printf("N");return 0;
	}
	printf("Y");
	return 0;
}
