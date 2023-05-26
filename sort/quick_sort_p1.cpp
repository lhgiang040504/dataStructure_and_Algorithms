#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// recursion
vector<int> quick_sort(vector<int> arr){
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < pivot)
            left.push_back(arr[i]);
        else if(arr[i] >= pivot)
            right.push_back(arr[i]);
    }
    left.push_back(arr[0]);
    if(left.size() > 1)
        left = quick_sort(left);
    if(right.size() > 1)
        right = quick_sort(right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


void output(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}

int main(){
    vector<int> arr = {5, 7, 1, 6, 3, 8, 0, 6, 2};
    vector<int> result = quick_sort(arr);
    output(result);
    return 0;
}