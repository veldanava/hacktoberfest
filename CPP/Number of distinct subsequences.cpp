//=========Question================
// Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
// Note: Answer can be very large, so, ouput will be answer modulo 109+7.

// Example 1:

// Input: 
// s = "gfg"
// Output: 
// 7
// Explanation: 
// The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
// Example 2:

// Input: 
// s = "ggg"
// Output: 
// 4
// Explanation: 
// The four distinct subsequences are "", "g", "gg", "ggg".
// Your task:
// You do not need to read any input or print anything. The task is to complete the function distinctSubsequences(), which takes a string as input and returns an integer.

// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 ≤ |s| ≤ 105
// s contains lower case English alphabets

// =================Solution==============


#include <bits/stdc++.h>
using namespace std;



class Solution{
  public:
  int mod = 1000000007;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    
	    vector<int> arr(26,-1);
	    long ans = 0;
	    long diff = 0;
	    
	    for(int i =0;i<n;i++){
	        int x = s[i] - 'a';
	        if(i==0){
	            ans =1;
	            arr[x]=1;
	            continue;
	        }
	        
	        diff =ans+1;
	        
	        if(arr[x]==-1){
	            ans = (ans+diff)%mod;
	        }else{
	            ans = (ans+diff-arr[x])%mod;
	        }
	        arr[x]=diff;
	    }
	    
	    ans+=1;
	    
	    return (int)(ans<0?ans+mod:ans);
	}
};



int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
