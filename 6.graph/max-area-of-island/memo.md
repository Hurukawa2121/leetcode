## step1

- BFS, DFS, (Union By Sizeするなどした)UnionFind で解く。
  - 比較的馴染みないUnionFindは省く。
  - 制約からスタックオーバーフローの可能性がほぼない。(つまり再帰でも良い。)
- 時間計算量: O(H*W), 空間計算量: O(H*W)

### 思考メモ

- `CalculateIslandArea`が「呼んだときに何が起きるか」を明確にしていない。
  - 具体的には、 `explored` が出力引数になることを説明できていない。
  - なので、それを想起させる `WalkthroughIsland` などにしたいが、そうすると今度は返り値が「島の面積」になることが不明確になる。
  - 他に思いつかないため `CalculateIslandArea` にする。

- `push_land_cell` の命名は少し違和感がある。
  - `push_cell` よりはいいと考える。
    - 陸でなければ push しないが、 `push_cell` だとどんな cell も push するように読めてしまうから。
  - 今回の制約であれば、追加する cell を陸に制限せず、訪問時に陸かチェックする方法もあるが、探索対象でない cell をキューに持つ必要はないと判断。

- `std::vector<bool>` ではなきく `std::vector<uint8_t>` を使う。
  - 理由は `std::vector<bool>` はプロキシクラス経由で値にアクセスすることになるため、速度が落ちる可能性があるからだ。
    - 速度がどれくらいの確率で落ちるかが分かれば、認知負荷と天秤にかけてどちらを採用するべきか判断できるが、わからなかった。
- `std::vector<bool>` の特殊化は以下のリンクで挙げられているリンクが参考になった。
  - https://softwareengineering.stackexchange.com/questions/328112/how-did-stdvectorbool-come-about
  - `std::vector<bool>::reference` は `bool&` ではなく、1ビットを参照するプロキシオブジェクトを返す。
  - C++23 で出力イテレータが追加され、 std::vector<bool>::reference  に代入できるようになった。
    - https://cpprefjp.github.io/reference/vector/vector.html#:~:text=C%2B%2B23%E3%81%AB,%E3%81%AA%E3%81%A3%E3%81%9F%E3%80%82 

## step2

- 他のコードを読む

- `CalculateIslandArea` は `CountIslandArea` にする。

- `explore` は `visit` にする。
  - 感覚的に前者は地域を含むが、後者は地点を示す。確かに、今回なら後者がいい。

- `lands_to_explore` は `next_lands_cell` にする。

- `grid[0].size();` は `grid.front().size();` にする。
  - 意味は同じだが、マジックナンバーではなくなる。

## step3
- 補完無しで9分ほど実装する。
