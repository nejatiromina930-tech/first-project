#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string myID;
    cin >> myID; 

    int n, K;
    cin >> n >> K;

    vector<vector<string>> buckets(K + 1);

    for (int i = 0; i < n; i++) {
        string studentID;
        int score;

        cin >> studentID >> score;
        buckets[score].push_back(studentID);
    }

    for (int score = K; score >= 1; score--) {
        for (const string& id : buckets[score]) {
            cout << id << '\n';
        }
    }

    return 0;
}