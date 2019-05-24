#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char a[1024];
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline int readb() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*2+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	int n=read();
	for(int k=0;k<n;k++){
		int t=readb();
		printf("%c",t);
	}
	return 0;
}
