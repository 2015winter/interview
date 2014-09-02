/****************************************************************************
* @file     04_�����������.c
* @brief    ������������� 
* @version  V1.00
* @date     2014.9.1
* @note     
****************************************************************************/
#include <stdio.h> 
#include <string.h>

#define MAXNUM 200

int LCSPro[MAXNUM][MAXNUM];
int LCSPath[MAXNUM][MAXNUM];
/**        �����ֵ   
 *     
 *     ��������������һ����    
 */
int Max(int a, int b)
{
    return a > b ? a : b;
}

/** 
 * @brief   ��text��query�����ַ�����������������С�
 * @param   query      query����ָ�� 
 * @param   query_len  query�ĳ��� 
 * @param   text       text����ָ��     
 * @param   text_len   text�ĳ��� 
 * @retval  ������     0���ɹ�	-1�������������	-2������ռ�ʧ�ܡ�
 * @see     None;
 * @note    
 */
int LCS(char* query, int query_len, char* text, int text_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("�����������\r\n");
		return -1;
	}
	int *p;
	int i,j;
	if(NULL == (p = (int*)malloc(sizeof(int)*(text_len + 1))))
	{
		printf("����ռ�ʧ��!\r\n");
		return -2;
	}	
	for(i = 0; i < query_len; i++){ LCSPro[i][0] = 0; }
	for(j = 0; j < text_len; j++){ LCSPro[0][j] = 0; }

	for(i = 0; i < query_len; i++)
	{
		for(j = 0; j < text_len; j++)
		{
			if(query[i] == text[j])
			{
				LCSPro[i+1][j+1] = LCSPro[i][j] + 1;
				LCSPath[i+1][j+1] = 0;
			}
			else if(LCSPro[i+1][j] <= LCSPro[i][j+1])
			{
				LCSPro[i+1][j+1] = LCSPro[i][j+1];
				LCSPath[i+1][j+1] = 1;
			}
			else
			{
				LCSPro[i+1][j+1] = LCSPro[i+1][j];
				LCSPath[i+1][j+1] = 2;
			}
		}
	}
}

/** 
 * @brief   ��ӡ��query��text�����ַ�����������������С�
 * @param   query      query����ָ�� 
 * @param   query_len  query�ĳ���  
 * @param   text_len   text�ĳ��� 
 * @retval  None
 * @see     None
 * @note    
 */
void PrintPath(char* query, int query_len, int text_len)
{
	if(query_len == 0 || text_len == 0)
		return;//�ݹ���ֹ����
	if(LCSPath[query_len][text_len] == 0)
	{	
		PrintPath(query, query_len - 1, text_len - 1);
		printf("%c", query[query_len - 1]);
	}
	else if(LCSPath[query_len][text_len] == 1)
	{
		PrintPath(query, query_len - 1, text_len);
	}
	else
	{
		PrintPath(query, query_len, text_len - 1);
	}
} 



int main()
{
	char *query = (char*)malloc(sizeof(char)*MAXNUM);
	char *text = (char*)malloc(sizeof(char)*MAXNUM);
	printf("������query��");
	gets(query);
	printf("������text��");
	gets(text);
	//char query[] = "ABCBDAB";
	//char text[] = "BDCABA";
	int query_len = 0, text_len = 0, i, j;
	while(query[query_len] != '\0'){query_len++;};
	while(text[text_len] != '\0'){text_len++;};
	LCS(query, query_len, text, text_len);
	printf("LCS����Ϊ%d\r\n",LCSPro[query_len][text_len]);
	printf("LCSΪ");
	PrintPath(query, query_len, text_len);
	free(query);
	free(text);
}
