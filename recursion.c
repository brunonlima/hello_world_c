#include <stdio.h>
#include <stdlib.h>

void f3(char hello[]) {
    printf("%x\n", &hello);
    f3(hello);
}


int main () {

  char hello[] = "Hello World";
  printf("from main : %d\n", &hello);
  f3(hello);  

  return 0 ;

}
