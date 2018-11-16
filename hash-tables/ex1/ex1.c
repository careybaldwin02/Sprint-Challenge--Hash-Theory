//initial commit

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  LinkedPair *current_pair;
  if(length>ht->capacity){
    printf("Too many values entered, cannot exceed, %d", ht->capacity);
  }

  //place the weights into the hash table as the value in pair
  for(int i = 0; i < ht->capacity; i++){
    current_pair = ht->storage[i]; //maybe use create_pair function?
    while(current_pair->next != NULL){
      hash_table_insert(ht, current_pair->key, weights[i]);
      current_pair = current_pair -> next;
    }
  }

  

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif