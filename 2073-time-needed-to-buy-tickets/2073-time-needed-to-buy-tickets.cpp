

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int ke) {
        
        int n=tickets.size();

        int result=0;
int k=tickets[ke];
for(int i=0;i<n;i++){
if(i<=ke){

    result+=min(tickets[i],k);
}else{
    result+=min(tickets[i],k-1);
}
}
return result;
}

};

