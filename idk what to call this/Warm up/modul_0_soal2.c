#include <stdio.h>
#include <stdlib.h>
  
int main()
{
  
    // address of the block created hold by this pointer
    int* ptr;
    int size;
  
    // Size of the array
    printf("Enter size of elements:");
    scanf("%d", &size);
  
    //  Memory allocates dynamically using malloc()
    ptr = (int*)malloc(size * sizeof(int));
  
    // Get the elements of the array
    for (int i = 0; i < size; ++i) {
        ptr[i] = i + 1;
    }
  
    // Print the elements of the array
    printf("The elements of the array are: ");
    for (int k = 0; k < size; ++k) {
        printf("%d, ", ptr[k]);
    }

	
 
    return 0;
}