#include <stdio.h>
#include "./myhead.h"//用不到，只是用来讲解相对路径
#include <stdlib.h>
#include <string.h>
//相对路径：包含在同一个目录下可用->1  myhead.h 2  ./myhead.h
//在上级或其他->../myhead.h
//绝对的路径->"D:\Cc_code\myhead.h"


/*                 读写方式起决定性作用

w   创建文件，清空原文件
r   不能创建
a   末尾接着写，也具有创建功能
b   binary二进制
+   可读可写
*/


/*                    四种读写方式
    * 字符读写方式
    ** fgerc()
       fputc()  
       类似getchar,putchar

    * 字符串读写方式
    ** fgets();
       fputs();
       类似gets,puts

    * 格式化读写方式->支持转义字符的一种方式，但是不支持文件指针的移动
    ** fprintf()
       fscanf()

    * 二进制读写方式
    ** fwrite()
       fread()*/


//无论是读到还是写到，指针会自己像后移，文件函数封装了指针的移动


void testwrite()
{
    char str[]="我爱你啊";
    FILE* fp=fopen("love.txt","w");
    //文件在当前目录下

    //防御性编程
    if(fp==NULL)
    {
        printf("error!\n");
        return;
        //提前终止代码（没有女朋友就别想着入洞房了）
    }

//字符写--麻烦

    /*int i=0;
    while(str[i]!='\0')
    {
        fputc(str[i],fp);
        i++;
    }*/
    
//字符串写--方便
    fputs(str,fp);
    //这种方法明显更加简洁
    
    
    fclose(fp);
    //要做有个有始有终的男人
}
void testread()
{
    FILE* fp=fopen("love.txt","r");
    
    //防御性编程 
    if(fp==NULL)
    {
        printf("error!\n");
        exit(0);
        //提前终止代码（没有女朋友就别想着入洞房了）
    }

//字符读
    /*
    int readChar=0;
    readChar=fgetc(fp);
    //文件结束标记->EOF
    while (readChar!=EOF)
    {
        printf("%c",readChar);
        readChar=fgetc(fp);
        //再次读取下一个位置
    }
    */

    //这样写更加简洁->要学会
   
    int readChar;
    while ((readChar=fgetc(fp))!=EOF)
      putchar(readChar);
    

//字符串读--感觉不如...字符
    /*
    char str[1024];
    fgets(str,1024,fp);
    fputs(str,stdout);
    */
    
    

    fclose(fp);

}
int main()
{
    testwrite();
    testread();
    system ("pause");
    return 0;   
}
