/****************************************************************************
 * @file     ɾ���ظ��ַ�.c
 * @brief    ����һ�����Ȳ����� 100 ���ַ�����ɾ�����е��ظ��ַ���
 * @version  V1.00
 * @date     2013.12.27
 * @note     ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
 ****************************************************************************/
# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <stdint.h>
# include <stdlib.h>
//�����ַ�����󳤶�
# define N 100

int HashTable[255]={0};   // contains A-F and a-z character
/**
 * ����Hash��
 */
int Hash(char c) 
{
	return (int)c;
}
/** 
 * ���ַ�������Hash�� 
 */
void LoadHashTable(const char *str) 
{
    int i;
    int pos;   // the hash address 
    for(i = 0;i < strlen(str);i++) 
	{
		pos = Hash(str[i]); //�ҵ���Ӧ��λ��
		HashTable[pos] += 1;//���ڵļ�ֵ��1
    }
}

int main() 
{
	char *Old_ptr,* New_ptr;
	int Old_Length,i,j = 0, pos,val;
	char Test_char;
	//���������ַ�����С�Ŀռ�
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
	//��������ַ����ĳ���
	Old_Length = strlen(Old_ptr);
	printf("�ַ�������Ϊ%d\n",Old_Length);	
	//��ʼ����ϣ��
	LoadHashTable(Old_ptr);
	for(i = 0; i < Old_Length; i++)
	{
		pos = Hash(Old_ptr[i]);
		val = HashTable[pos];
		if(val > 1) 
		{
			Old_ptr[j++] = Old_ptr[i];
			HashTable[pos] = 0;
		}
		else if(val == 1)
		{
			Old_ptr[j++] = Old_ptr[i];
		}
		else if(val == 0)
		{
			i++;
		}
	}
	Old_ptr[j] = '\0';
	printf("ɾ���ظ��ַ�����ַ���Ϊ��\n%s\n", Old_ptr);
	//�ͷ�����Ŀռ�
	free(Old_ptr);
	return 0;
}
