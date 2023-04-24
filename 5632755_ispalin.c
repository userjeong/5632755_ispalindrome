#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100
typedef char element;

typedef struct { //���ñ���
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
		char myString[MAX_STACK_SIZE] = { NULL };//�Է¹��� ���ڿ� �迭 ����
		printf("���ڿ��� �Է��Ͻÿ�: ");
		gets_s(myString, sizeof(myString));
		if (is_pal(myString) == 1)//myString�� ȸ���̶��. ȸ���Ǵ��Լ�(myString)
		{
			printf("ȸ���Դϴ�.\n");
		}
		else printf("ȸ���� �ƴմϴ�\n");
		printf("\n");
		printf("��� �Ͻðڽ��ϱ�? (Y / N): ");
		scanf("%c", &answer);
		printf("\n");

		gets_s(myString, sizeof(myString)); //�� ���ڵ尡 ������ ������ ����� �ȵǴ���
	} while (answer == 89);

	return 0;

}

void init_stack(StackType* s) //���� �ʱ�ȭ �Լ�
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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
	}
	else return s->data[(s->top)--];
}

int is_pal(char string[]) //ȸ���̶�� 1�� �����ϱ⶧���� int�� �Լ�
{
	StackType s; //�Էµȹ��ڿ��� �ҹ��ڷ� �����ؼ� ���� ����
	init_stack(&s);
	int i = 0;

	while (string[i] != '\0') //���ڿ��� ������ �˻�. ���ڿ��� ������������ �ݺ�
	{
		if ('33' <= string[i] && string[i] <= '47')
		{
			continue;
		}
		if ('a' <= string[i] && string[i] <= 'z') //���ڰ� �ҹ����϶�
		{
			if (is_full(&s))
			{
				printf("������ ���� á���ϴ�.\n");
				return 0;
			}
			push(&s, string[i]);
		}
		if ('A' <= string[i] && string[i] <= 'Z')//���ڰ� �빮���϶�
		{
			if (is_full(&s))
			{
				printf("������ ���� á���ϴ�\n");
				return 0;
			}
			char x = string[i] + ('a' - 'A'); //�� char�� ������ �빮�ڿ� 32�� ���� �ƽ�Ű�ڵ尪�� �����ؼ� ����
			push(&s, x);
		}
		i++;
	}
	//���⼭���� ���ÿ� �� ���ڿ� string[i]�� ���ϴ� �ڵ�

	i = 0; //0���� �ʱ�ȭ
	while (string[i] != '\0') //���ڿ��� ���������� �˻�
	{
		if (('a' <= string[i] && string[i] <= 'z'))//���ڿ��� �ҹ��ڶ��
		{
			if (pop(&s) != string[i]) return 0;
		}

		if ('A' <= string[i] && string[i] <= 'Z')//���ڿ��� �빮�ڶ�� �ٲ������
		{
			char y = string[i] + ('a' - 'A');
			if (pop(&s) != y) return 0;
		}
		i++;
	}
	if (!is_empty(&s)) //���ڿ��� �����µ� ������ ���� ������ ����
	{
		printf("����");
		exit(1);
	}

	else return 1;
}