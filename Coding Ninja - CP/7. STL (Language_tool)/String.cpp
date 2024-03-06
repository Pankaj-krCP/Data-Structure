#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "pankaj";
    cout << s << endl;

    string s1(s);
    cout << s1 << endl;

    string s2(s, 2, 4);
    cout << s2 << endl;

    string s3 = s.substr(2, 4);
    cout << s3 << endl;

    if (s1.compare(s2) == 0)
    {
        cout << s1 << " is equal to " << s2 << endl;
    }
    else
    {
        cout << s1 << " is not equal to " << s2 << endl;
    }

    return 0;
}