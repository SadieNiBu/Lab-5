#include <stdio.h>

void bubbleSort(int arr[], int len);
void swap(int arr[], int x, int y);

int main(void) {

  int arr[] = {97,16,45,63,13,22,7,58,72};
  int len = sizeof(arr) / 4;
  
  bubbleSort(arr, len);

  printf("\nSorted array: ");
  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  
  return 0;
}

void bubbleSort(int arr[], int len) {
  
  for (int i = 0; i < len - 1; i++) {
    
    printf("Number of swaps for index %d (run %d): ", i, i + 1);
    int numSwaps = 0;
    
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
        numSwaps++;
      }
    }
    printf("%d\n", numSwaps);
  }
  
}

void swap(int arr[], int x, int y) {

  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}