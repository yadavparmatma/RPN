#include "../StackADT/stack.h"
#include <stdio.h>

typedef struct result Result;
typedef struct queue Queue;
typedef struct token Token;
typedef struct token* Token_ptr;

struct result {
  int error;
  int status;
};

struct queue {
	Node_ptr* front;
	Node_ptr* rear;
	LinkedList* list;
};

Queue createQueue(void);
int nQueue(Queue queue, void* data);
void* dQueue(Queue queue);

int fillSpace(Queue queue,void* data);
int checkPrecendence(char operatorr);
int isRearSpace(Queue queue);
int handleOperandInPostFix(Queue queue,char operand);
int shiftOneElementFromStackToQueue(Stack stack,Queue queue);

Result evaluate(char *expression);
char * infixToPostfix(char * expression);