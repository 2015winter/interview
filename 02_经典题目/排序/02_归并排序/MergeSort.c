/****************************************************************************
 * @file     MergeSort.c
 * @brief    �鲢���㷨ʵ�֡�
 * @version  V1.00
 * @date     2014.5.25
 * @note     ����ʱ�临�Ӷȶ���O(nlgn)���ռ临�Ӷ�O(n)����ֵ�����Ĵ�
			 ����(2nlogn)��ƽ���Ƚϴ���O(nlgn)����ñȽϴ���O(����)���
			�Ƚϴ���O(nlgn/2)
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/** 
 * @brief     �鲢������ʵ�ִ�С��������
 * @param[in] array  ԭʼ����ָ��
 * @param[in] temp   ���ڴ�����������
 * @param[in] begin  ������ʼλ��
 * @param[in] end    �������λ��
 * @retval    ������ 0����ɹ� 1�����������
 * @see       None
 * @note      		  
 */
int MergeSort(int *array, int *temp, int begin, int end)
{
	if(NULL == array || NULL == temp )
	{
		printf("��������!\n");
		return 1;
	}
	int mid;
	if(begin < end)
	{
		//������ֳ������֣��ֱ���й鲢�����ٽ������ź����������кϲ�
		mid = (begin + end)/2;
		MergeSort(array, temp, begin, mid);
		MergeSort(array, temp, mid + 1, end);
		Merge(array, temp, begin, mid + 1, end);
	}
	return 0;
}
/** 
 * @brief     �鲢������ʵ�ִ�С��������
 * @param[in] array  ԭʼ����ָ��
 * @param[in] temp   ���ڴ�����������
 * @param[in] begin  ������ʼλ��
 * @param[in] mid    �ڶ���������ʼλ��
 * @param[in] end    �������λ��
 * @retval    ������ 0����ɹ� 1�����������
 * @see       None
 * @note      		  
 */
int Merge(int *array, int *temp, int begin, int mid, int end)
{
	if(NULL == array || NULL == temp )
	{
		printf("��������!\n");
		return 1;
	}
	int i = begin;
	int j= mid;
	int k = begin;
	//�������������ν��бȽϣ���С�Ĵ����temp���飬�ٽ�temp���鿽����array
	while((i <= mid - 1) && (j <= end))
	{
		if(array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}
	while(i <= mid-1)
	{
		temp[k++] = array[i++];
	}
	while(j <= end)
	{
		temp[k++] = array[j++];
	}
	for(i = begin; i <= end; i++)
	{
		array[i] = temp[i];
	}
	return 0;
}

int main()
{
	int ForSort2[10] = {3,2,1,0,4,5,6,7,8,9},i;
	int *p = (int*)malloc(10*sizeof(int));
	MergeSort(ForSort2,p,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort2[i]);
	}
	printf("\n");
}
