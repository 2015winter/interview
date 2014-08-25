/****************************************************************************
 * @file     05_��������ĸ���.c
 * @brief    ��������ĸ���
 * @version  V1.00
 * @date     2014.7.24
 * @note     ʱ�临�Ӷ�:���:  �:
 * @note     
 ****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/**		�ڵ��������� \n  
 *     
 *		����ڵ��������͡�    
 */
typedef int ElementType;
/**		����ṹ�嶨�� \n  
 *     
 *		��������ڵ��������ĳ�Ա����������ָ����һ���ڵ��ָ��͵�ǰ�ڵ��ֵ��    
 */ 
typedef struct complexlistnode 
{
	int m_nValue;
	struct complexlistnode * m_pNext;
	struct complexlistnode * m_pSibling;
} ComplexListNode,*ComplexListNode_ptr;

/** 
 * @brief     ��������ĸ��ơ�
 * @param[in] pHead:��Ҫ���Ƶ�����ͷ
 * @retval    ComplexListNode *  ���ظ����������ָ�롣
 * @see       ComplexListNode
 * @note      ��
 */
ComplexListNode* Clone(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	
	while(NULL != pNode->m_pNext )
	{
		ComplexListNode *pNew = malloc(sizeof(ComplexListNode));
		pNew->m_nValue = pNode->m_nValue;
		pNew->m_pNext = pNode->m_pNext;
		pNew->m_pSibling = NULL;
	}	
}


 int main()
 {
	ComplexListNode a;
	a.m_nValue = 1;
	ComplexListNode b;
	b.m_nValue = 2;
	ComplexListNode c;
	c.m_nValue = 3;	
	
	a.m_pNext = &b;
	b.m_pNext = &c;
	c.m_pNext = NULL;
	
	ComplexListNode *p = Clone(&a);
	while(NULL != p)
	{
		printf("%d   ",p->m_nValue);
		p = p->m_pNext;
	}	
 }
