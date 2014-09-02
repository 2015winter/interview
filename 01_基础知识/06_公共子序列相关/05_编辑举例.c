/****************************************************************************
 * @file     EditDistance_bx.c
 * @brief    ��������ַ����ı༭����
 * @version  V1.00
 * @date     2014��5��30��
 * @note     �༭���붨�壺���������ַ����ľ��룬��ȫ��ͬ���ַ�������Ϊ0����
			 ��ͨ���޸�һ���ַ�������һ���ַ���ɾ��һ���ַ����ַ�ʽ��ʹ������
			 ������ͬ������Щ��ʽ��ʹ�þ����1��
             ˼·�� 2ά�Ķ�̬�滮��
****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/**		����Сֵ   
 *     
 *		������������С��һ����    
 */
int min(int a, int b, int c)
{
    return (a = a < b ? a : b) < c ? a : c;
}


/** 
 * @brief     �����ַ����ı༭���롣
 * @param[in] str1      �ַ���1����ʼ��ַ
 * @param[in] str1len   �ַ���1�ĳ���
 * @param[in] str2      �ַ���2����ʼ��ַ
 * @param[in] str2len   �ַ���2�ĳ���
 * @retval    �ɹ��������ַ���֮��ı༭���룬ʧ�ܣ�-1
 * @see       None
 * @note      		  
 */
int CalEditDist(char* str1, int str1len, char* str2, int str2len)
{
	if(NULL == str1 || NULL == str2 || 0 == str1len || 0 == str2len)
	{
		printf("��������\n");
		return -1;
	}
	int i,j,re;
	int *array = (int*)malloc(((str1len+1)*(str2len+1))*sizeof(int));
	
	for(i = 0; i <= str1len; i++)
		*(array + i*(str2len + 1)) = i;           //array[i][0]
	for(j = 0; j <= str2len; j++)
	    *(array + j) = j;                   //array[0][j]
	for(i = 1; i <= str1len; i++)
	{
		for(j = 1; j <= str2len; j++)
		{
			*(array+i*(str2len+1)+j) = min(*(array+i*(str2len+1)+j-1)+1,*(array+(i-1)*(str2len+1)+j)+1,*(array+(i-1)*(str2len+1)+j-1) + (str1[i-1] == str2[j-1] ? 0 : 1));
		}
	}
	re =  *(array+(str1len)*(str2len+1)+(str2len));
	free(array);
	array=NULL;
	return re;
}
 
int main()
{
	char a[]="David_and_Sophia";
	char b[]="Dadiudiu_and_Xiaodiugirl";
	printf("%d",CalEditDist(a,sizeof(a)/sizeof(char)-1,b,sizeof(b)/sizeof(char)-1));
}