#pragma once
#include"treePrint.h"
#include"RB head.h"

int main()
{
	int data;
	char cmd = 0;
	node *p;

	NIL = (node*)malloc(sizeof(node));
	memset(NIL, 0, sizeof(node));
	NIL->color = BLACK;

	while (cmd != '4')
	{
		printf("1.Insert\n");
		printf("4. End\n");
		printf("Data num:%d\n", DataNum);
		printf("Input cmd:");
		scanf_s("%c", &cmd, sizeof(cmd));
		scanf_s("%*[^\n]");
		while (getchar() != '\n')break;

		switch (cmd)
		{
		case '1':
			printf("Input key:");
			scanf_s("%d", &data);
			while (getchar() != '\n')break;

			RB_insert(head, data);
			print_ascii_tree(head);
			break;
		case '4':
			printf("Á¾·á\n");
			break;
		}
	}
	for (p = head; p != NULL; )
	{
		head = p;
		p = p->right;
		free(head);
	}
}