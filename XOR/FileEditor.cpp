#include<cstdio>
#include<cstdlib>
using namespace std;
int ch,indata[1024],n;
int main(int argc,char *argv[]){
	if(argc==1){
		printf("Usage: FileEditor.exe Filename\n");
		system("pause");
		return 0;
	}
	FILE *fp,*fpo;
	
	if(!(fp=fopen(argv[1],"rb+"))){
		printf("Openning File Failed\n");
		system("pause");
		return 0;
	}
	if(!(fpo=fopen("out.png","wb"))){
		printf("Openning File Failed\n");
		system("pause");
		return 0;
	}
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)scanf("%c",&indata[i]);
	int ch=fgetc(fp),p=0;
	while(ch!=EOF){
		fputc(ch^indata[p],fpo);
		p++;
		p%=n;
		ch=fgetc(fp);
	}
	return 0;
}
