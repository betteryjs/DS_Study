//
// Created by yjs on 2022/4/20.
//
#include <bits/stdc++.h>

using namespace std;



class KMP{

private:
    string  pat;
    vector<int> next;
public:

    KMP(const string & pat):pat(pat){
        // init next
        int j=0,k=-1;
        next.resize(pat.length());
        next[0]=-1;
        while (j<pat.length()-1){

            if(k==-1 || pat[j]==pat[k]){
                j++;
                k++;
                next[j]=k;
            }else{
                k=next[k];
            }


        } // end init next
    }


    int search(const string & txt ){
        int i=0,j=0;
        while (i<txt.length() && j<pat.length()){

            if(j==-1 || txt[i]==pat[j]){
                i++;
                j++;


            }else{
                j=next[j];
            }


        }
        if(j>=pat.length()){
            return i-pat.length();
        }else{
            return -1;
        }




    }





};


int main(){

    string res{"abaabc"};
    KMP * kmp=new KMP(res);
    int pos=kmp->search("abaabaabcab");
    cout <<pos<<endl;



    return 0;
}