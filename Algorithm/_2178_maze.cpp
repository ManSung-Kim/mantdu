#include<iostream>
#include<cstdio>

using namespace std;

#define MAX 102
#define ST_R 1
#define ST_C 1

int MOD = 0; //TEST 출력용. 1이면 주석출력..
int arr[MAX+2][MAX+2];

#define DIRECT_NO 4
int dr[DIRECT_NO] = { 0,-1, 1, 0 }; // direction of Row. 좌,위,아래,오른쪽 순으로 푸시.. 그래서 팝하면 답에 근접한 오른,아래,위,좌 순으로 팝한다.
int dc[DIRECT_NO] = {-1, 0, 0, 1 }; // direction of Col.
						// 기준점으로부터 (0,-1), (-1,0), (1,0), (0,1) 을 for문을 통해 탐색하는 방식


struct node {
	int r;
	int c;
	//int data;
	int sum;
	node() {
		r=0;
		c=0;
		//data = 0;
		sum = 0;
	}
}; 

class stack {
private:
	node _stack[10000];
	int top;
public:
	stack() {
		top = -1;
	}
	void push(node data) {
		_stack[++top] = data;
	}
	node pop() {
		node n;
		if(top<0)
			return n;
		return _stack[top--];
	}
	node peek() {
		return _stack[top];
	}
	int getTopIdx() {
		return top;
	}
};

void init();
void getInput(int w, int h);
void prt();
void dfs(int destR, int destC);

int main(void) {
	int destR,destC;
	setbuf(stdout,NULL); // Runtime Err시 프로그램종료없이 이전버퍼의 쓰레기값을 출력해주는 api 함수 
	cin>>destR>>destC;
	init();	//배열 초기화
	getInput(destR,destC); //배열 받기
	dfs(destR,destC); // DFS탐색시작 => 알고리즘

	return 0;
}


void init() {
	for(int i=0;i<MAX+2;i++) {
		for(int j=0;j<MAX+2;j++) {
			arr[i][j] = 0;
		}
	}
}

void getInput(int w, int h) {
	char temp[100];
	for(int i=1;i<=w;i++) {
		cin >> temp;
		for(int j=1;j<=h;j++) {
			arr[i][j] = temp[j-1]-'0';
		}
	}
}

void prt() {
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=6;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}cout<<endl;

}

// DFS로 미로탐색을 함. 왜냐하면 최소거리를 구하려면 모든 길을 다 돌아다녀봐야함.
// 그런데 마냥 다 돌아다니면 Timeout뜨기때문에 무언가 처리를 해줘야함.
// 그것은 아래 소스의 "처리1" 과 "처리2"로 해결함.
void dfs(int destR, int destC) {
	stack s; //스택
	int r,c;
	r=ST_R; // 1
	c=ST_C; // 1
	
	// 아래의 n은 첫 시작 노드를 Push하기 위해 생성한 것
	node n;
	n.r = r;
	n.c = c;
	n.sum = 1;
	s.push(n);	
	int _max = 100000;
	int nextR;
		int nextC;
	while(1) {
		n = s.pop();
		if(MOD) cout<<n.r<<" "<<n.c<<endl;
		arr[n.r][n.c] = n.sum; // 처리1. 발자국을 남긴다.(현재 이동한 점까지의 거리)
		if(n.r==destR && n.c == destC) {
			if(n.sum<_max) {
				_max = n.sum;
			}
			continue;
		}

		
		// dx,dy를 사용한 탐색. 이 아래에 주석된 네가지 if문은 방향을 일일히 넣어준 것
		for(int i=0; i<DIRECT_NO; i++) {
			nextR = n.r + dr[i];
			nextC = n.c + dc[i];
			if( arr[nextR][nextC]==1 || (n.sum+1)<arr[nextR][nextC] ) { // 처리2. 이전발자국보다 크면 가지 않는다
				node n2;
				n2.r = nextR;
				n2.c = nextC;
				n2.sum = n.sum + 1;
				s.push(n2);
				if(MOD) cout<<"push"<<nextR<<","<<nextC<<endl;
			}
		}
		/*
		if(arr[n.r][n.c-1]==1 || (n.sum+1)<arr[n.r][n.c-1] ) {
		node n2;
		n2.r = n.r;
		n2.c = n.c-1;
		n2.sum = n.sum + 1;
		s.push(n2);
		if(MOD) cout<<"push"<<n.r<<","<<n.c-1<<endl;
		}
		if(arr[n.r-1][n.c]==1 ||(n.sum+1)<arr[n.r-1][n.c] ) {
		node n2;
		n2.r = n.r-1;
		n2.c = n.c;
		n2.sum = n.sum + 1;
		s.push(n2);
		if(MOD) cout<<"push"<<n.r-1<<","<<n.c<<endl;
		}

		if(arr[n.r+1][n.c]==1 || (n.sum+1)<arr[n.r+1][n.c] ) {
		node n2;
		n2.r = n.r+1;
		n2.c = n.c;
		n2.sum = n.sum + 1;
		s.push(n2);
		if(MOD) cout<<"push"<<n.r+1<<","<<n.c<<endl;
		}
		if(arr[n.r][n.c+1]==1 || (n.sum+1)<arr[n.r][n.c+1] ) {
		node n2;
		n2.r = n.r;
		n2.c = n.c+1;
		n2.sum = n.sum + 1;
		s.push(n2);
		if(MOD) cout<<"push"<<n.r<<","<<n.c+1<<endl;
		}
		*/
		if(MOD) prt();

		if(s.getTopIdx()==-1) {
			//cout<<n.r<<" "<<n.c<<endl;
			break;
		}
	}
	cout<<_max<<endl;
}
