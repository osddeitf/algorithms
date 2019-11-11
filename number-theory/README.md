# Number theory
## Table of contents
// TODO
## Notation
- `a ≡ b (mod m)`: equivalent to `a % m = b`.

## Concepts
- **Coprime**: or **relative prime** are the integers `a` and `b` such that `gcd(a, b) = 1`.

## Algorithms
### Extended Euclidean algorithm
#### Problem statement
- Find **Bézout's identity**, which are integers x, y such that `ax + by = gcd(a, b)`.
#### Implement
- `r[0] = a, r[1] = b`
- `s[0] = 1, s[1] = 0`
- `t[0] = 0, t[1] = 1`
- `r[i+1] = r[i-1] - x * r[i]`
- `s[i+1] = s[i-1] - x * s[i]`
- `t[i+1] = t[i-1] - x * t[i]`
- Stop at `r[k+1] = 0`.
- `r[k]` is `gcd(a, b)`.
- `s[k], t[k]` is `x, y` that `ax + by = gcd(a, b)`.

### Modular multiplicative inverse
#### Problem statement
- Find `x` such that `ax ≡ 1 (mod m)` or `x ≡ a^-1 (mod m)`.
#### Solution
- Solution `0 <= x < m` exists if and only if `a` and `m` are **coprime**.
- `ax ≡ 1 (mod m)`, solve with `ax + my = 1` by **Extended Euclidean algorithm**.

### Chinese remainder theorem
#### Problem statement
- Given `n[]` whose elements are pairwise **coprime**.
- Given `a[]` which length equal to `n[]`.
- Find minimum positive integer `x` such that `x ≡ a[i] (mod n[i])` for every pair `(n[i], a[i])`.
#### Solution 1
- Let `N = prod(n)`, then `N[i] = N / n[i]`, we can easily find that `N[i]` and `n[i]` are coprime.
- There exists `M[i]` that `M[i] * N[i] ≡ 1 (mod n[i])`.
- For every `i`, and `k != i`, `N[k] ≡ 0 (mod n[i])`.
- There we go: `x = sum(M[i] * N[i] * a[i])`.
#### Solution 2
- Garner's Algorithm: https://cp-algorithms.com/algebra/chinese-remainder-theorem.html

### Divisor function
#### Statements
- For an integer `n`, and its positive divisors `d[]`.
- The **sum of positive divisors function** `σ(x) = sum(d[i] ^ x)`.
- Thus, `σ(0)` is **number-of-divisors function**.
- `σ(1)` is **sum-of-divisors function**.
#### Implement
- Find distinct prime factors of `n`, denotes `p[]`.
- Then, find maximum power `a[i]` of each `p[i]`.
- E.g: `72 = 2*2*2*3*3`, we got `p = [2, 3]`, `a = [3, 2]`.
- We have:
    
    ![Alt Text](https://latex.codecogs.com/gif.latex?%7B%5Cdisplaystyle%20%5Csigma%20_%7Bx%7D%28n%29%3D%5Cprod%20_%7Bi%3D1%7D%5E%7Br%7D%5Csum%20_%7Bj%3D0%7D%5E%7Ba_%7Bi%7D%7Dp_%7Bi%7D%5E%7Bjx%7D%3D%5Cprod%20_%7Bi%3D1%7D%5E%7Br%7D%5Cleft%281&plus;p_%7Bi%7D%5E%7Bx%7D&plus;p_%7Bi%7D%5E%7B2x%7D&plus;%5Ccdots%20&plus;p_%7Bi%7D%5E%7Ba_%7Bi%7Dx%7D%5Cright%29.%7D)

- Which is quivalent to:

    ![Alt Text](https://latex.codecogs.com/gif.latex?%7B%5Cdisplaystyle%20%5Csigma%20_%7Bx%7D%28n%29%3D%5Cprod%20_%7Bi%3D1%7D%5E%7Br%7D%7B%5Cfrac%20%7Bp_%7Bi%7D%5E%7B%28a_%7Bi%7D&plus;1%29x%7D-1%7D%7Bp_%7Bi%7D%5E%7Bx%7D-1%7D%7D.%7D)

- For `x = 0`:

    ![Alt Text](https://latex.codecogs.com/gif.latex?%5Csigma_0%28n%29%3D%5Cprod_%7Bi%3D1%7D%5Er%20%28a_i&plus;1%29.)

- Divisor function is **multiplicative**.
- Source: https://en.wikipedia.org/wiki/Divisor_function


### Euler's totient function
- Euler's totient function count positive integers up to `n` which are coprime to `n`, denotes as `φ(n)` or `ϕ(n)`.
- Formula: `φ(n) = n * prod(1 - 1/p)` where `p` are distinct prime numbers dividing `n`.
- In practical, we can compute by `n = n / p * (p - 1)` for each distinct `p`.
- Euler's totient function is **multiplicative**.

### Prime-counting function
- Meissel-Lehmer algorithm: https://en.wikipedia.org/wiki/Meissel%E2%80%93Lehmer_algorithm.

### Binomial coefficient
#### Lucas's theorem - O(p\*p*logp(n))
- Calculate `x` such that `nCk ≡ x (mod p)`.
- Let `n[i]`, `k[i]` are digits of `n` and `k` in base `p`.
- Then the result is `nCk ≡ prod(C(n[i], k[i])) (mod p)`.
- Reference: https://en.wikipedia.org/wiki/Lucas%27s_theorem
#### Inverse modulo - O(n\*log(p))
- Calculate by expand form of `nCk`, and inverse modulo.

### Fermat's little theorem
- If `p` is a **prime** number, then for any `a`, `a^p ≡ a (mod p)`.
- If `a` is not divisible by `p`, then `a^(p-1) ≡ 1 (mod p)`. This is a special case of **Euler's theorem** when `φ(p) = p-1`.

### Euler's theorem
- If `a` and `n` are coprime, then `a ^ φ(n) ≡ 1 (mod n)`.

## Category of Arithmetic functions
### Multiplicative and additive functions
An arithmetic function `a` is:

- **completely additive** if `a(mn) = a(m) + a(n)` for all natural numbers `m` and `n`;
- **completely multiplicative** if `a(mn) = a(m)a(n)` for all natural numbers `m` and `n`;
- **additive** if `a(mn) = a(m) + a(n)` for all **coprime** natural numbers `m` and `n`;
- **multiplicative** if `a(mn) = a(m)a(n)` for all **coprime** natural numbers `m` and `n`.

*References*: https://en.wikipedia.org/wiki/Arithmetic_function
