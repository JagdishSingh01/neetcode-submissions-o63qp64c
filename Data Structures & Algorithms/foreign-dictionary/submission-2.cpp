class Solution {
public:
    string topoSort(vector<vector<int>>& adj, vector<bool>& exists){
        vector<int>indegree(26,0);
        for(int i=0; i<adj.size(); i++){
            for(int node: adj[i]){
                indegree[node]++;
            }
        }
        queue<int>q;
        int totalChar=0;
        for(int i=0; i<26; i++){
            if(exists[i]){
                totalChar++;
                if(indegree[i]==0) q.push(i);
            }
        }
        string res = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node + 'a');
            for(int neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
                
            }
        }
        if(res.size()!= totalChar){
            return "";
        }
        return res;
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<bool>exists(26,false);
        for(string word: words){
            for(char ch: word){
                exists[ch-'a']=true;
            }
        }
        for(int i=0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            bool foundDiff=false;
            for(int j=0; j<len; j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    foundDiff= true;
                    break;
                }
            }
            if(!foundDiff && s1.length()>s2.length()) return "";
        }
        return topoSort(adj, exists);
    }
};
