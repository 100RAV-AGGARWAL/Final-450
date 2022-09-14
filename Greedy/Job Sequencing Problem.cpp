/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compare(Job a, Job b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, compare);
        
        int maxDeadline = INT_MIN;
        for(int i=0; i<n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> schedule(maxDeadline+1, -1);
        
        int jobs=0, profit=0;
        
        for(int i=0; i<n; i++) {
            int j = arr[i].dead;
            for( ; j>0; j--) {
                if(schedule[j] == -1) {
                    schedule[j] = arr[i].id;
                    jobs++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobs, profit};
    } 
};