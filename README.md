# myenvプログラムの作成

```env```コマンドのクローン```myenv```プログラムを作りなさい．

### 作成
1. myenvの仕様<br>
envは環境変数を初期化した上でプログラム（コマンド）を実行します．<br>
```env [name=value ...] [command [argument ...]]```<br>
```name=value```代入形式の文字列は環境変数の値を決定する．<br>
```command [argument ...]```は実行するプログラム（コマンド）と引数である．<br>
本物では```command [argument ...]```部分を省略できるが，
シスプロ宿題版では省略した場合はエラーとして扱っても良い．

2. myenvプログラムの作成<br>
レポジトリをクローンし```myenv.c```を編集してプログラムを完成する．<br>
上の仕様を満たすプログラムを美しくコーディングする．<br>
できたと思ったら十分な動作テストを行う．

### コンパイル方法
```Makefile```を準備してあるので```make```コマンドでコンパイルできる．

```
$ make
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c
$
```
