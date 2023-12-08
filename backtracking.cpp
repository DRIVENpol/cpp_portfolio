#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);

            // Recursion call
            permute(str, l + 1, r);

            // Backtracking
            swap(str[l], str[i]);
        }
    }
}

int main() {
    string str;

    cout << "Input String: " << endl;
    getline(cin, str);

    cout << endl <<  "Permutations: " << endl;
    permute(str, 0, str.length() - 1);
    return 0;
}
