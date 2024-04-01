#include <stdio.h>

void colorSort(int arr[], int n) {
    if (n == 0 || n == 1) return;

    int p0 = 0, p1 = 0, p2 = n - 1;

    while (p1 <= p2) {
        // ��0�ƶ���ǰ��
        while (arr[p1] != 0 && p1 <= p2)
            p1++;

        if (p1 >= p2) break;

        // ��1�ƶ����м�
        while (arr[p1] != 1 && p1 <= p2)
            p1++;

        if (p1 >= p2) break;

        // ��2�ƶ������
        while (arr[p2] != 2 && p1 <= p2)
            p2--;

        if (p1 >= p2) break;

        // ����Ԫ��
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;

        // ����Ƿ���Ҫ�ٴη���
        if (arr[p1] == 0) {
            p0++;
            p1++;
        }
        else if (arr[p1] == 1) {
            p1++;
        }
    }
}
//����
int main() {
    int arr[] = { 1, 2, 1, 0, 2, 0, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    colorSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}