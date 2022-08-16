
int minFlips (string S)
{
    // your code here
    string str1="", str2="";
    bool flag=true;
    
    for(int i=0; i<S.length(); i++) {
        if(flag) {
            str1 += "0";
            str2 += "1";
            flag = false;
        } else {
           str1 += "1";
            str2 += "0";
            flag = true; 
        }
    }
    
    int swap1=0, swap2=0;
    for(int i=0; i<S.length(); i++) {
        if(str1[i] != S[i]) swap1++;
        if(str2[i] != S[i]) swap2++;
    }
    
    return min(swap1, swap2);
}