/****************************************************************************
 * @file     Sort.c
 * @brief    ���������㷨ʵ�֡�
 * @version  V1.00
 * @date     2014.2.24
 * @note      
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/**		�ڲ�����  
 *     
 *		�������������н�����    
 */ 
static void Swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
/** 
 * @brief     ð��������ʵ�ִ�С��������
 * @param[in] array  ������ʼ��ַ
 * @param[in] length  �����С
 * @retval    None
 * @see       None
 * @note      ʱ�临�Ӷ�O(n^2)��������O(n)������O(n^2)��
			  �ռ临�Ӷ�O(1)���ȶ���
			  �Ľ�1������һ����־�������һ�˷����˽�������Ϊtrue������Ϊfalse��
			         ���������һ��û�з���������˵�������Ѿ���ɡ�
			  �Ľ�2�������100���������飬��ǰ��10�����򣬺���90�������ź�����
			         ������ǰ��10�����֣���ô�ڵ�һ�˱����������������λ��
					 �ض�С��10�������λ��֮������ݱض��Ѿ������ˣ���¼����λ
					 �ã��ڶ���ֻҪ������ͷ�����������λ�þͿ����ˡ�			  
 */
int BubleSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("�����������\n");
		return 1;
	}
	int i,j;
	for(i = 0; i < length-1; i++)
	{
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
			}
		}
	}
	return 0;
}

/** 
 * @brief     ����������ʵ�ִ�С��������
 * @param[in] array  ������ʼ��ַ
 * @param[in] length  �����С
 * @retval    None
 * @see       None
 * @note      ʱ�临�Ӷ�O(n^2)��������O(n)������O(n^2)��
			  �ռ临�Ӷ�O(1)���ȶ���			  
 */
int InsertSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("�����������\n");
		return 1;
	}
	int i = 0, j = 0, temp = 0;  
	for(i = 1; i < length; i++)
	{
		if(array[i] < array[i-1])
		{
			temp = array[i];
			for(j = i-1; j >= 0 && array[j] > temp; j--)
			{
				array[j+1] = array[j];
			}
			array[j+1] = temp;
		}
	}	
	return 0;
}

/** 
 * @brief     ����������ʵ�ִ�С��������
 * @param[in] array  ������ʼ��ַ
 * @param[in] length  �����С
 * @retval    None
 * @see       None
 * @note      ʱ�临�Ӷ�O(n^)��������O()������O(n^)��
			  �ռ临�Ӷ�O()���ȶ���			  
 */
void QuickSort(int *array, int low,int high)
{
	if((NULL == array) || low < 0 || high < 0)
	{
		printf("�����������\n");
		return 1;
	}
	if ( low < high ) 
	{
		int i = low, j = high, temp = array[low];
		while ( i < j ) 
		{
			//��������ɨ�裬�������Ԫ�ش���temp���������ֱ���ҵ���һ��С��temp��Ԫ��
			while ( i < j && array[j] >= temp ) {
				--j;
			}
			if ( i < j ) {
				array[i++] = array[j];
			}
			while ( i < j && array[i] <= temp ) {
				++i;
			}
			if ( i < j ) {
				array[j--] = array[i];
			}
		}
		array[i] = temp;
		QuickSort(array, low, i - 1);
		QuickSort(array, i + 1, high);
	}
}




int main()
{
	int ForSort[10] = {9,1,8,2,7,3,4,6,5,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {9,8,7,6,5,4,3,2,1,0};
	QuickSort(ForSort2,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort2[i]);
	}
}
