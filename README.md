# gitflow-tutorial
Gitflowの使い方を学ぶためのリポジトリです。
実践的にGitflowを学びましょう。

## Gitflowとは
Gitflowは、[Vincent Driessen](https://github.com/nvie)氏によって提唱されたGitのブランチモデル。

Gitflowは、以下の5つのブランチを使って開発を進めます。

- master(main): リリースされたコードを管理するブランチ
- develop: 開発中のコードを管理するブランチ
- feature: 機能の追加や修正を行うブランチ(feature/XXX)
- release: リリース前の最終調整を行うブランチ(release/vX.X.X)
- hotfix: リリース後の緊急修正を行うブランチ(hotfix/XXX)
<img src="/asset/img/gitflow.jpeg" width="400px">

### Github Flowとの違い
Github Flowは、masterブランチだけを使って開発を進めるブランチモデルです。

Github Flowは、masterブランチに直接コードをマージするため、masterブランチが常にデプロイ可能な状態を保つ必要があります。

一方、Gitflowは、masterブランチ以外にも開発用のブランチを使うため、masterブランチは常に安定した状態を保つことができます。

<img src="/asset/img/githubflow.jpeg" width="400px">

※ 上記ではmasterとなっているが、昨今mainの方が主流です(masterの対義語にはslaveがあり差別用語的なものらしい)。

## Gitflowの流れ
Gitflowの開発フローは以下の通りです。
1. develop から feature を切る
2. feature で機能の追加や修正を行う
3. feature を develop にマージする
4. develop から release を切る
5. release でリリース前の最終調整を行う
6. release を master(main) と develop にマージする
7. master(main) から hotfix を切る
8. hotfix でリリース後の緊急修正を行う
9. hotfix を master(main) と develop にマージする
10. master(main) をリリースする
以下、ループ。

# 参考サイト
- [【図解】git-flow、GitHub Flowを開発現場で使い始めるためにこれだけは覚えておこう](https://atmarkit.itmedia.co.jp/ait/articles/1708/01/news015.html)
