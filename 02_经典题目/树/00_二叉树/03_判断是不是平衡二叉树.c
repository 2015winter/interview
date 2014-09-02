/****************************************************************************
* @file     02_�����������.c
* @brief    ������������ 
* @version  V1.00
* @date     2013.12.25
* @note     
****************************************************************************/
#include "stdio.h"
#include "malloc.h"

/**		�ڵ���������  
*     
*		����ڵ��������͡�    
*/
typedef char ElementType;

/**		���ڵ�ṹ�嶨��  
*     
*		�������ڵ��������ĳ�Ա������    
*/ 
typedef struct treenode
{
	int data;					/**< �ڵ����� */  
	struct treenode* leftchild;		/**< ���ӽڵ�ָ�� */  
	struct treenode* rightchild;		/**< �Һ��ӽڵ�ָ�� */  
} TreeNode, *TreeNode_ptr;

/** 
* @brief   ʹ���������������������
* @param   None
* @retval  TreeNode* ���������ڵ㡣
* @see     TreeNode;
* @note    scanf���������⣺scanf�����س���������Ҫһ��һ���������ַ�ʱ��
			������%cǰ��Ӹ��ո�
*/
TreeNode* Create_Binarytree()
{
	ElementType ch;
	TreeNode* T;
	scanf(" %c",&ch);    //��������scanfʱ�����Ľ��һ��ȫ�����룬���Ҫһ��һ�������룬��%cǰ�Ӹ��ո�
	if(ch != '#')
	{
		if(NULL == (T = (TreeNode*)malloc(sizeof(TreeNode))))
		{
			perror("error...");
			exit(1);
		}
		T->data = ch;
		T->leftchild = Create_Binarytree();
		T->rightchild = Create_Binarytree();
	}
	else
	{
		T = NULL;
	}
	return T;
}

/** 
* @brief   ����������������ȡ�
* @param   T������������ĸ��ڵ�
* @retval  ����������ȡ�
* @see     TreeNode_ptr;
* @note    �ݹ����
*/
int BinaryTreeDepth(TreeNode_ptr T)
{
	if(NULL == T)
		return 0;
	int leftdepth, rightdepth;
	leftdepth = BinaryTreeDepth(T->leftchild);
	rightdepth = BinaryTreeDepth(T->rightchild);
	return (leftdepth > rightdepth) ? leftdepth+1 : rightdepth+1;
}

int main()
{
	TreeNode_ptr root= Create_Binarytree();
	printf("BinaryTreeDepth = %d\r\n", BinaryTreeDepth(root));
}