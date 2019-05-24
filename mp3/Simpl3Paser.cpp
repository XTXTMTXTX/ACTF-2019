#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<winuser.h>
//#include"minimp3/minimp3_ex.h"
using namespace std;
int ch,indata[1024],n;
int main(int argc,char *argv[]){
	if(argc==1){
		printf("Usage: %s Filename\n",argv[0]);
		system("pause");
		return 0;
	}
	FILE *fp,*fpo;
	
	if(!(fp=fopen(argv[1],"rb+"))){
		printf("Openning File Failed\n");
		system("pause");
		return 0;
	}
	if(!(fpo=fopen("out.hex","wb"))){
		printf("Openning File Failed\n");
		system("pause");
		return 0;
	}
	int ch=fgetc(fp),i=0;
	int p=0,out=0;
	while(ch!= EOF){
		if(ch!=0xff){ch=fgetc(fp);i++;continue;}
		while(i++,(ch=fgetc(fp))==0xff);
		if(ch!=0xfb){ch=fgetc(fp);i++;continue;}
		ch=fgetc(fp);i++;
		if((ch&0xf0)^0xb0)continue;
		int by=ch&1;
		ch=fgetc(fp);i++;
		if((ch^0x60)&0xf0)continue;
		printf("%d		%08X: %d   %d\n",p,i-3,by,ch&0xf);
		p++;
		out=out<<1|by;
		
		if(0==p%8){
			fputc(out,fpo);
			out=0;
		}
		//fputc(by,fpo);
		ch=fgetc(fp);i++;
	}
	return 0;
}
