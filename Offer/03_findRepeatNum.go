package offer

func findRepearNumber(nums []int) int {
	m := make(map[int]bool)
	for _, n := range nums {
		if _, exists := m[n]; exists {
			return n
		}
		m[n] = true
	}
	return -1
}

func findRepearNumber2(nums []int) int {
	i := 0
	for i < len(nums) {
		if nums[i] == i {
			i++
			continue
		}
		if nums[nums[i]] == nums[i] {
			return nums[i]
		} else {
			nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
		}
	}
	return -1
}
