7777年，为了表彰著名币学家尼古拉斯-鸡哥在虚拟货币市场运转，炒币理论方面的杰出贡献，
奥林匹斯市决定在韭菜街的路上为他修建雕像。

韭菜街是一条漫长的道路，这条道路上布满了韭菜，
但各种韭菜由于发育的不一样，会拥有各种奇怪的姿势和形态，
有的韭菜已经成熟，会被修剪和打压，而有的韭菜正在茁壮成长着，等待着成熟。
尼古拉斯-鸡哥的雕像就决定以这些韭菜们为背景，修建在这些韭菜中的某一棵上。

现在有 $n$ 棵可供选择的韭菜背景板，每棵韭菜都会有一个发育度 $a_i$。
修建雕像当然是为了让行人观赏膜拜，而如果将鸡哥的雕像修建在第 $i$ 根的韭菜上，
就能够让行人获得剩下除了这根韭菜以外所有韭菜的发育度乘积的愉悦值。

奥林匹斯市的市长想知道，若将鸡哥的雕像修建在所有韭菜中的某一棵上行人能够获得的愉悦值，请你帮助他。
为了防止答案过大，你只需输出答案对 $998244353$ 取模后的结果。

## Input

第一行输入一个整数 $n$ ( $2 \leq n \leq 10^5$ ) ，
代表韭菜街上的韭菜数。

第二行输入 $ n $ 个整数 ，$a_1, a_2,\cdots,a_n$($1 \leq a_i \leq 10^9$)，
代表每根韭菜的发育度为 $ a_i $ 。

## Output

在一行输出 $ n $ 个以空格分割的整数 ，$x_1, x_2,\cdots,x_n$，
代表将鸡哥雕像修建在第 $i$ 根韭菜上行人能获得的愉悦值对 $998244353$ 取模后的结果。
