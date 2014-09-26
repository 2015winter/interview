/****************************************************************************
 * @file     04_�ַ���ȫ����.c
 * @brief    ����ַ�����ȫ����
 * @version  V1.00
 * @date     2014.9.15
 * @note     �ֵ�����ȫ���к͵ݹ���ȫ����
 ****************************************************************************/
#include <stdio.h>


/**		�ڲ�����  
*     
*		�������������н�����    
*/ 
static void Swap(char *a, char *b)
{
	if(a == b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


/** 
 * @brief     ��ת�ַ�����
 * @param[in] array    �ַ�������ʼ��ַ
 * @param[in] begin    ��ת�ַ�������ʼ
 * @param[in] end      ��ת�ַ����Ľ���
 * @retval    None
 * @see       None
 * @note      ���ַ���1��n������2��n-1���������ν���...
 */
void Reverse(char* array, int begin, int end)
{
	if(NULL == array)
	{
		printf("��������!\n");
		return ;
	}
	while(begin < end)
	{
		array[begin] ^= array[end];
		array[end] ^= array[begin];
		array[begin++] ^= array[end--];
	}
}

/** 
 * @brief     ���ַ�������һ��ȫ���С�
 * @param[in] array    �ַ�������ʼ��ַ
 * @param[in] length   �ַ����ĳ���
 * @retval    None
 * @see       None
 * @note      �ֵ������ַ�������һ������
 */
int Permutation(char* array, int length)
{
	if(NULL == array || 0 == length)
	{
		printf("��������\r\n");
		return 2;	
	}
	int i, j, k, left, right, min;
	for(i = length - 1; i > 0; i--)
	{
		if(array[i-1] < array[i])
		{
			left = i - 1;
			right = i;
			min = array[i];
			for(k = i; k < length; k++)
			{
				if(array[k] > array[left] && array[k] < min)
				{
					min = array[k];
					right = k;
				}
			}
			Swap(&array[left], &array[right]);
			Reverse(array, left+1, length - 1);
			return 1;
		}
	}
	return 0;
}

/** 
 * @brief     ���ַ�������һ��ȫ���С�
 * @param[in] array    �ַ�������ʼ��ַ
 * @param[in] length   �ַ����ĳ���
 * @retval    -1����������
 * @see       None
 * @note      �ֵ������ַ�������һ������
 */
int Permutation_Recursion(char* array, char* begin)
{
	if(NULL == array)
	{
		printf("��������\r\n");	
		return -1;
	}
	char* temp;
	if(*begin == '\0')
	{
		printf("%s\n",array);
		return 0;
	}	
	for(temp = begin; *temp != '\0'; temp++)
	{
		Swap(begin, temp);
		Permutation_Recursion(array, begin + 1);
		Swap(begin, temp);
	}
}

int main()
{
	char array[] = "123";
	int i = 1;
	//printf("%s\n",array);
	// while(1 == Permutation(array, strlen(array)))
	// {
		// i++;
		// printf("%s\n",array);
	// }
	Permutation_Recursion(array, array);
	//printf("���� = %d\n",i);	
}


