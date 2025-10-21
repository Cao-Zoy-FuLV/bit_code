## Git 忽略文件

// 此为注释 – 将被 Git 忽略
```
*.a        //忽略所有 .a 结尾的文件
!lib.a     //但 lib.a 除外

/TODO      //仅仅忽略项目根目录下的 TODO 文件，不包括 subdir/TODO

node_modules
.project
.vscode

build/    // 忽略 build/ 目录下的所有文件
doc/*.txt    // 会忽略 doc/notes.txt 但不包括 doc/server/arch.txt
```
但有些时候我们会遇到这样的问题：放入gitignore文件夹中的文件却还是被 git index，当你通过 git status 显示文件状态时，他们并没有被忽略。

gitignore 忽略文件，必须先把它们从staged中移除：commit你已有的改变，保存当前的工作。
```git
git rm --cached 地址/文件名
git add .
git commit -m "fixed untracked files"
```
当文件夹是目录时，需要使用 -r 参数（递归）否则会报错
```git
git rm -r --cached .
git add .
git commit -m "update .gitignore"  // windows使用的命令时，需要使用双引号
```
