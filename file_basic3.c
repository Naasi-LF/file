#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    rewind(FILE*fp)���ļ�ָ�뻹ԭ����ͷ->׷��ģʽ�£��ļ�ָ����ĩβ
    
    fseek(FILE* fp,long bit,int mode)
    mode:SEEK_CUT->��ǰ
         SEEK_SET->��ʼ
         SEEK_END->ĩβ

    ftell():�жϵ�ǰ�ļ�ָ���ƶ������ֽڡ�>����С

    feof():�ж��ļ��Ƿ�ĩβ

*/

//��fseek��rewind�ı��ļ�ָ��
void readFile(const char* filename)
{
    FILE* fp=fopen(filename,"a+");
      //����ļ����Ƕ����˶������ļ�ָ����ĩβ
    
    //д
    char str[]="LLoveYou";
    fputs(str,fp);

    //��
    char readData[1024];
      //����rewind��ʲô����������

    //rewind(fp);

    fseek(fp,0L,SEEK_SET);
      //��rewind�ȼ�
    fgets(str,1024,fp);
    puts(str);
    
    
    fclose(fp);
}

//��ftell�����ļ���С
int getFileSize(const char* fileName)
{
    FILE* fp=fopen(fileName,"r");
    fseek(fp,0L,SEEK_END);//���ļ�ָ���ƶ������
    int size=ftell(fp);//�����ļ�ָ���ƶ��Ĵ�С
    fclose(fp);
    return size;//ͳ�Ƶ����ֽ�
}
int main()
{
    readFile("read.txt");

   //getFileSize("xxxx.exe");
   //ʹ�øú�����Ҫ��exe�ļ��ŵ�Ŀ¼��

    system("pause");
    return 0;
}