/****************************************************************************
 * @file     02_������ֻ����һ�ε���.c
 * @brief    һ���������������������֮�⣬���������ֶ����������Ρ���д������
			 ��������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)
 * @version  V1.00
 * @date     2014.9.2
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>


/** 
 * @brief     ������ֻ����һ�ε�һ����
 * @param[in] array       �������ʼ��ַ
 * @param[in] array_len   ����ĳ���
 * @retval    0���ɹ�	-1����������
 * @see       None
 * @note      		  
 */
int FindNumAppearOnce(int* array, int array_len, int* Num)
{
	if(NULL == array || 0 == array_len)
	{
		printf("��������\n");
		return -1;
	}
	int i;
	*Num = 0;
	for(i = 0; i < array_len; i++)
	{
		*Num ^= array[i];
	}
	return 0;
}

/** 
 * @brief     ������ֻ����һ�ε�������
 * @param[in] array       �������ʼ��ַ
 * @param[in] array_len   ����ĳ���
 * @retval    0���ɹ�	-1����������	-2��������ֻ����һ�ε�������
 * @see       None
 * @note      		  
 */
int FindNumsAppearOnce(int* array, int array_len, int* Num1, int* Num2)
{
	if(NULL == array || 0 == array_len)
	{
		printf("��������\n");
		return -1;
	}
	int i;
	int xor = 0,flag,xor1 = 0,xor2 = 0;
	for(i = 0; i < array_len; i++)
	{
		xor ^= array[i];
	}
	i = 0;
	//�ҳ������������ֵ�в�Ϊ0��һλ
	while(!(xor & (1<<i)) && i < 8*sizeof(int))
	{
		i++;
	}
	if(8*sizeof(int) == i)
	{
		printf("�����в�����ֻ����һ�ε�������");
		return -2;
	}
	flag = 1<<i;
	//���ݲ�Ϊ0��һλ�������Ϊ�����֣���ʱ2����ͬ�����ֱ������������������
	for(i = 0; i < array_len; i++)
	{
		if(array[i] & flag)
			xor1 ^= array[i];
		else
			xor2 ^= array[i];
	}
	*Num1 = xor1;
	*Num2 = xor2;
	return 0;
}
 
int main()
{
	int test[] = {1,2,3,4,5,6,7,3,7,6,1,2,4};
	int test1[] = {1,2,3,4,5,6,5,3,7,6,1,2};
	int num = 0,num1,num2;
	FindNumAppearOnce(test,sizeof(test)/sizeof(int), &num);
	FindNumsAppearOnce(test1,sizeof(test1)/sizeof(int), &num1, &num2);	
	printf("%d\r\n",num);
	printf("%d	%d\r\n",num1,num2);
}