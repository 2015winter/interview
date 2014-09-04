/****************************************************************************
 * @file     07_��С���жϼ�ת��.c
 * @brief    �жϵ�ǰ�����Ǵ�˻���С�˴洢
 * @version  V1.00
 * @date     2014.9.3
 * @note     
****************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define BigtoLittle16(A)   ((( (uint16)(A) & 0xff00) >> 8)   |   \
							(( (uint16)(A) & 0x00ff) << 8))
							
#define BigtoLittle32(A)   ((( (uint32)(A) & 0xff000000) >> 24)  | \
                            (( (uint32)(A) & 0x00ff0000) >> 8)   | \
                            (( (uint32)(A) & 0x0000ff00) << 8)   | \
                            (( (uint32)(A) & 0x000000ff) << 24))
/** 
 * @brief     ���Գ������жϻ������ֽ���
 * @param[in] None 
 * @retval    true�����ģʽ	false��С��ģʽ
 * @see       None
 * @note      		  
 */
bool IsBigEndian()
{
	int a = 0x1234;
	char b =  *(char *)&a;  //ͨ����intǿ������ת����char���ֽڣ�ͨ���ж���ʼ�洢λ�á�������ȡb����a�ĵ͵�ַ����
	if( b == 0x12)
	{
		printf("���ģʽ\r\n");
		return true;
	}
	printf("С��ģʽ\r\n");
	return false;
}
/** 
* @brief     ���Գ������жϻ������ֽ���
* @param[in] None 
* @retval    true�����ģʽ	false��С��ģʽ
* @see       None
* @note      ������union�Ĵ��˳�������г�Ա���ӵ͵�ַ��ʼ��ţ����ø�����
			 �������ɵػ����CPU���ڴ����Little-endian����Big-endianģʽ��д		  
*/
bool IsBigEndian1()
{
	union NUM
	{
		int a;
		char b;
	}num;
	num.a = 0x1234;
	if( num.b == 0x12 )
	{
		printf("���ģʽ\r\n");
		return true;
	}
	printf("С��ģʽ\r\n");
	return false;
}

int main()
{
	printf("%d",IsBigEndian1());
}