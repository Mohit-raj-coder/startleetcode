class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      
      std::queue<int>q;
      for(int num:students){
        q.push(num);
      }
int count=0;
int ind=0;


while(!q.empty() && count<q.size()){
if(q.front()== sandwiches[ind]){
q.pop();
ind++;
count=0;
}else{
   
q.push(q.front());
q.pop();
count+=1;
}
}

return q.size();
}


        
};
