#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Ccount(char *file){//查询字符数函数
FILE *f;
char a;
int num=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a!=' '&&a!='\n'&&a!='\t')
        num++;
    }
fclose(f);
if(f!=NULL) printf("the char number is:%d\n",num);
}

void Wcount(char *file){//查询词数函数
FILE *f;
char a;
int num=0; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if((a>='a'&&a<='z')||(a>='A'&&a<='A')) tag=1;
        else if(tag==1){
            num++;
            tag=0;
        }
    }
fclose(f);
if(f!=NULL) printf("the word number is:%d\n",num);
}

void Lcount(char *file){//查询行数函数
FILE *f;
char a;
int num=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a=='\n') num++;
    }
num++;
fclose(f);
if(f!=NULL) printf("the line number is:%d\n",num);
}

void blankcount(char *file){//查询空行函数
FILE *f;
char a;
int num=0; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) tag=1;
        else if(a=='\n'&&tag==0){
            num++;
        }
        else if(a=='\n'&&tag==1){
            tag=0;
        }
    }
if(tag==0) num++;
fclose(f);
if(f!=NULL) printf("the blankline number is:%d\n",num);
}

void codecount(char *file){//查询代码行函数
FILE *f;
char a;
int num1=0,num2=0,num; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a=='\n') num1++;
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) tag=1;
        else if(a=='\n'&&tag==0){
            num2++;
        }
        else if(a=='\n'&&tag==1){
            tag=0;
        }
    }
num1++;
if(tag==0) num2++;
num=num1-num2;
fclose(f);
if(f!=NULL) printf("the codeline number is:%d\n",num);
}



void notecount(char *file){//查询注释行函数
FILE *f;
char a;
int num=0; int tag=0;
f=fopen(file,"r");
if(f==NULL) printf("no file\n");
else while(!feof(f)){
        a=fgetc(f);
        if(a=='/'&&tag==0) tag=1;
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
        if(file==NULL){//检查文件是否存在
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
