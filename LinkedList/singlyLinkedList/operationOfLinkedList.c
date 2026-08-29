#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
  int data;
  struct Node *next;
} sNode;

sNode *createList(int n);
void display(sNode *head);
void freeList(sNode *head);

// Case 1: Insert at the first
sNode *insertAtFirstNode(sNode *head, int data);
// Case 2: Insert at given index
sNode *insertAtIndex(sNode *head, int index, int data);
// Case 3: Insert at the end
sNode *insertAtEnd(sNode *head, int data);
// Case 4: Insert after a specified node
sNode *insertAfertNode(sNode *head, int preNode, int data);
// Case 4: Insert before a specified node
sNode *insertBeforeNode(sNode *head, int preNode, int data);

int main()
{
  int n, ch, data, index, nodeNo;
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

  printf("---Linked List Operation---\n1) Insert at the first node.\n2) Insert at the given index.\n3) Insert at the end.\n4) Insert after a given node.\n5) Insert before a given node.\n6) Exit\n");

  while (1)
  {
    printf("Enter your choice ");
    scanf("%d", &ch);
    if (ch == 6)
    {
      printf("---Operation is terminated---");
      freeList(head);
      exit(0);
    }
    printf("Enter the data to insert ");
    scanf("%d", &data);
    switch (ch)
    {
    case 1:
      printf("After insert at the first of the list the list will be\n");
      head = insertAtFirstNode(head, data);
      display(head);
      break;
    case 2:
      printf("Enter the index to insert ");
      scanf("%d", &index);
      printf("List for insert at the given index\n");
      insertAtIndex(head, index, data);
      display(head);
      break;
    case 3:
      printf("List for insert at the end\n");
      insertAtEnd(head, data);
      display(head);
      break;
    case 4:
      printf("Enter the previous node number ");
      scanf("%d", &nodeNo);
      printf("List for insert after a given node\n");
      insertAfertNode(head, nodeNo, data);
      display(head);
      break;
    case 5:
      printf("Enter the previous node number ");
      scanf("%d", &nodeNo);
      printf("List for insert before a given node\n");
      insertBeforeNode(head, nodeNo, data);
      display(head);
      break;
    default:
      printf("Please enter a valid number.\n");
      break;
    }
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
      printf("Memory allocation failed.");
      exit(0);
    }
    printf("Enter the data of the Node %d ", i + 1);
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

void freeList(sNode *head)
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

sNode *insertAtFirstNode(sNode *head, int data)
{

  sNode *ptr = (sNode *)malloc(sizeof(sNode));
  ptr->data = data;
  ptr->next = head;
  return ptr;
}

sNode *insertAtIndex(sNode *head, int index, int data)
{
  sNode *p = head;
  sNode *ptr = (sNode *)malloc(sizeof(sNode));
  ptr->data = data;
  for (int i = 0; i < index - 1; i++)
  {
    p = p->next;
  }
  ptr->next = p->next;
  p->next = ptr;
}

sNode *insertAtEnd(sNode *head, int data)
{

  sNode *p = head;
  sNode *ptr = (sNode *)malloc(sizeof(sNode));
  ptr->data = data;
  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
}

sNode *insertAfertNode(sNode *head, int preNode, int data)
{
  sNode *p = head;
  sNode *ptr = (sNode *)malloc(sizeof(sNode));
  ptr->data = data;
  for (int i = 0; i < preNode - 1; i++)
  {
    p = p->next;
  }
  ptr->next = p->next;
  p->next = ptr;
}

sNode *insertBeforeNode(sNode *head, int postNode, int data)
{
  sNode *p = head;
  sNode *ptr = (sNode *)malloc(sizeof(sNode));
  ptr->data = data;
  for (int i = 0; i < postNode - 2; i++)
  {
    p = p->next;
  }
  ptr->next = p->next;
  p->next = ptr;
}

/*
OUTPUT:-

Enter the number of the node 5
Enter the data of the Node 1 1
Enter the data of the Node 2 2
Enter the data of the Node 3 3
Enter the data of the Node 4 4
Enter the data of the Node 5 5
The list is
[1|-]-->[2|-]-->[3|-]-->[4|-]-->[5|-]--> NULL
---Linked List Operation---
1) Insert at the first node.
2) Insert at the given index.
3) Insert at the end.
4) Insert after a given node.
5) Insert before a given node.
6) Exit
Enter your choice 1
Enter the data to insert 10
After insert at the first of the list the list will be
[10|-]-->[1|-]-->[2|-]-->[3|-]-->[4|-]-->[5|-]--> NULL
Enter your choice 2
Enter the data to insert 20
Enter the index to insert 2
List for insert at the given index
[10|-]-->[1|-]-->[20|-]-->[2|-]-->[3|-]-->[4|-]-->[5|-]--> NULL
Enter your choice 3
Enter the data to insert 30
List for insert at the end
[10|-]-->[1|-]-->[20|-]-->[2|-]-->[3|-]-->[4|-]-->[5|-]-->[30|-]--> NULL
Enter your choice 4
Enter the data to insert 40
Enter the previous node number 4
List for insert after a given node
[10|-]-->[1|-]-->[20|-]-->[2|-]-->[40|-]-->[3|-]-->[4|-]-->[5|-]-->[30|-]--> NULL
Enter your choice 5
Enter the data to insert 50
Enter the previous node number 5
List for insert before a given node
[10|-]-->[1|-]-->[20|-]-->[2|-]-->[50|-]-->[40|-]-->[3|-]-->[4|-]-->[5|-]-->[30|-]--> NULL
Enter your choice 6
---Operation is terminated---

*/