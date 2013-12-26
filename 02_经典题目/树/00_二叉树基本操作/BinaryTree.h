/****************************************************************************
 * @file     BinaryTree.h.h
 * @brief    ��������������ͷ�ļ� 
 * @version  V1.00
 * @date     2013.12.25
 * @note     
****************************************************************************/


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


TreeNode* Create_Binarytree();
void Preorder_Traversal(TreeNode *T);
