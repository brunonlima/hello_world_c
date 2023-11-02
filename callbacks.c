#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


struct Person {
    char name[10];
    uint8_t age;
    uint8_t height;
};

void createPerson(char name[],
     uint8_t age,
     uint8_t height,
     void(*function_pointer)(struct Person)) {
       struct Person person ;
       strcpy(person.name, "Bruno") ;
       person.age = 28 ;
       person.height = 169 ;
     
      (*function_pointer)(person);
}

void printPerson(struct Person person) {
   printf("Person: %s, %d, %d\n",
		   person.name,person.age,person.height);
}

void printPerson2(struct Person person) {
   printf("Person: { name: %s, age:  %d, height: %d}\n",
		   person.name,person.age,person.height);
}

int main () {

  createPerson("Bruno",28,169,&printPerson);
  createPerson("Bruno",28,169,&printPerson2);

  return 0 ;

}
