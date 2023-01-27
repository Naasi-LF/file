#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    rewind(FILE*fp)；文件指针还原到开头->追加模式下，文件指针在末尾
    
    fseek(FILE* fp,long bit,int mode)
    mode:SEEK_CUT->当前
         SEEK_SET->开始
         SEEK_END->末尾

    ftell():判断当前文件指针移动多少字节—>看大小

    feof():判断文件是否到末尾

*/

//用fseek，rewind改变文件指针
void readFile(const char* filename)
{
    FILE* fp=fopen(filename,"a+");
      //这个文件还是读不了东西，文件指针在末尾
    
    //写
    char str[]="LLoveYou";
    fputs(str,fp);

    //读
    char readData[1024];
      //不用rewind你什么都读不出来

    //rewind(fp);

    fseek(fp,0L,SEEK_SET);
      //和rewind等价
    fgets(str,1024,fp);
    puts(str);
    
    
    fclose(fp);
}

//用ftell测试文件大小
int getFileSize(const char* fileName)
{
    FILE* fp=fopen(fileName,"r");
    fseek(fp,0L,SEEK_END);//把文件指针移动到最后
    int size=ftell(fp);//测试文件指针移动的大小
    fclose(fp);
    return size;//统计的是字节
}
int main()
{
    readFile("read.txt");

   //getFileSize("xxxx.exe");
   //使用该函数需要将exe文件放到目录下

    system("pause");
    return 0;
}