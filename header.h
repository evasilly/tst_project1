#include <stdio.h>

int sp = 0;
int stack[100];

/*
Method that places an element into stack
*/
void push(int a) {
	stack[sp++] = a;
};
int empty() {
	return (sp == 0);
}

/*
Method that takes an element from stack
*/
int pop(void) {
	if (sp > 0) {
		return stack[--sp];
	}
	else {
		fprintf(stderr, "No elements in the stack!\n");
		return 0;
	}
};
