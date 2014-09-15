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
 * @brief     ����m_pNext�ĸ��ơ�
 * @param[in] pHead:��Ҫ���Ƶ�����ͷ
 * @retval    0:�ɹ�
 * @see       ComplexListNode
 * @note      ��
 */
int Clone(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	
	while(NULL != pNode)
	{
		ComplexListNode *pNew = malloc(sizeof(ComplexListNode));
		pNew->m_nValue = pNode->m_nValue;
		pNew->m_pNext = pNode->m_pNext;
		pNew->m_pSibling = NULL;
		
		pNode->m_pNext = pNew;
		pNode = pNew->m_pNext;
	}	
	return 0;
}

/** 
 * @brief     ����m_pSibling�ĸ��ơ�
 * @param[in] pHead:��Ҫ���Ƶ�����ͷ
 * @retval    0:�ɹ�
 * @see       ComplexListNode
 * @note      ��
 */
int CloneSibling(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	
	while(NULL != pNode)
	{
		pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pNode->m_pNext->m_pNext;
	}	
	return 0;
}

/** 
 * @brief     ����Ĳ�֡�
 * @param[in] pHead:��Ҫ���Ƶ�����ͷ
 * @retval    ComplexListNode*  ���ظ����������ָ�롣
 * @see       ComplexListNode
 * @note      �������е�����ż���ڵ���
 */
ComplexListNode_ptr ReConnect(ComplexListNode *pHead)
{
	ComplexListNode_ptr pNode = pHead;
	ComplexListNode_ptr pCopyHead, pCopyNode;
	
	if(NULL != pNode)
	{
		pCopyHead = pCopyNode = pNode->m_pNext;
		pNode->m_pNext = pCopyNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while(NULL != pNode)
	{
		pCopyNode->m_pNext = pNode->m_pNext;
		pCopyNode = pCopyNode->m_pNext;
		
		pNode->m_pNext = pCopyNode->m_pNext;
		pNode = pNode->m_pNext;
	}	
	return pCopyHead;
}

 int main()
 {
	ComplexListNode a;
	a.m_nValue = 1;
	ComplexListNode b;
	b.m_nValue = 2;
	ComplexListNode c;
	c.m_nValue = 3;	
	ComplexListNode d;
	d.m_nValue = 4;	
	ComplexListNode e;
	e.m_nValue = 5;	
	ComplexListNode f;
	f.m_nValue = 6;	
	
	a.m_pNext = &b;
	b.m_pNext = &c;
	c.m_pNext = &d;
	d.m_pNext = &e;
	e.m_pNext = &f;
	f.m_pNext = NULL;
	
	a.m_pSibling = &f;
	b.m_pSibling = &d;
	c.m_pSibling = &e;
	d.m_pSibling = &c;
	e.m_pSibling = &b;
	f.m_pSibling = &a;
	
	ComplexListNode_ptr pHead;
	Clone(&a);
	CloneSibling(&a);
	pHead = ReConnect(&a);
	ComplexListNode_ptr p = &a;
	
	while(NULL != p)
	{
		printf("%d->%d | ",p->m_nValue, p->m_pSibling->m_nValue);
		p = p->m_pNext;
	}	
	printf("\r\n");
	
	while(NULL != pHead)
	{
		printf("%d->%d | ",pHead->m_nValue, pHead->m_pSibling->m_nValue);
		pHead = pHead->m_pNext;
	}	
 }
