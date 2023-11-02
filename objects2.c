#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define Class  struct

typedef Class person {
    char name[10] ;
    uint8_t age ;
    uint8_t height ;
    void(*show)(Class person *) ;
} Person ;

void person_print(Person *this) {
   printf("Person: { name: %s, age:  %d, height: %d}\n",
		   this->name,this->age,this->height) ;
}

Person * newPerson(char name[],
     uint8_t age,
     uint8_t height) {
       Person *this =
	     (Person *)malloc(sizeof(Person)) ;
       strcpy(this->name, name) ;
       this->age = age ;
       this->height = height ;
     
      this->show= &person_print ;
      return this ;
}

int main () {

  Person *person2 = (Person* ) newPerson("Bruno", 28, 169) ;
  person2->show(person2) ;
  
  free(person2) ;
  return 0 ;
}
