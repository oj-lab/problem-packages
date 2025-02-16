Compute是个收集达人，他通过连续 $n$ 天坚持每天吃干脆面收集了一些他最喜爱的人物卡。

每个人物卡都有他喜欢的人物，他对第 $i$ 号人物的卡片有 $i$ 的满意度。

但我们都知道，收集到的卡片重复就失去了意义。于是Compute决定和大家玩若干轮游戏，送出他手中多余的卡片，**直到使得他手上的卡片都是不同的人物**。

游戏规则很简单，每轮由Compute任选出三张卡片，送出满意度值最大与最小的卡片给妈妈们，中间的依然保留。

Compupte很想知道自己手上卡片**满意度的和**最多为多少。请聪明的你帮帮他。

$n$ 一定是一个奇数，所以Compute手上最后一定会剩卡。

## Input

第一行输入一个整数 T ( $1 \leq  T \leq 10$ )，代表多少组测试数据。

每组开头第一行输入一个整数n ( $1 \leq  n \leq 1000000$ )，代表 Compute 共有 $n$ 张卡片，保证 $n$ 是一个奇数。

每组第二行输入 $n$ 个整数 $a_1, a_2,\cdots,a_N$ ( $1 \leq a_i \leq n$ ) ，表示 Compute 第 $i$ 天拿到了 $a_i$ 号人物的卡片。

保证 $1 \leq  \sum n \leq 2000000$ 。

## Output

对于每组测试数据，输出一行一个整数，代表Compute能获得的最大的满意度的和。
