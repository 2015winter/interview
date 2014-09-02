/****************************************************************************
 * @file     06_��������ĵ�һ�������ڵ�.c
 * @brief    ����2������ �����������ĵ�һ�������ڵ�
 * @version  V1.00
 * @date     2014.9.2
 * @note     ʱ�临�Ӷ�:���O()�:O() �ռ临�Ӷ�O()
 * @note     
 ****************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <math.h>

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
 * @brief     ���������������������������ĵ�һ�������ڵ��ֵ��
 * @param[in] head1_ptr   ����1����ָ��
 * @param[in] head2_ptr   ����2����ָ��
 * @retval    �����ڵ�
 * @see       Node
 * @note      ��
 */
Node_ptr CommonNode(Node_ptr head1_ptr, Node_ptr head2_ptr)
{
	if(NULL == head1_ptr || NULL == head2_ptr)
	{
		printf("�����������\r\n");
		return NULL;
	}
	Node_ptr node_ptr = head1_ptr, Node1_ptr, Node2_ptr;
	int i,head1_len = 0, head2_len = 0, difference;
	//������������ĳ���
	while(node_ptr != NULL)
	{
		head1_len++;
		node_ptr = node_ptr->next;
	}
	node_ptr = head2_ptr;
	while(node_ptr != NULL)
	{
		head2_len++;
		node_ptr = node_ptr->next;
	}
	//���㳤��֮�������������difference��
	difference = head1_len - head2_len;
	Node1_ptr = head1_ptr;
	Node2_ptr = head2_ptr;
	if(difference > 0)
	{
		//head1��head2������Ҫ����difference��
		for(i = 0; i < abs(difference); i++){ Node1_ptr = Node1_ptr->next; }
	}
	else
	{
		for(i = 0; i < abs(difference); i++){ Node2_ptr = Node2_ptr->next; }
	}
	while(NULL != Node1_ptr && NULL != Node2_ptr && Node1_ptr->data != Node2_ptr->data)
	{
		Node1_ptr = Node1_ptr->next;
		Node2_ptr = Node2_ptr->next;
	}
	if(NULL == Node1_ptr || NULL == Node2_ptr)
	{
		printf("δ�ҵ������ڵ�\r\n");
		return NULL;
	}
	else
		return Node1_ptr;
}


int main()
{	
	Node a,b,c,d,e,x,y,z;
	a.data = 0;b.data = 1;c.data = 2;d.data = 3;e.data = 4;
	a.next = &b;b.next = &c;c.next = &d;d.next = &e;e.next = NULL;
	
	x.data = 0;y.data = 5;z.data = 0;
	x.next = &y;y.next = &z;
	
	z.next = &c;  	//������ͬ�ڵ�
	//z.next = NULL;//��������ͬ�ڵ�
	List_Traversal(&a);
	List_Traversal(&x);
	printf("\r\n�����ڵ��data = %d\r\n",CommonNode(&a, &x)->data);
	return 0;
}