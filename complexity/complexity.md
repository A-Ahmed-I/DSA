# Time Complexity

> The relationship between the number of operations and the size of the input.

---

## Why Time Complexity?

Measuring speed in seconds is inaccurate — execution time depends on the machine. Different CPUs, RAM, and hardware mean the same code can run faster or slower on different devices. Time complexity gives us a **machine-independent** way to compare algorithms.

---

## Notation

| Symbol | Name      | Description                              |
| ------ | --------- | ---------------------------------------- |
| O      | Big-O     | Worst case — the upper bound on growth.  |
| Ω      | Big-Omega | Best case — the lower bound on growth.   |
| Θ      | Big-Theta | Actual (tight) case — both bounds match. |

---

## Rules for Computing Big-O

### 1 — Consecutive Blocks (Addition Rule)

Sequential calls add their complexities. The dominant term wins after simplification.

```cpp
void test1() { /* O(N) */ }
void test2() { /* O(M) */ }

int main() {
    test1();   // O(N)
    test2();   // O(M)
    // Total: O(N + M)
}
```

### 2 — Nested Loops (Multiplication Rule)

Every outer iteration runs the inner loop in full — multiply their complexities.

```cpp
for (int i = 0; i < N; i++) {       // runs N times
    for (int j = 0; j < M; j++) {   // runs M times per outer step
    }
}
// Total: O(N × M)
```

### 3 — Drop Constants

Constant multipliers are ignored in Big-O.

```cpp
for (int i = 0; i < 2*N; i++) {
    for (int j = 0; j < 2*M; j++) { }
}
// O(2N × 2M) = O(4NM)  →  O(N × M)
```

### 4 — Drop Lower-Order Terms

When adding complexities, keep only the fastest-growing term.

```cpp
for (int i = 0; i < N; i++) { }              // O(N)

for (int i = 0; i < N; i++) {                // O(N × M)
    for (int j = 0; j < M; j++) { }
}
// Total: O(N×M + N)  →  O(N × M)
```

### 5 — Conditionals Take the Worst Branch

When branches have different complexities, use the worst one.

```cpp
if (condition) {
    for (int i = 0; i < N; i++) { }          // O(N)
} else {
    for (int i = 0; i < N; i++)              // O(N²)
        for (int j = 0; j < N; j++) { }
}
// Total: O(N²)
```

## Some Useful Functions

### 1️⃣ Constant Function — O(1)

> A function is considered **O(1)** when the number of operations remains constant,  
> regardless of the size of the input.

### Explanation

Even if the input size changes, the execution time does **not** grow.

### Example

```cpp
int getFirstElement(int arr[]) {
    return arr[0];
}
```

---

### 2️⃣ Linear Function — O(n)

> A function is considered **O(n)** when the number of operations  
> increases linearly as the input size grows.

### Explanation

- The algorithm processes each element once
- If input size doubles → number of operations also doubles
- Growth rate is directly proportional to n

### Example

```cpp
int summation(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum += i;
    }
    return sum;
}
```

---

### 3️⃣ Logarithmic Function — O(log n)

> A function is considered **O(log n)** when the number of operations  
> increases logarithmically as the input size grows.

> In simple terms:  
> The problem size is repeatedly **divided (usually by 2)**  
> until it reaches 1.

### Explanation

- At each step, the input size is reduced by half
- The number of operations grow very slowly compared to n
- This makes it highly efficient for large datasets

### Example (Binary Search)

```cpp
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
```

---

### 4️⃣ Loglinear Function — O(n log n)

> A function is considered **O(n log n)** when the algorithm performs  
> a logarithmic operation **for each element** in the input.

### Explanation

- Combines linear and logarithmic growth
- Common in efficient sorting algorithms
- Much better than O(n²) for large datasets, but slower than O(n)

### Example (Merge Sort)

```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

---

### 5️⃣ Bilinear Function — O(n \* m)

> A function is considered **O(n \* m)** when the algorithm iterates  
> over **two independent inputs** of different sizes.

### Explanation

- Similar to O(n²) but with two _different_ variables
- If one input is fixed, it reduces to O(n)
- Common when processing 2D grids or two separate datasets

### Example

```cpp
void printPairs(int arr1[], int n, int arr2[], int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr1[i] << ", " << arr2[j] << endl;
        }
    }
}
```

---

### 6️⃣ Quadratic Function — O(n²)

> A function is considered **O(n²)** when the number of operations  
> grows proportionally to the **square** of the input size.

### Explanation

- Typically caused by nested loops over the same input
- If n doubles → operations quadruple
- Becomes very slow for large inputs

### Example (Bubble Sort)

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

---

### 7️⃣ Cubic Function — O(n³)

> A function is considered **O(n³)** when the number of operations  
> grows proportionally to the **cube** of the input size.

### Explanation

- Typically caused by **three nested loops**
- Extremely slow for large inputs
- Common in naive matrix multiplication

### Example (Matrix Multiplication)

```cpp
void matrixMultiply(int A[][N], int B[][N], int C[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

---

### 8️⃣ Exponential Function — O(2ⁿ)

> A function is considered **O(2ⁿ)** when the number of operations  
> **doubles** with every additional element in the input.

### Explanation

- Grows extremely fast — even small inputs can cause huge runtimes
- Common in brute-force solutions and recursive problems without memoization
- n = 30 already means over **1 billion** operations

### Example (Fibonacci — Naive Recursion)

```cpp
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

---

### 9️⃣ Factorial Function — O(n!)

> A function is considered **O(n!)** when the number of operations  
> grows as the **factorial** of the input size.

### Explanation

- The slowest common complexity class
- n = 20 means over **2.4 quintillion** operations
- Appears in algorithms that generate all permutations of the input

### Example (Generate All Permutations)

```cpp
void permutations(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        permutations(str, l + 1, r);
        swap(str[l], str[i]); // backtrack
    }
}
```

---

## Amortize Complexity

**Amortized Complexity** is a way to analyze the performance of an algorithm over a sequence of operations instead of looking at just one operation.

Sometimes an operation can be expensive, but it happens very rarely. Amortized analysis spreads the cost of these expensive operations across many cheap operations to find the average cost per operation.

### Dynamic Array Example

A common example is a **dynamic array** (such as a Python list).

When we use `append()`:

- Most insertions take **O(1)** time.
- Sometimes the array becomes full and needs to grow.
- When this happens, a new larger array is created and all elements are copied, which takes **O(n)** time.

Example:

```text
Append 1 → O(1)
Append 2 → O(1)
Append 3 → O(1)
Resize + Append 4 → O(n)
Append 5 → O(1)
Append 6 → O(1)
```

Although one operation may cost **O(n)**, resizing happens only occasionally. Therefore, the average cost of each append operation is **O(1)**.

### Why is it Useful?

Amortized analysis helps us:

- Understand the real performance of data structures.
- Ignore rare expensive operations.
- Measure long-term efficiency more accurately.

---

## Examples

### 1 — `calcSum` — O(1)

```cpp
int calcSum(int a, int b) {
    int sum = a + b;
    return sum;
}
```

### 2 — `calcAverage` — O(1)

```cpp
double calcAverage(int a, int b) {
    return (a + b) / 2.0;
}
```

### 3 — `isAlphabetic` — O(1)

```cpp
bool isAlpha(char x) {
    return (x >= 'A' && x <= 'Z')
        || (x >= 'a' && x <= 'z');
}
```

### 4 — `sumHarmonic` — O(n)

```cpp
double sumHarmonic(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++){
        sum += 1.0 / i;
    }
    return sum;
}
```

### 5 — `sumSegment` — O(b − a)

```cpp
long long sumSegment(int a, int b) {
    long long sum = 0;
    for (int i = a; i <= b; i++){
        sum += i;
    }
    return sum;
}
```

### 6 — `stepper` — O(n / s)

```cpp
int stepper(int n, int s) {
    int ret = 0;
    for (int i = 1; i <= n; i += s){
        ret += i;
    }
    return ret;
}
```

### 7 — `calcLog` — O(Log n)

```cpp
int calcLog(int n) {
    int ret = 0;
    while(n > 1){
        ++ret;
        n /= 2;
    }
    return ret;
}
```

### 8 — `fact` — O(n)

```cpp
int fact(int n) {
    if (!n || n == 1) return 1
    return n * fact(n - 1);
}
```

### 9 — `power` — O(power)

```cpp
int power(int base, int power) {
    if (!power) return 1
    return base * power(base, power - 1);
}
```

### 10 — Nested Loop (Triangular Pattern) — O(n²)

## Code

```cpp
for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
        cout << "Hello" << endl;
    }
}
```

## Explanation

The inner loop starts at `j = i`, so its iteration count depends on `i`.

| i   | Number of j iterations |
| --- | ---------------------- |
| 0   | n + 1                  |
| 1   | n                      |
| 2   | n − 1                  |
| 3   | n − 2                  |
| ⋯   | ⋯                      |
| n   | 1                      |

## Total Iterations

Summing all inner iterations:

$$
(n+1) + n + (n-1) + (n-2) + \cdots + 1
$$

This is an arithmetic series:

$$
\sum_{k=1}^{n+1} k = \frac{(n+1)(n+2)}{2}
$$

## Final Complexity

Dropping constants and lower-order terms:

$$
T(n) = O(n^2)
$$
