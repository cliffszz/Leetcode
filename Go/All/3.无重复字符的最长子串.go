/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	freq := make([]int, 256)
	res, l, r := 0, 0, -1
	for l < len(s) {
		if r < len(s)-1 && freq[s[r+1]-'a'] == 0 {
			freq[s[r+1]-'a']++
			r++
		} else {
			freq[s[l]-'a']--
			l++
		}
		res = max(res, r-l+1)
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// @lc code=end

