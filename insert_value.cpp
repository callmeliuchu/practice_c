//
// Created by 刘楚 on 2020/11/21.
//


#include <cstdio>

int find_val(int arr[], int n, int val){
    int bg = 0;
    int ed = n-1;
    while(bg <= ed){
        int mid = (bg+ed)/2;
        if(arr[mid] > val){
            ed = mid - 1;
        }else{
            bg = mid + 1;
        }
    }
    return bg;
}


int main(int argc,char *args[]){
    int arr[20] = {1,5,8,10,29,34};
    int n = 6;
    int val = 18;
    int loc = find_val(arr,n,val);
    for(int k=n;k>loc;k--){
        arr[k] = arr[k-1];
    }
    arr[loc] = val;
    for(int i=0;i<n+1;i++){
        printf("%d\n",arr[i]);
    }
}