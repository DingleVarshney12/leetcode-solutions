class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int totalCustomers = customers.size();
        long long totalWaitingTime = 0;
        long long starts = 0;
        for (auto& customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            starts = max(starts, (long long)arrival) + time;
            totalWaitingTime += starts - arrival;
        }
        return static_cast<double>(totalWaitingTime) / totalCustomers;
    }
};