/****************************************************************************
 * @file     list.c
 * @brief    �����������Դ�ļ�
 * @version  V1.00
 * @date     2013.12.30
 * @note     ��
****************************************************************************/
#include "list.h" 

/** 
 * @brief     ����������
 * @param[in] ��
 * @retval    Node *  ���ش����������ָ�롣
 * @see       Node
 * @note      ��
 */
Node * List_Init()
{
	Node *head_ptr;
	if(head_ptr == NULL)
		exit(0);
	if(NULL  == (head_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}
	head_ptr->next = NULL;
	return head_ptr;
}

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
 * @brief     ɾ����������
 * @param[in] head_ptr   �������ָ��
 * @retval    None
 * @see       Node
 * @note      ��
 */
void List_Delete(Node * head_ptr)
{
	if(head_ptr == NULL)
		return ;
	Node * node_ptr = head_ptr,*next_ptr;
	while(node_ptr != NULL)
	{
		next_ptr = node_ptr->next;
		free(node_ptr);
		node_ptr = next_ptr;
	}
}

/** 
 * @brief     ���������������ݡ�
 * @param[in] head_ptr   �������ָ��
 * @param[in] data       ��Ҫ���������
 * @retval    None
 * @see       Node
 * @note      ��
 */
void List_Insert(Node * head_ptr,ElementType data)
{
	if(head_ptr == NULL)
		return ;
	Node * node_ptr = head_ptr,*new_ptr;	
	while(node_ptr->next != NULL)
	{
		node_ptr = node_ptr->next;
	}
	if(NULL  == (new_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}	
	new_ptr->data = data;
	new_ptr->next = NULL;
	node_ptr->next = new_ptr;
}

/** 
 * @brief     ����ָ��λ�ò���,�ڵ�n���ڵ�֮����롣
 * @param[in] head_ptr   �������ָ��
 * @param[in] n          ��Ҫ�������ݵ�λ��
 * @param[in] data       ��Ҫ���������
 * @retval    None
 * @see       Node
 * @note      ��
 */
void List_Insertn(Node * head_ptr,int n,ElementType data)
{
	if(head_ptr == NULL)
		return ;
	Node * node_ptr = head_ptr,*new_ptr;	
	while(n--)
	{
		node_ptr = node_ptr->next;
	}
	if(NULL  == (new_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}	
	new_ptr->data = data;
	new_ptr->next = node_ptr->next;;
	node_ptr->next = new_ptr;
}



/** 
 * @brief     ɾ���������һ���ڵ㡣
 * @param[in] head_ptr   �������ָ��
 * @retval    None
 * @see       Node
 * @note      ��
 */
void List_DeleteNode(Node * head_ptr)
{
	if(head_ptr == NULL)
		return ;
	else if(head_ptr->next == NULL)
			head_ptr = NULL;
	Node * node_ptr = head_ptr;	
	while(node_ptr->next->next != NULL)
	{
		node_ptr = node_ptr->next;
	}
	free(node_ptr->next);
	node_ptr->next = NULL;
}

/** 
 * @brief     ɾ��ָ��λ�õĽڵ㡣
 * @param[in] head_ptr   �������ָ��
 * @param[in] n          ��Ҫɾ�������λ��
 * @retval    None
 * @see       Node
 * @note      ��
 */
void List_DeleteNthNode(Node * head_ptr,int n)
{
	if(head_ptr == NULL || n < 0)
		return ;
	Node * node_ptr = head_ptr,*del_ptr;	
	while(n-- > 1)
	{
		node_ptr = node_ptr->next;
	}
	del_ptr = node_ptr->next;
	node_ptr->next = del_ptr->next;
	free(del_ptr);
}

/** 
 * @brief     ɾ�����������������������Ľڵ�Ļ���������
 * @param[in] head  ָ��ͷ�ڵ��ָ��
 * @param[in] rm    �Զ���ڵ��Ƿ�ɾ���ĺ���ָ��
 * @retval    None
 * @see       Node
 * @note      ��
 */
Node * remove_if_basic(Node * head, remove_fn rm)
{
	for(Node *prev = NULL, *curr = head ;curr != NULL; )
	{
		Node *next = curr->next;
		if (rm(curr))
		{
			if(prev)
				prev->next = next;    //ɾ���Ĳ���ͷ��� 
			else	
				head =  next;        //ɾ������ͷ���
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
	return head;
}

/** 
 * @brief     Linus��˵��ɾ�����������������������Ľڵ�ķ�����
 * @param[in] head  ָ��ͷ�ڵ�Ķ���ָ��
 * @param[in] rm    �Զ���ڵ��Ƿ�ɾ���ĺ���ָ��
 * @retval    None
 * @see       node
 * @note      ����ڻ�����������Ҫά��ָ��ǰһ���ڵ��prevָ���ˣ�
			  Ҳ����Ҫ��ȥ�ж��Ƿ�Ϊ����ͷ��
 */
void remove_if(node ** head, remove_fn rm)
{
    for (node** curr = head; *curr; )
    {
        node * entry = *curr;
        if (rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}
/**		���жϺ��� \n  
 *     
 *		�жϽڵ�������Ƿ��4��ȣ���ȷ���1�����򷵻�0��    
 */ 
bool fun1(Node const * node_ptr)
{
	if(node_ptr->data == 4)
		return true;
	else
		return false;
}
/**		���жϺ��� \n  
 *     
 *		�жϽڵ�������Ƿ��3��ȣ���ȷ���1�����򷵻�0��    
 */ 
bool fun2(Node const * node_ptr)
{
	if(node_ptr->data == 3)
		return true;
	else
		return false;
}

int main()
{
	Node * head_ptr;	
	head_ptr = List_User_Init();
	List_Traversal(head_ptr);
	List_Insert(head_ptr,7);
	List_Insertn(head_ptr,2,7);
	List_Traversal(head_ptr);
	
	List_DeleteNode(head_ptr);
	List_DeleteNthNode(head_ptr,3);
	List_Traversal(head_ptr);
	
	head_ptr = remove_if_basic(head_ptr,fun1);
	remove_if(&head_ptr,fun2);
	
	List_Traversal(head_ptr);
	List_Delete(head_ptr);
}


