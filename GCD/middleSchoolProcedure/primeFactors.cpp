// let n = 25
// -> 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 ..... 25
// Iteration 1: eliminate all multiples of 2 from the list.
// get rid of 2, 4, 8, 10, 12, 14, 16, 18, 20, 22, 24
// -> 2 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19 ...
// Iteration 2: eliminate all multiples of 3
// get rid of 9, 15, 21
//Iteration 3: eliminate all multiples of 5
//get rid of 25
// List that we are left with is the list of all prime numbers from 0 to n
// p * p <= n
// p^2 <= n 
// p <= floor(sqrt(n))
// 
// Sieve of Eratosthenes 
// Input: A postive number n > 1
// Output: an Array L of all primes less than or equal to n

// for p <- 2 to n do A[p] = p
// for p <- 2 to floor(sqrt(n)) do
//	if A[p] ~= 0
//		j <- p * p 
//		while j <= n do 
//			A[j] <- 0
//			j <- j + p
// i <- 0
// for p <- 2 to n do 
//	if A[p] ~=  0 
//	L[i] <- A[p]
//	i <- i +1
// return L 
