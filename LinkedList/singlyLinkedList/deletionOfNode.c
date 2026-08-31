#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} sNode;

sNode *createList(int n);
void display(sNode *head);
void freeMem(sNode *head);

// Case 1: Delete first node
sNode *deleteFirstNode(sNode *head);
// Case 2: Delete node from the given index
sNode *deleteNodeByIndex(sNode *head, int index);
// Case 3: Delete the end node
sNode *deleteEndNode(sNode *head);
// Case 4: Delete node by given value
sNode *deleteNodeByValue(sNode *head, int value);

int main()
{
  int n, index, value, ch;
  sNode *head = NULL;
  printf("Enter the number of the node ");
  scanf("%d", &n);
  if (n <= 0)
  {
    printf("Please enter a valid node number.");
  }
  head = createList(n);
  printf("The list is\n");
  display(head);

  printf("---Linked List Deletion Operation---\n1) Delete the first node.\n2) Delete at the given index.\n3) Delete the end node.\n4) Delete by given value.\n5) Exit\n");
  scanf("%d", &ch);
  switch (ch)
  {
  case 1:
    printf("The linked list after deleting the first node is \n");
    head = deleteFirstNode(head);
    display(head);
    break;
  case 2:
    printf("Enter the index to delete the node ");
    scanf("%d", &index);
    printf("The linked list after deleting the given index node is \n");
    deleteNodeByIndex(head, index);
    display(head);
    break;
  case 3:
    printf("The linked list after deleting the end node is \n");
    deleteEndNode(head);
    display(head);
  case 4:
    printf("Enter the value of the node to be delete ");
    scanf("%d", &value);
    deleteNodeByValue(head, value);
    break;
  case 5:
    printf("---System is terminated---");
    freeMem(head);
    exit(0);

  default:
    printf("Please Enter a valid number.");
    break;
  }
  return 0;
}

sNode *createList(int n)
{
  sNode *head = NULL;
  sNode *tail = NULL;
  sNode *temp = NULL;
  for (int i = 0; i < n; i++)
  {
    temp = (sNode *)malloc(sizeof(sNode));
    if (temp == NULL)
    {
      printf("Memory allocation failed.\n");
      exit(0);
    }
    printf("Enter the value of the node %d ", i + 1);
    scanf("%d", &(temp->data));
    temp->next = NULL;
    if (head == NULL)
    {
      head = temp;
      tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }
  return head;
}

void display(sNode *head)
{
  sNode *p = head;
  while (p != NULL)
  {
    printf("[%d|-]-->", p->data);
    p = p->next;
  }
  printf(" NULL\n");
}
void freeMem(sNode *head)
{
  sNode *current = head;
  sNode *nextNode = NULL;
  while (current != NULL)
  {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
}

sNode *deleteFirstNode(sNode *head)
{
  sNode *p = head;
  head = head->next;
  free(p);
  return head;
}

sNode *deleteNodeByIndex(sNode *head, int index)
{
  sNode *p = head;
  sNode *q = head->next;
  for (int i = 0; i < index - 1; i++)
  {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);
}
sNode *deleteEndNode(sNode *head)
{
  sNode *p = head;
  sNode *q = head->next;
  while (q->next != NULL)
  {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
}

sNode *deleteNodeByValue(sNode *head, int value)
{
  sNode *p = head;
  sNode *q = head->next;

  while (q->next != NULL && q->data != value)
  {
    p = p->next;
    q = q->next;
  }
  if (q->data == value)
  {
    p->next = q->next;
    free(q);
    printf("The linked list after deleting node by given value is \n");
    display(head);
  }
  else
  {
    printf("The given value is not found!");
  }
}