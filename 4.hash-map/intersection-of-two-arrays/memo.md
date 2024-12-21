## step1
- `map` でもいいが value を使わないので `std::set` か `std::unordered_set` を採用する。

- `std::set` と `std::unordered_set` のどちらを使う考える。
  - `std::unordered_set` はハッシュテーブルなので整数徐算が遅いCPUアーキテクチャ (ARMなど) では遅くなる可能性がある。数回比較する (`std::set` を使う) 方が早い可能性がある。
    - https://chromium.googlesource.com/chromium/src/+/master/base/containers/README.md#std_unordered_map-and-std_unordered_set
  - `std::unordered_set`も C++11 からリハッシュできるようだが、最悪の場合で 計算量に`std::unordered_set::size` の二乗かかるので、(確率に依るが) あまり使いたくない。
    - https://cpprefjp.github.io/reference/unordered_set/unordered_set/rehash.html
  - `std::set` の方が良いと考える。

## step2
- 他のコードを見る

- 以下の初期化方法が C++17 からあった。
```cpp
std::unordered_set<int> unique_nums1(nums1.begin(), nums1.end());
```
  - これなら `seen_in_nums1` より `unique_nums1` の方が自然。

- C++03 から `std::set_intersection` がある。
  - `std::unordered_set` だと Wrong Answer になる。
    - ソートしていない場合は未定義動作とある。(つまり何が起きても構わない。)
    - https://en.cppreference.com/w/cpp/algorithm/set_intersection#:~:text=range%2C%20preserving%20order.-,1),-If

-  C++03 からの `std::back_inserter` をOutputIterator で使う。
  - https://en.cppreference.com/w/cpp/iterator/back_inserter
  - つまり `*(back_inserter(vec)) = value;` で `vec.push_back(value);` になる。
- 今回と関係ないが、他の書き込みを想定したイテレータを初めて知る。
  - https://stackoverflow.com/questions/19907677/whats-the-difference-between-iterator-and-back-insert-iterator#:~:text=see%20the%20following-,(adaptor)%20iterators,-%3A

## step3
- 補完無しで2分弱ほどで実装する。
