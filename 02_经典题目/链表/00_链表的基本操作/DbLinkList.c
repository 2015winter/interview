/****************************************************************************
 * @file     DbLinkList.c
 * @brief    ˫������Դ�ļ���
 * @version  V1.00
 * @date     2014.1.6
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>
typedef int ElementType;

typedef struct list_head {
	struct list_head *next, *prev;
	ElementType data;
}List_Head,*List_Head_ptr;

//����������ҳ�ʼ���ڵ��next��prevָ��ָ���Լ�
#define LIST_HEAD_INIT(name) { &(name), &(name)}
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
	
//���ڽ��Ѿ����ڵı����ĳ�Աָ��ָ���Լ�
void List_Head_Init(List_Head_ptr list)
{
	list->next = list;
	list->prev = list;
}
/** 
 * @brief     �����������Ľڵ��м����ڵ㡣
 * @param[in] list  ����ı�ͷ
 * @retval    None
 * @see       List_Head_ptr
 * @note      ֻ����ǰ��ڵ���֪������²����ڲ��ڵ�ʹ��
 */
void List_Head_Add(List_Head_ptr list)
{
	list->next = list;
	list->prev = list;
}


/** 
 * @brief     �ڱ�ͷ��������һ���ڵ㣬�ڲ�������
 * @param[in] new_ptr  ��Ҫ���ӵĽڵ�ָ�룬
 * @param[in] prev     ����λ�õ�ǰһ���ڵ�ָ��
 * @param[in] next     ����λ�õĺ�һ���ڵ�ָ��
 * @retval    None
 * @see       List_Head_ptr
 * @note      
 */
static inline void __list_add(List_Head_ptr new_ptr, List_Head_ptr prev, List_Head_ptr next)
{
	next->prev = new_ptr;
	new_ptr->next = next;
	new_ptr->prev = prev;
	prev->next = new_ptr;
}


/** 
 * @brief     �ڱ�ͷ��������һ���ڵ㡣
 * @param[in] new_ptr  ��Ҫ���ӵĽڵ�ָ�룬
 * @param[in] head     ����ͷָ��
 * @retval    None
 * @see       List_Head_ptr
 * @note      �ڱ�ͷ��������½ڵ㣬��������ʵ��ջ��
 */
void list_add(List_Head_ptr new_ptr, List_Head_ptr head)
{
	__list_add(new_ptr, head, head->next);
}


/** 
 * @brief     �ڱ�ͷǰ������һ���ڵ㡣
 * @param[in] new_ptr  ��Ҫ���ӵĽڵ�ָ�룬
 * @param[in] head     ����ͷָ��
 * @retval    None
 * @see       List_Head_ptr
 * @note      �������β����½ڵ㣬��������ʵ�ֶ��С�
 */
void list_add_tail(List_Head_ptr new_ptr, List_Head_ptr head)
{
	__list_add(new_ptr, head->prev, head);
}

/** 
 * @brief     ɾ�������ڵ�֮��Ľڵ㣬�ڲ�����
 * @param[in] prev     ɾ��λ�õ�ǰһ���ڵ�ָ��
 * @param[in] next     ɾ��λ�õĺ�һ���ڵ�ָ��
 * @retval    None
 * @see       List_Head_ptr
 * @note      ������ָ��λ��ɾ���ڵ㡣
 */
static inline void __list_del(List_Head_ptr prev, List_Head_ptr next)
{
	next->prev = prev;
	prev->next = next;
}

/** 
 * @brief     ɾ���ڵ㡣
 * @param[in] entry   ��Ҫɾ���Ľڵ�ָ��
 * @retval    None
 * @see       List_Head_ptr
 * @note      ������ָ��λ��ɾ���ڵ㡣
 */
static void list_del(List_Head_ptr entry)
{
	__list_del(entry->prev, entry->next);
	free(entry);
	entry = NULL;
}

/**   �ж������Ƿ�Ϊ�� \n
 *  
 *    ���ýڵ��nextָ��ָ���Լ���Ϊ������
 */
static inline int list_empty(const List_Head_ptr head)
{
	return head->next == head;
}

/** 
 * @brief     �������������ӡ�
 * @param[in] list   �¼��������
 * @param[in] head   �����ӵ�������Ϊ��ͷ
 * @retval    None
 * @see       List_Head_ptr
 * @note      list�ĵ�һ���ڵ���Ϊ�׽ڵ㣬head��β�ڵ���Ϊβ�ڵ㣬�ϲ���head��Ϊ��ͷ��
 *            �ο�http://www.ibm.com/developerworks/cn/linux/kernel/l-chain/
 */
static inline void __list_splice(List_Head_ptr list, List_Head_ptr head)
{
	struct list_head *first = list->next;
	struct list_head *last = list->prev;
	struct list_head *at = head->next;

	first->prev = head;
	head->next = first;

	last->next = at;
	at->prev = last;
}


/** 
 * @brief     �������������ӡ�
 * @param[in] list   �¼��������
 * @param[in] head   �����ӵ�������Ϊ��ͷ
 * @retval    None
 * @see       List_Head_ptr
 * @note      list�ĵ�һ���ڵ���Ϊ�׽ڵ㣬head��β�ڵ���Ϊβ�ڵ㣬�ϲ���head��Ϊ��ͷ��
 *            �ο�http://www.ibm.com/developerworks/cn/linux/kernel/l-chain/
 */
void list_splice(List_Head_ptr list, List_Head_ptr head)
{
	if (!list_empty(list))
		__list_splice(list, head);
}

#define __list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

/** 
 * @brief     ������������
 * @param[in] head     ��Ҫ�����������ͷ
 * @retval    None
 * @see       List_Head_ptr
 * @note      
 */
static void list_traversal(List_Head_ptr head)
{
	List_Head_ptr pos;
	__list_for_each(pos,head)
	{
		printf("%d   ",pos->data);
	}
}
	
int main()
{
	int num;
	LIST_HEAD(HEAD1);	
	LIST_HEAD(HEAD2);
	List_Head_ptr head1 = &HEAD1,head2 = &HEAD2, node_ptr;
	printf("����������1Ԫ����Ŀ��\n");
	scanf("%d",&num);
	printf("����������Ԫ�أ�\n");	
	for(int i = 0; i < num; i++)
	{
		if(NULL  == (node_ptr = (List_Head_ptr)malloc(sizeof(struct list_head))))
		{
			perror("error...");
			exit(0);
		}
		List_Head_Init(node_ptr);   //��ʼ����Աָ��
		scanf("%d",&node_ptr->data);//��ʼ��������
		list_add_tail(node_ptr,head1);
	}

	printf("����������2Ԫ����Ŀ��\n");
	scanf("%d",&num);
	printf("����������Ԫ�أ�\n");	
	for(int i = 0; i < num; i++)
	{
		if(NULL  == (node_ptr = (List_Head_ptr)malloc(sizeof(struct list_head))))
		{
			perror("error...");
			exit(0);
		}
		List_Head_Init(node_ptr);   //��ʼ����Աָ��
		scanf("%d",&node_ptr->data);//��ʼ��������
		list_add_tail(node_ptr,head2);
	}
	
	printf("������1���ӵ�����2��\n");
	list_splice(head1,head2);
	list_traversal(head2);
}
