/****************************************************************************
 * @file     04_˳ʱ���ӡ����.c
 * @brief    ����һ�����󣬴�������˳ʱ���ӡ��ÿһ�������������£�
 *		     1  2  3  4  5 
 *		     6  7  8  9  10
 *		     11 12 13 14 15 
 *		     16 17 18 19 20
 *		     21 22 23 24 25
 * @version  V1.00
 * @date     2014.9.24
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define ROW 5
#define COLUMN 5

/** 
 * @brief     ˳ʱ���ӡ���顣
 * @param[in] array  ��ά������ָ��
 * @param[in] row    ����
 * @param[in] column ����
 * @retval    None
 * @see       None
 * @note      		  
 */
void PrintMatrix(int** array, int row, int column)
{
	int start = 0,i;
	while(start * 2 < row && start * 2 < column)
	{
		int endx = row - start - 1;
		int endy = column - start - 1;
		//������һ��
		for(i = start; i <= endy; i++)
		{
			printf("%d    ",array[start][i]);	
		}
		//���ұ�һ�У�ֻ���ڴ��ڵ���2�е������
		if(endx > start)
		{
			for(i = start+1; i <= endx; i++)
			{
				printf("%d    ",array[i][endy]);	
			}
		}
		//������һ�У�����2��2�е�����£�����һ�л���һ�ж�������ظ���ӡ
		if(endx > start && endy > start)
		{
			for(i = endy-1; i >= start; i--)
			{
				printf("%d    ",array[endx][i]);	
			}
		}
		//�����һ�У�����3��2�е������
		if(endx > start+1 && endy > start)
		{
			for(i = endx-1; i > start; i--)
			{
				printf("%d    ",array[i][start]);	
			}
		}
		start++;
	}
}

/** 
 * @brief     ˳ʱ���ӡ���顣
 * @param[in] array  ��ά������ָ��
 * @param[in] row    ����
 * @param[in] column ����
 * @retval    None
 * @see       None
 * @note      		  
 */
void PrintMatrix_Recursion(int** array, int row, int column, int start)
{
	if(start * 2 >= row || start * 2 >= column)	
		return ;
	//������һ��
	int i;
	int endx = row - start - 1;
	int endy = column - start - 1;
	for(i = start; i <= endy; i++)
	{
		printf("%d    ",array[start][i]);	
	}
	//���ұ�һ�У�ֻ���ڴ��ڵ���2�е������
	if(endx > start)
	{
		for(i = start+1; i <= endx; i++)
		{
			printf("%d    ",array[i][endy]);	
		}
	}
	//������һ�У�����2��2�е�����£�����һ�л���һ�ж�������ظ���ӡ
	if(endx > start && endy > start)
	{
		for(i = endy-1; i >= start; i--)
		{
			printf("%d    ",array[endx][i]);	
		}
	}
	//�����һ�У�����3��2�е������
	if(endx > start+1 && endy > start)
	{
		for(i = endx-1; i > start; i--)
		{
			printf("%d    ",array[i][start]);	
		}
	}
	PrintMatrix_Recursion(array, row, column, start+1);
}

int main()
{
	int **array = (int**)malloc(sizeof(int*)*ROW);
	//printf("array = %d  array+1 = %d\n", array, array+1);
	int i,j;
	for(i = 0; i < ROW; i++)
	{
		array[i] = (int*)malloc(sizeof(int)*COLUMN);
		//printf("array[%d] = %d\n",i,array[i]);
		for(j = 0; j < COLUMN; ++j)
		{
		//	printf("array[%d][%d] = %d\n",i,j,&array[i][j]);
			array[i][j] = i * COLUMN + j + 1;
		}
	}
	//PrintMatrix(array,ROW,COLUMN);
	PrintMatrix_Recursion(array,ROW,COLUMN,0);
	//�ͷ��ڴ�
	for(i = 0; i < ROW; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);	
	array = NULL;
}