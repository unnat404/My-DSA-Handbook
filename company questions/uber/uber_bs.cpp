//=================================================================================================

/*
Justify Text
Hard
Given a list of words and an integer line length k, return a list of strings which represents each line fully justified, with as many words as possible in each line.
There should be at least one space between each word, and pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with any extra spaces distributed starting from the left.
If you can only fit one word on a line, then pad the right-hand side with spaces.
Each word is guaranteed not to be longer than k.
Example 1
Input
words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
k = 16
Output
["the  quick brown", "fox  jumps  over", "the   lazy   dog"]
Explanation
First line: 1 extra space on the left (distributing from the left)
Second line: 2 extra spaces distributed evenly
Third line: 4 extra spaces distributed evenly
*/

/*
Implementation
....................................................................................................

Time Complexity
\mathcal{O}(n)O(n), we've pre-calculated the sum of elements, so it is O(n), if we need to consider the length of the strings, then it is O(n*k)

Space Complexity
\mathcal{O}(n)O(n), we need to prepare the answer array. To speed up calculation, we also preserve a sum array.
*/
void fit_in(vector<string>& words, vector<int>& sumsize, int i, int j, int k, vector<string>& ans) {
    string wip;
    int left_sp = k - sumsize[j + 1] + sumsize[i];
    for (int p = i; p < j; p++) {
        int sp = left_sp % (j - p) == 0 ? left_sp / (j - p) : 1 + left_sp / (j - p);
        left_sp -= sp;
        wip.append(words[p]);
        wip.append(sp, ' ');
    }
    wip.append(words[j]);
    if (wip.size() < k) wip.append(k - wip.size(), ' ');
    ans.push_back(wip);
}

vector<string> solve(vector<string>& words, int k) {
    vector<string> ans;
    vector<int> sumsize{0};
    for (int i = 0, s = 0; i < words.size(); i++) {
        s += words[i].size();
        sumsize.push_back(s);
    }

    for (int i = 0, j = 0; i < words.size();) {
        while (j < words.size() && sumsize[j + 1] - sumsize[i] + j - i <= k) j++;
        fit_in(words, sumsize, i, j - 1, k, ans);
        i = j;
    }
    return ans;
}
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
//=================================================================================================
