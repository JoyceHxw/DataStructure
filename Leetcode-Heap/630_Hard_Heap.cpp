#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        //优先队列，最大堆
        //按结束时间排序，依次学习
        sort(courses.begin(),courses.end(),[](vector<int>& course1, vector<int>& course2){
            return course1[1]<course2[1];
        });
        priority_queue<int> q;
        int total=0;
        for(auto& course: courses){
            int t=course[0];
            int d=course[1];
            if(total+t<=d){
                total+=t;
                q.push(t);
            }
            else if(!q.empty() && q.top()>t){ //压缩学习时间
                total-=q.top();
                total+=t;
                q.pop();
                q.push(t);
            }
        }
        return q.size();
    }
};