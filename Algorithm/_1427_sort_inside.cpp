#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
 
#define DEBUG 1
#define EXE 0
int MOD = EXE;
 
void sort(char arr[15],int l, int r) {
    int MAX_ARR_SIZE = r;
    int MIN_ARR_SIZE = l;
    char p=arr[l];
    int left = l;
    int right = r;
 
 
 
    if(l>=r) {
        if(MOD) printf("r이 l보다 작아져서r return [l r]=[%d %d];\n",l,r);
        return;
    }
 
    if((r-l)==1) {
        int min = arr[l]<arr[r]?arr[l]:arr[r]; int="" max="arr[l]">arr[r]?arr[l]:arr[r];
 
        arr[l]=min;
        arr[r]=max;
        if(MOD) printf("원소가 두개남아서 return [l r]=[%d %d];\n",l,r);
        if(MOD) printf("%s\n",arr);
        return;
    }   
 
 
    while(1) {
        char temp;
        while( (p>=arr[left+1])  &&  ((left+1)<=MAX_ARR_SIZE) ) {
            left++;
            if(MOD) printf("Left ptr 이동 현재값은 [left,val][pivot] = [%d %c] %c\n",left,arr[left],p);
        }
        while( (p<arr[right]) &&="" ((right-1)="">=MIN_ARR_SIZE) ) {
            right--;
            if(MOD) printf("right ptr 이동 현재값은 [right,val][pivot] =  = [%d %c] %c\n",right,arr[right],p);
        }
        if(left==right) {
            if(MOD) printf("Left 와 Right 만나거나 넘어서 break; \n");
            temp=arr[l];
            arr[l]=arr[left];
            arr[left]=temp;
            break;
        }
        if(MOD) printf("Left+1과 right 교환 [%c->%c] break; \n",arr[left+1],arr[right]);
        temp=arr[left+1];
        arr[left+1]=arr[right];
        arr[right]=temp;
        if(MOD) printf("%s\n",arr);
    }
    if(MOD) printf("%s\n",arr);
 
 
    sort(arr,l,left-1);
    sort(arr,left+1,r);
 
}
 
void invertPrt(char* arr) {
    int length= strlen(arr);
    int i=0;
    for(i=length-1;i>=0;i--) {
        printf("%c",arr[i]);
    }
    printf("\n");
}
 
int main() {
 
    //char* arr=(char*)malloc(sizeof(char)*1000000001);
    char arr[15];
 
    scanf("%s",arr);
 
    if(MOD) printf("strlen = %d\n",strlen(arr));
 
    sort(arr,0,strlen(arr)-1);
    invertPrt(arr);
    //printf("%s\n",arr);
 
 
 
    //free(arr);
 
    return 0;
}
 
 
 
</arr[right])></arr[r]?arr[l]:arr[r];></stdlib.h></string.h></stdio.h>
