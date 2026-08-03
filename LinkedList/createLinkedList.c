#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} sNode;

sNode *createLinkedList(int n);
void display(sNode *head);


int main()
{
  int n;
  sNode *head = NULL;
  printf("Enter the number of the Nodes ");
  scanf("%d", &n);
  head = createLinkedList(n);
  display(head);
  return 0;
}

sNode *createLinkedList(int n)
{
  sNode *head = NULL;
  sNode *temp = NULL;
  sNode *p = NULL;

  for (int i = 0; i < n; i++)
  {
    temp = (sNode *)malloc(sizeof(sNode));
    printf("Enter the data of Node %d ", i + 1);
    scanf("%d",&(temp->data));
    temp->next = NULL;
    if (head == NULL)
    {
      head = temp;
    }
    else
    {
      p = head;
      while (p->next != NULL)
      {
        p = p->next;
      }

      p->next = temp;
    }
  }
  return head;
}

void display(sNode *head)
{
  sNode *p = head;
  printf("The list is ");
  while (p != NULL)
  {
    printf("%d-> ", p->data);
    p = p->next;
  }
  printf("NULL");
}