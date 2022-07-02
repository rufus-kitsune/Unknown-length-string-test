#include <stdio.h>
#include <malloc.h>

//오늘의 목표: 길이를 모르는 문자열 입력받기! 1.STACK FRAME 이용, 2. STREAM 이용, 3.이중링크드 리스트이용
 
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
