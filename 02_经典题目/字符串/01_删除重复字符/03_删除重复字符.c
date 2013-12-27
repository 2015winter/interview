/****************************************************************************
 * @file     ɾ���ظ��ַ�.c
 * @brief    ����һ�����Ȳ����� 100 ���ַ�����ɾ�����е��ظ��ַ���
 * @version  V1.00
 * @date     2013.12.27
 * @note     ʱ�临�Ӷ�O(1) �ռ临�Ӷ�O(1)
 ****************************************************************************/
# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <stdint.h>
# include <stdlib.h>
//�����ַ�����󳤶�
# define N 100

int HashTable[255]={0};   // contains A-F and a-z character

/**   ���ַ�������Hash�� 
 * 
 *	  �ж��ַ��Ƿ���ֹ���û�г��ֹ��Ͱ����µ�������ǰ��ֵ����Ϊǰ���ַ��Ѿ�
 *    �жϹ������Ա����ǣ���ԭ����������������ƶ�����Ӱ�졣�������ַ�����
 *    ������������'\0'�����������ڴ���Hash���ͬʱ���ַ�����ɴ���
 */
void LoadHashTable(char *str) 
{
    int i,j = 0;
    int pos;   // the hash address 
    for(i = 0;i < strlen(str);i++) 
	{
		if(HashTable[(int)str[i]] == 0)
		{
			str[j++] = str[i];
			HashTable[(int)str[i]] += 1;//���ڵļ�ֵ��1		
		}

    }
	str[j] = '\0';
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
	//��ʼ����ϣ������ɴ���
	LoadHashTable(Old_ptr);
	printf("ɾ���ظ��ַ�����ַ���Ϊ��\n%s\n", Old_ptr);
	//�ͷ�����Ŀռ�
	free(Old_ptr);
	return 0;
}
