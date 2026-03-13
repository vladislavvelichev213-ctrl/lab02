# Отчет по лабораторной работе №2
## Системы контроля версий на примере Git

**Студент:** Владислав Величев  
**Дата выполнения:** 13.03.2026

---

## 1. Подготовка и настройка

### 1.1 Установка Git

```bash
sudo apt install git
```

**Листинг вывода:**
```
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
git is already the newest version (1:2.43.0-1ubuntu7).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
```

### 1.2 Настройка переменных окружения

```bash
export GITHUB_USERNAME="vladislavvelichev213-ctrl"
export GITHUB_EMAIL="vladislavvelichev213@gmail.com"
export GITHUB_TOKEN="ghp_23b...."

echo $GITHUB_USERNAME
echo $GITHUB_EMAIL
```

**Листинг вывода:**
```
vladislavvelichev213-ctrl
vladislavvelichev213@gmail.com
```

### 1.3 Настройка Git

```bash
git config --global user.name "vladislavvelichev213-ctrl"
git config --global user.email "vladislavvelichev213@gmail.com"

git config --global --list
```

**Листинг вывода:**
```
user.name=vladislavvelichev213-ctrl
user.email=vladislavvelichev213@gmail.com
```

### 1.4 Клонирование репозитория

```bash
git clone https://github.com/vladislavvelichev213-ctrl/lab02.git
cd lab02
ls -la
```

**Листинг вывода:**
```
Cloning into 'lab02'...
warning: You appear to have cloned an empty repository.

total 12
drwxrwxr-x 3 ubuntu ubuntu 4096 Mar 13 15:40 .
drwxr-x--- 17 ubuntu ubuntu 420 Mar 13 15:40 ..
drwxrwxr-x 7 ubuntu ubuntu 4096 Mar 13 15:40 .git
```

---

## 2. Выполнение Tutorial

### 2.1 Создание README.md

```bash
cat > README.md <<'EOF'
# Lab02
## Git Version Control System

This repository contains laboratory work #2 on Git.
EOF

cat README.md
```

**Листинг вывода:**
```markdown
# Lab02
## Git Version Control System

This repository contains laboratory work #2 on Git.
```

### 2.2 Первый коммит

```bash
git add README.md
git status
git commit -m "initial commit"
```

**Листинг вывода:**
```
On branch main

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md

[main (root-commit) 1616be0] initial commit
 1 file changed, 4 insertions(+)
 create mode 100644 README.md
```

### 2.3 Отправка на GitHub

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 298 bytes | 298.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To https://github.com/vladislavvelichev213-ctrl/lab02.git
 * [new branch]      main -> main
```

### 2.4 Создание .gitignore

```bash
cat > .gitignore <<'EOF'
*build*/
*install*/
*.swp
.idea/
EOF

cat .gitignore
```

**Листинг вывода:**
```
*build*/
*install*/
*.swp
.idea/
```

```bash
git add .gitignore
git commit -m "Add .gitignore"
git push origin main
```

**Листинг вывода:**
```
[main 6c7a30f] Add .gitignore
 1 file changed, 4 insertions(+)
 create mode 100644 .gitignore

Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 2 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 343 bytes | 343.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To https://github.com/vladislavvelichev213-ctrl/lab02.git
   1616be0..6c7a30f  main -> main
```

### 2.5 Создание структуры проекта

```bash
mkdir sources include examples
ls -la
```

**Листинг вывода:**
```
total 28
drwxrwxr-x 5 ubuntu ubuntu 4096 Mar 13 16:15 .
drwxr-x--- 17 ubuntu ubuntu 420 Mar 13 15:40 ..
drwxrwxr-x 8 ubuntu ubuntu 4096 Mar 13 16:10 .git
-rw-r--r-- 1 ubuntu ubuntu   30 Mar 13 16:10 .gitignore
-rw-r--r-- 1 ubuntu ubuntu   71 Mar 13 15:50 README.md
drwxrwxr-x 2 ubuntu ubuntu 4096 Mar 13 16:15 examples
drwxrwxr-x 2 ubuntu ubuntu 4096 Mar 13 16:15 include
drwxrwxr-x 2 ubuntu ubuntu 4096 Mar 13 16:15 sources
```

### 2.6 Создание файлов исходного кода

**sources/print.cpp:**

```bash
cat > sources/print.cpp <<'EOF'
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF

cat sources/print.cpp
```

**Листинг вывода:**
```cpp
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
```

**include/print.hpp:**

```bash
cat > include/print.hpp <<'EOF'
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF

cat include/print.hpp
```

**Листинг вывода:**
```cpp
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
```

**examples/example1.cpp:**

```bash
cat > examples/example1.cpp <<'EOF'
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF

cat examples/example1.cpp
```

**Листинг вывода:**
```cpp
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
```

**examples/example2.cpp:**

```bash
cat > examples/example2.cpp <<'EOF'
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF

cat examples/example2.cpp
```

**Листинг вывода:**
```cpp
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
```

### 2.7 Обновление README.md

```bash
cat > README.md <<'EOF'
# Lab02
## Git Version Control System

This repository contains laboratory work #2 on Git.

## Project Structure
- **include/** - Header files
  - print.hpp - Function declarations for printing
- **sources/** - Source files
  - print.cpp - Function implementations for printing
- **examples/** - Example programs
  - example1.cpp - Prints to console
  - example2.cpp - Prints to file

## Description
The project implements simple printing functions that can output text
to either console (std::cout) or file (std::ofstream).

## Author
Vladislav Velichev
EOF

cat README.md
```

### 2.8 Коммит всех изменений

```bash
git status
git add .
git status
git commit -m "added sources"
git push origin main
```

**Листинг вывода:**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        examples/
        include/
        sources/

no changes added to commit (use "git add" and/or "git commit -a")

On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   README.md
        new file:   examples/example1.cpp
        new file:   examples/example2.cpp
        new file:   include/print.hpp
        new file:   sources/print.cpp

[main a51d669] added sources
 5 files changed, 48 insertions(+)
 create mode 100644 examples/example1.cpp
 create mode 100644 examples/example2.cpp
 create mode 100644 include/print.hpp
 create mode 100644 sources/print.cpp

Enumerating objects: 12, done.
Counting objects: 100% (12/12), done.
Delta compression using up to 2 threads
Compressing objects: 100% (8/8), done.
Writing objects: 100% (10/10), 1.22 KiB | 1.22 MiB/s, done.
Total 10 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/vladislavvelichev213-ctrl/lab02.git
   6c7a30f..a51d669  main -> main
```

---

## 3. Домашнее задание Part I

### 3.1 Создание hello_world.cpp с плохим стилем

```bash
cat > hello_world.cpp <<'EOF'
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
EOF

cat hello_world.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
```

### 3.2 Добавление и коммит

```bash
git add hello_world.cpp
git status
git commit -m "Add hello world program with bad style"
```

**Листинг вывода:**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   hello_world.cpp

[main 6e5798c] Add hello world program with bad style
 1 file changed, 8 insertions(+)
 create mode 100644 hello_world.cpp
```

### 3.3 Изменение кода для ввода имени

```bash
cat > hello_world.cpp <<'EOF'
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
}
EOF

cat hello_world.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
}
```

### 3.4 Коммит изменений

```bash
git commit -am "Add user input to hello world program"
```

**Листинг вывода:**
```
[main 01c6677] Add user input to hello world program
 1 file changed, 5 insertions(+), 2 deletions(-)
```

### 3.5 Отправка на GitHub

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 2 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (5/5), 598 bytes | 598.00 KiB/s, done.
Total 5 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/vladislavvelichev213-ctrl/lab02.git
   a51d669..01c6677  main -> main
```

---

## 4. Домашнее задание Part II

### 4.1 Создание ветки patch1

```bash
git checkout -b patch1
git branch
```

**Листинг вывода:**
```
Switched to a new branch 'patch1'
  main
* patch1
```

### 4.2 Исправление кода (убираем using namespace std)

```bash
cat > hello_world.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF

cat hello_world.cpp
git commit -am "Remove using namespace std"
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}

[patch1 9509677] Remove using namespace std
 1 file changed, 4 insertions(+), 2 deletions(-)
```

### 4.3 Отправка ветки на GitHub

```bash
git push origin patch1
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 367 bytes | 367.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/vladislavvelichev213-ctrl/lab02/pull/new/patch1
remote: 
To https://github.com/vladislavvelichev213-ctrl/lab02.git
 * [new branch]      patch1 -> patch1
```

### 4.4 Добавление комментариев

```bash
cat > hello_world.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    // Variable to store user's name
    std::string name;
    
    // Prompt user for input
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Display greeting
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF

cat hello_world.cpp
git commit -am "Add comments to code"
git push origin patch1
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    // Variable to store user's name
    std::string name;
    
    // Prompt user for input
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Display greeting
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}

[patch1 01cc411] Add comments to code
 1 file changed, 5 insertions(+), 1 deletion(-)

Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 412 bytes | 412.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/vladislavvelichev213-ctrl/lab02.git
   9509677..01cc411  patch1 -> patch1
```

### 4.5 Слияние Pull Request и удаление ветки

```bash
git checkout main
git pull origin main
git branch -d patch1
git branch
```

**Листинг вывода:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.

remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (1/1), done.
From https://github.com/vladislavvelichev213-ctrl/lab02
 * branch            main       -> FETCH_HEAD
   01c6677..0f1781a  main       -> origin/main
Updating 01c6677..0f1781a
Fast-forward
 hello_world.cpp | 9 +++++++--
 1 file changed, 7 insertions(+), 2 deletions(-)

Deleted branch patch1 (was 01cc411).

* main
```

---

## 5. Домашнее задание Part III

### 5.1 Установка clang-format

```bash
sudo apt install clang-format -y
clang-format --version
```

**Листинг вывода:**
```
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
clang-format is already the newest version (1:20.0-63ubuntu1).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.

Ubuntu clang-format version 20.1.8
```

### 5.2 Создание ветки patch2

```bash
git checkout -b patch2
git branch
```

**Листинг вывода:**
```
Switched to a new branch 'patch2'
  main
* patch2
```

### 5.3 Форматирование кода в стиле Mozilla

```bash
clang-format -style=Mozilla -i hello_world.cpp
cat hello_world.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int
main()
{
  // Variable to store user's name
  std::string name;

  // Prompt user for input
  std::cout << "Enter your name: ";
  std::cin >> name;

  // Display greeting
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}
```

### 5.4 Коммит и push ветки patch2

```bash
git commit -am "Apply Mozilla code style"
git push origin patch2
```

**Листинг вывода:**
```
[patch2 3b8f2f5] Apply Mozilla code style
 1 file changed, 5 insertions(+), 3 deletions(-)

Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 412 bytes | 412.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/vladislavvelichev213-ctrl/lab02/pull/new/patch2
remote: 
To https://github.com/vladislavvelichev213-ctrl/lab02.git
 * [new branch]      patch2 -> patch2
```

### 5.5 Создание конфликта в ветке main

```bash
git checkout main
cat > hello_world.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    // Переменная для хранения имени пользователя
    std::string name;
    
    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Вывод приветствия
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF

cat hello_world.cpp
git commit -am "Translate comments to Russian"
git push origin main
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    // Переменная для хранения имени пользователя
    std::string name;
    
    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Вывод приветствия
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}

[main b0fb2ed] Translate comments to Russian
 1 file changed, 3 insertions(+), 3 deletions(-)

Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 398 bytes | 398.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/vladislavvelichev213-ctrl/lab02.git
   0f1781a..b0fb2ed  main -> main
```

### 5.6 Разрешение конфликта через rebase

```bash
git checkout patch2
git pull --rebase origin main
```

**Листинг вывода:**
```
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 1), reused 3 (delta 1), pack-reused 0
Unpacking objects: 100% (3/3), done.
From https://github.com/vladislavvelichev213-ctrl/lab02
 * branch            main       -> FETCH_HEAD
   0f1781a..b0fb2ed  main       -> origin/main
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 3b8f2f5... Apply Mozilla code style
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 3b8f2f5... Apply Mozilla code style
```

### 5.7 Исправление конфликта

```bash
cat > hello_world.cpp <<'EOF'
#include <iostream>
#include <string>

int
main()
{
    // Переменная для хранения имени пользователя
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF

cat hello_world.cpp
git add hello_world.cpp
git rebase --continue
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int
main()
{
    // Переменная для хранения имени пользователя
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}

[detached HEAD 874dbf5] Apply Mozilla code style
 1 file changed, 4 insertions(+), 3 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```

### 5.8 Force push и слияние

```bash
git push --force origin patch2
git checkout main
git pull origin main
git branch -d patch2
git log --oneline --graph --all
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 322 bytes | 322.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/vladislavvelichev213-ctrl/lab02.git
 + 3b8f2f5...874dbf5 patch2 -> patch2 (forced update)

Switched to branch 'main'
Your branch is up to date with 'origin/main'.

remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 908 bytes | 908.00 KiB/s, done.
From https://github.com/vladislavvelichev213-ctrl/lab02
 * branch            main       -> FETCH_HEAD
   b0fb2ed..f19bfaf  main       -> origin/main
Updating b0fb2ed..f19bfaf
Fast-forward
 hello_world.cpp | 7 ++++---
 1 file changed, 4 insertions(+), 3 deletions(-)

Deleted branch patch2 (was 874dbf5).

*   f19bfaf (HEAD -> main, origin/main) Merge pull request #2 from vladislavvelichev213-ctrl/patch2
|\  
| * 874dbf5 (origin/patch2) Apply Mozilla code style
|/  
* b0fb2ed Translate comments to Russian
*   0f1781a Merge pull request #1 from vladislavvelichev213-ctrl/patch1
|\  
| * 01cc411 (origin/patch1) Add comments to code
| * 9509677 Remove using namespace std
|/  
* 01c6677 Add user input to hello world program
* 6e5798c Add hello world program with bad style
* a51d669 added sources
* 6c7a30f Add .gitignore
* 1616be0 initial commit
```

---

## 6. Выводы

В ходе выполнения лабораторной работы были изучены основные возможности системы контроля версий Git:

1. **Создание и клонирование репозиториев** (`git init`, `git clone`)
2. **Добавление и коммит изменений** (`git add`, `git commit`)
3. **Работа с ветками** (`git branch`, `git checkout`, `git merge`)
4. **Синхронизация с удаленным репозиторием** (`git push`, `git pull`)
5. **Разрешение конфликтов** при слиянии веток
6. **Использование rebase** для обновления веток
7. **Работа с Pull Request** на GitHub
8. **Автоматическое форматирование кода** с помощью `clang-format`

**Ссылка на репозиторий:** https://github.com/vladislavvelichev213-ctrl/lab02
```
