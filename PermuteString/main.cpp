//
//  main.cpp
//  PermuteString
//
//  Created by Vinod Gupta on 3/9/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

string InsertAt(string str,char c,int i)
{
    stringstream ss;
    string tmp = str.substr(0,i);
    ss<<tmp;
    ss<<c;
    tmp = str.substr(i);
    ss<<tmp;
    return ss.str();
}

void PushAtAllPos(string str,char c,queue<string> & perm)
{
    string out_str;
    for(int i=0;i<=str.length();++i)
    {
        perm.push(InsertAt(str,c,i));
    }
}

queue<string> PermuteString(string str)
{
    queue<string> perm;
    
    for(string::iterator itr = str.begin(); itr != str.end(); ++itr)
    {
        char c = *itr;
        size_t qs = perm.size();
        
        if(!qs)
        {
            stringstream ss;
            ss<< c;
            perm.push(ss.str());
            continue;
        }
        
        for(int i=0;i<qs;++i)
        {
            string str = perm.front();
            perm.pop();
            PushAtAllPos(str,c,perm);
        }
  
    }
    
    return perm;
}

int main(int argc, const char * argv[])
{
    queue<string> perm = PermuteString("abcd");
    
    int i=1;
    while(!perm.empty())
    {
        
        cout<<perm.front()<<",";
        perm.pop();
        if(i%5==0)
        {
            cout<<endl;
        }
        ++i;
    }
    cout<<endl<<"Total="<<i-1<<endl;
    return 0;
}
