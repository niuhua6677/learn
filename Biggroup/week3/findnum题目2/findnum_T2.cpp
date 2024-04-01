#include <stdio.h>

// 交换两个元素
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 对数组进行快速排序
void quick_sort(int* nums, int left, int right) {
    if (left < right) {
        int pivot = partition(nums, left, right);
        quick_sort(nums, left, pivot - 1);
        quick_sort(nums, pivot + 1, right);
    }
}

// 划分数组，使得左边的元素都小于等于pivot，右边的元素都大于pivot
int partition(int* nums, int left, int right) {
    int pivot = nums[left];  
    int i = left + 1;       
    int j = right;         
    while (i < j) {
        // 如果左侧元素比pivot大，将其与右侧元素交换
        if (nums[i] > pivot) {
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        }
        // 继续向右扫描
        i++;
        j--;
    }
    // 将pivot放到正确的位置上
    nums[left] = nums[j];
    nums[j] = pivot;
    return j;
}

// 找到第k大的元素
int find_kth_largest(int* nums, int k, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    int pivot = partition(nums, left, right);
    if (k == pivot + 1) {
        return nums[pivot];
    }
    else if (k < pivot + 1) {
        return find_kth_largest(nums, k, left, pivot);
    }
    else {
        return find_kth_largest(nums, k - pivot - 1, pivot + 1, right);
    }
}

int main() {
    int nums[] = { 5, 2, 8, 3, 7, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    int result = find_kth_largest(nums, k, 0, n - 1);
    printf("The %d-th largest element is: %d\n", k, result);
    return 0;
}