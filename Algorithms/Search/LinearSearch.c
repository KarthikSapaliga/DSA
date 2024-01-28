#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(target==arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,target;

    printf("Enter the number of elements : ");
    scanf("%d",&n);
    if(n==0){
        printf("error : Enter a valid positive integer <N>\n");
        exit(EXIT_FAILURE);
    }

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements :\n");
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    printf("Enter the element to search : ");
    scanf("%d",&target);

    int loc = LinearSearch(arr,n,target);
    if(loc != -1){
        printf("The element %d is found at index %d\n",target,loc);
    }else{
        printf("Element not found !\n");
    }
    free(arr);
    return 0;
}
