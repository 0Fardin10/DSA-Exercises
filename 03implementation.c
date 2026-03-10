#include <stdio.h>

void selectionSort(int arr[], int size){
int i, j, minIdx, temp;

for(i = 0; i < size-1; i++){
    minIdx = i;

    for (j = i+1; j < size; j++){
        if(arr[j] < arr[minIdx])
            minIdx = j;
    }

    if(minIdx != i){
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

}

void printArray(int arr[], int size){
for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
printf("\n");
}

int main(){

int size;

printf("Enter the number of elements: ");
scanf("%d", &size);

int arr[size];

printf("Enter %d elements :\n", size);

for(int i = 0; i < size; i++){
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
}

printf("\nBefore sorting: ");
printArray(arr, size);

selectionSort(arr, size);

printf("After Sorting: ");
printArray(arr, size);

return 0;
}
