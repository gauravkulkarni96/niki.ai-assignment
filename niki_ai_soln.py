
def countBitstrings(n):
	if n==0:
		return 0;
	total = (zero_ending_strings[n-1] + one_ending_strings[n-1]) % (10**9+7)
	return total

zero_ending_strings = [1]
one_ending_strings = [1]

for i in xrange(1, 10000):
	zero_ending_strings.append(
		one_ending_strings[i-1] % (10**9+7)
		)
	one_ending_strings.append(
		(one_ending_strings[i-1] % (10**9+7) + \
		zero_ending_strings[i-1] % (10**9+7)) % (10**9+7)
	)

t = int(raw_input())
for i in xrange(t):
	n = int(raw_input())
	print countBitstrings(n)