class Solution {

#define f(i,a,n) for(int i = a; i < n; i++)
#define min_heap(type) priority_queue<type,vector<type>,greater<type>>

    int k;
    int getServerId(int i){
        return i % k;
    }

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        this->k = k;
        int n = arrival.size();
        set<int> servers;
        f(i,0,k) servers.insert(i);

        using ServerType = pair<int,int>; // {finishTime, serverId}
        min_heap(ServerType) busy;

        vector<int> requestOnServer(k,0);
        
        f(i,0,n){
            int time = arrival[i];

            while(!busy.empty() && busy.top().first <= time){
                auto [_, serverId] = busy.top();
                busy.pop();
                servers.insert(serverId);
            }

            int targetServer = getServerId(i);
            auto it = servers.lower_bound(targetServer);
            if(it == servers.end()) it = servers.begin();
            if(servers.empty()) continue;

            int serverId = *it;
            servers.erase(serverId);
            busy.emplace(time + load[i], serverId);
            requestOnServer[serverId]++;
        }

        int maximumRequests = *max_element(begin(requestOnServer),end(requestOnServer));
        vector<int> BusiestServers;
        f(i,0,k) if(requestOnServer[i] == maximumRequests) BusiestServers.push_back(i);

        return BusiestServers;

    }
};