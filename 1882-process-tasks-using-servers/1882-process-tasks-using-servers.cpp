class Solution {
using FreeServerType = pair<int,int>;
using BusyServerType = tuple<long,int,int>;
#define f(i,a,n) for(int i = a; i < n; i++)
#define min_heap(type) priority_queue<type,vector<type>,greater<type>>
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int s = servers.size(), t = tasks.size();

        min_heap(FreeServerType) freeServer;
        min_heap(BusyServerType) busyServer;

        f(i,0,s) freeServer.emplace(servers[i],i);

        vector<int> ans(t);

        f(i,0,t){
            while(!busyServer.empty() && get<0>(busyServer.top()) <= i){
                auto [finishTime,weight,idx] = busyServer.top();
                busyServer.pop();
                freeServer.emplace(weight,idx);
            }
            if(!freeServer.empty()){
                auto [weight,idx] = freeServer.top();
                freeServer.pop();
                ans[i] = idx;
                busyServer.emplace(i + tasks[i], weight, idx);
            }else{
                auto [finishTime,weight,idx] = busyServer.top();
                busyServer.pop();
                ans[i] = idx;
                busyServer.emplace(finishTime + tasks[i],weight,idx);
            }
        }
        return ans;  
    }
};