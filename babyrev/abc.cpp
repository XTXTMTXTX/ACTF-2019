#include<cstdio>
#include<cstdlib>
#include<cstring>

#define N 40 
using namespace std;
char dict[80]=" 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@$,.()-=_+{}[]|";
int redict[256];
char poem[1453];
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//https://www.cnblogs.com/1436177712qqcom/p/10467470.html
int p=79,n=37;
struct xin {
	int a[N][N];
	//inline int* operator [](int x){return a[x];} //  b的话直接调用b[][]
	inline void Swap(int x,int y) {
		for(int i=1; i<=n; i++) {
			int t=a[x][i];
			a[x][i]=a[y][i];
			a[y][i]=t;
		}
	}
	inline void mul(int x,int k) {
		for(int i=1; i<=n; i++) a[x][i]=(a[x][i]*k%p+p)%p;   //a[x]=k*a[y];
	}
	inline void add(int x,int y,int k) {
		for(int i=1; i<=n; i++) a[x][i]=((a[x][i]+a[y][i]*k)%p+p)%p;   // a[x]加k*a[y]
	}
	inline void prt() {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) printf("%x ",a[i][j]);
			printf("\n");
		}
	}
} a,b;
int rev[81];
inline void init() {
	rev[0]=rev[1]=1;
	for(int i=2; i<p; i++)rev[i]=(p-p/i)*rev[p%i]%p;
}
void gaosi() {
	for(int i=1; i<=n; i++) {
		if(!a.a[i][i]) for(int j=i+1; j<=n; j++) if(a.a[j][i]) {
					a.Swap(i,j);
					b.Swap(i,j);
					break;
				}
		if(!a.a[i][i]) {
			printf("No Solution\n");
			exit(0);
		}
		b.mul(i,rev[a.a[i][i]]);
		a.mul(i,rev[a.a[i][i]]);//把所有项除a[i][i] 变成a[i][i]变成1
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			b.add(j,i,-a.a[j][i]);
			a.add(j,i,-a.a[j][i]);//消去  b要放前面因为a放前面会被修改
		}
	}
}
char fs[128];
int f[128],ans[128];
int matr[40][40]; 
int main() {
	init();
	gets(poem);
	gets(fs);
	int len=strlen(fs); 
	//printf("%d %d\n%s\n%s",strlen(dict),strlen(poem),dict,poem);
	for(int i=0; i<79; i++)redict[dict[i]]=i;
	for(int i=1; i<=len;i++)f[i]=redict[fs[i-1]];
	printf("%d\n",len);
	for(int i=0; i<1452; i++)if(i>=n*n)continue;
		else matr[i/n+1][i%n+1]=a.a[i/n+1][i%n+1]=redict[poem[i]];
	for(int i=1;i<=n;i++)b.a[i][i]=1;
	
	a.prt();
	
	gaosi();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)ans[i]=(ans[i]+b.a[i][j]*f[j])%p;
	
	for(int i=1;i<=n;i++)putchar(dict[ans[i]]);
	putchar('\n');
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)f[i]=(f[i]+matr[i][j]*ans[j])%p;
	
	for(int i=1;i<=n;i++)putchar(dict[f[i]]);
	putchar('\n');
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)ans[i]=(ans[i]+b.a[i][j]*f[j])%p;
	
	for(int i=1;i<=n;i++)putchar(dict[ans[i]]);
	return 0;
}
