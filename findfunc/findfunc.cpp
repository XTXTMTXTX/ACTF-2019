#include<cstdio>
#include<cstring>
using namespace std;
unsigned char dword_C001194[28] = {
	0x30, 0xB2, 0xAA, 0xC4, 
	0x84, 0x4E, 0xCA, 0x0D, 
	0x4C, 0x55, 0xCA, 0x76, 
	0x9B, 0xF0, 0x28, 0xE5,
	0x9E, 0xCB, 0x71, 0x04, 
	0x08, 0xA9, 0xA2, 0x30, 
	0x00, 0x00, 0x00, 0x00
};
char *__fastcall sub_C000FB8(char *result, char *a2, int a3) {
	char *v3; // lr
	int v4; // r3
	int v5; // r3
	unsigned __int8 v6; // r5
	int v7; // r4
	char v8; // r8
	char v9; // r7
	char *v10; // r7

	v3 = result + 8;
	v4 = 0;
	*(unsigned int *)result = 0;
	*((unsigned int *)result + 1) = 0;
	do {
		v3[v4] = v4;
		++v4;
	} while ( v4 != 256 );
	v5 = 0;
	v6 = 0;
	v7 = 0;
	do {
		v8 = v3[v5];
		if ( v7 >= a3 )
			v7 = 0;
		v9 = a2[v7++];
		v6 += v8 + v9;
		v10 = &result[v6];
		v3[v5++] = v10[8];
		v10[8] = v8;
	} while ( v5 != 256 );
	return result;
}
int __fastcall sub_C001030(char *input, signed int a2, char *iiinput, char *output) {
	int v4; // lr
	int v5; // r12
	char *v6; // r5
	char v7; // r6
	char v8; // r4
	char v9; // t1

	v4 = *(unsigned int *)input;
	v5 = *((unsigned int *)input + 1);
	if ( a2 >= 1 ) {
		do {
			v6 = input + 8;
			--a2;
			v4 = (unsigned __int8)(v4 + 1);
			v7 = input[v4 + 8];
			v5 = (unsigned __int8)(v5 + v7);
			v8 = input[v5 + 8];
			v6[v4] = v8;
			v6[v5] = v7;
			v9 = *iiinput++;
			*output++ = input[(unsigned __int8)(v8 + v7) + 8] ^ v9;
		} while ( a2 );
	}
	*(unsigned int*)input = v4;
	*((unsigned int *)input + 1) = v5;
	return 0;
}
char v6[500],v9[500],v10[500];
char ans[5000];
//char ans[28]={0x66, 0x6c, 0x61, 0x67, 0x7b, 0x44, 0x6f, 0x31, 0x6e, 0x1b, 0x5f, 0x49, 0x26, 0x5f, 0x62, 0x45, 0x6c, 0x69, 0x33, 0x75, 0x4c, 0x4e, 0x39, 0x7d,0};
int main() {

	for(int i=0; i<24; i++) {
		for(int j=127; j>=0; j--) {
			memcpy(v6,ans,i);
			v6[i]=j;
			sub_C000FB8(v9,"Java_com_a_findfunc_MainActivity_check", 38);
			sub_C001030(v9, i+1, v6, v10);
			if((unsigned char)v10[i]==dword_C001194[i]) {
				ans[i]=j;
				break;
			}
			for(int k=0; k<i+1; k++)printf("%02x, ",(unsigned char)v10[k]);
			putchar('\n');
		}
	}
	ans[24]=0;
	for(int k=0; k<24; k++)printf("%02X",(unsigned char)ans[k]);
	putchar('\n');
	puts(ans);
	//while(1){
	//	for(int i=0;i<v7;i++)printf("%02x, ",(unsigned char)v10[i]);
	//	putchar('\n');
	//}
	//puts(v10);
	/*
	memcpy(v6,ans,24);
	puts(ans);
	v6[24]=0;
	int v7=strlen(v6);
	sub_C000FB8(v9,"Java_com_a_findfunc_MainActivity_check", '&');
	sub_C001030(v9, v7, v6, v10);
	for(int i=0;i<v7;i++)printf("%02x, ",(unsigned char)v10[i]);
	*/
}
