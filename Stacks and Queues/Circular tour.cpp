/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int prev = 0, curr = 0, start = 0;
       
       for(int i=0; i<n; i++) {
           curr += p[i].petrol - p[i].distance;
           
           if(curr < 0) {
               prev += curr;
               curr = 0;
               start = i+1;
           }
       }
       
       return (prev+curr>0) ? start : -1;
    }
};