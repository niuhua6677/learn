#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <cstdio>
#include <time.h>
using namespace std;

void insertionSort(vector<long long>& q) {
    clock_t start = clock();
    for (long long i = 1; i < (long long)q.size(); i++) {
        long long t = q[i], j;
        for (j = i - 1; j >= 0; j--) {
            if (q[j] > t)
                q[j + 1] = q[j];
            else
                break;
        }
        q[j + 1] = t;
    }
    clock_t end = clock();
    cout << "排序时间";
    cout << (double)(end - start);
    cout << "ms" << endl;
}

void mergeSort(vector<long long>& q, long long l, long long r) {
    
    if (l >= r)
        return;
    long long mid = (l + r) >> 1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    static vector<long long> w;
    w.clear();
    long long i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] > q[j])
            w.push_back(q[j++]);
        else
            w.push_back(q[i++]);
    }
    while (i <= mid)
        w.push_back(q[i++]);
    while (j <= mid)
        w.push_back(q[j++]);
    for (long long i : w)
        q[l++] = i;
}
void mergeSort1(vector<long long>& q, long long l, long long r) {
    clock_t start = clock();
    mergeSort(q, l, r);
    clock_t end = clock();
    cout << "排序时间";
    cout << (double)(end - start);
    cout << "ms" << endl;
}
void quickSort(vector<long long>& q, long long l, long long r) {
   
    if (l >= r)
        return;
    long long i = l - 1, j = r + 1, x = q[l + rand() % (r - l + 1)];
    while (i < j) {
        do j--; while (q[j] > x);
        do i++; while (q[i] < x);
        if (i < j)
            swap(q[i], q[j]);
        else {
            quickSort(q, l, j);
            quickSort(q, j + 1, r);
        }
    }
    
}

void  quickSort1(vector<long long>& q, long long l, long long r) {
    clock_t start = clock();
    quickSort(q, l, r);
    clock_t end = clock();
    cout << "排序时间";
    cout << (double)(end - start);
    cout << "ms" << endl;
}
void countingSort(vector<long long>& q) {
    clock_t start = clock();
    vector<long long> cnt(1000001, 0);
    for (long long i = 0; i < (long long)q.size(); i++)
        cnt[q[i]]++;
    for (long long i = 0, k = 0; i <= 100; i++) {
        while (cnt[i]) {
            q[k++] = i;
            cnt[i]--;
        }
    }
    
    clock_t end = clock();
    cout << "排序时间";
    cout << (double)(end - start);
    cout << "ms" << endl;
}

int get(long long x, long long i) {
    while (i--)
        x /= 10;
    return x % 10;
}

void radixSort(vector<long long>& q) {
    clock_t start = clock();
    vector<vector<long long>> cnt(10);
    for (long long i = 0; i < 10; i++) {
        for (long long j = 0; j < 10; j++)
            cnt[j].clear();
        for (long long j = 0; j <(long long) q.size(); j++)
            cnt[get(q[j], i)].push_back(q[j]);
        for (long long j = 0, k = 0; j < 10; j++) {
            for (long long x : cnt[j])
                q[k++] = x;
        }
    }
    clock_t end = clock();
    cout << "排序时间";
    cout << (double)(end - start);
    cout << "ms" << endl;
}

// 生成指定长度的随机整数数组，并将其保存到文件中
void RandomDataToFile(const std::string& filename, long long dataSize, long long minVal, long long maxVal) {
    std::vector<long long> data(dataSize+1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> dis(minVal, maxVal);

    for (long long& num : data)
        num = dis(gen);

    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    for (long long val : data)
        outfile << val << '\n'; // 假设每个数值占一行

    outfile.close();
}

// 从文件中读取数据到整数数组
std::vector<long long> readDataFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        throw std::runtime_error("File not found or couldn't be opened.");
    }

    std::vector<long long> data(10000000);
    int value;
    while (infile >> value)
        data.push_back(value);

    infile.close();
    return data;
}

int main() {
    string s;
    std::string filename = "data.txt";
    long long dataSize=0;
    long long min=0;
    long long max=0;
    std::vector<long long> testData(10000000);
    
    while (1) {
        cout << "请输入你的操作:" << endl;
        cout << "1.生成随机数据" << endl;
        cout << "2.插入排序" << endl;
        cout << "3.归并排序" << endl;
        cout << "4.快速排序" << endl;
        cout << "5.计数排序" << endl;
        cout << "6.基数排序" << endl;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                continue;
            }
            else {
                cout << "输入有误" << endl;
                break;
            }
        }
        switch (s[0]) {
        case '1':
            cout << "请输入数据个数" << endl;
            cin >> dataSize;
            cout << "请输入数据最小值" << endl;
            cin >> min;
            cout << "请输入数据最大值" << endl;
            cin >> max;
            // 生成并保存数据
            RandomDataToFile(filename, dataSize, min, max);
            // 读取数据
            testData = readDataFromFile(filename);
            break;
        case '2':
           
            testData = readDataFromFile(filename);
            insertionSort(testData);
            
            break;

        case '3':
            testData = readDataFromFile(filename);
            mergeSort1(testData, 1, dataSize + 1);
           
            
            break;

            
        case '4':
            testData = readDataFromFile(filename);
            quickSort1(testData, 1, dataSize + 1);
           
            break;

        case '5':
            testData = readDataFromFile(filename);
            countingSort(testData);
           
            break;

        case '6':
            testData = readDataFromFile(filename);
            radixSort(testData);
            
            break;

        }

    }
    return 0;
}