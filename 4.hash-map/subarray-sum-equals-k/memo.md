## step1
- 累積和 (`sums`) を使う。
- 問いは`sums[j] - sums[i] = k (i < j)` となる `i,j` のペアの数を求めることと読み換えられる。
  - `sums[j] = k + sums[i] (i < j)` や `sums[j] - k = sums[i] (i < j)` で一致判定すれば探索が二重ループにならず済む。
  - 累積和の構築も subarray の探索も前からするので、subarray を探索しながら累積和を計算できる。
- `std::map` でカウントする。
  - `std::map` か `std::unordered_map` の判断は難しい。 
  - 私の考え：https://github.com/Hurukawa2121/leetcode/blob/main/4.hash-map/group-anagrams/memo.md?plain=1#L10
- 時間計算量: O(NlogN), 空間計算量: O(N)
  - 制約から 0.003秒 ほど。

- 型は符号付き32bit ( `int` ) で十分。

- 命名が難しい。
  - 前述の `sums[j]` と `k + sums[i]` が同じ `std::map` を参照するので、 value を同じ概念で表現することが難しい。
    - 「格納する値」をシンプルにしたいため、 `k + sums[i]` をカウントして `sums[j]` を一致するか判定せず、 `sums[i]` をカウントして `sums[j] - k` を判定する。
  - `target_sum` も自信がない。
  ```cpp
  int target_sum = current_sum - k;
  ```
  - そもそも関数名から予測される処理と、式変形をして累積和を取る動きに乖離がある。

## step2
- 他のコードを見る。

- 以下の if 文がなかった。
  - 必要ない領域の確保のオーバーヘッドを考えたが、無くても LeetCode では Time Out にならず（これをパフォーマンス要件を満たしていると捉える）、無い方が読みやすい。
```cpp
if (sum_to_count.contains(target_sum)) {
  k_sum_count += sum_to_count[target_sum];
}
```

- 累積和を計算するのに C++17 からの `std::exclusive_scan()` が使える。
  - https://en.cppreference.com/w/cpp/algorithm/exclusive_scan
  - ここで C++17 から`std::execution` にアルゴリズムの並列実行を許可する実行ポリシーがあることを知る。
    - https://cpprefjp.github.io/reference/execution/execution/execution_policy.html#:~:text=parallel_policy%20/%20par
    - 確かに、排他制御をユーザが担うのかプログラムが担うのかを区別する必要がある。

- `current_sum` は自明なので `sum` にする。
- 更に累積和なので `sum` は `cumulative_sum` や `prefix_sum` にする。

## step3
- 補完無しで2分ほどで実装。
