#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::copy_if;
using std::find_if;
using std::for_each;
using std::sort;

void merge_filter_and_sort();

int main(int argc, char* argv[]) { 
    merge_filter_and_sort(); 
}

void merge_filter_and_sort() {
  std::vector<int> vec1 = {4, 9, 1, 7, 23, 18, 17};
  std::vector<int> vec2 = {102, 64, 47, 6, 5, 4, 18};
  std::vector<int> vec3;

  auto isEven = [](int num) -> bool { return !(num % 2); };

  auto printValue = [](int val) -> void { cout << "Value = " << val << endl; };

  copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec3), isEven);
  copy_if(vec2.begin(), vec2.end(), std::back_inserter(vec3),
          [isEven, vec1](int num) -> bool {
            return find_if(vec1.begin(), vec1.end(),
                           [num](int num_vec1) -> bool {
                             return num == num_vec1;
                           }) == vec1.end() &&
                   isEven(num);
          });

  sort(vec3.begin(), vec3.end());

  for_each(vec3.begin(), vec3.end(), printValue);
}
