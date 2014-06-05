/****************************************************************************
 * @file     answer.c
 * @brief    ��description
 * @version  V2.00
 * @date     2014��6��5��
 * @note     V1 ���ü���༭����ķ���,ģ����ö�ά�����š�
			 V2 ģ�����ָ�������š�
****************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_NUM 100
/**		����Сֵ   
 *     
 *		������������С��һ����    
 */
int min(int a, int b, int c)
{
    return (a = a < b ? a : b) < c ? a : c;
}


/** 
 * @brief     ��ά��̬�滮�����ַ����ı༭���롣
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
	    *(array + j) = j;                         //array[0][j]
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
	char *temp = (char*)malloc(256*sizeof(char)),*ptr;
	char *template[MAX_NUM];
	int count[MAX_NUM],i;
	int len[MAX_NUM] = {0},length,flag,max;
	memset(count,-1,sizeof(int)*MAX_NUM);
	while(gets(temp) != NULL)
	{
		if(strlen(temp) == 0)
			break;
		//��ʼ����һ��ģ�壬�����޷�������һ��
		if(count[0] == -1)
		{
			template[0] = temp;
			count[0] = 1;
			len[0] = strlen(temp);
			continue;
		}
		length = strlen(temp);
		flag = 0;
		for(i = 0; i < MAX_NUM && count[i] != -1; i++)
		{
			if(CalEditDist(temp,length,template[i],len[i]) <= 5)
			{
				count[i]++;
				flag = 1;
				break;
			}
		}
		//�����ģ���б���û���ҵ���Ӧ��ģ��
		if(!flag)
		{
			template[i] = temp;
			count[i] = 1;
			len[i] = length;
		}
	}
	i = 0;
	max = 0;
	while(count[i] != -1)
	{
		if(count[i] > max)
			max = count[i];
		i++;
	}
	printf("%d ",max);
	free(temp);
	temp = NULL;
	//printf("%d",CalEditDist(a,sizeof(a)/sizeof(char)-1,b,sizeof(b)/sizeof(char)-1));	
}