#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0; 
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            count++; // new distinct element found
        }
    }

    cout << "Total distinct elements: " << count << endl;

    return 0;
}
