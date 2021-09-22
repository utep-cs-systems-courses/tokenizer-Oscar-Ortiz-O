#include <stdlib.h>

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
  int hasWhitespace = 0;
  while (*str != '\0'){
    if (space_char(*str)){
      str = str + 1;
      hasWhitespace = 1;
      continue;
    }
    if (hasWhitespace){
      return str;
    }
    str = str + 1;
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
}

