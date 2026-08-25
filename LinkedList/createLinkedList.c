
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} sNode;

sNode *createLinkedList(int n);
void display(sNode *head);
void freeList(sNode *head);

int main()
{
  int n;
  sNode *head = NULL;
  printf("Enter the number of the node ");
  scanf("%d", &n);
  if (n <= 0)
  {
    printf("Invalid node number.");
    return 1;
  }
  head = createLinkedList(n);
  display(head);
  freeList(head);

  return 0;
}

sNode *createLinkedList(int n)
{
  sNode *head = NULL;
  sNode *tail = NULL;
  sNode *temp = NULL;

  for (int i = 0; i < n; i++)
  {
    temp = (sNode *)malloc(sizeof(sNode *));
    if (temp == NULL)
    {
      printf("Memory allocation is failed.");
      exit(0);
    }
    printf("Enter the value of the Node %d ", i + 1);
    scanf("%d", &(temp->data));
    temp->next = NULL;
    if (head == NULL)
    {
      head = temp;
      tail = temp; // At first head == temp
    }
    else
    {
      tail->next = temp; // tail points to the last Node data
      tail = temp;       // Now this will store the temp value,its pointer move to the last inserted value
    }
  }
  return head;
}

void display(sNode *head)
{
  sNode *p = head;
  while (p != NULL)
  {
    printf("[%d|-]--->", p->data);
    p = p->next;
  }
  printf(" NULL");
}

void freeList(sNode *head)
{
  sNode *current = head;
  sNode *nextNode = NULL;
  while (current != NULL)
  {
    nextNode = current->next; // to keep the referance
    free(current);
    current = nextNode;
  }
}