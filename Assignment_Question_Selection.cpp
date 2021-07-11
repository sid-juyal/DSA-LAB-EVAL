#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second==b.second)
    {
        return a.first/a.second < b.first/b.second;
    }
    return a.second>b.second;
}
int main()
{
    int min_marks,stud,n;
    cin>>min_marks>>stud>>n;
    int a[stud];
    for(int i=0;i<stud;i++)
    {
        cin>>a[i];
    }
    int mat[n][3];
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int max_score,sub_parts;
        cin>>max_score>>sub_parts;
        mat[i][0]=max_score;
        mat[i][1]=sub_parts;
        mat[i][2]=i+1;
        v.push_back(make_pair(max_score,sub_parts));
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> ans[stud];
  /*  for(int m=0;m<n;m++)
    {
        cout<<mat[m][0]<<" "<<mat[m][1]<<" "<<mat[m][2];
        cout<<endl;
    }

    for(int q=0;q<v.size();q++)
    {
        cout<<v[q].first<<" "<<v[q].second;
        cout<<endl;
    }
*/
    for(int i=0;i<stud;i++)
    {
        //int count=0;
        int temp=a[i];
        int j=0;
        while(temp<min_marks)
        {
            //count++;
            temp+=v[j].first;
            for(int z=0;z<n;z++)
            {
                if(mat[z][0]==v[j].first && mat[z][1]==v[j].second)
                {
                    ans[i].push_back(mat[z][2]);
                }
            }
            //ans[i].push_back(v[j].first);
            j++;
        }
        sort(ans[i].begin(),ans[i].end());
        cout<<ans[i].size()<<" ";
        for(int q=0;q<ans[i].size();q++)
        {
            cout<<ans[i][q]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
