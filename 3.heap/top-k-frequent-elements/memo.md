## step1
- 用途は設定による。プログラムの実行時間は制約から0.2秒ほど
  - 時間計算量O(NlogN)、空間計算量O(N)

- 「要素に対する要素数」の保持する変数名は、引数の`nums`に合わせて `num_to_frequency`。
  - `val_to_frequency`も考えたが、`std::map`がキーバリューの形式なのでややこしくなる。
  - 長くなるが、引数を変えて良いなら`num`より`element`を使いたい。

- 以下の変数名は関数名`topKFrequent`に合わせた。
  - `std::map<int, int> num_to_frequency;`
  - `std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> top_k_frequencies_with_nums;`

- 以下のループ内処理が`top_k_frequencies_with_num`の名前に少し反していそうに見える。
```cpp
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> top_k_frequencies_with_nums;
for (auto [num, frequency] : num_to_frequency) {
  top_k_frequencies_with_nums.push({frequency, num}); // ここで要素数がk+1になる場合がある
  if (top_k_frequencies_with_nums.size() > k) {
    top_k_frequencies_with_nums.pop();
  }
}
```
- しかし、要素数は変数名に反するが、役割は変数名の「最も頻度が高いK個の頻度と数値(要素)を保持する」と相違ないと判断。
  - 要素数を変数名と相違なくするなら、ループ内の処理を関数化し、要素数がk+1になっている瞬間をその関数内だけに閉じる方法が考えられる。
    - つまり`topKFrequent`内では`top_k_frequencies_with_nums`の要素数は常に`k`個にできる。

- `pair<int,int>`は構造体にしたいがソートのために比較関数を作る必要がある。
  - 構造体をつくらず変数名で要素の意味を明確にする方針にする。
  - [参考](https://google.github.io/styleguide/cppguide.html#Structs_vs._Tuples)

- `std::pair<int, int>`で使わない変数を`auto [_, num]`のようにアンスコで定義することの是非は分からない。

## step2
- 他のコードを読む。

-  `frequent`と`frequency`を`freq`としていた。
  - 確かにこの関数内であれば分かる。
- `top_k_freqs_with_nums`は`top_k_freqs_and_nums`としていた。
  - ここはあまり分からない。`std::pair`そのものに優先順位はないが、ソートをするとなると順序がありそう。
    - `freqs_with_nums`はそれを意図して明示した。

## step3
- 2分ほどで実装。
