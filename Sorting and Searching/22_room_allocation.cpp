#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

using CustomerData = tuple<int, int, int>;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    vector<CustomerData> customers(N);
    for (int i = 0; i < N; ++i) {
        int start_time, end_time;
        if (!(cin >> start_time >> end_time)) return;
        customers[i] = make_tuple(start_time, end_time, i); 
    }

    sort(customers.begin(), customers.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied_rooms;
    priority_queue<int, vector<int>, greater<int>> available_room_ids;

    vector<int> room_assignments(N);

    int max_rooms = 0; 
    int next_id = 1;   

    for (const auto& c : customers) {
        int start_time = get<0>(c);
        int end_time = get<1>(c);
        int original_index = get<2>(c);

        while (!occupied_rooms.empty() && occupied_rooms.top().first < start_time) {
            int freed_room_id = occupied_rooms.top().second;
            occupied_rooms.pop();
            available_room_ids.push(freed_room_id); 
        }

        int assigned_id;

        if (available_room_ids.empty()) {
            assigned_id = next_id++;
            max_rooms = max(max_rooms, assigned_id); 
        } else {
            assigned_id = available_room_ids.top();
            available_room_ids.pop();
        }

        room_assignments[original_index] = assigned_id;
        occupied_rooms.push({end_time, assigned_id});
    }

    cout << max_rooms << "\n";
    for (int id : room_assignments) {
        cout << id << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}