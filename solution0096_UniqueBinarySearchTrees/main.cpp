//
// Created by 王存俊 on 2019-09-16.
//

/*
 * Given a sorted sequence 1 ... n, to construct a Binary Search Tree (BST)
 * out of the sequence, we could enumerate each number i in the sequence, and
 * use the number as the root, then, the subsequence 1 ... (i-1) on its left
 * side would lay on the left branch of the root, and similarly the right
 * subsequence (i+1) ... n lay on the right branch of the root. We then can
 * construct the subtree from the subsequence recursively. Through the above
 * approach, we could be assured that the BST that we construct are all unique,
 * since they start from unique roots.
 *
 * As we can see, the problem can be reduced into problems with smaller sizes,
 * instead of recursively (also repeatedly) solve the subproblems, we can store
 * the solution of subproblems and reuse them later, i.e. the dynamic programming
 * way.
 */
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        vector<int> G(n + 1, 0);
        G[0] = G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};