给定 $n$ 个数 $a_1,a_2,\cdots,a_n$，
保证每个数都可以写成 $a_i = p\times q$ ( $p,q$ 都不是合数) 的形式。

现在，Zztrans 想要从中选出 $k$ 个数，
$i_1,i_2,\cdots,i_k$ ( $i_1\lt i_2 \lt \cdots \lt i_k$ )，
使得 $a_{i_1},a_{i_2},\cdots,a_{i_k}$ 中任选两个数都互质。

这个问题被 compute 秒了，所以他想问问你，这个 $k$ 最大可以为多少？

## Input

第一行一个整数 $n$ ( $1 \leq n \leq 500$ )。

第二行 $n$ 个整数 $a_1,a_2,\cdots,a_n$ ( $1 \lt a_i \leq 10^7$ )。

## Output

输出一个整数 $k$，表示可以选出的满足要求的数的最多的个数。
