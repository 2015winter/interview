/****************************************************************************
 * @file     ɾ���ظ��ַ�.c
 * @brief    ����һ�����Ȳ����� 100 ���ַ�����ɾ�����е��ظ��ַ���
 * @version  V1.00
 * @date     2013.12.27
 * @note     ʱ�临�Ӷ�O(1) �ռ临�Ӷ�O(1)
 ****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
//�����ַ�����󳤶�
#define N 100
#define DEBUG

int HashTable[255]={0};   // contains A-F and a-z character

/**   ���ַ�������Hash�� 
 * 
 *	  �ж��ַ��Ƿ���ֹ���û�г��ֹ��Ͱ����µ�������ǰ��ֵ����Ϊǰ���ַ��Ѿ�
 *    �жϹ������Ա����ǣ���ԭ����������������ƶ�����Ӱ�졣�������ַ�����
 *    ������������'\0'�����������ڴ���Hash���ͬʱ���ַ�����ɴ���
 */
void LoadHashTable(char *str) 
{
    if(0 == strlen(str))
	{
		printf("�����ַ���Ϊ�գ�\n\n");
		return ;
	}
    int i,j = 0;
    for(i = 0;i < strlen(str);i++) 
	{
		if(HashTable[(int)str[i]] == 0)
		{
			str[j++] = str[i];
			HashTable[(int)str[i]] += 1;//���ڵļ�ֵ��1		
		}

    }
	str[j] = '\0';
	printf("ɾ���ظ��ַ�����ַ���Ϊ��\n%s\n\n", str);
}

int main() 
{
#ifdef USERMODE
	char *Old_ptr,* New_ptr;
	int Old_Length,i,j = 0,val;
	char Test_char;
	// ���������ַ�����С�Ŀռ�
	if (NULL == (Old_ptr = (char * )malloc(N * sizeof(char)))) 
	{
		perror("error...");
		return 1;
	}
	printf("�������ɾ���ַ���,���Իس�������\n");
	gets(Old_ptr);
	if(NULL == Old_ptr)
	{
		printf("�����ַ���Ϊ��!\n");
		free(Old_ptr);
		return 1;
	}
	// ��������ַ����ĳ���
	Old_Length = strlen(Old_ptr);
	printf("�ַ�������Ϊ%d\n",Old_Length);	
	// ��ʼ����ϣ������ɴ���
	LoadHashTable(Old_ptr);
	// �ͷ�����Ŀռ�
	free(Old_ptr);
#endif	
#ifdef DEBUG
	//=======================================================================
	//����
	printf("==============================================================\n");
	char a[100] = "aabbccdd";
	printf("�����ַ���Ϊ��\n%s\n",a);
	LoadHashTable(a);
	memset(HashTable,0,255*sizeof(int));
	printf("==============================================================\n");
	char b[100] = "";	
	printf("�����ַ���Ϊ��%s\n",b);
	LoadHashTable(b);
	memset(HashTable,0,255*sizeof(int));
	printf("==============================================================\n");
	char c[100] = "123562356 abca deef";
	printf("�����ַ���Ϊ��%s\n",c);
	LoadHashTable(c);
	memset(HashTable,0,255*sizeof(int));
	printf("==============================================================\n");
	return 0;
#endif	
}
