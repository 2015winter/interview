/****************************************************************************
 * @file     01_�������ϵĹ���Ԫ��.c
 * @brief    A��B�����������ϣ����һ���㷨�����ǵĽ����������ܵĸ�Ч��
 * @version  V1.00
 * @date     2014.9.4
 * @note     ��1��HASH����Ϊ�Ǽ��ϣ�����Ԫ�����㻥���ԣ�
			 ��2��ѹ�����ϣ�������������½磬�غϵļ�Ϊ����Ԫ�أ��ٳ�ȥ����
				  �����Χ�ڵ�Ԫ�أ�ѭ��������ֱ��û���غ�
             ��2�������������
             ��3��bitmap
****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXNUM 200

int LCSPro[MAXNUM][MAXNUM]; //LCD���飬��ŵ�ǰ����Ԫ�ظ���
int LCSPath[MAXNUM][MAXNUM];//���ڴ�ӡ����Ԫ��
/**
 * ����Hash��
 */
int Hash(int* hashtable, int hash_len, int* array, int array_len, int min) 
{
	int i;
	memset(hashtable, '0', sizeof(int)*hash_len);
	for(i = 0; i < array_len; i++)
	{
		hashtable[array[i] - min] = 1;
	}
}

/** 
 * ��Ԫ�ط���Hash�����Ƚ��Ƿ���� 
*/
int LoadHashTable(int* hashtable, int hash_len, int* array, int array_len, int min) 
{
	int i;
	for(i = 0; i < array_len; i++)
	{
		if(1 == hashtable[array[i] - min])
		{
			printf("%d   ",array[i]);
		}	
	}	
}

/** 
* @brief     �������ϵĹ���Ԫ�أ������������ʾ
* @param[in] array1       ����1��ָ��
* @param[in] array1_len   ����1�Ĵ�С
* @param[in] array2       ����2��ָ��
* @param[in] array2_len   ����2�Ĵ�С
* @retval    
* @see       None
* @note            
*/
void CommonElements_Hash(int* array1, int array1_len, int* array2, int array2_len) 
{
    int i, min = array1[0], max = array1[0];
    //���arra1�����ֵ
    for(i = 0; i < array1_len; i++)
    {
        if(array1[i] > max)
            max = array1[i];
		else if(array1[i] < min)
			min = array1[i];
    }
    for(i = 0; i < array2_len; i++)
    {
        if(array2[i] > max)
            max = array2[i];
		else if(array2[i] < min)
			min = array2[i];
    }
	printf("max = %d, min = %d\r\n", max, min);
    int*hashtable;
	if(NULL == (hashtable = (int*)malloc(sizeof(int)*(max - min))))
	{
		printf("����ռ�ʧ��!\r\n");
		return;
	}
	Hash(hashtable, max-min, array1, array1_len, min);
	LoadHashTable(hashtable,  max-min, array2, array2_len, min);
	free(hashtable);
}

/** 
 * @brief   ��text��query�������ϵĹ���Ԫ�ء�
 * @param   query      query����ָ�� 
 * @param   query_len  query�ĳ��� 
 * @param   text       text����ָ��     
 * @param   text_len   text�ĳ��� 
 * @retval  ������     0���ɹ�	-1�������������	-2������ռ�ʧ�ܡ�
 * @see     None;
 * @note    
 */
int LCS(int* query, int query_len, int* text, int text_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("�����������\r\n");
		return -1;
	}
	int *p;
	int i,j;
	if(NULL == (p = (int*)malloc(sizeof(int)*(text_len + 1))))
	{
		printf("����ռ�ʧ��!\r\n");
		return -2;
	}	
	for(i = 0; i < query_len; i++){ LCSPro[i][0] = 0; }
	for(j = 0; j < text_len; j++){ LCSPro[0][j] = 0; }

	for(i = 0; i < query_len; i++)
	{
		for(j = 0; j < text_len; j++)
		{
			if(query[i] == text[j])
			{
				LCSPro[i+1][j+1] = LCSPro[i][j] + 1;
				LCSPath[i+1][j+1] = 0;
			}
			else if(LCSPro[i+1][j] <= LCSPro[i][j+1])
			{
				LCSPro[i+1][j+1] = LCSPro[i][j+1];
				LCSPath[i+1][j+1] = 1;
			}
			else
			{
				LCSPro[i+1][j+1] = LCSPro[i+1][j];
				LCSPath[i+1][j+1] = 2;
			}
		}
	}
}

/** 
 * @brief   ��ӡ���������ϵĹ���Ԫ�ء�
 * @param   query      query����ָ�� 
 * @param   query_len  query�ĳ���  
 * @param   text_len   text�ĳ��� 
 * @retval  None
 * @see     None
 * @note    
 */
void PrintPath(int* query, int query_len, int text_len)
{
	if(query_len == 0 || text_len == 0)
		return;//�ݹ���ֹ����
	if(LCSPath[query_len][text_len] == 0)
	{	
		PrintPath(query, query_len - 1, text_len - 1);
		printf("%d   ", query[query_len - 1]);
	}
	else if(LCSPath[query_len][text_len] == 1)
	{
		PrintPath(query, query_len - 1, text_len);
	}
	else
	{
		PrintPath(query, query_len, text_len - 1);
	}
} 

/** 
* @brief     �������ϵĹ���Ԫ�أ������������ʾ
* @param[in] array1       ����1��ָ��
* @param[in] array1_len   ����1�Ĵ�С
* @param[in] array2       ����2��ָ��
* @param[in] array2_len   ����2�Ĵ�С
* @retval    
* @see       None
* @note            
*/
void CommonElements_LCS(int* array1, int array1_len, int* array2, int array2_len) 
{
    LCS(array1, array1_len, array2, array2_len);
	PrintPath(array1, array1_len, array2_len);
}

int main()
{
	int a[] = {1,3,-4,7,9,20};
	int b[] = {3,7,12,4,9,-4,14};
	//CommonElements_Hash(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
	CommonElements_LCS(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));

}