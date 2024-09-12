class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        int i = 0;
        int n = path.size();

        while(i < n) {

            while(i < n && path[i] == '/') i++;
            if(i == n) break;

            string s = "";
            while(i < n && path[i] != '/') {
                s += path[i];
                i++;
            }

            i++;

            if(s == ".") continue;
            else if(s == "..") {
                if(!dq.empty())
                    dq.pop_back();
            }
            else dq.push_back(s);
        }
        
        if(dq.empty()) return "/";

        string result = "";

        while(!dq.empty()) {
            result += "/" + dq.front();
            dq.pop_front();
        }

        return result;
    }
};