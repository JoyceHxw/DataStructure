// maxgap
// bucket_sort

#include <iostream>
using namespace std;
#include <vector>

int seed;

int rand(){
    return((( seed   =  seed   * 214013L + 2531011L) >> 16) & 0x7fff);
}

int rand32(){
    return ((rand() << 16) + (rand() << 1) + rand() % 2);
}

class bucket
{
public:
    bucket(){
        isEmpty=true;
        min_b=0x7FFFFFFF;
        max_b=0x8000000;
    }
    int min_b;
    int max_b;
    bool isEmpty;
};

int main(){
    int n;
    cin>>n>>seed;
    int* nums=new int[n];
    int min_num=0x7FFFFFFF;
    int max_num=0x8000000;
    for(int i=0; i<n; i++){
        nums[i]=rand32();
        min_num=min(min_num,nums[i]);
        max_num=max(max_num,nums[i]);
    }

    // 怎么划分桶？相邻数字的最大间距不会小于 ⌈(max−min)/(N−1)⌉
    int d=max(1,(max_num-min_num)/(n-1)); //桶的大小
    int cnt=(max_num-min_num)/d+1; //桶的数量
    // cout<<"d="<<d<<endl;
    // cout<<"cnt="<<cnt<<endl;
    vector<bucket>buckets; //桶
    buckets.resize(cnt);

    // 放元素
    for(int i=0; i<n; i++){
        int index=(nums[i]-min_num)/d;   //哪个区间（哪个桶）
        buckets[index].isEmpty=false;
        buckets[index].min_b=min(nums[i],buckets[index].min_b);
        buckets[index].max_b=max(nums[i],buckets[index].max_b);
    }
    // for(vector<bucket>::iterator it=buckets.begin(); it!=buckets.end(); it++){
    //     cout<<it->isEmpty<<" "<<it->min_b<<" "<<it->max_b<<endl;
    // }
    // 求间隔
    int gap=0;
    int last_max=min_num;
    for(int i=0; i<cnt; i++){
        // 上一个桶也不为空
        if(!buckets[i].isEmpty){
            gap=max(gap, buckets[i].min_b-last_max);
            last_max=buckets[i].max_b;
        }
    }
    cout<<gap;
}