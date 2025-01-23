#include <iostream> // #2164 카드2_연결 리스트 STL
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> li;
    for(int i=1; i<=n; i++) {
        li.push_back(i);
    }

    while(li.size() != 1) { // li.size() > 1로 해도 됨
        li.pop_front();
        li.push_back(li.front());
        li.pop_front();
    }
    cout << li.back(); // li.front() 도 가능
    return 0;
}
////////////////////////////////////////////////////////////////
#include <iostream> // #2164 카드2_큐
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    queue<int> que;    
    for(int i=1; i<=n; i++)
        que.push(i);
    
    while(que.size() > 1){
        que.pop();
        que.push(que.front());
        que.pop();
    }
    
    cout << que.front();
    return 0;
}
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front, rear, size;
} Queue;

void initQueue(Queue *q, int size) {
    q->data = (int *)malloc(sizeof(int) * size); 
    q->front = 0;
    q->rear = 0;
    q->size = size;
}

void enqueue(Queue *q, int value) {
    q->data[q->rear] = value;  
    q->rear = (q->rear + 1) % q->size; 
}

int dequeue(Queue *q) {
    int value = q->data[q->front]; 
    q->front = (q->front + 1) % q->size;
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("1\n");
        return 0;
    }

    Queue q;
    initQueue(&q, N);

    for (int i = 1; i <= N; i++) {
        enqueue(&q, i);
    }

    while (q.front != q.rear - 1) { 
        dequeue(&q);

        int topCard = dequeue(&q);
        enqueue(&q, topCard);
    }

    printf("%d\n", dequeue(&q));

    return 0;
}