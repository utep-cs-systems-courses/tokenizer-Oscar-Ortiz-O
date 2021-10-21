#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  if (c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}


int non_space_char(char c)
{
  if (c != ' ' && c != '\t'){
    return 1;
  }
  return 0;
}


char *word_start(char *str)
{
  while (*str != '\0'){
    if (space_char(*str)){
      str = str + 1;
      continue;
    }
    return str;
  }
  return str;
}


char *word_terminator(char *word)
{
  while (*word != '\0'){
    if (space_char(*word)){
      return word;
    }
    word = word + 1;
  }
  return word;
}


int count_words(char *str)
{
  int count = 0;
  str = word_start(str);

  while (*str != '\0'){
    count = count + 1;
    str = word_terminator(str);
    str = word_start(str);
  }
  return count;
}


char *copy_str(char *inStr, short len)
{
  char *newStr = (char*)malloc((len + 1) * sizeof(char));

  for (int i = 0; i < len; ++i) {
    newStr[i] = inStr[i];
  }
  newStr[len] = '\0';
  return newStr;
}


char **tokenize(char *str)
{
  int numOfWords = count_words(str);
  char **tokens = malloc((numOfWords + 1) * sizeof(char*));
  char *tempStr;
  
  for (int i = 0; i < numOfWords; ++i) {
    str = word_start(str);
    int count = 0;
    tempStr = str;
    
    while(non_space_char(*tempStr) && *tempStr != '\0') {
      count = count + 1;
      tempStr = tempStr + 1;
    }
    tokens[i] = copy_str(str, count);
    str = word_terminator(str);
  }
  tokens[numOfWords] = '\0';
  return tokens;
}


void print_tokens(char **tokens)
{
  int count = 0;
  while (*tokens) {
    printf("token[%d] = %s\n", count, *tokens);
    tokens++;
    count++;
  }
}

void free_tokens(char **tokens)
{
  int index = 0;
  while (tokens[index]) {
    free(tokens[index]);
    index++;
  }
  free(tokens);
}

int main()
{
  char userChoice[10];
  char userStr[100];
  int userContinue = 1;
  List *historyList = init_history();
  
  while (userContinue) {

    printf("Enter 'w' to write a string input, '!h' to see all history records, and '!' followed by a number to see a particular history record:\n");
    putchar('$');
    fgets(userChoice, 10, stdin);

    if (*userChoice == 'w') {
      printf("Please enter a String:\n");
      putchar('$');
      fgets(userStr, 100, stdin);
      
      // Splits string into words/tokens and displays them
      char **tokenizer = tokenize(userStr);
      print_tokens(tokenizer);
      free_tokens(tokenizer);

      // Adds string to history
      add_history(historyList, userStr); 
    }
    else if (userChoice[0] == '!') {
      
      if (userChoice[1] == 'h') {
	print_history(historyList);

      }
      else if (userChoice[1] >= 48 && userChoice[1] <= 57) {
	int userNumber = userChoice[1] - '0';
	printf("%s\n", get_history(historyList, userNumber));
      }
      else if (userChoice[1] == '1') {
	printf("wow");
      }
    }
    else {
      printf("You entered an invalid input!\n");
      userContinue = 0;
    }
   
    char *strPoint;
    strPoint = &userStr[0];

  }
  
  free_history(historyList);
  return 0;
}
