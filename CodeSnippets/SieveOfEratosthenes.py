
# Python3 implementation of  
# above solution 
MAX = 10000
  
# Create a boolean array "prime[0..n]"  
# and initialize all entries it as true.  
# A value in prime[i] will finally be  
# false if i is Not a prime, else true. 
prime = [True for i in range(MAX + 1)] 
def SieveOfEratosthenes(): 
  
    prime[1] = False
  
    for p in range(2, MAX + 1): 
  
        # If prime[p] is not changed, 
        # then it is a prime 
        if (prime[p] == True): 
              
            # Set all multiples of  
            # p to non-prime 
            i = p * 2
            while(i <= MAX): 
                prime[i] = False
                i = i + p 
          
# find the sum of 1st 
# N prime numbers 
def solve( n): 
  
    # count of prime numbers 
    count = 0
    num = 1
  
    # sum of prime numbers 
    total = 0
  
    while (count < n): 
  
        # if the number is prime add it 
        if ( prime[num] ):  
            total = total + num 
  
            # increase the count 
            count = count + 1
          
        # get to next number 
        num = num + 1
      
    return total 
  
# Driver code 
# create the sieve 
SieveOfEratosthenes() 
  
n = 4
  
# find the value of 1st  
# n prime numbers 
print("Sum of 1st N prime " + 
      "numbers are :", solve(n)) 
  
# This code is contributed by ash264 
