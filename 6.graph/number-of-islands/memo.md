## step1

- UnionFind を使うか探索する。
- どちらも組む。
  - UnionFind → 時間計算量: O(HW*logHW), 空間計算量: O(H*W)
  - 探索 (BFS,DFS) → 時間計算量: O(H*W), 空間計算量: O(H*W)
- ただ、2または4方向探索するため定数倍は少しかかる。

### 思考メモ

- UnionFind、もっというとグルーピングする方法は「水が陸になる (島がつながる可能性がある) 」クエリが飛んでくる場合は高速になるが、今回は関係ない。

- 今回は探索はBFSがよい。
  - 呼び出し回数が高々9*10^4でスタックオーバーフローの可能性がある。

- グリッドの周辺を水で囲い、範囲外参照の判定を「水か陸か」の判定に統合できる。
  - しかし、素直に範囲外参照を判定する。

- 以下の `int` を `using Node = int;` と定義し `Node` にしようか迷ったが、差し過ぎと考えやめた。
  ```cpp
  int current_node = PointToNode(current_y, current_x);
  ```

- `UnionFind` はあまり良い変数名が思いつかなかった。
  ```cpp
  UnionFind uf(height * width);
  ```

- Union By Rank (Size) をしなくても通った。
  - これをしないと最初のクエリが O(logN) ではなく O(N)になってしまう。

## step2

- UnionFind より馴染みがあるので、BFSで実装する

- 他のコードを読む。

- ややこしいので `x, y` は `row, `col` にする。
  - `column` を `col` にしたが、 `row` があるのでわかるだろうと思った。

- `'0'` がマジックナンバー化しているので `char water_char = '0';` をする。
  - 条件にしか使っていないので const はつける必要がないと判断。

- `BFS` ではなく `WalkThroughIsland` にする。

- 私の実装と関係ないが以下を初めて学んだ。
  - [] と at が違うこと。
    - https://github.com/konnysh/arai60/pull/6#discussion_r1856679268
  - メンバ減数にするとスレッドセーフでなくなること。
    - https://github.com/Ryotaro25/leetcode_first60/pull/20#discussion_r1687455278

## step3
- 補完なしで4分ほどで実装。
  - インポートをアルファベット順にしたかった。
