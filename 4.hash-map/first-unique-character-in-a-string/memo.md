## step1
- 時間計算量: O(NlogN), 空間計算量: O(N)
  - 制約から0.017秒ほど

- `std::map<char, std::vector<int>> character_to_indexes;` に全探索した内容を格納していく方法も考えたが、最初の index 以外も保持する意味があるように読めそうなのでやめた。

## step2

- 他のコードを読む。

- しゃくとり法で実装した。
  - 時間計算量: O(NlogN), 空間計算量: O(N)
  - https://github.com/colorbox/leetcode/blob/1fdb87356938b312be64bae5583e0095d0bd3530/387/step2_3.cpp

- C++03 から `std::numeric_limits` がある。
  - `std::numeric_limits<int>::max()` で型 T の値の最大値を取得する。
  - 以下の違いを初めて知る。
    - `std::numeric_limits<double>::min()` : 正規化された最小値
    - `std::numeric_limits<double>::denorm_min()` : 非正規化された最小値
  - 正規化と非正規化の違いを初めて知る。
    - 以下の記事が分かりやすかった。
    - https://in-neuro.hatenablog.com/entry/2021/10/20/233650

- C++03 から `std::find_if` がある。

## step3
- 補完無しで2分ほどで実装する。
