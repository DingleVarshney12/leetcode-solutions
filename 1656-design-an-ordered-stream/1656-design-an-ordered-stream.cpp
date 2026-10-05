class OrderedStream {
    vector<string> stream;
    int ptr;

public:
    OrderedStream(int n) {
        stream.resize(n + 1);
        ptr = 1;
    }
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> output;
        if (ptr == idKey) {
            int i = ptr;
            for (; i < stream.size(); i++) {
                if (stream[i] == "") {
                    break;
                };
                output.push_back(stream[i]);
            }
            ptr = i;
        }
        return output;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */