#include <stdio.h>
#include <stdlib.h>

typedef struct node {

char letter;
struct node* next;

} node;

// Returns number of nodes in the linkedList.
int length (node* head) {

  int counter = 0;
  node *temp = head;

  while (temp != NULL) {
    temp = temp->next;
    counter++;
  }

  return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString (node* head) {

  int len = length(head);
  node *temp = head;

  char *newString = malloc(sizeof(char) * (len + 1));

  for (int i = 0; i < len; i++) {
    newString[i] = temp->letter;
    temp = temp->next;
  }

  newString[len] = '\0';

  return newString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar (node** pHead, char c) {

  node *new = malloc(sizeof(node));
  new->next = NULL;
  new->letter = c;

  if (*pHead == NULL) {
    *pHead = new;
    return ;
  }
  
  node *temp = *pHead;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = new;
}

// deletes all nodes in the linkedList.
void deleteList (node** pHead) {

  node *temp = *pHead;
  node *current = temp;

  while (temp != NULL) {
    temp = temp->next;
    free (current);
    current = temp;
  }

  *pHead = NULL;
}

int main (void) {

  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;

  FILE* inFile = fopen("input.txt","r");
  fscanf(inFile, " %d\n", &numInputs);
  
  while (numInputs-- > 0) {
     fscanf(inFile, " %d\n", &strLen);
     for (i = 0; i < strLen; i++) {
         fscanf(inFile," %c", &c);
         insertChar(&head, c);
     }
    
     str = toCString(head);
     printf("String is : %s\n", str);
    
     free(str);
     deleteList(&head);
    
     if (head != NULL) {
       printf("deleteList is not correct!");
       break;
     }
   }
  
   fclose(inFile);
}