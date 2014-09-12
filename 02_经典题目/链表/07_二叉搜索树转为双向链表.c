 /**************************************************************************
 * @file     07_����������תΪ˫������.c
 * @brief    ����������תΪ˫������ 
 * @version  V1.00
 * @date     2014.9.11
 * @note     
****************************************************************************/
#include "stdio.h"
#include "malloc.h"

/**		�ڵ���������  
 *     
 *		����ڵ��������͡�    
 */
typedef int ElementType;


/**		���ڵ�ṹ�嶨��  
 *     
 *		�������ڵ��������ĳ�Ա������    
 */ 
typedef struct treenode
{
	ElementType data;					/**< �ڵ����� */  
	struct treenode* leftchild;		/**< ���ӽڵ�ָ�� */  
	struct treenode* rightchild;		/**< �Һ��ӽڵ�ָ�� */  
} TreeNode, *TreeNode_ptr;


/** 
* @brief   �����ڵ㡣
* @param[in]   data   �ڵ��data
* @retval  None��
* @see     TreeNode;
* @note    
*/
TreeNode_ptr CreateNode(ElementType data)
{
	TreeNode_ptr node_ptr;
	if(NULL == (node_ptr = (TreeNode_ptr)malloc(sizeof(TreeNode))))
	{
		printf("����ռ����!\r\n");
	}
	node_ptr->data = data;
	node_ptr->leftchild = NULL;
	node_ptr->rightchild = NULL;
	return node_ptr;
}

/** 
* @brief   ���ڵ�������ӡ�
* @param[in]   root         ���ڵ�root
* @param[in]   leftchild    �ڵ��leftchild
* @param[in]   rightchild   �ڵ��rightchild
* @retval  None��
* @see     TreeNode;
* @note    
*/
void ConnectNodes(TreeNode_ptr root, TreeNode_ptr leftchild, TreeNode_ptr rightchild)
{
	if(NULL == root)
	printf("��������!\r\n");
	root->leftchild = leftchild;
	root->rightchild = rightchild;
} 

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
    scanf(" %d",&ch);    
    if(ch != -1)
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
        printf("%d ",data);
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
 
 
void Convent(TreeNode_ptr Root, TreeNode_ptr* LastNode)
{
	if(NULL == Root)
		return;
	TreeNode_ptr PCurrent = Root;
	if(NULL != PCurrent->leftchild)
	{
		Convent(PCurrent->leftchild, LastNode);
	}
	PCurrent->leftchild = *LastNode;
	if(NULL != (*LastNode))
		(*LastNode)->rightchild = PCurrent;
	*LastNode = PCurrent;
	if(NULL != PCurrent->rightchild)
	{
		Convent(PCurrent->rightchild, LastNode);
	}
}

TreeNode_ptr ConventToDList(TreeNode_ptr Root)
{
	TreeNode_ptr LastNode = NULL;
	Convent(Root, &LastNode);
	if(NULL != LastNode)
	{
		while( NULL != LastNode->leftchild)
		{
			LastNode = LastNode->leftchild;
		}	
	}
	return LastNode;
}

int main()
{
	//TreeNode_ptr T;
	//T = Create_Binarytree();
	TreeNode_ptr TreeNode_ptr4 = CreateNode(4);
	TreeNode_ptr TreeNode_ptr2 = CreateNode(2);
	TreeNode_ptr TreeNode_ptr3 = CreateNode(3);
	TreeNode_ptr TreeNode_ptr1 = CreateNode(1);
	TreeNode_ptr TreeNode_ptr6 = CreateNode(6);
	TreeNode_ptr TreeNode_ptr5 = CreateNode(5);
	TreeNode_ptr TreeNode_ptr7 = CreateNode(7);
	
	ConnectNodes(TreeNode_ptr4, TreeNode_ptr2, TreeNode_ptr6);
	ConnectNodes(TreeNode_ptr2, TreeNode_ptr1, TreeNode_ptr3);
	ConnectNodes(TreeNode_ptr6, TreeNode_ptr5, TreeNode_ptr7);
	
	printf("\n�������Ϊ��");
	Inorder_Traversal(TreeNode_ptr4);

	printf("\nת��Ϊ˫������");
	TreeNode_ptr Head = ConventToDList(TreeNode_ptr4);
	while(NULL != Head)
	{
		printf("%d    ",Head->data);
		Head = Head->rightchild;
	}

	printf("\n");
}
