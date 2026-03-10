#include<stdio.h>
void bubbleSort(int arr[],int size){
  int i,j,temp;
  int swapped;
  for (i=0;i<size-1;i++){
     swapped =0;
       for(j=0;j<size-1-i;j++){
         if(arr[j]>arr[j+1]){
	   temp =arr[j];
	   arr[j] = arr[j+1];
	   arr[j+1]=temp;
	   swapped =1;
	 }
       }
       if(swapped==0){
         printf("\n Early termination at pass %d (array already sorted)\n",i);
          break;
       }
    }
}

void printArray(int arr[],int size){
  for (int i=0;i<size;i++)
	  printf("%d\n",arr[i]);
  printf("\n");
}

void printPass(int arr[],int size,int pass){
    printf("pass %d",pass);
    printArray(arr,size);
}

int main(){

	int size;

	printf(" Enter the number of elements: ");
	scanf("%d",&size);

	int arr[size];

	printf("Enter %d elements :\n",size);

	for(int i=0;i<size;i++){
	printf(" arr[%d]=",i);
	scanf("%d",&arr[i]);   // fixed
	}

 printf("\nBefore Sorting:");
 printArray(arr,size);

 int temp,swapped;
 int trace[size];

 for(int i =0;i<size;i++) trace[i]=arr[i];   

 for(int i=0;i<size-1;i++){
   swapped =0;

    for (int j=0;j<size-1-i;j++){

      if(trace[j]>trace[j+1]){   

       temp=trace[j];
       trace[j]=trace[j+1];
       trace[j+1]=temp;
       swapped =1;
      }

    }

    printPass(trace,size,i+1);

    if(!swapped){
      printf("No swaps-early Exit!\n");
      break;
    }

 }

 bubbleSort(arr,size);

 printf("\n After Sortin:\n");
 printArray(arr,size);

 return 0;
}
