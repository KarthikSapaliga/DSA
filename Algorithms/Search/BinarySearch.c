#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[],int n,int target){
    int low=0, mid, high=n-1;

    while(low<=high){
        mid = (low + high)/2;
        if(target==arr[mid]){
            return mid;
        }
        else if(target<arr[mid])
            high = mid -1;
        else 
            low = mid +1;
    }
    return -1;
}

int main(){
    int n,target;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    if(n==0){
        printf("ERROR : Binary Search is not possible !\n");
        exit(1);
    }

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements :\n");
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    printf("Enter the element to be searched : ");
    scanf("%d",&target);

    int loc = BinarySearch(arr,n,target);
    if(loc != -1) 
        printf("The element %d found at index %d\n",target,loc);
    else 
        printf("The element not found !\n");

    free(arr);
    return 0;
}
