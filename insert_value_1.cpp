//
// Created by liuchu on 2020/12/17.
//

#include <stdio.h>
#define MAX 100

int find(int arr[],int n,int target){
    int bg = 0;
    int ed = n-1;
    while(bg <= ed){
        int mid = (bg+ed)/2;
        if(arr[mid] > target){
            ed = mid-1;
        }else{
            bg = mid+1;
        }
    }
    return bg;
}


int main(){
    int arr[] = {1,4,7,9,12,16,19};
    int n = 7;
    int target = 20;
    int loc = find(arr,n,target);
    for(int j=n-1;j>=loc;j--){
        arr[j+1] = arr[j];
    }
    arr[loc] = target;
    n += 1;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}