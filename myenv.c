/*
 *  myenv.c : env コマンドのクローン
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
    if (argc == 1) {
        // 環境変数一覧を表示
        for (char **env = envp; *env != 0; env++) {
            printf("%s\n", *env);
        }
        return 0;
    }

    int i = 1;
    while (i < argc && strchr(argv[i], '=') != NULL) {
        // 環境変数を設定
        putenv(argv[i]);
        i++;
    }

    if (i < argc) {
        // コマンドを実行
        execvp(argv[i], &argv[i]);
        perror("execvp");
        return 1;
    } else {
        // 環境変数一覧を表示
        extern char **environ;
        for (char **env = environ; *env != 0; env++) {
            printf("%s\n", *env);
        }
        return 0;
    }
}

/* 実行例

% make
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c
%./myenv    <-環境変数の変更とコマンド実行なしの場合
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/1d/b7csmwyd6_95gmlrdg1j03140000gn/T/
TERM_PROGRAM_VERSION=452
TERM_SESSION_ID=F5CE2967-70C3-43A0-BE9A-751803170A57
USER=murafuto
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.NbQVx7CTqm/Listeners
PATH=/Library/Frameworks/Python.framework/Versions/3.12/bin:
/Library/Frameworks/Python.framework/Versions/3.6/bin:/usr
/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:
/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd
/codex.system/bootstrap/usr/local/bin:/var/run
/com.apple.security.cryptexd/codex.system/bootstrap
/usr/bin:/var/run/com.apple.security.cryptexd
/codex.system/bootstrap/usr/appleinternal/bin
LaunchInstanceID=E008B95C-50BF-4B93-96D1-46BE6CB6D601
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/murafuto/Syspro/kadai09-i20muraoka
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/murafuto
LOGNAME=murafuto
SECURITYSESSIONID=186a1
OLDPWD=/Users/murafuto/Syspro
LANG=ja_JP.UTF-8

%./myenv LANG=c 　　<-元々ある環境変数の変更を指示した場合
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/1d/b7csmwyd6_95gmlrdg1j03140000gn/T/
TERM_PROGRAM_VERSION=452
TERM_SESSION_ID=F5CE2967-70C3-43A0-BE9A-751803170A57
USER=murafuto
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.NbQVx7CTqm/Listeners
PATH=/Library/Frameworks/Python.framework/Versions/3.12/bin:/Library
/Frameworks/Python.framework/Versions/3.6/bin:/usr/local/bin:/System
/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run
/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:
/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:
/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin
LaunchInstanceID=E008B95C-50BF-4B93-96D1-46BE6CB6D601
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/murafuto/Syspro/kadai09-i20muraoka
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/murafuto
LOGNAME=murafuto
SECURITYSESSIONID=186a1
OLDPWD=/Users/murafuto/Syspro
LANG=c
_=/Users/murafuto/Syspro/kadai09-i20muraoka/./myenv

% ./myenv LC_TIME=c <-元々ない環境変数の変更を指示した場合
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/1d/b7csmwyd6_95gmlrdg1j03140000gn/T/
TERM_PROGRAM_VERSION=452
TERM_SESSION_ID=F5CE2967-70C3-43A0-BE9A-751803170A57
USER=murafuto
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.NbQVx7CTqm/Listeners
PATH=/Library/Frameworks/Python.framework/Versions/3.12/bin:/Library/Frameworks/Python.framework/Versions/3.6/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin
LaunchInstanceID=E008B95C-50BF-4B93-96D1-46BE6CB6D601
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/murafuto/Syspro/kadai09-i20muraoka
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/murafuto
LOGNAME=murafuto
SECURITYSESSIONID=186a1
OLDPWD=/Users/murafuto/Syspro
LANG=ja_JP.UTF-8
_=/Users/murafuto/Syspro/kadai09-i20muraoka/./myenv
LC_TIME=c

./myenv LC_TIME=c LANG=c <-2つの環境変数の変更を指示した場合
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/1d/b7csmwyd6_95gmlrdg1j03140000gn/T/
TERM_PROGRAM_VERSION=452
TERM_SESSION_ID=F5CE2967-70C3-43A0-BE9A-751803170A57
USER=murafuto
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.NbQVx7CTqm/Listeners
PATH=/Library/Frameworks/Python.framework/Versions/3.12/bin:
/Library/Frameworks/Python.framework/Versions/3.6/bin:/usr
/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr
/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system
/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd
・codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd
/codex.system/bootstrap/usr/appleinternal/bin
LaunchInstanceID=E008B95C-50BF-4B93-96D1-46BE6CB6D601
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/murafuto/Syspro/kadai09-i20muraoka
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/murafuto
LOGNAME=murafuto
SECURITYSESSIONID=186a1
OLDPWD=/Users/murafuto/Syspro
LANG=c
_=/Users/murafuto/Syspro/kadai09-i20muraoka/./myenv
LC_TIME=c

% ./myenv date <-コマンドを実行した場合
2024年 7月 2日 火曜日 17時01分51秒 JST
% ./myenv LANG=c date <-環境変数の変更とコマンドの実行をした場合
Tue Jul  2 20:02:15 JST 2024
% ./myenv date A <-コマンドの引数が違う場合
date: illegal time format
usage: date [-jnRu] [-I[date|hours|minutes|seconds]] [-f input_fmt]
            [-r filename|seconds] [-v[+|-]val[y|m|w|d|H|M|S]]
            [[[[mm]dd]HH]MM[[cc]yy][.SS] | new_date] [+output_fmt]
% ./myenv a <-引数のコマンドがない場合
execvp: No such file or directory
*/
