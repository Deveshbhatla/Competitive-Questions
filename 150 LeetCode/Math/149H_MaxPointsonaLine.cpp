//Given an array of points where points{i} = {xi, yi} represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// Input: points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}
// Output: 4


#include<bits/stdc++.h>
using namespace std;

    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;

        for(int i=0;i<points.size()-1;i++)
        {
            // mp of <slope,point> for each point we want new map to declare.
            unordered_map<double,int>mp;
            for(int j=i+1;j<points.size();j++){
                // if x cordinates are same then slope will be infinite .
                if(points[i][0] == points[j][0])
                {
                    mp[99999999]++;
                
                }
                else
                {
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            // now we have slopes for each points store in map.
            // count the maximum points .
            int temp=0;
            for(auto x:mp)
            {
                temp = max(temp,x.second);
            }
            // temp store max points with same slope with respect to point i.
            // store the maximum value in ans.
            // total points in line will be temp+1 as 1 for the ith point also.
            ans = max(ans,temp+1);
        }
        
        return ans;

    }



int main()
{
    vector<vector<int>> nums = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout<<maxPoints(nums)<<" ";

    return 0;

}