
# S为集合，时间复杂度为O(nlogn)，空间复杂度为O(n)
# 分析：
# 排序的时间复杂度为O(nlogn)，循环为O(n)，
# 所以时间复杂度为O(nlogn)
def findBestSubset(S):
	# 将S中的元素从小到大排序，得到序列L
	L = sorted(S)
	n = len(L)
	bestLen = 0
	ans = []
	j = 0
	# 枚举子序列的结尾i
	for i in range(n):
		# j是以i-1结尾的连续整数序列的开头，
		# 更新j：j到i为连续整数序列时j不变，否则变为i
		if (L[i]-L[j] != i-j):
			j = i
		# 更新答案
		m = i - j + 1
		if (m > bestLen):
			bestLen = m
			ans = L[j:i+1]
	
	return ans

S = {1, 0, 3, 4, 100, 199, 198, 200, 2, 201, 202}
print(findBestSubset(S))
