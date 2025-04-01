def root(n, degree=2, ndigit=2):
  if (n < 0):
    return None
  return round(n**(1/degree), ndigit)