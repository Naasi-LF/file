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
��ʽ����д��ʽ


{void writefile
  (const char* filename,struct MM array[],int arrayNum)
    FILE* fp=fopen(filename,"w");

//д����
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

//������---��ôд�ľ���ô��
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

//�����ƶ�д

//������д--�򵥻�
void writefile
  (const char* filename,struct MM array[],int arrayNum)
{
    FILE* fp=fopen(filename,"wb");
    fwrite(array,sizeof(struct MM),arrayNum,fp);
    //(д�Ķ����ĵ�ַ������д�Ķ����Ĵ�С��д���Σ��ļ���ַ)
    fclose(fp);
}

//�����ƶ�--�򵥻�
//bat�ļ���������������������ûţ���û����
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
��ʽ����д��ʽ
    struct MM readData[3];
    
    writefile("��ʽ��.txt",array,3);

    readfile("��ʽ��.txt",readData);
    */

//�����ƶ�д��ʽ
    struct MM readData[3];

    writefile("������.dat",array,3);

    readfile("������.dat",readData,3);
    for(int i=0;i<3;i++)
    {
        printf("%s\t%d\t%s\n",
            readData[i].name,readData[i].age,readData[i].tel);
    }

    system ("pause");
    return 0;
}
