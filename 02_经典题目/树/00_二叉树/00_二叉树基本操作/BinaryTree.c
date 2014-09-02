 /**************************************************************************
 * @file     BinaryTree.c
 * @brief    ��������������Դ�ļ� 
 * @version  V1.00
 * @date     2013.12.25
 * @note     ������ǰ�����򣬺������
****************************************************************************/
#include "BinaryTree.h"
#include "stdio.h"
#include "malloc.h"

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
	//������룬������һ���ո���߻س�
	//���%cǰ���ӿո�һ�������룬��ʱÿ���ַ�����һ���ڵ�
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
 * @brief   ʹ�����������������
 * @param[in]   T	���ڵ�ָ��
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
/** 
 * @brief   ʹ�����������������
 * @param[in]   T	���ڵ�ָ��
 * @retval  None��
 * @see     TreeNode;
 * @note   ���������������
 */
void Inorder_Traversal(TreeNode *T)
{
    ElementType data;
    if(T!=NULL)
    {
        Inorder_Traversal(T->leftchild);
		data=T->data;
        printf("%c ",data);
        Inorder_Traversal(T->rightchild);
    }
}/** 
 * @brief   ʹ�ú��������������
 * @param[in]   T	���ڵ�ָ��
 * @retval  None��
 * @see     TreeNode;
 * @note    ���������������
 */
void Postorder_Traversal(TreeNode *T)
{
    ElementType data;
    if(T!=NULL)
    {
        Postorder_Traversal(T->leftchild);
        Postorder_Traversal(T->rightchild);
		data=T->data;
        printf("%c ",data);
    }
}
 
int main()
{
	TreeNode* T;
	T = Create_Binarytree();
    printf("ǰ�����Ϊ��");
	Preorder_Traversal(T);
	printf("\n�������Ϊ��");
	Inorder_Traversal(T);
	printf("\n�������Ϊ��");
	Postorder_Traversal(T);
	printf("\n");
}
