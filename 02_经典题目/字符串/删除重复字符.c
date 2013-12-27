/****************************************************************************
 * @file     ɾ���ظ��ַ�.c
 * @brief    ����һ�����Ȳ����� 100 ���ַ�����ɾ�����е��ظ��ַ���
 * @version  V1.00
 * @date     2013.12.27
 * @note     ��
 ****************************************************************************/
# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <stdint.h>
# include <stdlib.h>
//�����ַ�����󳤶�
# define N 100

//�жϲ����Ƿ����
#define ASSERT(expr) \
	  ((expr) ? (void)0 : assert_failed((char *)__FILE__, __LINE__))

#define IS_POINTER(POINTER)      (POINTER != NULL)
#define IS_LENGTH(LENGTH)      (LENGTH > 0 && LENGTH <= N)

/**		��������ʱִ�еĺ���\n  
 *     
 *		��ʹ��ASSERT�жϲ�������ʱ����ʾ������ֵ�λ�á�    
 */
void assert_failed(char* file, uint32_t line)
{
	printf("%s �� %d �д���\n",file,line);
	while(1);
} 

/** 
 * @brief     ɾ���ظ����ֵ��ַ���
 * @param[in] Old_ptr     ָ�������ַ�����ָ��
 * @param[in] New_ptr     ָ������ַ�����ָ��
 * @param[in] Old_Length  �����ַ����ĳ���
 * @retval    None
 * @see       None
 * @note      ɨ��ԭ�����ַ������жϵ�ǰ�ַ��Ƿ������ַ������֣�������ֱ��
			  break,û������ӵ����ַ���ĩβ
 */
void delrepechar(char *Old_ptr, char *New_ptr, int Old_Length) 
{
	ASSERT(IS_POINTER(Old_ptr));
	ASSERT(IS_POINTER(New_ptr));
	ASSERT(IS_LENGTH(Old_Length));
	int i,j,k = 0;
	char Test_char;
	for (i = 0; i < Old_Length; i++) 
	{
		Test_char = Old_ptr[i];
		for (j = 0; j < k; j++) 
		{
			if (New_ptr[j] == Test_char) 
			{
				break;
			}
		}
		if (j == k) 
		{
			New_ptr[k++] = Test_char;
		}
	}
	//�ַ���ĩβ���Ͻ�����
	New_ptr[k] = '\0';
}

int main() 
{
	char * Old_ptr,* New_ptr;
	int Old_Length;
	//���������ַ�����С�Ŀռ�
	if (NULL == (Old_ptr = (char * )malloc(N * sizeof(char)))) 
	{
		perror("error...");
		return 1;
	}
	printf("�������ɾ���ַ���,���Իس�������\n");
	gets(Old_ptr);
	if(NULL == Old_ptr)
	{
		printf("�����ַ���Ϊ��!\n");
		free(Old_ptr);
		return 1;
	}
	//��������ַ����ĳ���
	Old_Length = strlen(Old_ptr);
	printf("�ַ�������Ϊ%d\n",Old_Length);
	//�����¿ռ������ַ���
	if (NULL == (New_ptr = (char * )malloc(Old_Length * sizeof(char)))) 
	{
		perror("error...");
		free(Old_ptr);
		return 1;
	}
	//ɾ���ظ����ַ���
	delrepechar(Old_ptr,New_ptr,Old_Length);

	printf("ɾ���ظ��ַ�����ַ���Ϊ��\n%s\n", New_ptr);
	//�ͷ�����Ŀռ�
	free(Old_ptr);
	free(New_ptr);
	return 0;
}


