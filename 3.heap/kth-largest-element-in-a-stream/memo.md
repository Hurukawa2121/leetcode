## step1
- 用途が明示されている。
    > You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time.
    > This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
    > あなたは大学の入学事務局に所属しており、志願者の中からk番目に高いテストスコアをリアルタイムで追跡する必要があります。
    > これは、新しい志願者がスコアを提出する際に、面接や入学試験のカットオフ・マークを動的に決定するのに役立ちます。(Deeplより)
- 文脈からカットオフ・マークは足切り辺りだろう。
- そう考えるとここでの「リアルタイム」の意味を推し量れる。（前提、この要望定義をした人に聞きたいが。）
  - 例えば、志願者の面接スコアが確定してから3秒以内に足切りを知る必要があるケースはないだろう。
    - その場で伝えるとしても「それでは結果をお伝えします。」の前置きで3秒くらい経ちそうなので。
  - つまりパフォーマンス要件はそのレベルまで緩いと捉えられる。

- スコアのソート手段は `std::vector`を `std::sort`が思いつく。
  - ここで降順ソートしたとき `K`番より大きい要素は保持する必要がない。
    - この場合降順ソートした先頭だけ取得できれば良いので、`std::multiset`と `std::priority_queue`も候補になる。
- `add`(スコアの追加) が呼ばれる回数が高々10^4という制限から、三つのどれも用途で求められる速さを出しそうなので、コードの読み手から考えて選ぶ。
  - `std::vector`や `std::multiset`は 降順ソートしたとき`K`番より大きい要素も取得できてしまうため「それらの要素を取得できること」に意味があるように読めてしまう。
  - `std::priority_queue::top`で取得できる`std::priority_queue`を使う方が意味が狭くて良さそう。

- スコアを格納する変数は「降順ソートしたとき`K`番以下の要素を保持すること」である。
  - `descending_sorted_scores_to_Kth`だと長すぎる。
- 形式でなく意味を自然言語にすると「降順ソートしたとき`K`番目の要素を取得できること」である。
  - `top_scores_less_than_Kth`は長い。
  - `top_scores_to_Kth`だと、語感的に`K`個未満のスコアを保持するときに変数名との齟齬がでそう。
    - しかし、短いのでこちらにする。

- `KthLargest`の引数 `k`を保持する変数名は、関数名に合わせて `Kth`にする。

- スコアはclass KthLargestのメンバにするのが綺麗。
  - 関数終了後に引き継ぐ必要があるので、他の選択肢はグローバル変数などになってしまう。
    
## step2
- 他の人のコードを見る。

- スコアのヒープを `k_largest_scores`で保持していた。
  - 英語として成立させることに囚われていた。

- `Kth`と定義した変数名を `size`と定義していた。
  - 確かに、「K番目」という変数として保持し続けるのはどこか変だ。
    - 変数名が`K`だとしても `size`の方が良い。
  - `std::priority_queue::size`があるので `max_size`辺りだろうか。

## step3
- 1分半ほどで実装できる。
