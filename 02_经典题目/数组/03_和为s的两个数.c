/****************************************************************************
 * @file     03_��Ϊs��������.c
 * @brief    ����һ����������������һ������s���������в�����������ʹ����
			 �ǵĺ�������s������ж�����ֵĺ͵���s���������һ�Լ��ɡ�
 * @version  V1.00
 * @date     2014.9.2
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/** 
 * @brief     �ҳ������е�������ʹ�����ǵĺ�������s
 * @param[in] array       �������ʼ��ַ
 * @param[in] array_len   ����ĳ���
 * @param[in] s           ��Ҫ������õĺ�
 * @retval    0���ɹ�	-1����������
 * @see       None
 * @note      		  
 */
int Find2NumsWithSum(int* array, int array_len, int s)
{
	if(NULL == array || 0 == array_len)
	{
		printf("��������\n");
		return -1;
	}

}

/** 
 * @brief     ������ֻ����һ�ε�������
 * @param[in] array       �������ʼ��ַ
 * @param[in] array_len   ����ĳ���
 * @retval    0���ɹ�	-1����������	-2��������ֻ����һ�ε�������
 * @see       None
 * @note      		  
 */
int FindNumsWithSum(int* array, int array_len, int s)
{
	if(NULL == array || 0 == array_len)
	{
		printf("��������\n");
		return -1;
	}

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