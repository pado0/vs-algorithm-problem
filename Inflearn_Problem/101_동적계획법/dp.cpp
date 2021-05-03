/*
# 다이나믹프로그래밍이란?
- 문제가 너무 복잡해서 작은 단위의 문제 먼저 풀고,
- 그 문제를 메모이제이션(저장) 해두고
- 점점 더 큰 문제를 푸는 것 : bottom up 방식
-> 점화식과 같은 원리

# 문제
네트워크 선을 자르려 하는데,
이를 1, 2m 길이로 자르려 한다.
선이 총 Nm라면 몇 가지 자르는 방법을 생각할 수 있을까?

1)원래같았으면 dfs로 1, 2미터 자르는 경우로 계속 들어갈듯
2)N짜리 배열을 만들어, 각 배열 인덱스에 해당 길이에 해당하는
  방법 수를 적는다. 
  직관적으로 답을 알 수 있는건 답을 채우고 시작한다.
  점화식을 알아내는게 중요하다

  1m : 1
  2m : 2 (1,1 & 2)
  3m: 3 
      맨 마지막을 1로 토막내면 2m랑 같음 (1,1,1), (2,1)
      맨 마지막을 2로 토막내면 1m랑 같음, (1,2)

  4m: 맨마지막 1로 토막시 3m랑 같음 3가지 
      맨마지막 2로 토막시 2m랑 같음 2가지

  즉, f(n)= f(n-2) +f(n-1)	  

 */



#include <iostream>
using namespace std;
int dy[50]; // dp 답 넣는 배열

int main() {
	ios_base::sync_with_stdio(false); // cin , cout만 쓸 수 있음
	cin.tie(NULL);
	
	int n;
	cin >> n; // nw선의 길이
	
	dy[1] = 1;
	dy[2] = 2;

	for (int i = 3; i <= n; i++) {
		dy[i] = dy[i - 2] + dy[i - 1];
	}
	cout << dy[n];
	
	return 0;
}