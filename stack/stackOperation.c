#include <stdio.h>
#include <stdlib.h>
#define max 10
// Global variables
int top = -1, cnt = 0, stack[max];
// Function declaration
void push(int);
void pop();
void display();
void peep();
int count();

int main()
{
  int val, ch;
  printf("\n---Stack Operations---\n1. PUSH\n2. POP\n3. DISPLAY\n4. PEEP\n5. COUNT\n6. EXIT\n------------------\n");
  while (1)
  {
    printf("Enter your choice ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter the value to push in the stack ");
      scanf("%d", &val);
      push(val);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      peep();
      break;
    case 5:
      printf("The number of elements in the stack is %d.\n", count());
      break;
    case 6:
      printf("Operation is terminated.");
      exit(0);
    default:
      printf("Please enter a valid number.\n");
      break;
    }
  }
  return 0;
}

// Function definition
void push(int val)
{
  if (top == max - 1)
  {
    printf("Stack is full!\n");
  }
  else
  {
    top++;
    stack[top] = val;
    printf("%d added successfully in the stack!\n", val);
    cnt++;
  }
}
void pop()
{
  if (top == -1)
  {
    printf("Queue is empty,nothing to be dequeue.\n");
  }
  else
  {

    printf("%d deleted successfully.\n", stack[top]);
    top--;
    cnt--;
    if (cnt == 0)
    {
      top = -1;
    }
  }
}
void display()
{
  if (top == -1)
  {
    printf("The queue is empty.\n");
  }
  else
  {

    printf("The Queue is \n");
    for (int i = top; i >= 0; i--)
    {
      printf("%d\n", stack[i]);
    }
  }
}
void peep()
{
  if (top == -1)
  {
    printf("The queue is empty.\n");
  }
  else
  {

    printf("The last element is %d.\n", stack[top]);
  }
}
int count()
{
  return cnt;
}