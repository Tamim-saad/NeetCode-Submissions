#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string intToRoman(int n) {
    vector<string> thousands = {"","M","MM","MMM"};
    vector<string> hundreds = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    return thousands[n/1000] + hundreds[(n%1000)/100] + tens[(n%100)/10] + ones[n%10];
  }
};