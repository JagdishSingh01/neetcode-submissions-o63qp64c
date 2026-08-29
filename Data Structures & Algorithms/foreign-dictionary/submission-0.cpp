class Solution {
public:
    string topoSort(vector<vector<int>>& adj, vector<bool>& present){
        int n=26;
        vector<int>indegree(n,0);
        for(int i=0; i<n ; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
            
        }
        int totalChars = 0;
        queue<int>q;
        for(int i=0; i<n;i++){
            if(present[i]){
                totalChars++;
                if(indegree[i]==0){
                    q.push(i);
                } 
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
        if(res.size()!=totalChars){
            return "";
        }
        return res;
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<bool>present(26, false);
        for(string word: words){
            for(char ch : word){
                present[ch - 'a'] = true;
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
        return topoSort(adj, present);
    }
};
