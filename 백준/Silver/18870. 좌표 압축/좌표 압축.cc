#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int X[N] = {0,};

    vector<int> v;

    for (int i=0; i < N; i++) {
        cin >> X[i];

        v.push_back(X[i]);
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i=0; i < N; i++) {
        cout << distance(v.begin(), lower_bound(v.begin(), v.end(), X[i])) << " ";

    }

}