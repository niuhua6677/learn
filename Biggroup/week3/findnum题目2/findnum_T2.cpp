#include <stdio.h>

// ��������Ԫ��
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ��������п�������
void quick_sort(int* nums, int left, int right) {
    if (left < right) {
        int pivot = partition(nums, left, right);
        quick_sort(nums, left, pivot - 1);
        quick_sort(nums, pivot + 1, right);
    }
}

// �������飬ʹ����ߵ�Ԫ�ض�С�ڵ���pivot���ұߵ�Ԫ�ض�����pivot
int partition(int* nums, int left, int right) {
    int pivot = nums[left];  
    int i = left + 1;       
    int j = right;         
    while (i < j) {
        // ������Ԫ�ر�pivot�󣬽������Ҳ�Ԫ�ؽ���
        if (nums[i] > pivot) {
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        }
        // ��������ɨ��
        i++;
        j--;
    }
    // ��pivot�ŵ���ȷ��λ����
    nums[left] = nums[j];
    nums[j] = pivot;
    return j;
}

// �ҵ���k���Ԫ��
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