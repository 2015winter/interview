/****************************************************************************
* @file     04_�ַ���ƥ��.c
* @brief    
* @version  V1.00
* @date     2014.9.4
* @note     
****************************************************************************/
#include <stdio.h>
#include <string.h>

int ViolentMatch(char* text, char* pattern)  
{  
	int text_len = strlen(text);  
	int pattern_len = strlen(pattern);  

	int i = 0;  
	int j = 0;  
	while (i < text_len && j < pattern_len)  
	{  
		if (text[i] == pattern[j])  
		{  
			//�����ǰ�ַ�ƥ��ɹ�����i++��j++      
			i++;  
			j++;  
		}  
		else  
		{  
			//���ƥ��ʧ�ܣ���i = i - (j - 1)��j = 0 ���ص���ǰƥ��ĵ�һ���ַ�����һ��     
			i = i - j + 1;  
			j = 0;  
		}  
	}  
	//ƥ��ɹ�������ģʽ��p���ı���s�е�λ�ã����򷵻�-1  
	if (j == pattern_len)  
		return i - j;  
	else  
		return -1;  
} 

//ֱ�Ӷ�t��������ƥ�䣬�������м���next����
//�������õ��Ʒ����м��㣺GetNext_R
//�������������
void GetNext_D(char *t,int *next)
{
	unsigned int i=0,j=0,k=0;
	int equal = 1;

	for(i=0;i<strlen(t);i++)
	{
		if(i==0)
		next[i] = -1;
		else if(i==1)
		next[i] = 0;
		else
		{
			for(j=i-1;j>0;j--)
			{
				equal = 1;
				//t[0��j]������ǰ׺�ͺ�׺���бȽ��жϣ���������
				//ƥ�䵽��break���õ�Ŀǰ����ƥ������ǰ׺�ͺ�׺
				//����ababa  next[4]=2,˵��t[0...2] match t[2...4]
				for(k=0;k<j;k++)
				{
					//ע������������
					if(t[k]!=t[i-j+k])
					equal = 0;
				}

				if(equal)
				{
					next[i] = j;
					break;
				}
			}
			if(j == 0)
			next[i]=0;

		}
	}

}

//���ƵĹ�ϵ����next
//�ú�����µ��ƹ�ϵ
void GetNext_R(char *t,int *next)
{
	unsigned int j=0;
	int k = -1;
	next[0]=-1;

	while(j<strlen(t)-1)
	{

		if(k==-1||t[j]==t[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
		k=next[k];
	}

}

int KMP(char *s, char *t)
{
	unsigned int i;
	int j = 0;
	int *next = (int*)calloc(strlen(t),sizeof(int));

	//GetNext_D(t,next);
	GetNext_R(t,next);

	printf("next[] = ");
	for(i=0;i<strlen(t);i++)
	printf("%d ",next[i]);

	i=0;
	while(i<strlen(s))
	{
		if(j==-1||s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		j = next[j];

		if(j==strlen(t))
		return (i-strlen(t));
	}

	free(next);

	return -1;
}

int main()
{
	char text[] = "ABCDEFGHIJKLMN";
	char pattern[] = "KLM";
	int result = ViolentMatch(text, pattern);
	if(-1 == result)
	{
		printf("ƥ�䲻�ɹ�\r\n");
	}
	else
	{
		printf("ƥ��ɹ���ƥ��λ�ã�%d\r\n",result);
	}
}


