#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int testcase;
    map<string, int> storage;
    string name;

        cin >> testcase;


            while (testcase--)
            {
                cin >> name;
                    if (storage.count(name) == 0)
                    {
                        cout << "OK" << endl;
                        storage[name] = 1;
                    }
                    else
                    {
                        cout << name << storage[name] << endl;
                        storage[name] += 1;
            }
}
return 0;
}
