class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int m=temperatures.length;
        int [] ngt=new int[m];
        Stack<Integer> st=new Stack<>();


        for(int i=m-1;i>=0;i--){
            while(!st.isEmpty()&&temperatures[st.peek()]<=temperatures[i]){

                st.pop();
            }
            if(st.isEmpty()){
                ngt[i]=i;
            }
            else{
                ngt[i]=st.peek();
            }
            st.push(i);

        }
        for(int i=0;i<m;i++){
            ngt[i]=ngt[i]-i;
        }
        return ngt;
    }
}
