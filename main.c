#include <stdio.h>
#include <malloc.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Node{
	struct Node *prev;  //단일 연결리스트여도 되지만 연습을 위해 이중으로 구현함. 
	char c;
	struct Node *next;
}Node;

Node *sus()
{
	
	char buf = 'a';
	Node *recentpoint;
	Node *head;
	int startcheck = 0;
	
	while(buf != '\n')
	{ 
		buf = fgetc(stdin);
		if(startcheck == 0)
		{
			head = (Node*)malloc(sizeof(Node));
			head->c = buf;
			head->prev = NULL;
			head->next = NULL;
			recentpoint = head;
			startcheck = 1;
		}
		else
		{
			recentpoint->next = (Node*)malloc(sizeof(Node));
			recentpoint->next->prev = recentpoint; 
			recentpoint = recentpoint->next; //recentpoint가 다음노드로 이동
			recentpoint->c = buf;
			recentpoint->next = NULL; 
		}
	}
	return head;
}

int main(int argc, char *argv[]) {
	
	Node *str;
	
	str = sus(); 
	
	while(str->next != NULL)
	{
		printf("%c", str->c);
		str = str->next;
	}
	
	return 0;
}
