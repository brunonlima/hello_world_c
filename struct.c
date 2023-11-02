#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


struct Person {
    char name[10];
    uint8_t age;
    uint8_t height;
};

int main () {
  struct Person person ;
  strcpy(person.name, "Bruno") ;
  person.age = 28 ;
  person.height = 169 ;

  printf("%x\n", &person);  
  return 0 ;

}
