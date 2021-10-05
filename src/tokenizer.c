#include <stdlib.h>
#include <stdio.h>

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
