#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Ccount(char *file){//��ѯ�ַ�������
FILE *f;
char a;
int num=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a!=' '&&a!='\n'&&a!='\t')//����Ƿ�Ϊ�ո񡢻��з���tab
        num++;
    }
fclose(f);
if(f!=NULL) printf("the char number is:%d\n",num);
}

void Wcount(char *file){//��ѯ��������
FILE *f;
char a;
int num=0; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) tag=1;
        else if(tag==1){//a������ĸ�ұ�־Ϊ1ʱ��˵���ռ����һ������
            num++;
            tag=0;
        }
    }
fclose(f);
if(f!=NULL) printf("the word number is:%d\n",num);
}

void Lcount(char *file){//��ѯ��������
FILE *f;
char a;
int num=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a=='\n') num++;
    }
num++;//�����ļ�����ʱ�޻��з�������ǰ��Ҳ��һ�У���Ҫ��һ
fclose(f);
if(f!=NULL) printf("the line number is:%d\n",num);
}

void blankcount(char *file){//��ѯ���к���
FILE *f;
char a;
int num=0; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) tag=1;//��־λΪ1��ʾ�������ַ�
        else if(a=='\n'&&tag==0){//�����޵����ַ��Ҷ�ȡ�����з��������һ
            num++;
        }
        else if(a=='\n'&&tag==1){//�����е����ַ��Ҷ�ȡ�����з����־λ��λ��0
            tag=0;
        }
    }
if(tag==0) num++;
fclose(f);
if(f!=NULL) printf("the blankline number is:%d\n",num);
}

void codecount(char *file){//��ѯ�����к���
FILE *f;
char a;
int num1=0,num2=0,num; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a=='\n') num1++;//num1ͳ������
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) tag=1;//num2ͳ�ƿ�����
        else if(a=='\n'&&tag==0){
            num2++;
        }
        else if(a=='\n'&&tag==1){
            tag=0;
        }
    }
num1++;
if(tag==0) num2++;
num=num1-num2;//�����е���������������
fclose(f);
if(f!=NULL) printf("the codeline number is:%d\n",num);
}



void notecount(char *file){//��ѯע���к���
FILE *f;
char a;
int num=0; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a=='/'&&tag==0) tag=1;//����⵽��һ����/��ʱ�����һ���ַ�Ϊ��/�����ߡ�*�������һ��ע��
        else if((tag==1&&a=='/')||(tag==1&&a=='*')){
            num++;
            tag=0;
        }
    }
fclose(f);
if(f!=NULL) printf("the noteline number is:%d\n",num);
}

void main(int a,char **fname){
FILE *file;
while(1){
        file=fopen(fname[2],"r");
        if(file==NULL){//����ļ��Ƿ����
            printf("no file\n");
            scanf("%s%s%s",fname[0],fname[1],fname[2]);
            continue;
        }else if(!strcmp(fname[1],"-c")) Ccount(fname[2]);
         else if(!strcmp(fname[1],"-w")) Wcount(fname[2]);
         else if(!strcmp(fname[1],"-l")) Lcount(fname[2]);
         else if(!strcmp(fname[1],"-a")){
            blankcount(fname[2]);
            codecount(fname[2]);
            notecount(fname[2]);
         }
         printf("\n");
         scanf("%s%s%s",fname[0],fname[1],fname[2]);
    }
}
