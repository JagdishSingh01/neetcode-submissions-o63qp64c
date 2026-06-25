class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>topo;
        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(auto p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(int neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};
