#include<stdio.h>
#include<iostream>
using namespace std;

#define NEXT_L(x) (((x)*(2))+(1))
#define NEXT_R(x) (((x)*(2))+(2))
int getParent(int a) {
	if(a%2==0) 
		return a/2-1;
	else
		return a/2;
}
void swap(int* a, int* b) {
	int* temp = b;
	*b = *a;
	*a = *temp;
}

typedef struct heap{
	int arr[100];
	int end;
	int popCnt;
	heap() {
		for(int i=0;i<100;i++) 
			arr[0] = 0;
		end = 0;
		popCnt=-1;
	}
	void put(int a) {
		int curr = end++;
		arr[curr] = a;
		while(1) {
			if(curr == 0 ) 
				break;
			int rParent = getParent(curr);
			if(arr[rParent]<=arr[curr]) {
				break;
			}			
			swap(arr[rParent], arr[curr]);
			curr = rParent;
		}
	}
	void pop() {
		if(popCnt==-1) { // init END IDX Cpy
			popCnt = end-1;
		}
		swap(arr[0],arr[popCnt]);
		int curr = 0;
		while(1) {
			int lChild = NEXT_L(curr);
			int rChild = NEXT_R(curr);
			int child = (arr[lChild]<=arr[rChild])?lChild:rChild;
			if(child>=popCnt
				|| arr[child] >= arr[curr]) 
				break;
			else {
				swap(arr[child], arr[curr]);
				curr = child;
			}				
		}
		popCnt--;
	}
}H;

int main() {
	H h; 
	int in;
	while(1) {
		cin >> in;
		if(in==9) // 입력종료로 9를 변수로 둠
			break;
		h.put(in);
		
		// prt
		for(int i=0;i<h.end;i++) 
			cout<<h.arr[i]<<" ";
		cout<<endl;
	}

	cout<<"최소힙 구성 끝 정렬 시작"<<endl;
	while(1) {
		h.pop(); // 모든 팝이 수행되면 0~end까지 내림차순 정렬 완료

		// prt
		for(int i=0;i<h.end;i++) 
			cout<<h.arr[i]<<" ";
		cout<<endl;
		
		if(h.popCnt==-1)
			break;
	}

	return 0;
}
