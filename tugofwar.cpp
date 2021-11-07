#include<bits/stdc++.h>
using namespace std;
int n,a,sum=0,min_diff=INT_MAX;
vector<int>v;
vector<bool>sol;
vector<bool>curr;
void tugofwar(int curr_sum,int curr_position,int no_of_selected)
{
  if(curr_position==n)
  return;
  if((n/2-no_of_selected)>(n-curr_position))
  return;
  tugofwar(curr_sum,curr_position+1,no_of_selected);
  no_of_selected++;
  curr_sum+=v[curr_position];
  curr[curr_position]=true;
  if(no_of_selected==n/2)
  {
    if(abs(sum/2-curr_sum)<min_diff)
    {
      min_diff=abs(sum/2-curr_sum);
      for(int i=0;i<n;i++)
      sol[i]=curr[i];
    }
  }else
  {
    tugofwar(curr_sum,curr_position+1,no_of_selected);
  }curr[curr_position]=false;
}
int main()
{
  cout<<"Enter number of elements-";
  cin>>n;
  curr.assign(n,false);
  sol.assign(n,false);
  for(int i=0;i<n;i++)
  {
    cin>>a;
    v.push_back(a);
    sum+=a;
  }tugofwar(0,0,0);
  cout<<"The first subset is: ";
    for(int i=0;i<n;i++)
    {
        if(sol[i]==true)
            cout<<v[i]<<" ";
    }
    cout<<"\nThe second subset is: ";
    for(int i=0;i<n;i++)
    {
        if(sol[i]==false)
            cout<<v[i]<<" ";
    }
}
