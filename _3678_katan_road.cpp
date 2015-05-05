#include<iostream>
using namespace std;

#define TEST 1
#define MAX 10002
#define MAX_CARD 5
#define MAX_FRIEND 6

int arr[MAX][2];
int card[MAX_CARD+1]; // 1,2,3,4,5

int getMin(int first, int last, int firstBeforeData) {
	int min = 999999;
	int minIdx = MAX_CARD;
	for(int i=MAX_CARD;i>=1;i--) {
		if(i==first || i==last) 
			continue;
		if(firstBeforeData==i) { // fisrt ptr이 옮겨진 상태, 이전first도 뛰어넘어야함
			continue;
		}
		if(card[i]<=min) {
			minIdx = i;
			min = card[i];
		}
	}
	return minIdx;
}

void road(int idx) {
	if(idx == 1) {
		cout<<1<<endl;
		return;
	}
	if(idx == 2) {
		cout<<2<<endl;
		return;
	}

	//cout<<1<<endl<<2<<endl;
	int first = 1;
	int curr = first + 2;
	for(int i=3;i<=idx;i++) {

		// . last ++
		arr[curr-1][0]++; // 직전 노드의 인접 노드 갯수 +1

		// . curr ++
		arr[curr][0]+=2; // 새로 추가한 노드는 인접한게 2개 추가됨

		// . first++
		arr[first][0]++; // 중앙 노드의 인접 노드 개수 +1
		int firstBeforeData = 0;
		if(arr[first][0]==MAX_FRIEND) { // MAX인접노드인 6이 되면 
			firstBeforeData= arr[first][1]; // 중앙노드의 포인터(라고하자)를 옮기기 전에 값 복사
			first++; // 중앙노드 포인터 옮기기
			arr[curr][0]++; // 한 사이클이 끝나면서 마지막 노드의 인접노드 +1
			arr[first][0]++; // 새로 옮겨진 노드 역시 +1되야지 이전 중앙노드기준으로 모든 면이 기록된다.
		}

		// . define curr node data
		int nodeData = getMin(arr[first][1], arr[curr-1][1], firstBeforeData); // 1~5카드중 최소 조건 카드 고르기
		arr[curr][1] = nodeData; // 골라진 카드를 배열에 기록
		card[nodeData]++; // 카드 고른횟수 +1

		//cout<<arr[curr][1]<<endl;
		curr++;	// 다음 노드로 진행
		
	}
	cout<<arr[curr-1][1]<<endl;
	
}

void init() {
	for(int i=0;i<MAX;i++) {
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
	for(int i=0;i<6;i++) {
		card[i] = 0;
	}

	arr[1][0]=1;
	arr[1][1] = 1;
	arr[2][0]=1;
	arr[2][1] = 2;

	card[1]++;
	card[2]++;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int roadIdx;
		cin>>roadIdx;
		init();
		road(roadIdx);
	}
	return 0;
}
