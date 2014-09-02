/****************************************************************************
* @file     03_�����������.c
* @brief    �������������
* @version  V1.00
* @date     2014.9.1
* @note     ��1������������з���ԭ����ΪA�����Ƕ�A������������������Ϊ
			A'������������������������������������A������������У���ʵ
			����������A��������������A'������������С�
			��2����̬�滮 ʱ�临�Ӷ�O(n^2)
****************************************************************************/
#include <stdio.h> 
#include <string.h>

/**        �����������ֵ   
 *     
 *     ������������һ��Ԫ�ء�    
 */
int Max(int* array, int array_len)
{
	int i,max = array[0];
	for(i = 1; i < array_len; i++)
	{
		if(array[i] > max)
			max = array[i];
	}
	return max;
}

/** 
 * @brief   ��array���������������������
 * @param   array       array����ָ�� 
 * @param   array_len   array�ĳ��� 
 * @retval  �����������������	-1�������������	-2������ռ�ʧ�ܡ�
 * @see     None
 * @note    ��̬�滮
 */
int LongestIncreaseSequence(int* array, int array_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("�����������\r\n");
		return -1;
	}
	int *LIS;
	if(NULL == (LIS = (int*)malloc(sizeof(int)*array_len)))
	{
		printf("����ռ�ʧ��!\r\n");
		return -2;
	}
	int i,j;
	for(i = 0; i < array_len; i++)
	{
		LIS[i] = 1;
		for(j = 0; j < i; j++)
		{
			if(array[i] > array[j] && LIS[j] + 1 > LIS[i])
			{
				LIS[i] = LIS[j] + 1;
			}
		}
	}	
	return Max(LIS, array_len);
} 


int main()
{
	int max,array[] = {1,-1,2,-3,4,-5,6,-7};
	max = LongestIncreaseSequence(array, sizeof(array)/sizeof(int));
	printf("%d\r\n", max);
}
