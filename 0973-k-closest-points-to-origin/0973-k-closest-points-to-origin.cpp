class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> max_heap;
        for(int i =0 ;i < points.size();i++){
            int distance = points[i][0]*points[i][0] +points[i][1]* points[i][1];

            max_heap.push({distance,i});
            if(max_heap.size() > k) max_heap.pop();
        }
        while(!max_heap.empty()){
            ans.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }
        return ans;
    }
};