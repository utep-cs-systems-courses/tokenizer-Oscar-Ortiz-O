#include <stdlib.h>   
#include <stdio.h>    
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List *listOfStrings = malloc(sizeof(List*));
  listOfStrings -> root = NULL;
  return listOfStrings;
}

void add_history(List *list, char *str)
{
  int len;
  for (len = 0; str[len] != '\0'; len++) {
  }
    
  char *newStr = copy_str(str, len);
  int count = 1;
  Item *currentNode = list -> root;

  if (currentNode == NULL) {
    currentNode = malloc(sizeof(Item));
    currentNode -> id = 0;
    currentNode -> str = newStr;
    currentNode -> next = NULL;
    list -> root = currentNode;
    return;
  }
  
  while (currentNode -> next != NULL) {
    count++;
    currentNode = currentNode -> next;
  }

  currentNode -> next = malloc(sizeof(Item));
  currentNode -> next -> id = count;
  currentNode -> next -> str = newStr;
  currentNode -> next -> next = NULL;
 
}

void print_history(List *list)
{
  Item *currentNode = list -> root;
  while (currentNode != NULL) {
    printf("%d - %s\n", currentNode -> id, currentNode -> str);
    currentNode = currentNode -> next;
  }
}

char *get_history(List *list, int id)
{
  Item *currentNode = list -> root;
  while (currentNode != NULL) {
    if (currentNode -> id == id) {
      return currentNode -> str;
    }
    currentNode = currentNode -> next;
  }
  return "";
}

void free_history(List *list)
{
  Item *currentNode = list -> root;
  Item *deleteNode = currentNode;
  
  while (currentNode != NULL) {
    deleteNode = currentNode;
    currentNode = currentNode -> next;
    free(deleteNode);
  }
  free(list);
}

