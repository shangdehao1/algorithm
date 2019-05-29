#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

// =================

/*

void insertion_sort(vector<int>& data) 
{
  for(int i = 0; i < data.size(); i++) {
    int target = data[i];
    int index = i - 1;
    while(index >= 0 && data[index] > target) {
      data[index + 1] = data[index]; 
      index--;
    }
    data[index + 1] = target;
  }
}

*/

void insertion_sort (vector<int>& data) {
  for (int i = 1; i < data.size(); i++) {
    int target = data[i];
    int insert_position = i;
    while ((insert_position - 1) >= 0 && data[insert_position - 1] > target) {
      data[insert_position] = data[insert_position - 1];
      insert_position--;
    }
    data[insert_position] = target;
  }  
}

// ===================

void shell_sort(vector<int>& data) {
  for(int step = data.size() / 2; step > 0; step = step / 2) 
  {
    for(int i = step; i < data.size(); i++) 
    {
      for(int j = i; j - step >= 0 && data[j] < data[j-step]; j = j - step) 
      {
        swap(data[j], data[j-step]);
      }
    }
  }
}

// ==================

/*
void selection_sort(vector<int>& data) {
  for(int i = 0; i < data.size() - 1; i++) {
    int index = i;
    for(int j = i + 1; j < data.size(); j++) {
      if(data[j] < data[index]) {
        index = j;
      }
    }
    swap(data[i], data[index]);
  }
}

*/

void selection_sort(vector<int>& data) {

  auto get_min_value = [](const vector<int>& data, int first, int last) {
    int ret = data[first];
    for (int i = first + 1; i <= last; i++) {
      if(ret > data[i]) {
        ret = data[i];
      } 
    }
    return ret;
  };

  for (int i = 1; i < data.size(); i++) {
    data[i - 1] = get_min_value(data, i, data.size() - 1);
  }
}


// =====================

/*
void bubble_sort(vector<int>& data) 
{
  for(int i = data.size() - 1; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(data[j] > data[j+1]) {
        swap(data[j], data[j+1]);
      }
    } 
  }
}
*/


void bubble_sort(vector<int>& data) {
  
  for(int i = data.size() - 1; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(data[j] > data[j+1]) {
        swap(data[j], data[j+1]);
      }
    }
  }

}





// =====================

/*
void quick_sort_internal1(vector<int>& data, int first, int last) {
  if(last <= first) {
    return;
  }

  int index = data[first];
  int left = first;
  int right = last;

  while(left < right) 
  {
    while(left < right && data[right] >= index) 
      right--;

    if(left < right) {
      data[left] = data[right];      
      left++;
    }
    
    while(left < right && data[left] < index)
      left++;

    if(left < right) {
      data[right] = data[left];
      right--;
    }
  }

  data[left] = index;
  
  quick_sort_internal1(data, first, left - 1);
  quick_sort_internal1(data, left + 1, last);
}

void quick_sort1(vector<int>& data) {
  quick_sort_internal1(data, 0, data.size() - 1);
}
*/


void quick_sort_internal(vector<int>& data, int first, int last) {
  if(first >= last) {
    return; 
  }

  int left = first;
  int right = last;
  int target = data[first];
  

  while (left < right) {
    while(left < right && data[right] >= target) {
      right--;
    }

    if(left < right) {
      data[left++] = data[right];
    }

    while(left < right && data[left] <= target) {
      left++;
    }

    if(left < right) {
      data[right--] = data[left];
    }
  }
  data[left] = target;

  quick_sort_internal(data, first, left - 1);
  quick_sort_internal(data, left + 1, last);

}


void quick_sort(vector<int>& data) {
  quick_sort_internal(data, 0, data.size() - 1);
}



// =======================================

/*
void heap_adjust(vector<int>& data, int index, int len) 
{
  int temp = data[index];

  for(int i = index * 2 + 1; i < len; i = 2 * i + 1) {
    if(i + 1 < len && data[i + 1] > data[i]) {
      i++;
    }
    
    if(temp < data[i]) {
      data[index] = data[i];
      index = i;
    } else {
      break;
    }
  }

  data[index] = temp;
}

void heap_sort(vector<int>& data) 
{
  for(int i = data.size() / 2 - 1; i >= 0; i--) {
    heap_adjust(data, i, data.size());
  }

  for(int i = data.size() - 1; i > 0; i--) {
    swap(data[0], data[i]);
    heap_adjust(data, 0, i);
  }
}
*/


void heap_sort(vector<int>& data) {
  for (int i = data.size() / 2  - 1; i >= 0; i--) {
    heap_adjust(data, i, data.size());
  }
}





// =====================================

void merge_adjust(vector<int>& data, int left, int mid, int right) 
{
  int index = left;
  int index_left = left;
  int index_right = mid + 1;

  vector<int> temp;

  while(index_left <= mid && index_right <=right) {
    if(data[index_left] <= data[index_right]) {
      temp.push_back(data[index_left++]);
    } else {
      temp.push_back(data[index_right++]);
    }
  }
  
  while(index_left <= mid) {
    temp.push_back(data[index_left++]);
  }

  while(index_right <= right) {
    temp.push_back(data[index_right++]);
  }

  copy(temp.begin(), temp.end(), data.begin() + left);
}

void merge(vector<int>& data, int left, int right) 
{
  if(right - left < 1) return;

  int mid = (left + right) / 2;

  merge(data, left, mid);
  merge(data, mid + 1, right);

  merge_adjust(data, left, mid, right); 
}

void merge_sort(vector<int>& data) 
{
  merge(data, 0, data.size() - 1);
}

// =====================================



// =====================================

void print_output(const string info, const vector<int>& data, bool sorted = true) 
{
  if(sorted) {
    for(int i = 0; i < data.size() -1; i++) {
      assert(data[i] <= data[i+1]);
    }
  }

  std::cout << info << " -- yes " << std::endl;

  for(auto t : data) {
    std::cout << t << " " ;
  }

  std::cout << std::endl;
}


int main() 
{
  vector<int> data1 = {77,3,2,3,4,1,2,10,33,2,9,8,2,3,4,5,6,100,32,43};
  vector<int> data2 = {2,3,4,100,2,3,23,55,12,38,88,65,133,7,1,2,6,67,89,55,88,44,22};
  vector<int> data3 = {2,3,1,9,55,31,3,4,99,1234,543,22,321,2345,12,3,90,888,234,9898,123,57,782};
  
  print_output("original data 1 : ", data1, false);
  print_output("original data 2 : ", data2, false);
  print_output("original data 3 : ", data3, false);

  std::cout << "=====================" << std::endl;
  
  {
    auto temp1 = data1; 
    auto temp2 = data2;
    auto temp3 = data3;

    insertion_sort(temp1);
    insertion_sort(temp2);
    insertion_sort(temp3);

    print_output("insertion sort : ", temp1);
    print_output("insertion sort : ", temp2);
    print_output("insertion sort : ", temp3);
  }
  
  {
    auto temp1 = data1;
    auto temp2 = data2;
    auto temp3 = data3;

    selection_sort(temp1);
    selection_sort(temp2);
    selection_sort(temp3);

    print_output("selection sort : ", temp1);
    print_output("selection sort : ", temp2);
    print_output("selection sort : ", temp3);
  }

  {
    auto temp1 = data1;
    auto temp2 = data2;
    auto temp3 = data3;

    bubble_sort(temp1);
    bubble_sort(temp2);
    bubble_sort(temp3);

    print_output("bubble sort : ", temp1);
    print_output("bubble sort : ", temp2);
    print_output("bubble sort : ", temp3);
  }

  {
    auto temp1 = data1;
    auto temp2 = data2;
    auto temp3 = data3;

    quick_sort(temp1);
    quick_sort(temp2);
    quick_sort(temp3);

    print_output("quick sort : ", temp1);
    print_output("quick sort : ", temp2);
    print_output("quick sort : ", temp3);
  }

  {
    auto temp1 = data1;    
    auto temp2 = data2;
    auto temp3 = data3;

    heap_sort(temp1);
    heap_sort(temp2);
    heap_sort(temp3);

    print_output("heap sort : ", temp1);    
    print_output("heap sort : ", temp2);
    print_output("heap sort : ", temp3);
  }

  {
    auto temp1 = data1;    
    auto temp2 = data2;
    auto temp3 = data3;

    merge_sort(temp1);
    merge_sort(temp2);
    merge_sort(temp3);

    print_output("merge sort : ", temp1);    
    print_output("merge sort : ", temp2);
    print_output("merge sort : ", temp3);
  }

  {
    auto temp1 = data1;    
    auto temp2 = data2;
    auto temp3 = data3;

    shell_sort(temp1);
    shell_sort(temp2);
    shell_sort(temp3);

    print_output("shell sort : ", temp1);    
    print_output("shell sort : ", temp2);
    print_output("shell sort : ", temp3);
  }


  return 0;

}





















// ========= back up =========














/*
void bubble_sort (int a[], int n) {
    int i, j, lastSwap, tmp;
    for (j=n-1; j>0; j=lastSwap) {
        lastSwap=0;     //每一轮要初始化为0，防止某一轮未发生交换，lastSwap保留上一轮的值进入死循环
        for (i=0; i<j; i++) {
            if (a[i] > a[i+1]) {
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
　　　　　　　　   //最后一次交换位置的坐标
                lastSwap = i;
            }
        }
    }
}
*/


