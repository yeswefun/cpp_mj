#include <iostream>
#include<vector>

#include "../include/print.h"

using namespace std;


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};

    vector<int> v1(arr, arr+6);
    printVector(v1);

    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    vector<int> v3;
    v3.assign(arr, arr+6);
    printVector(v3);

    vector<int> v4;
    v4.assign(v3.begin(), v3.end());
    printVector(v4);

    /*
        越界
            读
                v1[1000], 随机值
                v1.at(1000), 抛出异常
            写
                v1[1000], 不一定可以写入
                v1.at(1000), 抛出异常
    */
    cout << v1[1000] << endl;
    cout << v1.at(1000) << endl;

    return 0;
}
