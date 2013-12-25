/**
 * @brief  ���ַ����в��ҵ�һ��ֻ����һ�ε��ַ�(Google������)��
 * @note   ��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������AbAssvfFCCBbhV�������v��
 * @method 1 ����ѭ������ O(n * n)
 * @method 2 ����HashTable
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int HashTable[52]={0};   // contains A-F and a-z character
/**
 * ����Hash��
 */
int Hash(char c) 
{
    if(isupper(c)) 
	{
		return c - 'A';
    }
    else if(islower(c)) 
	{
		return 26 + c - 'a';
    }
}
/** 
 * ���ַ�������Hash�� 
*/
void LoadHashTable(const char *str) 
{
    int i;
    int pos;   // the hash address 
    for(i = 0;i < strlen(str);i++) 
	{
		pos = Hash(str[i]); //�ҵ���Ӧ��λ��
		HashTable[pos] += 1;//���ڵļ�ֵ��1
    }
}
/**
 * ���ҵ�һ��ֻ����һ�ε��ַ�
 */
int Locate(const char *str, char &X) 
{
    int i;
    int pos;
    int val;
	int find = 0;   
    for(i = 0;i < strlen(str);i++) 
	{
		pos = Hash(str[i]);
		val = HashTable[pos];
		if(val == 1) 
		{
			switch(pos/26) 
			{
				case 0:
					X = 'A' + pos%26;
					break;
				case 1:
					X = 'a' + pos%26;
					break;
			}
			find = 1;
			return find; //���Ҫ�����һ������һ�ε��ַ����Ͱ����ȥ��
		}
    }
	return find;
}
int main() 
{
    char buf[1024];
    char c;
    int i;
	printf("�������ַ�����\n");
    gets(buf);
    for(i = 0;i < strlen(buf);i++) 
	{
		if(!isupper(buf[i]) && !islower(buf[i])) 
		{
			perror("�ַ���ֻ���԰�����Сд��ĸ!\n");
			exit(1);
		}
    }
    LoadHashTable(buf);
    if(Locate(buf, c)) 
	{
		printf("��һ��ֻ����һ�ε��ַ�Ϊ��");
		putchar(c);
	}
	else 
		perror("û�г���һ�ε���ĸ!");
    printf("\n");
	return 0;
}

