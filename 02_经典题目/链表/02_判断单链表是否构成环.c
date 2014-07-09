/****************************************************************************
 * @file     02_�жϵ������Ƿ񹹳ɻ�.c
 * @brief    �жϵ������Ƿ��л� 
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
 * @brief     �ж������Ƿ��л�
 * @param[in] head_ptr   �������ָ��
 * @retval    1�������γɻ� 0��δ�γɻ�
 * @see       Node
 * @note      ��
 */
int IsLoop(Node_ptr ptr)
{
	Node_ptr p1,p2;
	p1 = p2 = ptr;
	while(NULL != p1 && NULL != p1->next)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if(p1 == p2)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{	
	Node_ptr ptr = List_User_Init();
	List_Traversal(ptr);
	Node_ptr p = ptr,tail;;
	int i = 2;
	while(p->next)
	{
		p = p->next;
	}
	tail = p;
	p = ptr;
	while(i--)
	{
		p = p->next;
	}
	tail->next = p;
	if(1 == IsLoop(ptr))
	{	
		printf("�����γɻ�״�ṹ\r\n");
	}
	else
	{
		printf("����δ�γɻ�״�ṹ\r\n");
	}

}