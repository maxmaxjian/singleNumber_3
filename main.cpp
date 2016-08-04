#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <bitset>

using std::vector;

class solution {
  public:
    vector<int> singleNumber(const vector<int> & nums) {
        int init = nums[0];
        auto it = nums.begin();
        ++it;
        int acc = std::accumulate(it, nums.end(), init, std::bit_xor<int>());
        size_t parbit = findFirstDiffBit(acc);

        std::cout << "The first different bit is located at:\n";
        std::cout << parbit << std::endl;

        vector<int> vec1, vec2;
        for (auto it : nums) {
            std::bitset<32> bin(it);
            if (bin[parbit])
                vec1.push_back(it);
            else
                vec2.push_back(it);
        }

        vector<int> singles;
        auto it1 = vec1.begin();
        ++it1;
        int res1 = std::accumulate(it1, vec1.end(), vec1[0], std::bit_xor<int>());
        auto it2 = vec2.begin();
        ++it2;
        int res2 = std::accumulate(it2, vec2.end(), vec2[0], std::bit_xor<int>());

        singles.push_back(res1);
        singles.push_back(res2);

        return singles;
    }

  private:
    size_t findFirstDiffBit(int num) {
        std::bitset<32> num_bin(num);
        for (size_t ix = 0; ix < num_bin.size(); ix++)
            if (num_bin[ix])
                return ix;
        return 0;
    }
};

int main()
{
    vector<int> nums{1,2,1,3,2,5};

    solution soln;
    auto singles = soln.singleNumber(nums);

    std::cout << "The two single numbers are:\n";
    for (auto n : singles) {
        std::cout << n << " ";
        // std::bitset<32> bin(n);
        // std::cout << bin.to_string() << std::endl;
    }
    std::cout << std::endl;
}
