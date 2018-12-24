#include <stdio.h>
#include <malloc.h>
#include "header.h"

int main() {
	int i;
	printf("Enter the statement > ");
	while (!feof(stdin)) {
		int c = getchar();
		int x;
		switch (c) {
		case '\n':
		case ' ': break;
		case '=': printf("Result = %d\n", pop()); break;
		case 27: goto RESULT;
		case '+': push(pop() + pop()); break;
		case '-': push(-pop() + pop()); break;
		case '*': push(pop() * pop()); break;
		default:
			ungetc(c, stdin);
			if (scanf("%d", &x) != 1) {
				fprintf(stderr, "Can't read element\n");
				return -1;
			}
			else {
				push(x);
			}
			break;
		}
	}
RESULT:
	i = 0;
	while (!empty()) {
		printf("Stack[%d] = %d\n", i, pop());
		i++;
	}
	return 0;
}