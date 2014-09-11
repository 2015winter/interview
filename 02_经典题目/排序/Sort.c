/****************************************************************************
* @file     Sort.c
* @brief    ���ֻ��������㷨ʵ�ּ����Ӷ��ȶ��ԡ�
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

/** 
* @brief     �鲢������ʵ�ִ�С��������
* @param[in] array  ԭʼ����ָ��
* @param[in] temp   ���ڴ�����������
* @param[in] begin  ������ʼλ��
* @param[in] end    �������λ��
* @retval    ������ 0����ɹ� 1�����������
* @note      ʱ�临�Ӷ�O(nlgn)��������O(nlgn)������O(nlgn)��
			�ռ临�Ӷ�O(1)���ȶ���	    		  
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
		for(j = i - 1; j >= 0 && array[j] > array[j+1]; j--)
		{
			Swap(&array[j], &array[j+1]);
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
* @note      ʱ�临�Ӷ�O(nlgn)��������O(nlgn)������O(n^2)��
			�ռ临�Ӷ�O(nlgn)�����ȶ���			  
*/
void QuickSort(int *array, int low,int high)
{
	if((NULL == array) || low < 0 || high < 0)
	{
		printf("�����������\n");
		return;
	}
	if ( low < high ) 
	{
		int i = low, j = high, temp = array[low];
		while ( i < j ) 
		{
			//��������ɨ�裬�������Ԫ�ش���temp,
			//�������ֱ���ҵ���һ��С��temp��Ԫ��
			while ( i < j && array[j] >= temp ) 
			{
				--j;
			}
			if ( i < j ) {
				array[i++] = array[j];
			}
			//��������ɨ�裬�������Ԫ��С��temp,
			//�������ֱ���ҵ���һ������temp��Ԫ��
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

/** 
* @brief     ѡ��������ʵ�ִ�С��������
* @param[in] array  ԭʼ����ָ��
* @param[in] length ���鳤��
* @retval    ������ 0����ɹ� 1�����������
* @see       None
* @note      ʱ�临�Ӷ�O(n^2)��������O(n^2)������O(n^2)��
			 �ռ临�Ӷ�O(1)�����ȶ���	   		  
*/
int SelectSort(int *array, int length)
{
	if(NULL == array || 0 == length )
	{
		printf("��������!\n");
		return 1;
	}
	int i,j,min,min_index;
	for(i = 0; i < length-1; i++)
	{
		min = array[i],min_index = i;
		for(j = i; j < length; j++)
		{
			if(array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
		}
		if(i != min_index)
			Swap(&array[i],&array[min_index]);
	}
	return 0;
}

/** 
* @brief     ϣ��������ʵ�ִ�С��������
* @param[in] array  ԭʼ����ָ��
* @param[in] length ���鳤��
* @retval    ������ 0����ɹ� 1�����������
* @see       None
* @note      ʱ�临�Ӷ�O(n^1.3)��������O(n)������O(n^2)��
			�ռ临�Ӷ�O(1)�����ȶ�(��ͬ�������ڲ�ͬ��������
			���ܵ������˳�����仯)��	   		  
*/
int ShellSort(int array[], int length)
{
	if((NULL == array) || length < 1)
	{
		printf("�����������\n");
		return 1;
	}
	int gap, i, j, temp;
	for(gap = length/2; gap > 0; gap /= 2)
	{
		//gapÿ�μ���
		for(i = gap; i < length; i++)
		{
			//�Լ��gap�����н��в�������array[j]ǰ������������ģ�����ֻ��Ҫ��
			//array[j+gap]���뵽ǰ���������
			for(j = i - gap; j >= 0 && array[j] > array[j+gap]; j -= gap)
			{
				Swap(&array[j], &array[j+gap]);
			}	
		}
	}

}

/** 
* @brief     �ѻ�������
* @param[in] array  ԭʼ����ָ��
* @param[in] i      ��ָ���ڵ㿪ʼ�ѻ�
* @param[in] length ���鳤��
* @retval    ������ 0����ɹ� 1�����������
* @see       None
* @note      ʱ�临�Ӷ�O(nlgn)��������O(nlgn)������O(nlgn)��
			 �ռ临�Ӷ�O(1)�����ȶ���	   		  
*/
void HeapAjust(int array[],int i,int length)
{
	if((NULL == array) || i < 0 || length < 1)
	{
		printf("�����������\n");
		return;
	}	
	int nChild;
	int nTemp;
	//���ı���˳����nChild��ֵΪi�������ѻ�
	for(nTemp = array[i]; 2 * i + 1 < length; i = nChild)
	{
		//����
		nChild = 2 * i + 1;
		//ѡ���ϴ�ĺ���
		if(nChild < length -1 && array[nChild+1] > array[nChild])
		{
			nChild++;
		}
		//������Լ������ĺ���С���ͽ���
		if(nTemp < array[nChild])
		{
			array[i] = array[nChild];
			array[nChild] = nTemp;
		}
		else//��������ĺ��ӻ��󣬾Ͳ�����
			break;
	}
}

/** 
* @brief     ��������ʵ�ִ�С��������
* @param[in] array  ԭʼ����ָ��
* @param[in] length ���鳤��
* @retval    ������ 0����ɹ� 1�����������
* @see       None
* @note      ʱ�临�Ӷ�O(nlgn)��������O(nlgn)������O(nlgn)��
			 �ռ临�Ӷ�O(1)�����ȶ���	   		  
*/
int HeapSort(int array[],int length)
{
	if((NULL == array) || length < 1)
	{
		printf("�����������\n");
		return 1;
	}	
	int i,j;
	//i=(length>>1)-1���������ţ�ԭ�����ȼ�������
	for(i = (length>>1) - 1; i >= 0; i--)
	{
		HeapAjust(array,i,length); //��ʼ��һ����
	}

	for(j = length-1; j > 0; --j)
	{
		Swap(&array[0], &array[j]);//�����Ѷ�Ԫ�غ����һ��Ԫ��
		//��ʱ�����Ϊ������0 ~ j��������j ~ length-1
		HeapAjust(array,0,j);      //�����������¶ѻ�
	}
}

int main()
{
	int ForSort[10] = {9,1,8,2,7,3,4,6,5,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {9,8,7,6,5,4,3,2,1,0};
	QuickSort(ForSort,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort[i]);
	}
}
