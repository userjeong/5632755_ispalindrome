#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100
typedef char element;

typedef struct { //스택구현
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s);
int is_empty(StackType* s);
int is_full(StackType* s);
element pop(StackType* s);
void push(StackType* s, element item);

int is_pal(char string[]);


int main(void)
{
	char answer = 0;
	//char myString[MAX_STACK_SIZE] = { NULL };
	do
	{
		char myString[MAX_STACK_SIZE] = { NULL };//입력받을 문자열 배열 선언
		printf("문자열을 입력하시오: ");
		gets_s(myString, sizeof(myString));
		if (is_pal(myString) == 1)//myString이 회문이라면. 회문판단함수(myString)
		{
			printf("회문입니다.\n");
		}
		else printf("회문이 아닙니다\n");
		printf("\n");
		printf("계속 하시겠습니까? (Y / N): ");
		scanf("%c", &answer);
		printf("\n");

		gets_s(myString, sizeof(myString)); //왜 이코드가 없으면 실행이 제대로 안되느냐
	} while (answer == 89);

	return 0;

}

void init_stack(StackType* s) //스택 초기화 함수
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
	}
	else return s->data[(s->top)--];
}

int is_pal(char string[]) //회문이라면 1을 리턴하기때문에 int형 함수
{
	StackType s; //입력된문자열을 소문자로 변경해서 넣을 스택
	init_stack(&s);
	int i = 0;

	while (string[i] != '\0') //문자열을 끝까지 검사. 문자열이 끝나기전까지 반복
	{
		if ('33' <= string[i] && string[i] <= '47')
		{
			continue;
		}
		if ('a' <= string[i] && string[i] <= 'z') //문자가 소문자일때
		{
			if (is_full(&s))
			{
				printf("스택이 가득 찼습니다.\n");
				return 0;
			}
			push(&s, string[i]);
		}
		if ('A' <= string[i] && string[i] <= 'Z')//문자가 대문자일때
		{
			if (is_full(&s))
			{
				printf("스택이 가득 찼습니다\n");
				return 0;
			}
			char x = string[i] + ('a' - 'A'); //새 char형 변수에 대문자에 32를 더해 아스키코드값을 변경해서 대입
			push(&s, x);
		}
		i++;
	}
	//여기서부터 스택에 들어간 문자와 string[i]값 비교하는 코드

	i = 0; //0으로 초기화
	while (string[i] != '\0') //문자열이 끝날때까지 검사
	{
		if (('a' <= string[i] && string[i] <= 'z'))//문자열이 소문자라면
		{
			if (pop(&s) != string[i]) return 0;
		}

		if ('A' <= string[i] && string[i] <= 'Z')//문자열이 대문자라면 바꿔줘야함
		{
			char y = string[i] + ('a' - 'A');
			if (pop(&s) != y) return 0;
		}
		i++;
	}
	if (!is_empty(&s)) //문자열이 끝났는데 스택이 비지 않으면 오류
	{
		printf("오류");
		exit(1);
	}

	else return 1;
}