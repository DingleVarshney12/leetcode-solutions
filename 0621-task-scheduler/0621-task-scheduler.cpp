class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        priority_queue<int> max_heap;
        int answer=0;

        //calculate frequency of character
        for(auto ch:tasks){
            freq[ch - 'A']++;
        }
        //store it in max heap
        for(auto f: freq){
            if(f > 0) max_heap.push(f);
        }
        while(!max_heap.empty()){
            queue<int> waiting_queue;
            int cycle = n +1;
            while(cycle > 0 && !max_heap.empty()){
                int freq = max_heap.top();
                max_heap.pop();
                freq--;
                if(freq > 0) waiting_queue.push(freq);
                cycle--;
                answer++;

            }
            while(!waiting_queue.empty()){
                int front = waiting_queue.front();
                max_heap.push(front);
                waiting_queue.pop();
            }

            if(!max_heap.empty()){
                answer +=cycle;
            }
        }
        return answer;        
    }
};