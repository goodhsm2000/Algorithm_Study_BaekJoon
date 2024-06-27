// 목표지점까지의 거리 구하기
// 음 BFS 사용하면 될 듯
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void BFS();
queue<pair<int,int>> q;
int n, m;
int map[1001][1001];
int distances[1001][1001];
bool visited[1001][1001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;

    fill(map[0], map[n], 0);
    
    // C++에 distance라는 함수가 존재해서 distances를 사용해야함
    fill(distances[0], distances[n], -1);

    fill(visited[0], visited[n], false);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];   
            if (map[i][j] == 2){
                q.push(make_pair(i, j));
                distances[i][j] = 0;
                visited[i][j] = true;
            }

            if (map[i][j] == 0) 
                distances[i][j] = 0;
        }
    } 

    BFS();

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << distances[i][j] << " ";
        }
        cout << "\n";
    } 

    
}

void BFS() {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || visited[next_x][next_y] || map[next_x][next_y] == 0) 
                continue;

            // cout << next_x << next_y;
            q.push(make_pair(next_x, next_y));
            distances[next_x][next_y] = distances[x][y] + 1;
            visited[next_x][next_y] = true;
            }

    }
}
