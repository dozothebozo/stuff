def isPrime(n):
  if n <= 1:
    return False
  if n == 2:
    return True
  if n % 2 == 0:
    return False

  for i in range(3, int(n**0.5) + 1, 2):
    if n % i == 0:
      return False
  return True

def Prime(n):
  if n < 2:
    return []

  res = [2]
  for i in range(3, n+1, 2):
    if isPrime(i):
      res.append(i)
  return res