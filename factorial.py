def factorial(n):
  res = 1
  if (n == 0):
    return res
  
  for i in range(1,n+1):
    res*=i
  return res