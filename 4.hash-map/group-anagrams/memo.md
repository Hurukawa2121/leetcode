## step1
- 要素の種類とそれぞれの個数が同じ文字列をグルーピングする。
- 二つ指針がある。
  - 文字列をソートして一致判定
  - 要素をカウントして一致判定
- カウントの処理がない分、周辺の処理が簡潔になるため文字列をソートして一致判定する。
- 文字列の数をN,文字列の長さをMとすると、時間計算量O(Nlog(M)+N), 空間計算量O(N)
  - 制約から1.4*10^5(0.001秒)ほど

- ソートした文字列を格納する `std::map` と `std::unordered_map` の比較は難しい。
  - キーをソートする必要がないので `std::unordered_map` としたいが、以下のリンクの通り整数徐算が遅くなる場合がある。そこに留意して使う。
  - https://chromium.googlesource.com/chromium/src/+/master/base/containers/README.md#std_unordered_map-and-std_unordered_set

- 以下の処理が不安
```cpp
      sorted_str_to_anagram_group[sorted_str].push_back(str);
```
- `sorted_str` が `anagram_group` に紐づいているか、読み手が直感的に分からない可能性がある。
  - ここが問題になる場合の書き方が分からなかった。

## step2
- 他のコードを読む。

- 以下なら値のコピーを避け、不可変にすることができる。
```cpp
...
  for (const std::string& str : strs) {
...
```

- C++ 17 から `std::transform` の記法があるらしい。
  - https://en.cppreference.com/w/cpp/algorithm/transform
```cpp
  transform(begin(sorted_str_to_anagram_group), end(sorted_str_to_anagram_group), back_inserter(anagram_groups), [](const auto& groups) {
      return groups.second;
  });
```
  - 標準ライブラリの多くが `constexpr` をサポートしてなかったことから出来たらしい。
    - https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0202r3.html#:~:text=I.%20Introduction%20and%20Motivation
  - 分かりやすいのでstep1の書き方にする。

## step3
- 補完無しで3分50秒ほどで実装
