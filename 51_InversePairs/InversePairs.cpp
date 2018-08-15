/*******************************************************************
Copyright (c) 2018 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者: 何海涛
//==================================================================

// 面试题51: 数组中的逆序对
// 题目: 在数组中的两个数字如果前面一个数字大于后面的数字, 则这两个数字组成一个逆序对. 输入一个数组,
// 求出这个数组中的逆序对的总数.

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <algorithm>

int MergeCore(int* data, int* tmp, int first, int last, int mid) {
  int i=mid,j=last,k=last,sum=0;
  while(i>=first && j>=mid+1){
    if(data[i]>data[j]){
      sum += j - mid;
      tmp[k--] = data[i--];
    }
    else
      tmp[k--] = data[j--];
  }
  while(i>=first){
    tmp[k--] = data[i--];
  }
  while(j>=mid+1){
    tmp[k--] = data[j--];
  }
  std::copy(tmp+first, tmp+last+1, data+first);
  return sum;
}

int MergeSort(int* data, int* tmp, int first, int last) {
  int sum = 0;
  if(first < last){
    int mid = ((last - first) >> 1) + first;
    sum += MergeSort(data, tmp, first, mid);
    sum += MergeSort(data, tmp, mid+1, last);
    sum += MergeCore(data, tmp, first, last, mid);
  }
  return sum;
}

int InversePairs(int* data, int length) {
  if(data == nullptr || length <= 0) {
    throw std::invalid_argument("bad");
  }
  if(length == 1) return 0;
  int *tmp = new int[length];
  if(tmp == nullptr) throw std::bad_alloc();
  std::copy(data, data+length, tmp);
  int sum = MergeSort(data, tmp, 0, length-1);
  delete []tmp;
  return sum;
}

// ====================测试代码====================
void Test(char const* testName, int* data, int length, int expected) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    if (InversePairs(data, length) == expected) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == 0) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }
}

void Test1() {
  int data[] = {1, 2, 3, 4, 7, 6, 5};
  int expected = 3;

  Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2() {
  int data[] = {6, 5, 4, 3, 2, 1};
  int expected = 15;

  Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3() {
  int data[] = {1, 2, 3, 4, 5, 6};
  int expected = 0;

  Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4() {
  int data[] = {1};
  int expected = 0;

  Test("Test4", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递增排序
void Test5() {
  int data[] = {1, 2};
  int expected = 0;

  Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6() {
  int data[] = {2, 1};
  int expected = 1;

  Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7() {
  int data[] = {1, 2, 1, 2, 1};
  int expected = 3;

  Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8() {
  int expected = 0;

  Test("Test8", nullptr, 0, expected);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();
  Test8();

  return 0;
}
