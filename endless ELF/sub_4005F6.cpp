#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 100005
#define ll long long
using namespace std;
unsigned ll ans[100000],q;
signed __int64 __fastcall GeneratingKey(unsigned int a1) {
	if(a1<100000&&ans[a1]!=q)return ans[a1];

	__int64 v1; // rax
	unsigned int i; // [rsp+14h] [rbp-2Ch]
	unsigned int j; // [rsp+18h] [rbp-28h]
	__int64 v5; // [rsp+20h] [rbp-20h]
	signed __int64 v6; // [rsp+20h] [rbp-20h]
	unsigned __int64 *ptr; // [rsp+28h] [rbp-18h]

	ptr = (unsigned __int64 *)malloc(0xA0uLL);
	v5 = 0LL;
	if ( a1 <= 0x13 ) {
		v6 = a1 * (a1 + 1337) + 7331;
	} else {
		for ( i = 0; i < 0x14; ++i ) {
			ptr[i] = GeneratingKey(a1 - i - 1);
			if ( i & 1 && 19 != i )
				ptr[i] = ptr[i - 1] - ptr[i];
		}
		for ( j = 0; j < 0x13; ++j ) {
			if ( j & 1 )
				v1 = ptr[j] * ptr[j];
			else
				v1 = ptr[j];
			v5 += v1;
		}
		v6 = 2019LL * ptr[19] + v5;
	}
	free(ptr);
	if(a1<100000)return ans[a1]=v6;
	return v6;
}
signed __int64 __fastcall GeneratingKey2(unsigned int a1) {

	__int64 v1; // rax
	unsigned int i; // [rsp+14h] [rbp-2Ch]
	unsigned int j; // [rsp+18h] [rbp-28h]
	__int64 v5; // [rsp+20h] [rbp-20h]
	signed __int64 v6; // [rsp+20h] [rbp-20h]
	unsigned __int64 *ptr; // [rsp+28h] [rbp-18h]

	ptr = (unsigned __int64 *)malloc(0xA0uLL);
	v5 = 0LL;
	if ( a1 <= 0x13 ) {
		v6 = a1 * (a1 + 1337) + 7331;
	} else {
		for ( i = 0; i < 0x14; ++i ) {
			ptr[i] = GeneratingKey2(a1 - i - 1);
			if ( i & 1 && 19 != i )
				ptr[i] = ptr[i - 1] - ptr[i];
		}
		for ( j = 0; j < 0x13; ++j ) {
			if ( j & 1 )
				v1 = ptr[j] * ptr[j];
			else
				v1 = ptr[j];
			v5 += v1;
		}
		v6 = 2019LL * ptr[19] + v5;
	}
	free(ptr);
	return v6;
}
int main() {
	printf("%llX ",GeneratingKey(0xAAA));
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		memset(ans,0x7E,sizeof(ans));
		memset(&q,0x7E,sizeof(q));
		printf("%llX ",GeneratingKey(i));
		printf("%llX\n",GeneratingKey2(i));
	}

	return 0;
}
