/****************************************************************************
 * @file     EditDistance_bx.c
 * @brief    ��������ַ����ı༭����
 * @version  V1.00
 * @date     2014��5��30��
 * @note     ˼·��2ά�Ķ�̬�滮��
****************************************************************************/
#include <stdio.h>
#include <malloc.h>


int min(int a, int b, int c)
{
    int small = a;
    if(b < small)
        small = b;
    if(c < small)
        small = c;
    return small;
}


/** 
 * @brief     �����ַ����ı༭���롣
 * @param[in] array  ԭʼ����ָ��
 * @param[in] temp   ���ڴ�����������
 * @param[in] begin  ������ʼλ��
 * @param[in] end    �������λ��
 * @retval    
 * @see       None
 * @note      		  
 */
int CalEditDist(char* str1, int str1len, char* str2, int str2len)
{
	int i,j,re;
	int *array = (int*)malloc(((str1len+1)*(str2len+1))*sizeof(int));
	
	for(i = 0; i < str1len; i++)
		*(array + i*str1len) = i;           //array[i][0]
	for(j = 0; j < str2len; j++)
	    *(array + j) = j;                   //array[0][j]
	for(i = 1; i <= str1len; i++)
	{
		for(j = 1; j <= str2len; j++)
		{
			*(array+i*(str2len+1)+j) = min(*(array+i*(str2len+1)+j-1)+1,*(array+(i-1)*(str2len+1)+j)+1,*(array+(i-1)*(str2len+1)+j-1) + (str1[i] == str2[j] ? 0 : 1));
		}
	}
	re =  *(array+(str1len)*(str2len+1)+(str2len));
	printf("===%d",re);
	free(array);
	array=NULL;
	return re;
}
 
int main()
{
	char a[10]="1234567890";
	char b[10]="1234567890";

	CalEditDist(a,10,b,10);
}