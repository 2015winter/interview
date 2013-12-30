/****************************************************************************
 * @file     01_Fibonacci.c
 * @brief    �ݹ����쳲��������С�
 * @version  V1.00
 * @date     2013.12.28
 * @note     ʱ�临�Ӷ�O(n)
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

long long Fibonacci(uint32_t n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		uint32_t i = 2;
		long long fibn,first = 0,last = 1;
		while(i++ <= n)
		{
			fibn = first + last;
			first = last;
			last = fibn;
		}
		return fibn;
	}
}

int main()
{
	uint32_t n; 
	printf("������N:\n");
	
	scanf("%d",&n);
	while(1)
	{
		printf("Fibnacci���еĵ�%d��Ϊ��%d\n",n,Fibonacci(n));
		scanf("%d",&n);
	}
}

