/****************************************************************************
* @file     02_���������.c
* @brief    ����������� 
* @version  V1.00
* @date     2014.9.1
* @note     
****************************************************************************/
#include <stdio.h> 
#include <string.h>

/** 
 * @brief   ��text����������������͡�
 * @param   text       text����ָ�� 
 * @param   text_len   text�ĳ��� 
 * @retval  None
 * @see     None
 * @note    
 */
void MaxSubSequence(int* text, int text_len)
{
	int i;
	int MaxSum = 0, CurrentSum = 0, begin = 0, newbegin = 0, end = 0;
	for(i = 0; i < text_len; i++)
	{
		if(CurrentSum <= 0)
		{
			CurrentSum = text[i];
			newbegin = i;
		}
		else
		{
			CurrentSum += text[i];
		}
		if(CurrentSum > MaxSum)
		{
			MaxSum = CurrentSum;
			begin = newbegin;
			end = i;
		}
	}
	printf("MaxSum = %d\r\n", MaxSum);
	for(i = begin; i < end+1; i++)
		printf("%d	",text[i]);
	
} 



int main()
{
	int  text[] = {1,-2,3,10,-4,7,2,-5};
	MaxSubSequence(text, sizeof(text)/sizeof(int));
}
