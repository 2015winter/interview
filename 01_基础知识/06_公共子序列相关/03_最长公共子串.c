/****************************************************************************
* @file     02_��text��query�е���Ӵ�.c
* @brief    ����һ��query��һ��text������Сд��ĸ��ɡ�Ҫ����text���ҳ���ͬ
			����˳������������query�е��������ĸ���еĳ��ȡ����磬 queryΪ��acbac����textΪ��acaccbabb������ôtext�еġ�cba��Ϊ�������
			������query�е���ĸ���У���ˣ����ؽ��Ӧ��Ϊ�䳤��3�� 
* @version  V1.00
* @date     2014.8.29
* @note     
****************************************************************************/
#include <stdio.h>

#define MAXNUM 200
/** 
 * @brief   ��text��query�����ַ�����������Ӵ���
 * @param   query      query����ָ�� 
 * @param   query_len  query�ĳ��� 
 * @param   text       text����ָ��     
 * @param   text_len   text�ĳ��� 
 * @retval  ������     0���ɹ�	-1�������������	-2������ռ�ʧ�ܡ�
 * @see     None;
 * @note    
 */
int MaxCommonSubString(char* query, int query_len, char* text, int text_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("�����������\r\n");
		return -1;
	}
	int *p, max = 0, postion = 0;
	int i,j;
	if(NULL == (p = (int*)malloc(sizeof(int)*(text_len + 1))))
	{
		printf("����ռ�ʧ��!\r\n");
		return -2;
	}
	memset(p, 0, sizeof(int)*(text_len + 1));
	for(i = 0; i < query_len; i++)
	{
		for(j = text_len - 1; j >= 0; j--)
		{
			//�Ӻ���ǰ����query������ǰ����������Ҫ�����һ������������p��һ�ε�ֵ
			if(text[j] == query[i])
			{
				p[j+1] = p[j] + 1;
				if(p[j+1] > max)
				{
					max = p[j+1];         //�滻��ǰ����Ӵ�����
					postion = j - max + 1;//�Ӵ���ʼλ��
				}
			}
			else
			{
				p[j+1] = 0;
			}
		}
	}
	//���벢����������Ӵ���substring
	char *substring;
	if(NULL == (substring = (char*)malloc(sizeof(char)*(max + 1))))
	{
		printf("����ռ�ʧ��!\r\n");
		return -1;
	}	
	memcpy(substring, text + postion, max);
	substring[max] = '\0';
	printf("������Ӵ�Ϊ��%s�����ȣ�%d\r\n", substring, max);
	free(p);
	free(substring);
	return 0;
}


/** 
 * @brief     ����query��text�г��ֵ��������ĸ���еĳ���
 * @param[in] text       text���׵�ַ
 * @param[in] text_len   text�ĳ���
 * @param[in] query      query���׵�ַ
 * @param[in] query_len  ������
 * @retval    �������ĸ���еĳ��� -1�����������
 * @see       
 * @note      �������
 */
int MaxString(char text[],int text_len,char query[],int query_len)
{
	if((NULL == text)|| (NULL == text) || text_len < 0 || query_len < 1)
	{
		printf("�����������\n");
		return -1;
	}
	char temp[MAXNUM];
	int MaxLeng = 0;
	int MaxTemp = 0;
	text[text_len]='\0';query[query_len]='\0';
	for(int i= 0;i < query_len; i++)
	{
		for(int j = query_len;j > i; j--)
		{
			strcpy(temp,query);
			temp[j]= '\0' ;
			if(strstr(text, &temp[i]))
			{
				MaxTemp = j - i;
				if(MaxTemp > MaxLeng)
					MaxLeng = MaxTemp;
			}
		}
	}
	return MaxLeng;
}

int main()
{
	char *query = (char*)malloc(sizeof(char)*MAXNUM);
	char *text = (char*)malloc(sizeof(char)*MAXNUM);
	printf("������query��");
	gets(query);
	printf("������text��");
	gets(text);
	int i = 0, j = 0;
	while(query[i] != '\0'){i++;};
	while(text[j] != '\0'){j++;};
	MaxCommonSubString(query, i, text, j);
	free(query);
	free(text);
}
