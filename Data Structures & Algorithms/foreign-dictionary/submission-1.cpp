class Solution {
public:
    string topoSort(vector<vector<int>>& adj, unordered_set<char>& chars){
        int n=26;
        vector<int>indegree(n,0);
        for(int i=0; i<n ; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }
    
        queue<int>q;
        for(char ch: chars){
            int node = ch-'a';  
            if(indegree[node]==0){
                q.push(node);
            }             
        }
        string res="";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(char(node+'a'));
            for(int neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                } 
            }
        }
        if(res.size()!=chars.size()){
            return "";
        }
        return res;
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        unordered_set<char>chars;
        for(string word: words){
            for(char ch : word){
                chars.insert(ch);
            }
        }
        for(int i=0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            bool foundDiff=false;
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    foundDiff=true;
                    break;
                }
            }
            if(!foundDiff && s1.length()>s2.length()) return "";
        }
        return topoSort(adj, chars);
    }
};
