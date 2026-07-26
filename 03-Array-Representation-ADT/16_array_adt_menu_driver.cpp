/*
Program Name: Array ADT - Complete Menu-Driven Mini-Project (Pre-Populated Array)


1. MENU-DRIVEN PROGRAM STRUCTURE WITH HARDCODED VALUES:
----------------------------------------------------------------------------------------------------
   - Objective: Consolidate all Array ADT operations into a clean, interactive console interface,
     pre-loaded with initial data.
   - Initial Array State:
     * Capacity = 15 (Slight extra space for testing Insert/Append)
     * Initial Length = 10
     * Initial Elements = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
   - Covered Operations:
     1. Display Elements
     2. Append Element
     3. Insert Element at Index
     4. Delete Element from Index
     5. Linear Search (with Transposition)
     6. Binary Search (Iterative)
     7. Get Element at Index
     8. Set Element at Index
     9. Find Max & Min Elements
     10. Calculate Sum & Average
     11. Reverse Array (In-Place)
====================================================================================================
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *A;      // Dynamic array in heap
    int size;    // Total capacity
    int length;  // Current count of elements

    void Swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    // Constructor - Automatically initializes array with 10 pre-set values
    Array(int sz = 15) {
        size = sz;
        A = new int[size];

        // Hardcoded initial values: 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
        int initialValues[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        length = 10;

        for (int i = 0; i < length; i++) {
            A[i] = initialValues[i];
        }
    }

    // Destructor
    ~Array() {
        delete []A;
    }

    // 1. Display
    void Display() {
        if (length == 0) {
            cout << "\n[Info] Array is currently empty!" << endl;
            return;
        }
        cout << "\n[Array Elements]: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << "\n[Status]: Total Capacity = " << size << ", Current Length = " << length << endl;
    }

    // 2. Append
    void Append(int x) {
        if (length < size) {
            A[length++] = x;
            cout << "[Success] Element " << x << " appended successfully." << endl;
        } else {
            cout << "[Error] Array overflow! Capacity full." << endl;
        }
    }

    // 3. Insert
    void Insert(int index, int x) {
        if (index >= 0 && index <= length && length < size) {
            for (int i = length; i > index; i--) {
                A[i] = A[i - 1];
            }
            A[index] = x;
            length++;
            cout << "[Success] Element " << x << " inserted at index " << index << "." << endl;
        } else {
            cout << "[Error] Invalid index or array capacity is full!" << endl;
        }
    }

    // 4. Delete
    int Delete(int index) {
        if (index >= 0 && index < length) {
            int x = A[index];
            for (int i = index; i < length - 1; i++) {
                A[i] = A[i + 1];
            }
            length--;
            return x;
        }
        return -1;
    }

    // 5. Linear Search with Transposition
    int LinearSearch(int key) {
        for (int i = 0; i < length; i++) {
            if (A[i] == key) {
                if (i > 0) {
                    Swap(&A[i], &A[i - 1]); // Optimization
                    return i - 1;
                }
                return i;
            }
        }
        return -1;
    }

    // 6. Binary Search
    int BinarySearch(int key) {
        int low = 0, high = length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == key) return mid;
            else if (key < A[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    // 7. Get
    int Get(int index) {
        if (index >= 0 && index < length) return A[index];
        return -1;
    }

    // 8. Set
    void Set(int index, int x) {
        if (index >= 0 && index < length) {
            A[index] = x;
            cout << "[Success] Index " << index << " updated to " << x << "." << endl;
        } else {
            cout << "[Error] Invalid index!" << endl;
        }
    }

    // 9. Max
    int Max() {
        if (length == 0) return -1;
        int maxVal = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] > maxVal) maxVal = A[i];
        }
        return maxVal;
    }

    // 10. Min
    int Min() {
        if (length == 0) return -1;
        int minVal = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] < minVal) minVal = A[i];
        }
        return minVal;
    }

    // 11. Sum
    int Sum() {
        int total = 0;
        for (int i = 0; i < length; i++) total += A[i];
        return total;
    }

    // 12. Average
    float Avg() {
        if (length == 0) return 0.0;
        return (float)Sum() / length;
    }

    // 13. Reverse In-Place
    void Reverse() {
        for (int i = 0, j = length - 1; i < j; i++, j--) {
            Swap(&A[i], &A[j]);
        }
        cout << "[Success] Array reversed successfully." << endl;
    }
};

int main() {
    // Array automatically initializes with 10 pre-loaded values
    Array arr;

    cout << "==================================================" << endl;
    cout << "      ARRAY ADT: INTERACTIVE MENU DRIVER          " << endl;
    cout << "==================================================" << endl;
    cout << "[System]: Array initialized with 10 elements: {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}" << endl;

    int choice, val, idx, res;

    do {
        cout << "\n---------------- MENU OPTIONS ----------------" << endl;
        cout << "1. Display Elements      2. Append Element" << endl;
        cout << "3. Insert at Index       4. Delete from Index" << endl;
        cout << "5. Linear Search         6. Binary Search" << endl;
        cout << "7. Get Value at Index    8. Set Value at Index" << endl;
        cout << "9. Find Max & Min       10. Sum & Average" << endl;
        cout << "11. Reverse Array        0. Exit" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr.Display();
                break;
            case 2:
                cout << "Enter value to append: ";
                cin >> val;
                arr.Append(val);
                break;
            case 3:
                cout << "Enter index and value: ";
                cin >> idx >> val;
                arr.Insert(idx, val);
                break;
            case 4:
                cout << "Enter index to delete: ";
                cin >> idx;
                res = arr.Delete(idx);
                if (res != -1) cout << "[Success] Deleted value: " << res << endl;
                else cout << "[Error] Invalid index!" << endl;
                break;
            case 5:
                cout << "Enter key to search (Linear): ";
                cin >> val;
                res = arr.LinearSearch(val);
                if (res != -1) cout << "[Found] Element located at index " << res << endl;
                else cout << "[Not Found] Element not present." << endl;
                break;
            case 6:
                cout << "Enter key to search (Binary - Sorted Array): ";
                cin >> val;
                res = arr.BinarySearch(val);
                if (res != -1) cout << "[Found] Element located at index " << res << endl;
                else cout << "[Not Found] Element not present." << endl;
                break;
            case 7:
                cout << "Enter index: ";
                cin >> idx;
                res = arr.Get(idx);
                if (res != -1) cout << "Value at index " << idx << " is " << res << endl;
                else cout << "[Error] Invalid index!" << endl;
                break;
            case 8:
                cout << "Enter index and new value: ";
                cin >> idx >> val;
                arr.Set(idx, val);
                break;
            case 9:
                cout << "Max Element: " << arr.Max() << ", Min Element: " << arr.Min() << endl;
                break;
            case 10:
                cout << "Total Sum: " << arr.Sum() << ", Average: " << arr.Avg() << endl;
                break;
            case 11:
                arr.Reverse();
                break;
            case 0:
                cout << "\nExiting Array ADT Application. Goodbye!" << endl;
                break;
            default:
                cout << "[Error] Invalid choice! Please select from menu." << endl;
        }
    } while (choice != 0);

    return 0;
}