#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> & nums) {
    cout << '[';
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i == nums.size() - 1) {
            cout << ']';
        } else cout << ',';
    }
    cout << endl;
}

class Sort {
public:
    void bubbleSort(vector<int>& nums) {
        //flag表示是否数组是否有序
        bool flag = false;
        //n-1趟即可完成排序
        for (int i = 1; i < nums.size() && !flag; i++) {             
            flag = true;    //初始化为true,假设本轮排序未发生数据交换，则退出循环
            //从最后一个数开始往上冒泡,前i-1个已经排序完成
            for (int j = nums.size() - 1; j >= i; j--) {    
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                    flag = false;   //有数据交换，说明数组还未排序完成
                }
            }
        }
    }

    void selectSort(vector<int>& nums) {
        //只需n-1趟，但下标应该从0开始
        for (int i = 0; i < nums.size() - 1; i++) {
            //初始化当前位置为本轮的最小值
            int min = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            //若最小值不是i则交换
            if (i != min) {
                swap(nums[i], nums[min]);
            }
        }
    }

    void insertSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int flag = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > flag) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = flag;
        }
    }

    void shellSort(vector<int>& nums) {
        int increment = nums.size();
        while (increment > 1) {
            increment = increment / 3 + 1;
            for (int i = increment; i < nums.size(); i++) {
                int flag = nums[i];
                int j = i - increment;
                while (j >= 0 && nums[j] > flag) {
                    nums[j + increment] = nums[j];
                    j = j - increment;
                }
                nums[j + increment] = flag;
            }
        }
    }
    
    void heapSort(vector<int>& nums) {
        printVector(nums);
        for (int i = nums.size() / 2 - 1; i >= 0; i--) {
            heapAdjust(nums, i, nums.size());
            printVector(nums);
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapAdjust(nums, 0, i);
            printVector(nums);
        }
    }

    void mergeSort(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }

    void quickSort(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
private:
    void heapAdjust(vector<int>& nums, int i, int j) {
        int parent = i;
        int child = 2 * i + 1;
        while (child < j) {
            if (child + 1 < j && nums[child] < nums[child + 1]) {
                child++;
            }
            if (nums[parent] < nums[child]) {
                swap(nums[parent], nums[child]);
                parent = child;
            }
            child = child * 2 + 1;
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l == r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        int n = r - l + 1;
        vector<int> tmp(n);
        int i = 0, left = l, right = m + 1;
        while (left <= m && right <= r) tmp[i++] = nums[left] <= nums[right] ? nums[left++] : nums[right++];
        while (left <= m) tmp[i++] = nums[left++];
        while (right <= r) tmp[i++] = nums[right++];
        for (int j = 0; j < n; j++) nums[l + j] = tmp[j];
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int q = parition(nums, l, r);
            quickSort(nums, l, q - 1);
            quickSort(nums, q + 1, r);
        }
    }

    int parition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] < pivot) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
};


int main() {
    vector<int> nums = {6,8,5,4,1,2,9,0,3,7};
    Sort().quickSort(nums);
    printVector(nums);
}