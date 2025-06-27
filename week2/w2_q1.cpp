#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
int num;
cin>> num;
vector<int>songlist(num);
    for(int i=0;i< num; i++) {
cin>>songlist[i]; }
 map<int,int> Count;
int le = 0;
    int maxle = 0;
for (int ri= 0; ri< num; ri++) {
    Count[songlist[ri]]++;
 while (Count[songlist[ri]] > 1) {
    Count[songlist[le]]--;
le++;}

int curle= ri-le+1;
if (curle> maxle) {
maxle =curle;}
    }
cout<<maxle<< endl;

}
