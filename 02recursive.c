#include <stdio.h>
int binarySearchRecursive(int arr[],int left,int right,int target){
  //Base case : element not found
  if (left>right)
	  return -1;
  int mid =left+(right -left)/2;
  //Base case :element found
  if (arr[mid]==target)
	  return mid;
//Recursive case : search right half
  else if (arr[mid]<target)
	  return binarySearchRecursive(arr,left,mid +1,target);

  //Recursive case : search left half
  else 
	  return binarySearchRecursive(arr,left,mid -1,target);

}
int main(){

int size,target;
printf("Enter the number of elements: ");
scanf("%d",&size);
int arr[size];
printf("Enter %d sorted elements:\n",size);
for (int i=0;i<size;i++){
printf(" arr[%d]=",i);
scanf("%d",&arr[i];
}
printf("enter the target to search:");
 scanf("%d",&target);
int result = binarySearchRecursive(arr,0,size -1,target);
 if(result != -1)
 printf("\n Element %d found at index %d\n",target,result);
 else
 printf("\n Element %d not found in the array\n",target);
return 0;
}
