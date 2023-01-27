#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct MM
{
    char name[20];
    int age;
    char tel[12];
};

/*
格式化读写方式


{void writefile
  (const char* filename,struct MM array[],int arrayNum)
    FILE* fp=fopen(filename,"w");

//写操作
    for(int i=0;i<arrayNum;i++)
    {
        fprintf(fp,"%s\t%d\t%s\n",
          array[i].name,array[i].age,array[i].tel);
    }

    fclose(fp);
}

void readfile
  (const char* filename,struct MM buffer[])
{
    FILE* fp=fopen(filename,"r");

//读操作---怎么写的就怎么读
    int i=0;
    while(fscanf(fp,"%s\t%d\t%s\n",
      buffer[i].name,&buffer[i].age,buffer[i].tel)!=EOF)
    {
        
        printf("%s\t%d\t%s\n",
          buffer[i].name,buffer[i].age,buffer[i].tel);
        i++;

    }

    fclose(fp);
}
*/

//二进制读写

//二进制写--简单化
void writefile
  (const char* filename,struct MM array[],int arrayNum)
{
    FILE* fp=fopen(filename,"wb");
    fwrite(array,sizeof(struct MM),arrayNum,fp);
    //(写的东西的地址，单次写的东西的大小，写几次，文件地址)
    fclose(fp);
}

//二进制读--简单化
//bat文件里面有乱码很正常，不用慌，你没出错
void readfile
  (const char* filename,struct MM array[],int arrayNum)
{
    FILE* fp=fopen(filename,"rb");
    fread(array,sizeof(struct MM),arrayNum,fp);
    fclose(fp);
}

int main()
{
    struct MM array[3]=
    {
      {"baby",18,"18860978860"},
      {"Lisa",38,"18860988860"},
      {"Nasi",28,"18860778860"}
    };
   /*
格式化读写方式
    struct MM readData[3];
    
    writefile("格式化.txt",array,3);

    readfile("格式化.txt",readData);
    */

//二进制读写方式
    struct MM readData[3];

    writefile("二进制.dat",array,3);

    readfile("二进制.dat",readData,3);
    for(int i=0;i<3;i++)
    {
        printf("%s\t%d\t%s\n",
            readData[i].name,readData[i].age,readData[i].tel);
    }

    system ("pause");
    return 0;
}
