//initial commit

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

// Answer *get_indices_of_item_weights(int *weights, int length, int limit)
// {
//   HashTable *ht = create_hash_table(16);

//   int *index_1 = 0;
//   int *index_2 = 0;

//   LinkedPair *current_pair;
//   if(length>ht->capacity){
//     printf("Too many values entered, cannot exceed, %d", ht->capacity);
//   }

//   //place the weights into the hash table as the keys and the weight indices as values
//   for(int i = 0; i < ht->capacity; i++){
//     current_pair = ht->storage[i]; //maybe use create_pair function?
//     while(current_pair->next != NULL){
//       // set keys as the weights and the values as weight indices
//       hash_table_insert(ht, weights[i], i);
//       current_pair = current_pair -> next;
//     }
//   }

//   //check the condition sum of weights == limit for each combination of two weights
//   //weights are the keys, so we can use retrieve
//   //we need to use the hash table instead of a nested for loop - how???
//   //see if one of the weights has a value equivalent to limit - another weight
//   //return the indices of the two weights
//   //index_1 = limit-index_2
//   for(int i = 0; i<ht->capacity; i++){
//     current_pair = ht->storage[i];

//     // use ht->current_pair->key and ht->current_pair->value
//     while(current_pair->next != NULL){
//       if(current_pair->key == limit - weights[i]){
//       hash_table_retrieve(ht, limit-current_pair->key);
//       }
//       index_1 = limit-current_pair->key;
//       index_2 = current_pair->key;
//     }
//   }
//   return index_1, index_2;
// }

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  
  for (int i = 0; i<length; i++){
    int complement = hash_table_retrieve(ht, limit - weights[i]);
    if (complement != -1){
      Answer *answer = malloc(sizeof(Answer));
      answer->index_1 = i;
      answer->index_2 = complement;
      return answer;
    } else {
      hash_table_insert(ht, weights[i], i);
    }
  }

  destroy_hash_table(ht);

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