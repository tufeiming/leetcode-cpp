#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 455. 分发饼干
 * @param g
 * @param s
 * @return
 */
int findContentChildren(vector<int> &g, vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int childIdx = 0;
    int cookieIdx = 0;
    while (childIdx < g.size() && cookieIdx < s.size()) {
        if (g[childIdx] <= s[cookieIdx]) {
            ++childIdx;
        }
        ++cookieIdx;
    }
    return childIdx;
}

/**
 * 135. 分发糖果
 * @param ratings
 * @return
 */
int candy(vector<int> &ratings) {
    vector<int> candies(ratings.size(), 1);
    for (int i = 0; i < ratings.size(); ++i) {
        if (i + 1 < ratings.size() && ratings[i + 1] > ratings[i] && candies[i + 1] <= candies[i]) {
            candies[i + 1] = candies[i] + 1;
        }
    }
    for (int i = ratings.size() - 1; i >= 0; --i) {
        if (i - 1 >= 0 && ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
            candies[i - 1] = candies[i] + 1;
        }
    }
    return accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
