#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INFIN 100000

using namespace std;

void Dijkstra(int);

int N, M, X;

vector<pair<int, int>> weight[1001];
int dist[1001];
int result[1001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    int start, end, T;

    for (int i=0; i<M; i++) {
        cin >> start >> end >> T;
        weight[start].push_back(make_pair(T, end));
    }

    Dijkstra(X);
    copy(dist, dist+N+1, result);

    for (int i=1; i<=N; i++) {
        Dijkstra(i);
        result[i] += dist[X];
    }

    int max = -1;
    for (int i=1; i<=N; i++) {
        if (result[i] > max) 
            max = result[i];
    }

    cout << max;

}

void Dijkstra(int s_node) {

    fill(dist, dist + N +1, INFIN);

    // 내림차순 정렬, <자료형, 구현체, 비교연산자>
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, s_node));
    dist[s_node] = 0;

    while(!pq.empty()) {
        int min_dis = pq.top().first;
        int min_idx = pq.top().second;

        pq.pop();

        if (dist[min_idx] < min_dis)
            continue;

        for(int i=0; i<weight[min_idx].size(); i++) {
            int near_idx = weight[min_idx][i].second;
            int update_dis = min_dis + weight[min_idx][i].first;
            if (update_dis < dist[near_idx] ) {
                dist[near_idx] = update_dis;
                pq.push(make_pair(update_dis, near_idx));
            }
        }   
    }

}