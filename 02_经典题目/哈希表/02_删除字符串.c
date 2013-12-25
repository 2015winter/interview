/**
 * @brief   �����ַ���A��B����A���޳�������B�е��ַ���
 * @note   ����A=��hello world��,B="er"����ô�޳�֮��A��Ϊ"hllowold"���ռ临�Ӷ�Ҫ����O(1)��ʱ�临�Ӷ�Խ��Խ�á�
 * @method ��B�ַ�������Hash����A�޳�ʱֱ�Ӳ���Hash��
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Num 52
#define LEN 100

int HashChar[Num];

int Hash(char c) {
		if(!isalpha(c)) return -1;
		if(islower(c)) return c - 'a';
		return c - 'A' + 26;
}
void InitialHash(char *B) {
		int i;
		int pos;
		for(i = 0;B[i];i++) {
				pos = Hash(B[i]);
				if(pos == -1) {
						perror("B contains illegal characters\n");
				}
				else HashChar[pos] = 1;
		}
}
void DelSameStr(char *A, char *B) {
		int i, j;
		int pos;
		i = 0;
		while(A[i]) {
				pos = Hash(A[i]);
				if(HashChar[pos]) {
						for(j = i;A[j];j++) {
								A[j] = A[j + 1];
						}
				}
				else i++;
		}
}
int main() {
		char A[LEN], B[LEN];
		printf("A = ");
		gets(A);
		printf("B = ");
		gets(B);
		InitialHash(B);
		DelSameStr(A, B);
		printf("after coping...");
		puts(A);

		return 0;
}
