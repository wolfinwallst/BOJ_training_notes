#include <iostream> // #13335 트럭_큐
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, w, l;
    cin >> n >> w >> l;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    queue<int> q;  // 다리 위에 있는 트럭을 표현하기 위한 큐
    int t = 0, wSum = 0; // 걸리는 시간, 다리 위 트럭들 무게 합
    for(int i=0; i<n; i++) {  // 트럭 하나씩 처리
        while(true) { // 현재 트럭이 다리 위에 올라갈 수 있을 때까지 반복
            if(q.size() == w) {
                wSum -= q.front();
                q.pop();
            }

            if(wSum + a[i] <= l) break;

            q.push(0); // 다리 위 공간 채우기(트럭이 올라올 수 있을 때까지 대기)
            t++;
        }
        q.push(a[i]); // 현재 트럭을 다리 위로 올림
        wSum += a[i];
        t++;
    }

    cout << t + w; // w는 마지막 트럭 이동에 걸리는 시간
    return 0;
}
///////////////////////////////////////////////////////////////////
/*
주석 설명이 full로 추가된 버전_위와 코드는 동일
*/
#include <iostream> // #13335 트럭_큐
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, w, l;  // n: 트럭 수, w: 다리 길이, l: 다리 최대 하중
    cin >> n >> w >> l;

    vector<int> a(n); // 트럭들의 무게를 저장할 벡터
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    queue<int> q;  // 다리 위에 있는 트럭을 표현하기 위한 큐
    int t = 0, wSum = 0; // t: 총 걸리는 시간, wSum: 다리 위 트럭들의 무게 합

    for(int i=0; i<n; i++) {  // 모든 트럭을 하나씩 처리
        while(true) {  // 현재 트럭이 다리 위에 올라갈 수 있을 때까지 반복
            if(q.size() == w) {  // 다리 길이(w)만큼 트럭이 차 있으면
                wSum -= q.front();  // 맨 앞(출구)의 트럭 무게를 제거 (다리에서 나감)
                q.pop();  // 큐에서 트럭 제거
            }
            
            if(wSum + a[i] <= l) break;  // 현재 트럭을 더 올릴 수 있으면 반복문 종료

            q.push(0);  // 다리 위 공간 채우기(트럭이 올라올 수 있을 때까지 대기)
            t++;  // 시간 증가 (트럭이 이동하는 시간)
        }
        
        q.push(a[i]);  // 현재 트럭을 다리 위로 올림
        wSum += a[i];  // 다리 위 무게 합에 추가
        t++;  // 트럭이 이동한 시간 증가
    }

    cout << t + w;  // 모든 트럭이 다리를 지나가는 데 걸리는 총 시간 출력
                    // 마지막 트럭이 다리를 완전히 지나가는 데 w 시간이 더 걸림
    return 0;
}

/////////////////////////////////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, w, l;
    cin >> n >> w >> l;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    queue<int> q;  
    int t = 0, wSum = 0; 
    for(int i=0; i<n; i++) {  
        while(true) { 
            if(q.size() == w) {
                wSum -= q.front();
                q.pop();
            }

            if(wSum + a[i] <= l) break;

            q.push(0); 
            t++;
        }
        q.push(a[i]); 
        wSum += a[i];
        t++;
    }

    cout << t + w; 
    return 0;
}
///////////////////////////////////////
// 프로그래머스에 있는 똑같은 문제
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q; // 다리 위 트럭 무게를 담는 큐
    int t = 0, wSum = 0;
    
    for(int i=0; i<truck_weights.size(); i++) {
        while(true) {
            if(q.size() == bridge_length) {
                wSum -= q.front();
                q.pop();
            }

            if(truck_weights[i] + wSum <= weight) break;

            q.push(0);
            t++;
        }
        
        q.push(truck_weights[i]);
        wSum += truck_weights[i];
        t++;
    }
    
    answer = t + bridge_length;
    return answer;
}
///////////////////////////////////////////////////////////
#include <stdio.h>
int main(){
    int i, n, w, l;
    scanf("%d %d %d\n", &n, &w, &l);
    int front=0, l_hap=0, queue[1001], time=0, cnt=0;
    //  cnt: 다리 위에있는 트럭의 수, front: 다리를 막 빠져나간 트럭
    int remain_time[1001]={0}; // 다리에서 남은 시간
    for(i=0; i<n; i++) scanf("%d ", &queue[i]);
    
    while(front < n){
        time++;
        for(i=front; i<front+cnt; i++){  //front+cnt: 다음에 올라갈 예정인 트럭
            remain_time[i]--;
            if (remain_time[i] == 0) {   //방금 그 트럭이 다리를 다 건넘
                l_hap=l_hap-queue[i];
                front++;
                cnt--;
            }            
        }  // 다리위에 있는 트럭 수는 무조건 w보다 작아야함 && 다음에 올릴 트럭이 있어야함 && 다리 무게 제한
        if (cnt<w && front+cnt<n && l_hap+queue[front+cnt]<=l) {
            remain_time[front+cnt]=w;  // 건널 시간 w초
            l_hap+=queue[front+cnt];
            cnt++;
        } // 다리 위에 트럭이 올라감
    }        
    printf("%d", time);
}