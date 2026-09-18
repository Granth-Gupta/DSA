#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int burst_time; 
    int arrival_time; 
    int waiting_time; 
    int turnaround_time; 
};

bool compareArrivalTime(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

bool compareBurstTime(Process a, Process b) {
    return a.burst_time < b.burst_time;
}

int main() {
    int n; 
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    // To input process details
    for (int i = 0; i < n; i++) {
        cout << "Enter details of process " << i+1 << ":" << endl;
        cout << "PID: ";
        cin >> processes[i].pid;
        cout << "Arrival time: ";
        cin >> processes[i].arrival_time;
        cout << "Burst time: ";
        cin >> processes[i].burst_time;
    }

    // sort processes by arrival time
    sort(processes, processes+n, compareArrivalTime);

    int current_time = 0;
    int total_waiting_time = 0; 
    int total_turnaround_time = 0;
    cout << "Gantt Chart:" << endl;
    for (int i = 0; i < n; i++) {
        // sort processes by burst time until arrival time of the next process
        sort(processes+i, processes+n, compareBurstTime);
        while (i < n-1 && processes[i+1].arrival_time <= current_time) {
            i++;
            sort(processes+i, processes+n, compareBurstTime);
        }

        // process current process
        cout << current_time << "-" << current_time+processes[i].burst_time << " P" << processes[i].pid << " "<<endl;

        // update waiting time and turnaround time
        if (processes[i].arrival_time > current_time){
            processes[i].waiting_time = 0;
        }
        else {
            processes[i].waiting_time = current_time - processes[i].arrival_time;
        }
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        cout<<"Waiting time "<<" "<<processes[i].waiting_time << endl;
        cout<<"Turnaround time "<<" "<<processes[i].turnaround_time << endl;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        // update current time
        current_time += processes[i].burst_time;
    }

    cout << endl;
    cout << "Average waiting time: " << (double)total_waiting_time/n << endl;
    cout << "Average turnaround time: " << (double)total_turnaround_time/n << endl;
    return 0;
}

