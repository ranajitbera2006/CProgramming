#include <stdio.h>
#include <stdlib.h>
#define max 10
// Global variables
int front = -1, rear = -1, cnt = 0, queue[max];
// Function declaration
void enqueue(int);
void dequeue();
void display();
void peep();
int count();

int main()
{
  int val, ch;
  printf("\n---Queue Operation---\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. PEEP\n5. COUNT\n6. EXIT\n------------------\n");
  while (1)
  {
    printf("Enter your choice ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter the value to enqueue ");
      scanf("%d", &val);
      enqueue(val);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      peep();
      break;
    case 5:
      printf("The number of elements in the queue is %d.\n", count());
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
void enqueue(int val)
{
  if (rear == max - 1)
  {
    printf("Queue is full!\n");
  }
  else
  {
    if (front == -1)
    {
      front = 0;
    }
    rear++;
    queue[rear] = val;
    printf("%d added successfully in the queue!\n", val);
    cnt++;
  }
}
void dequeue()
{
  if (front == -1 || front > rear)
  {
    printf("Queue is empty,nothing to be dequeue.\n");
  }
  printf("%d deleted successfully.\n", queue[front]);
  front++;
  cnt--;
  if (front > rear)
  {
    front = -1;
    rear = -1;
  }
}
void display()
{
  if (front == -1)
  {
    printf("The queue is empty.\n");
  }

  printf("The Queue is \n");
  for (int i = front; i <= rear; i++)
  {
    printf("%d\n", queue[i]);
  }
}
void peep()
{
  if (front == -1)
  {
    printf("The queue is empty.\n");
  }
  printf("The first element is %d.\n", queue[front]);
}
int count()
{
  return cnt;
}