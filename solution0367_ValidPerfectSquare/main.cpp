//
// Created by 王存俊 on 2019-08-20.
//

using namespace std;

// TODO: binary search; sum of 1 + 3 + 5 + ...
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        for (long long i = 0; i <= num / 2; i++) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};

int main() {
    for (int i = 0; i <= 100; i++) {
        cout << "number i: " << i << " is a perfect square: " << Solution().isPerfectSquare(i) << endl;
    }
}