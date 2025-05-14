#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i-1;
        while (j>=0 && key < nums[j])
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
        
    }
    
}

void selectionSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++)
    {
        int min = i;
        for (int j = i+1; j < nums.size(); j++)
        {
            if(nums[min] > nums[j]) min = j;
        }
        swap(nums, min, i);
    }
    
}

void merge(vector<int> &nums, int start, int mid, int end) {
    vector<int> temp;
    int left = start, right = mid+1;
    while (left <= mid && right <= end) 
    {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid) 
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(nums[right]);
        right++;
    }
    
    for (int i = start; i <= end; i++)
    {
        nums[i] = temp[i-start];
    }
    
}

void mergeSort(vector<int> &nums, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[low];

    int i = low, j = high;

    while (i < j)
    {
        while (nums[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (nums[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if(i < j) {
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[low], nums[j]);
    return j;
    
}

void quickSort(vector<int> &nums, int low, int high) {
    if(low < high) {
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi-1);
        quickSort(nums, pi+1, high);
    }
}


int main() {
    vector<int> arr = {99,77,-99,458};
    quickSort(arr,0, arr.size()-1);

    for(auto num: arr) cout << num << " ";
    cout << endl;

    return 0;
}