#include<iostream>
#include<string>
#include<vector>
#include <math.h>
using namespace std;

string encode(string str){
    string result = "";
    int count = 1;
    for(int i = 1; i <str.length();i++){
        if(str[i]==str[i-1]){
            count ++;
        }
        else{
            result += to_string(count);
            result += str[i-1];
            count = 1;
        }
        if (i == str.length()-1){
            result += to_string(count);
            result += str[i-1];
        }
    }

    return result;
}


int coin(vector<int>offers,int discount){
    if(offers.size()==0){
        return 0;
    }
    int result=0;
    int max = offers[0];
    for(auto offer : offers){
        if(max< offer){
            max = offer;
        }
        result += offer;
    }
    
    result -= (max*discount)/100;
    return result;
}


int main(){
    string str = "aaabbccd";
    vector<int>offers={1,2,3,4};
    cout << coin(offers,20);
    // cout << encode(str);
}