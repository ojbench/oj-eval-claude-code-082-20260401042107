#include <iostream>
#include <string>
#include <vector>
#include "src.hpp"

using namespace std;

int main() {
    int n, len;
    bool forEachByTime;

    // Read array length and traversal type
    cin >> len >> forEachByTime;

    LinkedHashMap hashMap(len, forEachByTime);

    // Read number of operations
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int key;
            string value;
            cin >> key >> value;
            hashMap.insert(key, value);
        } else if (operation == "remove") {
            int key;
            string value;
            cin >> key >> value;
            hashMap.remove(key, value);
        } else if (operation == "ask") {
            int key;
            cin >> key;
            vector<string> result = hashMap.ask(key);
            cout << result.size();
            for (const string& val : result) {
                cout << " " << val;
            }
            cout << endl;
        } else if (operation == "forEach") {
            vector<Data> result = hashMap.forEach();
            cout << result.size();
            for (const Data& d : result) {
                cout << " " << d.key << " " << d.value;
            }
            cout << endl;
        }
    }

    return 0;
}
