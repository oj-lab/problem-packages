Zztrans 最近沉迷庄园，他又可以种地了。

在庄园中，要成为一个好的农夫升级农场，每天还必须钓鱼，
作为一个精打细算的农夫，他想知道他一天钓鱼的期望收益是多少。

庄园里，鱼的稀有度分为以下五个等级，
"普通"，"稀有"，"罕见"，"珍稀"，"传说"，
分别用 $D$ , $C$ , $B$ , $A$ , $S$ 来表示。  

一般来说，钓来的鱼都会卖给一个叫花婶的精明女商人，对于以上稀有度的鱼，她分别收
$16$, $24$, $54$, $80$, $100$ 豆子。
你可以认为前面四类鱼对于 Zztrans 来说就值这么些钱。

但 "传说" 鱼就不一样了，除了概率比较低外，钓某些 "传说" 鱼还要特定天气特定时间。
每次钓到传说鱼，Zztrans 都会高兴得跳起来，所以 Zztrans 认为传说鱼一条值 $ 10000 $ 豆子。
(即传说鱼不再被认为是原收购价 $100$ 豆子，而是 $10000$ 豆子)

但钓鱼不能空手套白 "鱼"，钓一条鱼需要 $23$ 豆子的鱼饵。

现在假设你知道鱼塘里有 $n$ 种鱼以及他们各自的稀有度和钓到的概率，
以及 Zztrans 今天准备钓多少杆，Zztrans 想请你教教他今天的期望收益是多少豆子？

## Input

第一行有二个整数 $n, k$ ( $1 \leq  n \leq 100, 1 \leq  k \leq 100$ )，分别表示鱼塘里鱼的种类数和 Zztrans 准备钓的杆数。

接下来 $n$ 行，第 $i$ 行有一个字符 t,  
$t \in \{D,C,B,A,S\}$ 和 一个实数 $P_i$ ( $0.00 \leq P_i \leq 1.00$ )，
分别表示第 $i$ 条鱼的等级和钓到的概率。

保证所有的 $P_i$ 均给到小数点后两位，$\sum {P_i = 1.00}$。

## Output

在一行输出一个实数，表示 Zztrans 今天的期望收益。
你的答案的相对或绝对误差不超过 $ 10^{−4} $ 会被认为是正确的。

形式化地说：令你的答案为 $ a $ ，标准答案为 $ b $ ，
你的答案会被判为正确当且仅当 $\frac{ |a−b| }{\max(1,|b|)} \leq 10 ^{−4} $ 。
