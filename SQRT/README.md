# Square Root Decomposition & Ideas
Square root decomposition is the process of separating a structure of size $\mathcal{O}(N)$
into $\mathcal{O}(\sqrt{N})$ "blocks" of size $\mathcal{O}(\sqrt{N})$ each, in a way that aids manipulation of the entire structure. Square root decomposition is extremely versatile. Some of its most well-known use cases are:

answering queries on a static array, with methods such as Mo's algorithm or block precomputation
"lazy" brute force modifications, where it is easy to query an entire block, but tag pushing isn't obvious
separating objects based on a threshold, when there exists both an $\mathcal{O}(x)$ algorithm and an $\mathcal{O}(n/x)$ algorithm
In this tutorial we will walk through multiple types of square root decomposition.


## Table of Contents
  - [Problems](#problems)
  - [External Links](#external-links)
  - [Contact](#contact)



## Problems
### Decomposition
- [Sereja and Squares](https://codeforces.com/contest/425/problem/D)
- [GukiZ and GukiZiana](https://codeforces.com/contest/551/problem/E)
- [Holes](https://codeforces.com/problemset/problem/13/E)
- [Conveyor Belts](https://codeforces.com/contest/487/problem/D)
- [Serega and Fun](https://codeforces.com/problemset/problem/455/D)
- [Nagini](https://codeforces.com/contest/855/problem/F)
- [Tricky Password](https://codeforces.com/contest/418/problem/E)
- [Mass Change Queries](https://codeforces.com/problemset/problem/911/G)
- [Transferring Pyramid](https://codeforces.com/contest/354/problem/D)
- [Isolation](https://codeforces.com/contest/1129/problem/D)
- [Colorful Tree](https://atcoder.jp/contests/abc133/tasks/abc133_f)
- [Yuezheng Ling and Dynamic Tree](https://codeforces.com/problemset/problem/1491/H)
- [Welcome home Chtholly](https://codeforces.com/problemset/problem/896/E)
- [The Awesomest Vertex](https://codeforces.com/contest/1178/problem/G)
### MO's Comparator
- [Liitle Elephant and Array](https://codeforces.com/contest/220/problem/B)
- [Powerful Array](https://codeforces.com/contest/86/problem/D)
- [Tree and Queries](https://codeforces.com/contest/375/problem/D)
- [XOR and Favorite Number](https://codeforces.com/contest/617/problem/E)
- [Destiny](https://codeforces.com/contest/840/problem/D)
### Heavy Light
- [Vanya and Treasure](https://codeforces.com/contest/677/problem/D)
- [Time to Raid Cowavans](https://codeforces.com/contest/103/problem/D)
- [Containers](https://szkopul.edu.pl/problemset/problem/oNnWY6ZuzzhvG-jCmijiXkIk/site/?key=statement)
- [Train Maintenance](https://codeforces.com/contest/1580/problem/C)
- [Propagation](https://atcoder.jp/contests/abc219/tasks/abc219_g)
- [Subset Sums](https://codeforces.com/contest/348/problem/C)
- [Instant Messanger](https://codeforces.com/contest/398/problem/D)
### Query Decomposition
- [Xenia and Tree](https://codeforces.com/contest/342/problem/E)
- [The Tree](https://codeforces.com/contest/1017/problem/G)
- [May Holidays](https://codeforces.com/contest/925/problem/E)

## External Links

- [Usaco Guide](https://usaco.guide/plat/sqrt?lang=cpp)
- [[Tutorial] Square root decomposition and applications](https://codeforces.com/blog/entry/83248)

## Contact
Created by [Abolfazl]() - feel free to contact me!
