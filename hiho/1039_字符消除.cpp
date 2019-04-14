/*
第一次做hiho题目，感觉很难，无从下手
很久没有用C++，忘了怎么读取输入

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Del(const string &s){
    string str = s;
    while(true){
        if(str.size() == 0){
            return 0;
        }
        vector<char> v;
        char pre = str[0];
        int count = 1;
        for(int i=1; i<str.size(); i++){	//进行一次扫描
            if(str[i]==pre){	//有重复字符，则计数（相当于改变标志）
                count++;
            }
            else{	//没有重复字符
                if(count==1){	//如果是一个孤立字符，则入容器
                    v.push_back(pre);
                }
                pre = str[i];	//将当前指针后移一位
                count = 1;	//改变计数（相当于还原标志位）
            }
        }
        if(count==1){	//扫描结束后，如果标志位被还原，表示最后还有一个字符，那么将其放入容器
            v.push_back(pre);
        }
        if(v.size()==str.size()){	//扫描结束后，如果容器容量和str串的长度（即每次更新后的字符串）相等，说明没有可消除字符，循环结束
            break;
        }
        str = string(v.begin(),v.end()); //使用迭代器构造string，相当于将指针之间的内容拷贝给str（左闭右开），str更新为进行一次消除后的字符串
    }
    return str.size();
}
int main(){
    int T;
    cin>>T;
    string s;
    while(T--){
        cin>>s;
        int min=s.size();
        for(int i=0;i<s.size();i++){
            for(char ch='A';ch<='C';ch++){
                string newStr=s.substr(0,i)+ch+s.substr(i);	//在第i个位置上插入ch
                int len=Del(newStr);
                if(len<min){
                    min=len;
                }
            }
        }
        cout<<s.size()+1-min<<endl;	//分数（的最大值）=字符串长度+1-剩余字符长度（的最小值）
    }
    return 0;
}