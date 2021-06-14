#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;

   while(t--)
   {
       int n;
       cin>>n;

       string str;
       cin>>str;

       int temp =-1;

       for(int i=0;i<n;i++)
         if(str[i]=='1')
            temp =i;

       if(temp==-1){
          cout<<n<<endl;
          continue;
       }

       int ans =(temp+1)*2;

       for(int i=0;i<n;i++){
          if(str[i]=='1'){
            temp =n-i;
            break;
          }
       }

       ans = max(ans,temp*2);

       cout<<ans<<endl;
   }
}
