#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int num;
    cin >> num;

    
    vector<pair<int, int>> tasks;

   
    for (int i = 0; i < num; i++) {
        int a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    
    sort(tasks.begin(), tasks.end());

    long long c_time = 0;   
    long long t_reward = 0;   


    for (int i = 0; i < num; i++) {
        int duration = tasks[i].first;
        int deadline = tasks[i].second;

        c_time += duration;          
        t_reward += (deadline - c_time);  
    }


    cout << t_reward << endl;

    return 0;
}
