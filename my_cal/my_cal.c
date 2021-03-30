char _my_getchar();
void _my_putchar(char ch);
void _my_exit();

int rd(){
	int ans=0;char i=_my_getchar();
	while(i<'0'||i>'9')i=_my_getchar();
	while('0'<=i&&i<='9'){ans=ans*10+i-'0';i=_my_getchar();}
	return ans;
}
void prt(int x){
	if(x>10)prt(x/10);
	_my_putchar('0'+x%10);
}
int main(){
	int a=rd(),b=rd();
	prt(a+b);
	return 0;
}
