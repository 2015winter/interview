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

int List_Init(Node *N);
Node* List_User_Init();
int List_Traversal(Node * head_ptr);
void List_Delete(Node *N);
void List_Insert(Node * head_ptr,ElementType data);
void List_Insertn(Node * head_ptr,int n,ElementType data);





