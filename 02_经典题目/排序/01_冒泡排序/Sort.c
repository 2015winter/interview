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
 * @param[in] a  ������ʼ��ַ
 * @param[in] n  �����С
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
	int i=0,j=0,count = 0;
	for(i = 0; i < length-1; i++)
	{
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
			}
			count++;
		}
	}
	printf("�Ƚϴ���Ϊ%d��\n",count);
	return 0;
}
/** 
 * @brief     ð��������ʵ�ִ�С��������
 * @param[in] a  ������ʼ��ַ
 * @param[in] n  �����С
 * @retval    None
 * @see       None
 * @note      ʱ�临�Ӷ�O(n^2)��������O(n)������O(n^2)��
			  �ռ临�Ӷ�O(1)���ȶ���
			  �Ľ�1������һ����־�������һ�˷����˽�������Ϊtrue������Ϊfalse��
			         ���������һ��û�з���������˵�������Ѿ���ɡ�		  
 */
int BubleSort1(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("�����������\n");
		return 1;
	}
	int i=0,j=0,flag = 0,count = 0;
	for(i = 0; i < length-1; i++)
	{
	    flag = 0;
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
				flag = 1;
			}
			count++;
		}
		if(flag == 0)
		{
			break;
		}
	}
	printf("�Ƚϴ���Ϊ%d��\n",count);
	return 0;
}


/** 
 * @brief     ð��������ʵ�ִ�С��������
 * @param[in] a  ������ʼ��ַ
 * @param[in] n  �����С
 * @retval    None
 * @see       None
 * @note      ʱ�临�Ӷ�O(n^2)��������O(n)������O(n^2)��
			  �ռ临�Ӷ�O(1)���ȶ���
			  �Ľ�2�������100���������飬��ǰ��10�����򣬺���90�������ź�����
			         ������ǰ��10�����֣���ô�ڵ�һ�˱����������������λ��
					 �ض�С��10�������λ��֮������ݱض��Ѿ������ˣ���¼����λ
					 �ã��ڶ���ֻҪ������ͷ�����������λ�þͿ����ˡ�			  
 */
int BubleSort2(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("�����������\n");
		return 1;
	}
	int i=0,j=0,k=0,flag = length-1-i,count = 0;
	for(i = 0; i < length-1; i++)
	{
		k = flag;
		flag = 0;
		for(j = 0; j < k; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
				flag = j;        //j��j+1�Ѿ���������j�������ݶ��������
			}
			count++;
		}
		if(flag == 0)
		{
			break;
		}
	}
	printf("�Ƚϴ���Ϊ%d��\n",count);
	return 0;
}
int main()
{
	int ForSort[10] = {9,8,7,6,5,4,3,2,1,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {3,2,1,0,4,5,6,7,8,9};
	if(0 == BubleSort2(ForSort2,10))
	{	
		for(i = 0; i < 10; i++)
		{
			printf("%d   ",ForSort2[i]);
		}
	}
	printf("\n");
}
