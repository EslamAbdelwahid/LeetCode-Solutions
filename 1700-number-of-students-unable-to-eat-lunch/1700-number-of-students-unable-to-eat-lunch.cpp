class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int one = 0, zero = 0;
        for(auto &i : students){
            one += (i == 1);
            zero += (i == 0);
            q.push(i);
        }
        int n = sandwiches.size(), i = 0;
        while(i < n){
            if((sandwiches[i] == 0 && !zero) || (sandwiches[i] == 1 && !one))  return q.size();
            int tp = q.front(); q.pop();
            if(sandwiches[i] != tp) q.push(tp);
            else{
                ++i;
                if(tp == 1) --one;
                else --zero;
            }
        }
        return 0;
    }
};