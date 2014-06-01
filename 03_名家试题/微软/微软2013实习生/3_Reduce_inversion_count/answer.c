/****************************************************************************
 * @file     answer.c
 * @brief    �μ�description��
 * @version  V1.00
 * @date     2014.5.1
 * @note     
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


/** 
 * @brief     �鲢������ʵ�ִ�С��������
 * @param[in] array  ԭʼ����ָ��
 * @param[in] temp   ���ڴ�����������
 * @param[in] begin  ������ʼλ��
 * @param[in] end    �������λ��
 * @retval    
 * @see       None
 * @note      		  
 */
int MergeSort(int *array, int *temp, int begin, int end)
{
	int inv_count = 0;  //��¼������
	if(NULL == array || NULL == temp )
	{
		printf("��������!\n");
		return -1;
	}
	int mid;
	if(begin < end)
	{
		//������ֳ������֣��ֱ���й鲢�����ٽ������ź����������кϲ�
		mid = (begin + end)/2;
		inv_count = MergeSort(array, temp, begin, mid);
		inv_count += MergeSort(array, temp, mid + 1, end);
		inv_count += Merge(array, temp, begin, mid + 1, end);
	}
	return inv_count;
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
		return -1;
	}
	int inv_count = 0;
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
			inv_count += mid - i;
			temp[k++] = array[j++];
		}
	}
	//����ʣ���Ԫ�ص�������temp
	while(i <= mid-1)
	{
		temp[k++] = array[i++];
	}
	while(j <= end)
	{
		temp[k++] = array[j++];
	}
	//��temp���ź�������ݸ��Ƶ�array��
	for(i = begin; i <= end; i++)
	{
		array[i] = temp[i];
	}
	return inv_count;
}


int main()
{
	int i,j,k,decrease,max,inv_count,num,arr_num;
	char *str = (char*)malloc(100*sizeof(char));
	int *SourceArray = (int*)malloc(100*sizeof(int));
	while(scanf("%s", str) != EOF) 
	{
		i = j = num = 0;
		while(str[i] != '\0')
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				num *= 10;
				num += str[i] - '0';
			}
			else
			{
				SourceArray[j++] = num;
				num = 0;
			}
			str[i++] = '\0';
		}
		SourceArray[j++] = num;
		arr_num = j;
		int *temp = (int*)malloc(arr_num*sizeof(int));
		int *copy = (int*)malloc(arr_num*sizeof(int));
		memcpy(copy,SourceArray,arr_num*sizeof(int));
		//printf("��ǰ�������ĸ���Ϊ��%d  \n",inv_count = MergeSort(copy,temp,0,arr_num-1));
		inv_count = MergeSort(copy,temp,0,arr_num-1);
		max = 0;
		for(i = 0; i < arr_num-1; i++)
		{
			for(j = i + 1; j < arr_num; j++)
			{
				
				if(SourceArray[i] <= SourceArray[j])
					continue;
				decrease = 1;
				//Ӱ�����i��j֮���������i+1��j-1
				for(k = i + 1; k < j; k++)
				{
					if((SourceArray[k] <  SourceArray[i]) && (SourceArray[k] > SourceArray[j]))
					{
						decrease = decrease + 2;
					}
					if(SourceArray[k] == SourceArray[i] || SourceArray[k] == SourceArray[j])
					{
						decrease++;
					}
				}
				if(decrease > max)
				{
					max = decrease;
				}
			}
		}		
		printf("%d\n",inv_count - max);
		free(temp);
		free(copy);
		temp = copy = NULL;
	}
	free(str);
	str = NULL;
}
