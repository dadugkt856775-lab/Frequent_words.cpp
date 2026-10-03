#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<int, string>& a,
                    const pair<int, string>& b) {

        if (a.first != b.first)
            return a.first < b.first;

        return a.second > b.second;
    }
};

int main() {
    vector<string> words = {
        "i", "love", "leetcode",
        "i", "love", "coding"
    };

    int k = 2;

    unordered_map<string, int> freq;

    for (string word : words)
        freq[word]++;

    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        Compare
    > pq;

    for (auto& p : freq)
        pq.push({p.second, p.first});

    cout << "Top " << k << " Frequent Words: ";

    while (k-- && !pq.empty()) {
        cout << pq.top().second << " ";
        pq.pop();
    }

    return 0;
}
