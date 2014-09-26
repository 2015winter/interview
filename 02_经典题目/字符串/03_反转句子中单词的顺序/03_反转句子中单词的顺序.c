/****************************************************************************
 * @file     03_��ת�����е��ʵ�˳��.c
 * @brief    ����"I am a  student"�����"student a am I"
 * @version  V1.00
 * @date     2014.9.15
 * @note     
 ****************************************************************************/
#include <stdio.h>

/** 
 * @brief     ��ת�ַ�����
 * @param[in] begin    �ַ�����ͷָ��
 * @param[in] end      �ַ�����βָ��
 * @retval    None
 * @see       None
 * @note      ���ַ���1��n������2��n-1���������ν���...
 */
void Reverse(char* begin,char* end)
{
	if(NULL == begin ||  NULL == end)
	{
		printf("��������!\n");
		return ;
	}
	while(begin < end)
	{
		*begin ^= *end;
		*end ^= *begin;
		*begin++ ^= *end--;
	}
}

int ReverseWordOrder(char* data_ptr)
{
	if(NULL == data_ptr)
	{
		printf("��������!\n");
		return 1;
	}
	char *begin,*end;
	begin = end  = data_ptr;
	while('\0' != *++end){}
	end--;
	//��ת�����ַ���
	Reverse(begin, end);
	//��ת�������
	begin = end  = data_ptr;
	while('\0' != *begin)
	{
		if(*begin == ' ')
		{
			begin++;
			end++;
		}
		else if(*end == ' ' || *end == '\0')
		{
			Reverse(begin, --end);
			begin = ++end;
		}
		else
		{
			end++;
		}
	}
}

int main()
{
	char p[16] = " I am a  tudent";
	ReverseWordOrder(p);
	printf("%s",p);
}


