#include<bits/stdc++.h>
using namespace std;


vector<int>tempArray(string pattern)
{
    vector<int>lps(pattern.length());
    int index = 0;
    for(int i=1; i<pattern.length();)
    {
        if(pattern[index]==pattern[i])
        {
            lps[i] = index + 1;
            ++index;
            ++i;
        }
        else
        {
            if(index!=0)
            {
                index = lps[index-1];
            }
            else
            {
                lps[i] = index;
                ++i;
            }
        }
    }
    return lps;
}

void kmp(string text, string pattern)
{
    bool match = false;
    vector<int>lps(tempArray(pattern));
    int i=0; // here i = text
    int j=0; // here j = pattern
    while(i<text.length())
    {
        if(text[i]==pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            if(j!=0)
            {
                j = lps[j-1];
            }
            else
            {
                ++i;
            }
        }

        if(j==pattern.length())
        {
            cout<<"Pattern Matched"<<endl;
            match = true;
            break;
        }
    }
    if(!match)
    {
        cout<<"Pattern not matched"<<endl;
    }
}
 int main()
 {
     string text, pattern;
     getline(cin, text);
     getline(cin, pattern);
     kmp(text, pattern);
     return 0;
 }
