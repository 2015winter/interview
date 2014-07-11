/****************************************************************************
 * @file     04_�ϲ���������.c
 * @brief    ����2�����������ϲ�֮������������������
 * @version  V1.00
 * @date     2014.7.10
 * @note     ʱ�临�Ӷ�:���O(m��n�е���Сֵ)�:O(m+n) �ռ临�Ӷ�O(1)
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
 * @brief     �ϲ���������
 * @param[in] head1_ptr����һ���������ָ��
 * @param[in] head2_ptr���ڶ����������ָ��
 * @retval    ��ת���������ָ��
 * @see       Node
 * @note      ��������������Ϊͬһ��ָ���ʱ�򣬵�һ���ڵ�ָ���Լ�����ѭ������
 */
Node_ptr ListMerge_Recursion(Node_ptr head1_ptr, Node_ptr head2_ptr)
{
	if(head1_ptr == NULL)
		return head2_ptr;
	else if(head2_ptr == NULL)
		return head1_ptr;
	Node_ptr head_ptr;
	if(head1_ptr->data <= head2_ptr->data)
	{
		head_ptr = head1_ptr;
		head_ptr->next = ListMerge_Recursion(head1_ptr->next,head2_ptr);
	}
	else
	{
		head_ptr = head2_ptr;
		head_ptr->next = ListMerge_Recursion(head1_ptr,head2_ptr->next);
	}
	return head_ptr;
}



/** 
 * @brief     �ϲ�������������
 * @param[in] head1_ptr����һ���������ָ��
 * @param[in] head2_ptr���ڶ����������ָ��
 * @retval    ��ת���������ָ��
 * @see       Node
 * @note      ��������������Ϊͬһ��ָ���ʱ�򣬵�һ���ڵ�ָ���Լ�����ѭ������
 */
Node_ptr ListMerge(Node_ptr head1_ptr, Node_ptr head2_ptr)
{
	Node_ptr head1 = head1_ptr;
	Node_ptr head2 = head2_ptr;
	Node_ptr ptr,head;

	if(head1->data < head2->data)
	{
		ptr = head1;
		head1 = head1->next;
	}
	else
	{
		ptr = head2;
		head2 = head2->next;
	}
	head = ptr;
	
	while(NULL != head1 && NULL != head2)
	{
		if(head1->data < head2->data)
		{
			ptr->next = head1;
			ptr = ptr->next;
			head1 = head1->next;
		}
		else
		{
			ptr->next = head2;
			ptr = ptr->next;
			head2 = head2->next;
		}
	}
	if(!head1)
	{
		ptr->next = head2;
	}
	else if(!head2)
	{
		ptr->next = head1;
	}
	return head;
}
int main()
{	
	Node_ptr ptr1 = List_User_Init();
	Node_ptr ptr2 = List_User_Init();

	Node_ptr ptr = ListMerge(ptr1,ptr2);
	List_Traversal(ptr);
	return 0;
}