## step1
- 二つ思いつく
  - UnionFindのようにグルーピングする
  - 隣接リストでグラフを作り探索
- 簡潔なので、UnionFindをイメージして解いてみる。
- 時間計算量O(Nlog(N)),空間計算量O(N)
  - 制約から0.04秒ほど。

- `node1`などマジックナンバーを使いたくないが、的確な識別子が思い付かず、つける。

- `std::vector` で `bool` ではなく `uint8_t` を使う。
  - プロキシクラス経由でアクセスするため速度が落ちる可能性がある。
  - https://github.com/Hurukawa2121/leetcode/pull/17#discussion_r1898907043

## step2
- 探索（今回はBFS）でも実装してみる。

- `emplace_back` なら `push_back` より不必要なコピーが発生する可能性が少ない。
  - https://en.cppreference.com/w/cpp/container/vector/emplace_back#:~:text=which%20typically%20uses%20placement%2Dnew%20to%20construct%20the%20element%20in%2Dplace%20at%20the%20location%20provided%20by%20the%20container.
  - ただし、今回は `int` を `emplace_back` しているだけなので大きく変わらなそう。
    - コピーコンストラクタが重いクラスのオブジェクトを追加する場合は顕著に差が出る。
    - https://hirlab.net/nblog/category/programming/art_685/#実験3_コピーコンストラクタが重めのクラス

- 他のコードを見る。

- 隣接リストを格納する変数は `adjacency_list` にする。
  - 今まで `graph` と命名していた。

## step3
- 補完無しで3分ほどで実装する。
