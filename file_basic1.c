#include <stdio.h>
#include "./myhead.h"//�ò�����ֻ�������������·��
#include <stdlib.h>
#include <string.h>
//���·����������ͬһ��Ŀ¼�¿���->1  myhead.h 2  ./myhead.h
//���ϼ�������->../myhead.h
//���Ե�·��->"D:\Cc_code\myhead.h"


/*                 ��д��ʽ�����������

w   �����ļ������ԭ�ļ�
r   ���ܴ���
a   ĩβ����д��Ҳ���д�������
b   binary������
+   �ɶ���д
*/


/*                    ���ֶ�д��ʽ
    * �ַ���д��ʽ
    ** fgerc()
       fputc()  
       ����getchar,putchar

    * �ַ�����д��ʽ
    ** fgets();
       fputs();
       ����gets,puts

    * ��ʽ����д��ʽ->֧��ת���ַ���һ�ַ�ʽ�����ǲ�֧���ļ�ָ����ƶ�
    ** fprintf()
       fscanf()

    * �����ƶ�д��ʽ
    ** fwrite()
       fread()*/


//�����Ƕ�������д����ָ����Լ�����ƣ��ļ�������װ��ָ����ƶ�


void testwrite()
{
    char str[]="�Ұ��㰡";
    FILE* fp=fopen("love.txt","w");
    //�ļ��ڵ�ǰĿ¼��

    //�����Ա��
    if(fp==NULL)
    {
        printf("error!\n");
        return;
        //��ǰ��ֹ���루û��Ů���Ѿͱ������붴���ˣ�
    }

//�ַ�д--�鷳

    /*int i=0;
    while(str[i]!='\0')
    {
        fputc(str[i],fp);
        i++;
    }*/
    
//�ַ���д--����
    fputs(str,fp);
    //���ַ������Ը��Ӽ��
    
    
    fclose(fp);
    //Ҫ���и���ʼ���յ�����
}
void testread()
{
    FILE* fp=fopen("love.txt","r");
    
    //�����Ա�� 
    if(fp==NULL)
    {
        printf("error!\n");
        exit(0);
        //��ǰ��ֹ���루û��Ů���Ѿͱ������붴���ˣ�
    }

//�ַ���
    /*
    int readChar=0;
    readChar=fgetc(fp);
    //�ļ��������->EOF
    while (readChar!=EOF)
    {
        printf("%c",readChar);
        readChar=fgetc(fp);
        //�ٴζ�ȡ��һ��λ��
    }
    */

    //����д���Ӽ��->Ҫѧ��
   
    int readChar;
    while ((readChar=fgetc(fp))!=EOF)
      putchar(readChar);
    

//�ַ�����--�о�����...�ַ�
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
