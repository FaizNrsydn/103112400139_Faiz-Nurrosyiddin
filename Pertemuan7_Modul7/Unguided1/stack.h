#ifndef STACK_H
#define STACK_H

typedef int infotype;
struct Stack
{
    infotype info[20];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif