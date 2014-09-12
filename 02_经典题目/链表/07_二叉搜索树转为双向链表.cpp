#include<iostream>
#include<stdlib.h>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//�������������
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode=new BinaryTreeNode();
    pNode->m_nValue=value;
    pNode->m_pLeft=NULL;
    pNode->m_pRight=NULL;
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,BinaryTreeNode* pRight)
{
    if(pParent!=NULL)
    {
        pParent->m_pLeft=pLeft;
        pParent->m_pRight=pRight;
    }
}

void InOrderPrintTree(BinaryTreeNode* pRoot)//�������
{
    if(pRoot!=NULL)
    {
        if(pRoot->m_pLeft!=NULL)//
            InOrderPrintTree(pRoot->m_pLeft);

        cout<<"value of this node is "<<pRoot->m_nValue<<endl;

        if(pRoot->m_pRight!=NULL)
            InOrderPrintTree(pRoot->m_pRight);
    }
    else
    {
        cout<<"this node is null."<<endl;
    }

}

void Convert(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
    if(pNode==NULL)
        return;

    BinaryTreeNode* pCurrent=pNode;
    //������ת������������������Ҷ�ӽ��
    if(pCurrent->m_pLeft!=NULL)//����������
        Convert(pCurrent->m_pLeft,pLastNodeInList);

    pCurrent->m_pLeft=*pLastNodeInList;
    if((*pLastNodeInList)!=NULL)
        (*pLastNodeInList)->m_pRight=pCurrent;

    *pLastNodeInList=pCurrent;
    //������ת��
    if(pCurrent->m_pRight!=NULL)//����������
        Convert(pCurrent->m_pRight,pLastNodeInList);

}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
    BinaryTreeNode* pLastNodeInList=NULL;//ָ��˫�������β���
    Convert(pRoot,&pLastNodeInList);//ת�����������Ϊ˫������

    //��˫�������ͷ���
    BinaryTreeNode* pHeadOfList=pLastNodeInList;
    while(pHeadOfList!=NULL&&pHeadOfList->m_pLeft!=NULL)
        pHeadOfList=pHeadOfList->m_pLeft;
    return pHeadOfList;

}

//���˫������
void PrintList(BinaryTreeNode* pRoot)
{
    BinaryTreeNode* pNode = pRoot;
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pRight;
    }
    printf("\nPrintList ends.\n");
}

int main()
{
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
    //���������
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);
    //���������
    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    //PrintTree(pNode10);
    InOrderPrintTree(pNode10);//�������
    BinaryTreeNode* pHeadOfList=Convert(pNode10);//��ȡ˫������ͷ���
    PrintList(pHeadOfList);//�������
}

