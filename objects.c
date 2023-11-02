#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define Class struct

Class Person {
    char name[10] ;
    uint8_t age ;
    uint8_t height ;
    void(*show)(Class Person *) ;
};

void person_print(Class Person *this) {
   printf("Person: { name: %s, age:  %d, height: %d}\n",
		   this->name,this->age,this->height) ;
}

Class Person * newPerson(char name[],
     uint8_t age,
     uint8_t height) {
       Class Person *this =
	     (Class Person *)malloc(sizeof(Class Person)) ;
       strcpy(this->name, "Bruno") ;
       this->age = 28 ;
       this->height = 169 ;
     
      this->show= &person_print ;
      return this ;
}

int main () {

  Class Person *person2 =
	(Class Person *) newPerson("Bruno", 28, 169) ;
  person2->show(person2);
  
  free(person2);
  return 0 ;
}
