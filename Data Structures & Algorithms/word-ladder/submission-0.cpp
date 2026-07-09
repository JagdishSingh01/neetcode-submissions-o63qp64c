class Solution {
public:
    void words(string curr, int step, int i, unordered_set<string>& uset, queue<pair<string, int>>& q){
        string temp=curr;
        for(char ch='a'; ch<='z'; ch++){
            temp[i]= ch;
            if(uset.find(temp)!=uset.end()){
                uset.erase(temp);
                q.push({temp, step+1});
            }
        }
       
    }


    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string>uset(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({begin, 1});
        //everytime you push the data in the queue , you have to delete it from the set as well (it will work as the visited)
        uset.erase(begin);    
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==end) return step;
            for(int i=0; i<word.length(); i++){
                words(word, step, i, uset, q);
            }
        }
        return 0;
    }
};
