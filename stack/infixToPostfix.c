#include <stdio.h>
#include <stdbool.h>
#define max 100
char stack[max];
int top = -1;
void push(char ops)
{
  top++;
  stack[top] = ops;
}
void pop()
{
  top--;
}
// To check wheather the char is a operator or not
bool isOperator(char ch)
{
  if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '^' || ch == '(' || ch == ')')
  {
    return true;
  }
  else
  {
    return false;
  }
}
// To check priority of the operator
int priority(char ops)
{
  if (ops == '+' || ops == '-')
  {
    return 1;
  }
  else if (ops == '/' || ops == '*' || ops == '%')
  {
    return 2;
  }
  else if (ops == '^')
  {
    return 3;
  }
  return 0;
}
void infixToPostfix(char *str, char *post)
{
  int i = 0, j = 0;
  while (str[i] != '\0')
  {
    if (!isOperator(str[i]) && str[i] != '\n')
    {
      post[j] = str[i];
      j++;
    }
    // Opening parenthesis
    else if (str[i] == '(')
    {
      push(str[i]);
    }
    // Closing parenthesis
    else if (str[i] == ')')
    {
      // Pop until '(' comes
      while (top != -1 && stack[top] != '(')
      {
        post[j] = stack[top];
        j++;
        pop();
      }
      if (top != -1 && stack[top] == '(')//Remove '('
      {
        pop();
      }
    }
    else if (isOperator(str[i]))
    {
      while (top != -1 && priority(str[i]) <= priority(stack[top]))
      {
        post[j] = stack[top];
        j++;
        pop();
      }
      push(str[i]);
    }
    i++;
  }
  while (top != -1)
  {
    post[j] = stack[top];
    j++;
    pop();
  }
  post[j] = '\0';
  puts(post);
}

int main()
{
  char str[max], post[max];
  printf("Enter the string ");
  fgets(str, sizeof(str), stdin);
  printf("The expression after the operation is ");
  infixToPostfix(str, post);
  return 0;
}

// str -> A+(B*C-(D/E^F)*G)*H
// post -> ABC*DEF^/G*-H*+