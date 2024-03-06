#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;

    //insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    //find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    // cout<<ourmap.at("ghi")<<endl; //terminate called after throwing an instance of 'std::out_of_range' what():  _Map_base::at
    cout << "size : " << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl; //this will insert the value of ghi as 0
    cout << "size : " << ourmap.size() << endl;

    //check Presence
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    //erase
    ourmap.erase("ghi");
    cout << "size : " << ourmap.size() << endl;
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    return 0;
}