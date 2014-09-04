/****************************************************************************
 * @file     01_�������ϵĹ���Ԫ��.c
 * @brief    A��B�����������ϣ����һ���㷨�����ǵĽ����������ܵĸ�Ч��
 * @version  V1.00
 * @date     2014.9.4
 * @note     ��1��HASH����Ϊ�Ǽ��ϣ�����Ԫ�����㻥���ԣ�
             ��2�������������
             ��3��bitmap
****************************************************************************/
#include <stdio.h>
#include <stdbool.h>

/**
 * ����Hash��
 */
int Hash(int* hashtable, int hash_len, int* array, int array_len) 
{
	int i;
	memset(hashtable, '0', sizeof(int)*hash_len);
	for(i = 0; i < array_len; i++)
	{
		hashtable[array[i]] = 1;
	}
}

/** 
 * ��Ԫ�ط���Hash�� 
*/
int LoadHashTable(int* hashtable, int hash_len, int* array, int array_len) 
{
	int i;
	for(i = 0; i < array_len; i++)
	{
		if(1 == hashtable[array[i]])
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
void CommonElements(int* array1, int array1_len, int* array2, int array2_len) 
{
    int i, max = array1[0];
    //���arra1�����ֵ
    for(i = 0; i < array1_len; i++)
    {
        if(array1[i] > max)
            max = array1[i];
    }
    for(i = 0; i < array2_len; i++)
    {
        if(array2[i] > max)
            max = array2[i];
    }
    int*hashtable;
	if(NULL == (hashtable = (int*)malloc(sizeof(int)*max)))
	{
		printf("����ռ�ʧ��!\r\n");
		return;
	}
	Hash(hashtable, max, array1, array1_len);
	LoadHashTable(hashtable, max, array2, array2_len);
	free(hashtable);
}



int main()
{
	int a[] = {1,3,4,7,9,20};
	int b[] = {3,7,12,4,9,5,14};
	CommonElements(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
}