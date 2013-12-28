/****************************************************************************
 * @file     ��˾Ա����������.c
 * @brief    ĳ��˾�м�����Ա���������һ��ʱ�临�Ӷ�ΪO(n)���㷨�Ըù�˾Ա��
			 �����������򣬿�ʹ��O(1)�ĸ����ռ䡣
 * @version  V1.00
 * @date     2013.12.28
 * @note     Ա������Ŀ��Ȼ�м����ˣ����⼸��Ա��������ȴֻ�м�ʮ�ֿ��ܡ��÷�
			 ���ó���100���������鸨���ռ䣨�����Hash��������O(n)��ʱ��Ч�ʡ�
			 ���ڲ��ܶԶ����˵����������򣬸�������ĳ����ǹ̶���100��������
			 ������Ŀռ临�Ӷ��Ǹ���������O(1)��
****************************************************************************/
#include "stdio.h"   

/** 
 * @brief     �����������������ͳ��ȣ���������������������
 * @param[in] ages    ������������
 * @param[in] length  ����ĳ��ȣ�Ա���ĸ�����
 * @retval    None
 * @see       None
 * @note      ��
 */
void SortAges(int ages[], int length)
{
    if(ages == NULL || length <= 0)
        return;
 
    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];
 
    for(int i = 0; i <= oldestAge; ++ i)
        timesOfAge[i] = 0;
 
    for(int i = 0; i < length; ++ i)
    {
        int age = ages[i];
        if(age < 0 || age > oldestAge)
		{
            printf("age out of range.\n");
			return ;
		}
        ++ timesOfAge[age];
    }
 
    int index = 0;//������ages�е�����
    for(int i = 0; i <= oldestAge; ++ i)
    {
        for(int j = 0; j < timesOfAge[i]; ++ j)
        {
            ages[index] = i;
            ++ index;
        }
    }
}

int main()
{
	int i;
	int ages[16] = {25,24,26,24,25,19,25,29,36,80,76,76,76,45,25,48};
	SortAges(ages,16);
	for(i = 0; i < 16; i++)
	{
		printf("%d  ",ages[i]);
	}
}