/****************************************************************************
* @file     03_�ж��ǲ���ƽ�������.c
* @brief    �ж��ǲ���ƽ�������
* @version  V1.00
* @date     2014.9.2
* @note     ����һ���������ĸ��ڵ㣬�жϸ����ǲ���ƽ������������ĳ��������
			����ڵ���������������������1����ô������һ��ƽ���������
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
	scanf(" %c",&ch);
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

/** 
* @brief   �ж��ǲ���ƽ���������
* @param   T������������ĸ��ڵ�
* @retval  0������  1���ǡ�
* @see     TreeNode_ptr;
* @note    �ݹ���ã�ȱ���ǽڵ�ᱻ�ظ��������
*/
int IsBalancedBinary1(TreeNode_ptr T)
{
	if(NULL == T)
		return 1;
	int leftdepth, rightdepth, difference;
	leftdepth = IsBalancedBinary1(T->leftchild);
	rightdepth = IsBalancedBinary1(T->rightchild);
	difference = leftdepth - rightdepth;
	if(difference > 1 || difference < -1)
		return 0;
	
	return IsBalancedBinary1(T->leftchild) && IsBalancedBinary1(T->rightchild);
}

/** 
* @brief   �ж��ǲ���ƽ���������
* @param   T������������ĸ��ڵ�
* @retval  0������  1���ǡ�
* @see     TreeNode_ptr;
* @note    �ݹ���ã������ظ�����
*/
int IsBalancedBinary2(TreeNode_ptr T, int *depth)
{
	if(NULL == T)
	{
		*depth = 0;
		return 1;
	}
	int leftdepth, rightdepth,difference;
	if(IsBalancedBinary2(T->leftchild, &leftdepth) && IsBalancedBinary2(T->rightchild, &rightdepth))
	{
		difference = leftdepth - rightdepth;
		if(difference <= 1 && difference >= -1)
		{
			*depth = (leftdepth > rightdepth) ? leftdepth+1 : rightdepth+1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	TreeNode_ptr root= Create_Binarytree();
	int depth  =0;
	if(IsBalancedBinary2(root, &depth))
	{
		printf("Balanced");
	}
	else
	{
		printf("Not Balanced");		
	}
}