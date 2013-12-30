/****************************************************************************
 * @file     01_ɾ��������ڵ�.c
 * @brief    ɾ���������з��������Ľڵ� 
 * @version  V1.00
 * @date     2013.12.30
 * @note     ��
****************************************************************************/
#include <stdio.h>
#include <malloc.h>


/**		����ṹ�嶨�� \n  
 *     
 *		��������ڵ��������ĳ�Ա����������ָ����һ���ڵ��ָ��͵�ǰ�ڵ��ֵ��    
 */ 
typedef struct node 
{
	struct node * next;
	int node_val;
} node;

/**		�жϽڵ��Ƿ���Ҫɾ���ĺ���ָ�� \n  
 *     
 *		�Զ����жϽڵ��Ƿ���Ҫɾ���ĺ���ָ�롣    
 */ 
typedef bool (* remove_fn)(node const * v);

//
/** 
 * @brief     Linus��˵��ɾ�����������������������Ľڵ�ķ�����
 * @param[in] head  ָ��ͷ�ڵ�Ķ���ָ��
 * @param[in] rm    �Զ���ڵ��Ƿ�ɾ���ĺ���ָ��
 * @retval    None
 * @see       node
 * @note      ����ڻ�����������Ҫά��ָ��ǰһ���ڵ��prevָ���ˣ�
			  Ҳ����Ҫ��ȥ�ж��Ƿ�Ϊ����ͷ��
 */
void remove_if(node ** head, remove_fn rm)
{
    for (node** curr = head; *curr; )
    {
        node * entry = *curr;
        if (rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}

/** 
 * @brief     ɾ�����������������������Ľڵ�Ļ���������
 * @param[in] head  ָ��ͷ�ڵ��ָ��
 * @param[in] rm    �Զ���ڵ��Ƿ�ɾ���ĺ���ָ��
 * @retval    None
 * @see       node
 * @note      ��
 */
node * remove_if_basic(node * head, remove_fn rm)
{
	for(node *prev = NULL, *curr = head ;curr != NULL; )
	{
		node *next = curr->next;
		if (rm(curr))
		{
			if(prev)
				prev-next = next;    //ɾ���Ĳ���ͷ��� 
			else	
				head =  next;        //ɾ������ͷ���
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
	return head;
}

int main()
{	
	
}