def fib(n):
  res = [0, 1]

  if (n == 0):
    return [0]
  
  if (n == 1):
    return res
  
  for i in range(2, n):
    res.append(res[i-2]+res[i-1])

  return res