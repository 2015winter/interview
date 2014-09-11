/****************************************************************************
 * @file     ����λ��.c
 * @brief    ѡ�������е���λ��
 * @version  V1.00
 * @date     2014.9.10
 * @note     ʹ�ÿ��������partion�������
****************************************************************************/
#include "stdio.h"   

int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition_new(int data[], int length, int start, int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        printf("Invalid Parameters\r\n");

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for(index = start; index < end; ++ index)
    {
        if(data[index] < data[end])
        {
            ++ small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}

void QuickSort_new(int* array, int length, int low, int high)
{
	int pivot;
	if(low < high)
	{
		pivot = Partition_new(array, length, low, high);
		if(pivot > low)
			QuickSort_new(array, length, low, pivot - 1);
		if(pivot < high)
			QuickSort_new(array, length, pivot + 1, high);
	}
}

/** 
* @brief     �ҳ�pivot��
* @param[in] array   ������ʼ��ַ
* @param[in] length  �����С
* @param[in] low     ѡȡ��Χ����Сλ��
* @param[in] high    ѡȡ��Χ����Сλ��
* @retval    ����pivot��λ��
* @see       QuickSort
* @note      None		  
*/
int Partition(int* array, int length, int low, int high)
{
	int i = low, j = high;
	int temp = array[low];
	while(i < j) 
	{
		while( i < j && temp < array[j])
		{
			j--;
		}
		if( i < j)
			array[i++] = array[j];
		while(i < j && temp > array[i]) 
		{
			i++;
		}
		if ( i < j)
			array[j--] = array[i];
	}
	array[i] = temp;
	return i;
}

void QuickSort(int* array, int length, int low, int high)
{
	int pivot;
	if(low < high)
	{
		pivot = Partition(array, length, low, high);
		QuickSort(array, length, low, pivot - 1);
		QuickSort(array, length, pivot + 1, high);
	}
}

int FindMiddle(int* array, int length, int low, int high)
{
	int pivot;
	int middle =  length/2;
	if(low == high && high == middle)
	{
		printf("�ҵ���λ����%d\r\n",array[middle]);
		return;
	}
	if(low < high)
	{
		pivot = Partition(array, length, low, high);
		if(pivot == middle)
		{
			printf("�ҵ���λ����%d\r\n",array[pivot]);
			return;
		}
		else if(pivot < middle)
		{
			
			FindMiddle(array, length, pivot + 1, high);
		}
		else
		{
			FindMiddle(array, length, low, pivot - 1);
		}		
	}
}


int FindNth(int* array, int nth, int low, int high)
{
	int pivot;
	if(low == high && high == nth)
	{
		printf("�ҵ���%d������%d\r\n",nth, array[nth]);
		return;
	}
	if(low < high)
	{
		pivot = Partition(array, nth, low, high);
		if(pivot == nth)
		{
			printf("�ҵ���%d������%d\r\n",nth, array[pivot]);
			return;
		}
		else if(pivot < nth)	
			FindNth(array, nth, pivot + 1, high);
		else
			FindNth(array, nth, low, pivot - 1);		
	}
}

int main()
{
	int array[] = {5,4,7,3,1,6,9}, i;
	QuickSort(array, sizeof(array)/sizeof(array[0]), 0, 6);
	for(i = 0; i < 7; i++)
		printf("%d   ",array[i]);
}