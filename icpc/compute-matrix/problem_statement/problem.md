\begin{problem}{Compute's Matrix}{standard input}{standard output}{1 second}{512 megabytes}

Compute有一个大小为 $n \times n$ 的特殊矩阵，他的第 $i$ 行，第 $j$ 列用 $(i,j)$表示，这个位置上的元素是 $i \times j$。

现在给你一个这样的矩阵，以及一个子矩阵的左上角和右下角坐标。

你需要求这样一个子矩阵中所有元素的和。

由于和可能非常的大，你只需要输出对$10^9+7$取模后的答案。

\InputFile
第一行是一个整数 $T$ ($1\leq T\leq 30$)，代表有 $T$ 组测试数据。

接下来 $T$ 行，每行是 $5$ 个整数，$n,x_1,y_1,x_2,y_2$ ($1\leq n\leq 100000$，$1\leq x_1\leq x_2 \leq n$, $1\leq y_1\leq y_2 \leq n$)，分别代表矩阵大小，左上角坐标$(x_1,y_1)$和右下角坐标$(x_2,y_2)$。


\OutputFile
输出 $T$ 行，每行输出一个整数代表子矩阵的和在对 $10^9+7$ 取模后的结果。

\Example

\begin{example}
\exmpfile{example.01}{example.01.a}%
\end{example}

\end{problem}
