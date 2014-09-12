/****************************************************************************
 * @file     01_Fibonacci.c
 * @brief    �ݹ����쳲��������С�
 * @version  V1.00
 * @date     2013.12.28
 * @note     ʱ�临�Ӷ�O(n)
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/**		��쳲��������еĵ�n��   
 *     
 *		���õ�����⡣    
 */ 
long long Fibonacci_Iteration(uint32_t n)
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

/**		��쳲��������еĵ�n��   
 *     
 *		���õݹ���⡣    
 */ 
long long Fibonacci_Recursion(uint32_t n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return Fibonacci_Recursion(n-1) + Fibonacci_Recursion(n-2);
	}
}

/**		��쳲��������еĵ�n��   
 *     
 *		����β�ݹ���⡣    
 */ 
int factorial_tail(int n,int acc1,int acc2)
{
    if (n == 0)
    {
        return acc1;
    }
    else
    {
        return factorial_tail(n-1,acc2,acc1+acc2);
    }
}
int main()
{
	uint32_t n; 
	printf("������N:\n");
	
	while(EOF != scanf("%d",&n))
	{
		printf("Fibnacci���еĵ�%d��Ϊ��%d\n",n,factorial_tail(n, 0, 1));
	}
}

