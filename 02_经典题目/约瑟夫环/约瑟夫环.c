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
 * @brief     ����ѭ������
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
	Tail_ptr->next = Head_ptr;
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
 * @brief     Լɪ�򻷣�����m�Ľڵ㱻ɾ����ֱ�����ڵ㡣
 * @param[in] head_ptr   �������ָ��
 * @retval    ���ʣ�µĽڵ��ָ��
 * @see       head_ptr
 * @note      ģ��������
 */
Node_ptr Josephus(Node_ptr head_ptr, int m)
{
	if(head_ptr == NULL)
		return NULL;
	Node_ptr p = head_ptr;
	int count = 1;
	while(p->next != p)
	{
		p = p->next;
		count++;
		if(count == m)
		{
			Node_ptr temp = p->next;
			p->data = p->next->data;
			p->next = p->next->next;
			free(temp);
			temp = NULL;
			count = 1;
		}		
	}
	return p;
}


/** 
 * @brief     Լɪ�򻷣�����m�Ľڵ㱻ɾ����ֱ�����ڵ㡣
 * @param[in] head_ptr   �������ָ��
 * @retval    ���ʣ�µ���
 * @see       head_ptr
 * @note      �ݹ鷨 http://www.tuicool.com/articles/ZrQ3U3
 *            Josephus(n,m) = (Joseph(n-1,m)+m) % n ��n>1��
 */
int Josephus_Recursion(int n, int m)
{
	if(n == 1)
		return 0;
	return (Josephus_Recursion(n-1, m) + m) % n;
}
/** 
 * @brief     Լɪ�򻷣�����m�Ľڵ㱻ɾ����ֱ�����ڵ㡣
 * @param[in] head_ptr   �������ָ��
 * @retval    ���ʣ�µ���
 * @see       head_ptr
 * @note      ����
 */
int Josephus_Iteration(int n, int m)
{
	int Josephus_last = 0, Josephus_now = 0, i = 0;
	for(i = 2; i <= n; i++)
	{
		Josephus_now = (Josephus_last + m) % i;
		Josephus_last = Josephus_now;
	}
	return Josephus_now;
}
int main()
{
	// Node * head = List_User_Init();
	// int m;
	// printf("������m������m�Ľڵ㱻ɾ������");
	// scanf("%d",&m);
	// head = Josephus(head,m);
	// printf("ʣ�µĽڵ�Ϊ��%d\n", head->data);
	int n =  9,m = 3;
	printf("n = %d, m = %d,ʣ�µĽڵ�Ϊ��%d\n", n, m, Josephus_Recursion(n, m));
	printf("n = %d, m = %d,ʣ�µĽڵ�Ϊ��%d\n", n, m, Josephus_Iteration(n, m));
}
