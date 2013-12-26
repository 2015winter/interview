/**************************************************************************
 * @file     ���뺯������.c
 * @brief    �˽�scanf(),getchar()��gets()�Ⱥ���
 * @version  V1.00
 * @date     2013.12.25
 * @note     scanf()������ȡ�����������س����ո�TAB�ͻ�ֹͣ��
			 scanf()��ȡ�ַ������������Ļس�����			scanf()��ȡ�ַ���ʱ���ַ����в����Գ��ֿո�һ�����ֿո񣬺���
			 �����ݾͻ����������ڻ������б���һ�ζ�ȡ��
			 gets()��ȡ�ַ������Խ��ܿո�
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string>
/* 
��ȡ�ַ�ʱ��
1 scanf()��Space��Enter��Tab����һ�����룬�����������Ļس��������س��������
  �ڻ������У���
2 getchar()��Enter�������룬Ҳ�����������Ļس�����
��ȡ�ַ���ʱ��
1 scanf()��Space��Enter��Tab����һ�����룬�����ܿո񣬻��������Ļس�����
2 gets()��Enter�������루�ո񲻽����������ܿո񣬻��������Ļس�����


���������
1  C�������ṩ�˺�����fflush(stdin)����ջ�������ֻҪ�ڶ�����֮ǰ����ջ�������û���⡣
2  �Լ�ȡ����������Ĳ������ݣ�scanf("%[^\n]",string);
*/

#define READSTRING1
int main()
{
/* scanf()��getchar()�����Ǵ��������������ж�ȡֵ�ģ������ǴӼ���(Ҳ�����ն�)��������ȡ������ȡʱ�����س�('\n')�������ģ����'\n'��һ������������������ģ����Ե�һ�ν�������ʱȡ���ַ���������ַ�'\n'�������ڶ��εĶ��뺯��ֱ�Ӵӻ������а�'\n'ȡ���ˣ���Ȼ��ȡ�ɹ��ˣ����Բ����ٴ��ն˶�ȡ�������Ϊʲô�������ִֻ����һ����������ͽ�����ԭ�� 
*/
#if defined SCANF
	printf("SCANF TEST\n");
	char ch1, ch2;
	scanf("%c", &ch1); 
	scanf("%c", &ch2);
	printf("%d %d\n", ch1, ch2);
#elif defined GETCHAR   
	printf("GETCHAR TEST\n");
	char ch1, ch2;
	ch1 = getchar();
	ch2 = getchar();
	printf("%d %d\n", ch1, ch2);
#elif defined READSTRING1   
	char str1[20], str2[20];
	scanf("%s",str1); 
	printf("%s\n",str1);    
	scanf("%s",str2); 
	printf("%s\n",str2); 
#elif defined READSTRING2   
	char str1[20], str2[20];
	gets(str1); 
	printf("%s\n",str1);    
	gets(str2); 
	printf("%s\n",str2); 
#endif	

   printf("���ڣ�%s\n",__DATE__);
   printf("ʱ�䣺%s\n",__TIME__);
   printf("�ļ�����%s\n",__FILE__);
   printf("���ǵ�%d�д���\n",__LINE__);
   printf("��������%s��׼C\n",(__STDC__)?"����":"������");
}

    
	