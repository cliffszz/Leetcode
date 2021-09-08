/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
var result []string
var dict = map[string][]string{
	"2" : []string{"a","b","c"},
	"3" : []string{"d", "e", "f"},
	"4" : []string{"g", "h", "i"},
	"5" : []string{"j", "k", "l"},
	"6" : []string{"m", "n", "o"},
	"7" : []string{"p", "q", "r", "s"},
	"8" : []string{"t", "u", "v"},
	"9" : []string{"w", "x", "y", "z"},
}

func letterCombinations(digits string) []string {
	result = []string{}
	if digits == "" {
		return result
	}
	letterFunc("", digits)
	return result
}

func letterFunc(res, digits string) {
	if digits == "" {
		result = append(result, res)
		return
	}
	k := digits[0:1]
	digits = digits[1:]
	for i := 0; i < len(dict[k]); i++ {
		res += dict[k][i]
		letterFunc(res, digits)
		res = res[:len(res)-1]
	}
}
// @lc code=end

