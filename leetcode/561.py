# 
# 
#  a[begin:end:step]
#  range --> [begin, end)
#  step  --> step
#  
#  sorted
#  
#  sum 
#

def arrayPairSum(self, A):
    return sum(sorted(A)[::2])



