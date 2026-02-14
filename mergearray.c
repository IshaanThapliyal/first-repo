#include <stdio.h>

// Function prototype
void mergeArrays(int arr1[], int s1, int arr2[], int s2, int result[]);

int main(){
    // Two sorted arrays
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int result[10];   // Array to store output
    mergeArrays(arr1, 5, arr2, 5, result);
    // Display merged array
    printf("Merged Array:\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", result[i]);
    }
    return 0;
}

void mergeArrays(int arr1[], int s1, int arr2[], int s2, int result[]){
    int a = 0;   // Tracks position in arr1
    int b = 0;   // Tracks position in arr2
    int c = 0;   // Tracks position in result array
    // Compare elements from both arrays
    while (a < s1 && b < s2){
        if (arr1[a] <= arr2[b]){
            result[c++] = arr1[a++];
        }
        else{
            result[c++] = arr2[b++];
        }
    }
    while (a < s1){
        result[c++] = arr1[a++];
    }
    while (b < s2){
        result[c++] = arr2[b++];
    }
}
