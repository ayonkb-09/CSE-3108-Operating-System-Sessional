#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Number of processes: ";
    cin >> n;

    int id[n], arrival[n], burst[n], completion[n], waiting[n], turnaround[n], order[n], done[n] = {0};

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        cout << "Enter Arrival time & Burst time for P" << i + 1 << ": ";
        cin >> arrival[i] >> burst[i];
        order[i] = i;
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival[order[i]] > arrival[order[j]] ||
               (arrival[order[i]] == arrival[order[j]] && id[order[i]] > id[order[j]])) {
                swap(order[i], order[j]);
            }
        }
    }

    int currentTime = 0, totalWT = 0, totalTAT = 0, totalCT = 0;
    int completed = 0;

    while (completed < n) {
        int index = -1, minBurst = INT_MAX;


        for (int i = 0; i < n; i++) {
            if (!done[order[i]] && arrival[order[i]] <= currentTime) {
                if (burst[order[i]] < minBurst) {
                    minBurst = burst[order[i]];
                    index = order[i];
                }
            }
        }


        if (index == -1) {
            currentTime++;
            continue;
        }


        completion[index] = currentTime + burst[index];
        turnaround[index] = completion[index] - arrival[index];
        waiting[index] = turnaround[index] - burst[index];

        totalCT += completion[index];
        totalWT += waiting[index];
        totalTAT += turnaround[index];

        currentTime = completion[index];
        done[index] = 1;
        completed++;
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << id[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completion[i] << "\t" << turnaround[i] << "\t" << waiting[i] << endl;
    }

    cout << "\nAverage Completion Time: " << (double)totalCT / n << endl;
    cout << "Average Turnaround Time: " << (double)totalTAT / n << endl;
    cout << "Average Waiting Time: " << (double)totalWT / n << endl;

    return 0;
}