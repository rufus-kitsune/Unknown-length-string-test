#include <stdio.h>
#include <malloc.h>

//������ ��ǥ: ���̸� �𸣴� ���ڿ� �Է¹ޱ�! 1.STACK FRAME �̿�, 2. STREAM �̿�, 3.���߸�ũ�� ����Ʈ�̿�
 
void scanUstring(int* length, char** stradress)
{
	char buffer;
	buffer = getc(stdin);
	(*length) ++;
	
	if(buffer == '\n')
	{
		(*length) --;
		*stradress = (char*) malloc(*length);
		*(*stradress + *length) = NULL;
		(*length) --;
	}
	else
	{
		scanUstring(length, stradress);
		
		*(*stradress + *length) = buffer;
		(*length) --;
	}
}
 
int main()
{
	   int num = 0;
	   char* str = NULL;
	   scanUstring(&num, &str);
}
