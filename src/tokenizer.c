#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

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
  while (*tokens) {
    printf("%s\n", *tokens);
    tokens++;
  }
}

int main()
{
  printf("Working!\n");

  char str[100] = " hello world !";
  char *wow;
  wow = &str[0];

  int count = count_words(wow);
  printf("%d\n", count);

  copy_str(wow, 5);

  char **tokens = tokenize(wow);
  print_tokens(tokens);
  
  return 0;
}
