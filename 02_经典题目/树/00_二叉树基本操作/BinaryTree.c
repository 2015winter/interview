 /**************************************************************************
 * @file     BinaryTree.c
 * @brief    ��������������Դ�ļ� 
 * @version  V1.00
 * @date     2013.12.25
 * @note     
****************************************************************************/
#include "BinaryTree.h"
#include "stdio.h"
#include "malloc.h"

/** 
 * @brief   ʹ���������������������
 * @param   None
 * @retval  TreeNode* ���������ڵ㡣
 * @see     TreeNode;
 * @note    scanf���������⣺scanf�����س���������Ҫһ��һ���������ַ�ʱ��������%cǰ��Ӹ��ո�
 */
TreeNode* Create_Binarytree()
{
    ElementType ch;
    TreeNode* T;
    // scanf(" %c",&ch);    //��������scanfʱ�����Ľ��һ��ȫ�����룬���Ҫһ��һ�������룬��%cǰ�Ӹ��ո�
	ch  = getchar();
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
 * @brief   ʹ�����������������
 * @param   T	���ڵ�ָ��
 * @retval  None��
 * @see     TreeNode;
 * @note    ���������������
 */
void Preorder_Traversal(TreeNode *T)
{
    ElementType data;
    if(T!=NULL)
    {
        data=T->data;
        printf("%c ",data);
        Preorder_Traversal(T->leftchild);
        Preorder_Traversal(T->rightchild);
    }
}


int main()
{
	TreeNode* T;
	T = Create_Binarytree();
	Preorder_Traversal(T);
}
