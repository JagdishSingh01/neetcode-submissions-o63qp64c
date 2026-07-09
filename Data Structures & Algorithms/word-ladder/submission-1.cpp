class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({begin, 1});
        uset.erase(begin);
        while(!q.empty()){
            string word = q.front().first;
            int steps= q.front().second;
            q.pop();
            if(word==end) return steps;
            for(int i=0; i<word.length(); i++){
                string temp=word;
                for(char ch='a'; ch<='z'; ch++){
                    temp[i]=ch;
                    if(uset.find(temp)!=uset.end()){
                        uset.erase(temp);
                        q.push({temp,steps+1});
                    }
                }
            }
        }
        return 0;
    }

};
