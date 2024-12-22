## step1
- 指定された処理をした後、重複を除いた文字列の数を答える。
- 時間計算量: O(NLog(N)), 空間計算量: O(N)
  - 制約から

#### ライブラリ
- 重複の排除は `std::set` か `std::unordered_set` で行う。
  - value (頻度など) は今回必要ないので `std::map` を使わない。
- 以下の考察から`std::set` を使う。
  - https://github.com/Hurukawa2121/leetcode/pull/13/files#diff-004a360db73df57b9b1d8d87e9a393f4dd4f6ceb75f04ef47d3ab13403dca161R4

- `std::basic_string::find`は最初に一致する位置を返す。
  - https://cpprefjp.github.io/reference/string/basic_string/find.html

- `std::basic_string::substr` は新しい文字列を生成する。
  - つまり生成した文字列の変更が引数の文字列に影響しない。

- `@`, `+`, `.` はコンパイル時に決定可能なので C++11からの `constexpr` にできるが。この機能が必要になった背景にそぐわないので、読み手に誤解させないよう単に不変を示す  `const` にする。
  - https://cpprefjp.github.io/lang/cpp11/constexpr.html#:~:text=この機能が必要になった背景・経緯

- C++03 からの `std::transform` の実装を見たがあまりよくわからなかった。

- C++20 から `std::erase` でコンテナから削除できる。
  - 前から探索し、指定された値以外のコンテナの領域を削除する実装だった。

#### 関数化

- 関数化の理由
  - `normalizeEmails` : `normalized_emails` の初期化を関数化しないと `unique_emails` の初期化と粒度が合わなくなるから。
    ```cpp
    // normalizeEmails を作らなかった場合
    int numUniqueEmails(std::vector<std::string>& emails) {
      const std::vector<std::string> normalized_emails;
      ここに normalizeEmails に相当する処理が約10行ある
      const std::set<std::string> unique_emails = std::set(normalized_emails.begin(), normalized_emails.end());
      return unique_emails.size();
    }
    ```
    > 「関数の中で複数の抽象レベルのことを一緒に行うと常に混乱を招きます。コードを読む人には、特定の式が本質的な概念なのか、実装詳細なのかを判別することができないかもしれません。
    > さらに、ひとたび本質的な概念と実装詳細とが一緒になったコードが現われると、割れた窓理論のごとく、関数の中に実装詳細が増えていきます。」
    > Robert C.Martin Clean Code. KADOKAWA, 2017. 「1つの関数に1つの抽象レベル」 節より
  - `normalizeLocalName`:
    - `+` と `.` の処理の要件を知らない人が読めるコードを書けなかった。
      - なので、コメントに要件の概要を書きたかった。
    - コメントに合わせて「`+` と `.` の要件を説明すべき処理」と「それ以外の処理」を分けたかったため、前者を関数化した。

- `normalizeEmail` から「ローカル名とドメイン名を区切る関数」を切り出すことで `at_index` をその関数内に閉じることができる。
  - ただ何度も呼び出さないため、そこまで良い関数化ではないと考え、やめる。
  ```cpp
  // ローカル名とドメイン名を区切る関数 (splitByDelimiter) を切り出した場合
  ...
  std::vector<std::string> normalizeEmails(const std::vector<std::string>& emails) {
    auto normalizeEmail = [this](const std::string& email) {
      const auto [local_name, domain_name] = splitByDelimiter(email);
  ...
  std::pair<std::string, std::string> splitByDelimiter(const std::string& email) {
    const int at_index = email.find(AT, 0);
    const std::string local_name = email.substr(0, at_index);
    const std::string domain_name = email.substr(at_index + 1);
    return {local_name, domain_name};
  }
  ...
  ```

## step2

- `AT` は `AT_SIGN` の方が良い。

- 他のコードを読む。

- 特に意図がなければ、ローカル変数には const を付けないほうがシンプルに感じるようだ。
  - 意図がある場合は明示的に付けたほうが良いようだ。
  - 今回は `canonicalize` 系の関数の引数だけ `const` を付ける。

- 引数の型のサイズがレジスター幅に比べて十分に大きい場合は、過多なメモリーコピーを避けるため、 const 左辺値参照で渡す。
  - 今回は自作関数の全ての引数がconst 左辺値参照になっている。

- 関数名は UpperSnake にする。
  - https://google.github.io/styleguide/cppguide.html#Function_Names

- `normalize` より `canonicalize` の方が意図を表している。
  - 今回の正規化は「項目間での横断的な比較体制の確立」なので。
  - https://it.sifr.me/study/the-difference-between-normalize-and-canonicalize/

- 戻り値の型を string にした場合、 RVO (Return Value Optimization) が行われない場合、ヒープメモリーのコピーが発生する。
  - RVOを知らなかった。
    - ここがよくまとまっていた。
    - https://komorinfo.com/blog/copy-elision-in-cpp17/#:~:text=関数内のローカル変数を戻り値として返すときは
    - https://cpprefjp.github.io/lang/cpp17/guaranteed_copy_elision.html

## step3
- 補完なしで7分ほどで実装。
