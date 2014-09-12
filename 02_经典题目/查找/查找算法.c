/****************************************************************************
* @file     Search.c
* @brief    5�ֲ����㷨ʵ�ּ����Ӷ��ȶ��ԡ�
* @version  V1.00
* @date     2014.9.10
* @note     
****************************************************************************/
#include<stdio.h>


/**		���ֲ���   
 *     
 *		���õ�����⡣    
 */ 
int BinarySearch_Iteration(int* array, int length, int data)
{
	if(NULL == array || 0 == length)
	{
		printf("��������\r\n");
		return 1;
	}
	int low = 0, high = length - 1;
	int middle = length>>2;
	while(low <= high)
	{
		//left��right��ֵ�Ƚϴ��ʱ����Ϳ������
		middle = low + ((high - low)>>1);
		if(array[middle] > data)
		{
			high = middle - 1;
		}
		else if(array[middle] < data)
		{
			low = middle + 1;
		}
		else
		{
			printf("�ҵ�data��λ�ã�%d\r\n",middle);
			return 0;
		}
	}
		
}
/**		���ֲ���   
 *     
 *		���õݹ���⡣    
 */ 
int BinarySearch_Recursion(int* array, int low, int high, int data)
{
	if(NULL == array)
	{
		printf("��������\r\n");
		return 1;
	}
	int middle;
	if(low <= high)
	{
		//left��right��ֵ�Ƚϴ��ʱ����Ϳ������
		middle = low + ((high - low)>>1);
		if(array[middle] > data)
		{
			BinarySearch_Recursion(array, low, middle - 1, data);
		}
		else if(array[middle] < data)
		{
			BinarySearch_Recursion(array, middle + 1, high, data);
		}
		else
		{
			printf("�ҵ�data��λ�ã�%d\r\n",middle);
			return 0;
		}
	}
		
}
/**		���ֲ���   
 *     
 *		������ͬ�����֣����ص�һ��ƥ��λ�û������һ��ƥ��λ�ã��ɺ����������������    
 */ 
int BinarySearch(int* array, int length, int data, int flag)
{
	if(NULL == array || 0 == length)
	{
		printf("��������\r\n");
		return 1;
	}
	int low = 0, high = length - 1, middle;
	while(low + 1 < high)
	{
		//left��right��ֵ�Ƚϴ��ʱ����Ϳ������
		middle = low + ((high - low)>>1);
		if(array[middle] > data)
		{
			high = middle - 1;
		}
		else if(array[middle] < data)
		{
			low = middle + 1;
		}
		else
		{
			//flag = 1�ҳ��ظ������һ��λ��
			if(flag == 1)
				low = middle;
			else
			//flag = 0�ҳ��ظ��ĵ�һ��λ��
				high = middle;
		}
	}
	if(flag == 1)
	{
		if(array[high] == data)
			return high;
		else if(array[low] == data)
			return low;
	}
	else
	{
		if(array[low] == data)
			return low;
		else if(array[high] == data)
			return high;
	}
	return -1;	
}

int main()
{
	int array[] = {1,2,2,3,4,4,5,6,7,7};
	printf("%d",BinarySearch(array, sizeof(array)/sizeof(array[0]),5,1));
}