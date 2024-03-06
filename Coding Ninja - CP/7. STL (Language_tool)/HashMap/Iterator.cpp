#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "Key : " << it->first << " value: " << it->second << endl;
        it++;
    }

    //find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");
    ourmap.erase(it2);

    cout << endl;
    unordered_map<string, int>::iterator it3 = ourmap.begin();
    while (it3 != ourmap.end())
    {
        cout << "Key : " << it3->first << " value: " << it3->second << endl;
        it3++;
    }

    return 0;
}