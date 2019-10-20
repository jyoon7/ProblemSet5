#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 32;
const int MAX_ARRAY_SIZE = 19660;

void sort(char arr[MAX_ARRAY_SIZE][SIZE], int size);

int main(int argc, char *argv[]){
  int size = 0;
  char ngram[MAX_ARRAY_SIZE][SIZE];



  // Open text file in read mode
  FILE *readFile;
  readFile = fopen("Ngram.txt", "r");

  if(readFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  // Read each line in the text file using fgets()
  while(fgets(ngram[size], SIZE, readFile) != NULL){
    // Remove new line from the item
    for(int i = 0; i < SIZE; i++){
      if(ngram[size][i] == '\n'){
        ngram[size][i] = '\0';
      }
    }

    //Check to make sure we don't read more items than we can store in the ngram array
    if(size >= MAX_ARRAY_SIZE){
      fprintf(stderr, "Reached the maximum number of strings that the ngram array can hold.\n");
      break;
    }

    size++;
  }
  // Close the file since we are done reading it.
  if(!readFile) fclose(readFile);

  // Sort our ngram  
  sort(ngram, size);

  // Print the sorted array
  for(int i=0; i < size; i++){
    printf("%s\n", ngram[i]);
  }
  return 0;
}

// Implement Bubble Sort in this function
void sort(char arr[MAX_ARRAY_SIZE][SIZE], int size){
  int x = 0;
  int swapped = 1;
  char tmp[MAX_ARRAY_SIZE][SIZE];
  while (swapped != 0){
    swapped = 0;
    for(int x = 0; x != size; x++){
      if (strcmp(arr[x],arr[x+1]) > 0){
        strcpy (tmp[0], arr[x]);
        strcpy (arr[x], arr[x+1]);
        strcpy (arr[x+1], tmp[0]);
        swapped = 1;
      }  
    }
  }
}

