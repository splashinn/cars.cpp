#include <iostream>
#include <list>
#include <map>
 
using namespace std;
 
bool my_pair_compare(pair<string,int> &a, pair<string,int> &b) { 
  return a.second > b.second; 
}
 
void my_pair_output(pair<string,int> &p) { 
  cout << p.first << " " << p.second << endl; 
}
 
int main() {
  map<string,int> cars;
 
  while (1) {
    string name;
    cin >> name;
    if (cin.eof()) break;
    cars[name]++;
  }
 
  list<pair<string,int> > names;
 
  map<string,int>::iterator citer = cars.begin();
  while (citer != cars.end()) 
    names.push_back(*citer++);
 
  names.sort(my_pair_compare);
  for_each(names.begin(), names.end(), my_pair_output);
 
  return 0;
}