#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

class cpu {
public:
    int process_num; int arrival_time;int brust_time; int completion_time = 0; int turn_around_time = 0;int waiting_time = 0; int bt;
    bool done = false;
};
int32_t main() {
    int n;
    cin >> n;
    vector<cpu> algo(n);
    for (int i = 0; i < n; ++i) {
        algo[i].process_num = i + 1;
        cin >> algo[i].arrival_time;
        cin >> algo[i].brust_time;
        algo[i].bt = algo[i].brust_time;
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.arrival_time < b.arrival_time;
    });
    int cnt = 0, waiting_time = 0, c = 0;
    int q;cin >> q;
    queue<int> prev;
    int index = 0;
    while (index < n && algo[index].arrival_time <= cnt) {
        prev.push(index); index++;
    }
    while (!prev.empty()) {
        int i = prev.front();prev.pop();
        int executeTime = min(q, algo[i].bt); cnt += executeTime;algo[i].bt -= executeTime;
        if (algo[i].bt == 0) {
            algo[i].completion_time = cnt;
            algo[i].done = true;
        }
        while (index < n && algo[index].arrival_time <= cnt) {
            prev.push(index);
            index++;
        }
        if (algo[i].bt > 0) {
            prev.push(i);
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        algo[i].turn_around_time = algo[i].completion_time - algo[i].arrival_time;
        algo[i].waiting_time = algo[i].turn_around_time - algo[i].brust_time;
        a += algo[i].turn_around_time;
        b += algo[i].waiting_time;
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.process_num < b.process_num;
    });
    for (int i = 0; i < n; ++i) {
        cout << "p" << algo[i].process_num << ' ' << algo[i].arrival_time << ' ' << algo[i].brust_time << ' ' << algo[i].completion_time << ' ' << algo[i].turn_around_time << ' ' << algo[i].waiting_time << nl;
    }
    if (waiting_time > 0) {
        cout << "CPU was free for " << waiting_time << " period time\n";
    }
    cout << nl;
    cout << "Average Turn Around Time = " << (float)a / n << nl;
    cout << "Average Waiting Time = " << (float)b / n << nl;
}
