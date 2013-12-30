/****************************************************************************
 * @file     list.h
 * @brief    �����������ͷ�ļ� 
 * @version  V1.00
 * @date     2013.12.30
 * @note     ��
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

/**		�жϽڵ��Ƿ���Ҫɾ���ĺ���ָ�� \n  
 *     
 *		�Զ����жϽڵ��Ƿ���Ҫɾ���ĺ���ָ�롣    
 */ 
typedef bool (* remove_fn)(node const * v);


Node * List_Init();
Node* List_User_Init();
void List_Traversal(Node * head_ptr);
void List_Delete(Node * head_ptr);
void List_Insert(Node * head_ptr,ElementType data);
void List_Insertn(Node * head_ptr,int n,ElementType data);
void List_DeleteNode(Node * head_ptr);
void List_DeleteNthNode(Node * head_ptr,int n);
Node * remove_if_basic(Node * head, remove_fn rm);
bool fun1(Node const * node_ptr);
