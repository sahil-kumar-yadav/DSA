long long int floorSqrt(long long int n) {
        if(n<=1) return n;
        // Your code goes here
        if(n==0 || n==1) return n;
          int left=0,right=n/2;
          long long int ans;
          while(left<=right)
          {
              long long int mid=(left+right)/2;
              if(mid*mid==n) return mid;
              else if(mid*mid<=n){
                  left=mid+1;
                  ans=mid;
              }
              else{
                  right=mid-1;
              }
          }
          return ans;
    }