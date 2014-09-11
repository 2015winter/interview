/****************************************************************************
 * @file     03_��ת����.c
 * @brief    ��һ��������з�ת 
 * @version  V1.00
 * @date     2014.7.9
 * @note     һ��ָ���߿�һ����һ��ָ������һ��
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
typedef struct node 
{
	struct node * next;
	ElementType data;
} Node,*Node_ptr;

/** 
 * @brief     �������������Ԫ�ش�������
 * @param[in] ��
 * @retval    Node *  ���ش����������ָ�롣
 * @see       Node
 * @note      ��
 */
Node* List_User_Init()
{
	Node * Head_ptr,*Tail_ptr,*node_ptr;
	ElementType data; 
	int num,i;
	Tail_ptr = 	Head_ptr = NULL;
	printf("����������Ԫ����Ŀ��\n");
	scanf("%d",&num);
	printf("����������Ԫ�أ�\n");	
	for(i = 0; i < num; i++)
	{
		if(NULL  == (node_ptr = (Node *)malloc(sizeof(Node))))
		{
			perror("error...");
			exit(0);
		}
		scanf("%d",&node_ptr->data);
		node_ptr->next = NULL;
		if(i == 0)
		{
			Head_ptr = Tail_ptr	= node_ptr;
		}
		else
		{		
			Tail_ptr->next = node_ptr;
			Tail_ptr = node_ptr;
		}

	}
	return Head_ptr;
}
/** 
 * @brief     ���������
 * @param[in] head_ptr   �������ָ��
 * @retval    None
 * @see       Node
 * @note      ��
 */
void List_Traversal(Node * head_ptr)
{
	if(head_ptr == NULL)
		exit(0);
	Node * node_ptr = head_ptr;
	while(node_ptr != NULL)
	{
		printf("%d  ",node_ptr->data);
		node_ptr = node_ptr->next;
	}
	printf("\n");
}

/** 
 * @brief     ��ת����
 * @param[in] head_ptr   �������ָ��
 * @retval    ��ת���������ָ��
 * @see       Node
 * @note      ��
 */
Node_ptr ListReverse(Node_ptr phead)
{
	if(NULL == phead)
	{
		printf("ListReverse param error!\r\n");
		return NULL;
	}
	Node_ptr pnext,ptr,ppre;
	ppre = phead->next;
	phead->next = NULL;
	
	pnext = phead;
	ptr = ppre;
	while(NULL != ptr)
	{
		ppre = ptr->next;
		ptr->next = pnext;
		
		pnext = ptr;
		ptr = ppre;
	}
	return pnext;
}

int main()
{	
	Node_ptr ptr = List_User_Init();
	Node_ptr ptrrev;
	List_Traversal(ptr);
	if(NULL == (ptrrev = ListReverse1(ptr)))
	{
		printf("param error!\r\n");
		return 1;
	}	
	List_Traversal(ptrrev);
	return 0;
}