#include <stdio.h>
#include <string.h>
#include "strops.h"

int main(int argc, char* argv[])
{
  char str[256] = "If you don’t like it, change it. If you can’t, ignore it.";
  int ret;

  printf("%s\n", str);

  insert_substring(str, 0, "What I'd say: ");
  printf("insert: %s\n", str);
  
  insert_substring(str, 100, " Make sense?");
  printf("insert: %s\n", str);

  ret = delete_substring(str, "What ");
  printf("delete: (%d) %s\n", ret, str);
  
  ret = delete_substring(str, " it");
  printf("delete: (%d) %s\n", ret, str);
  
  ret = delete_substring(str, "make");
  printf("delete: (%d) %s\n", ret, str);
  
  ret = replace_substring(str, "change", "don't change");
  printf("replace: (%d) %s\n", ret, str);

  ret = replace_substring(str, " change", "");
  printf("replace: (%d) %s\n", ret, str);

  ret = replace_substring(str, "make", "fake");
  printf("replace: (%d) %s\n", ret, str);

  return 0;
}
