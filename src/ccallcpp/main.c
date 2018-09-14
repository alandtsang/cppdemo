#include <stdio.h>
#include "wrapper.h"

int main() {
  void *p = call_Person_Create();
  int age = call_Person_GetAge(p);
  const char *name = call_Person_GetName(p);
  call_Person_Destroy(p);
  printf("name=%s, age=%d\n", name, age);
}
