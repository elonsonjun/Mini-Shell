# 🐚 MiniShell - Advanced Modular C Shell

Welcome to **MiniShell**, a powerful, modular, and feature-rich shell written in C.  
Inspired by Bash, with fantasy commands, autocorrection, environment logic, and interactive dashboards, MiniShell is built for learning, experimenting, and having fun with the command line.

---

## 📦 Features

- ✅ Modular file structure (14+ C files)
- 🎯 Auto-correction of mistyped commands
- ⏳ Command history and timestamps
- 🧙 Fantasy commands like `summon`, `quantum`, `fortune`
- 🧠 Environment management: `setenv`, `unsetenv`, `printenv`
- 📊 Interactive session dashboard (`stats`)
- ⛑️ Signal handling (`Ctrl+C`, `Ctrl+Z`)
- 📁 Config loader via `.minirc`
- 📜 Logger with timestamps
- 🔧 Debug/Release/Valgrind support
- 🎨 Colorized Makefile with testing/linting/git helpers

---

## 📁 File Structure

minishell/
├── main.c
├── parser.c
├── executor.c
├── builtins.c
├── utils.c
├── history.c
├── dashboard.c
├── fantasy.c
├── autocorrect.c
├── signals.c
├── logger.c
├── config.c
├── Makefile
├── Makefile.advanced
├── README.md
└── tests/

yaml
Copy
Edit

---

## 🛠️ Build & Run

### ⚙️ Build with default `Makefile`
```bash
make
🚀 Run the shell
bash
Copy
Edit
./minishell
🧹 Clean binaries
bash
Copy
Edit
make clean
🧪 Advanced Makefile Usage
bash
Copy
Edit
make -f Makefile.advanced           # full build
make run                            # build and run
make lint                           # static code analysis (cppcheck)
make valgrind                       # memory leak test
make debug                          # compile with debug symbols
make release                        # optimized build
make install                        # install shell to /usr/local/bin
make uninstall                      # remove from system
make backup                         # backup source files
make test                           # run all test cases (from tests/)
make git-status                     # show git status
make notify                         # bell notification on build
🐚 Shell Command Examples
Built-in commands:
bash
Copy
Edit
cd /home/user
exit
history
clear
printenv
setenv MODE dev
unsetenv MODE
Fantasy commands:
bash
Copy
Edit
quantum             # Prints quantum-style pseudo-output
summon dragon       # Summons a "dragon" 🐉
fortune             # Shows a random quote
dance               # Prints a funky ASCII dance 💃
⚙️ Bash Integration
You can invoke MiniShell from your terminal:

bash
Copy
Edit
# Start minishell from bash
./minishell

# Pipe output to minishell
echo "ls -l" | ./minishell
⚡ .minirc Example
Create a .minirc in your home directory:

ini
Copy
Edit
USER=sonjun
MODE=developer
EDITOR=nano
MiniShell will read and load these variables at startup.

🧩 Auto-Correction Feature
If you type a mistyped command like:

bash
Copy
Edit
hsitory
MiniShell will auto-suggest:

matlab
Copy
Edit
🤖 Did you mean 'history' instead of 'hsitory'?
📜 Logging
Every executed command gets saved in .minilog with a timestamp:

bash
Copy
Edit
[2025-06-18 10:24:31] ls -l
[2025-06-18 10:24:35] cd /usr/bin
📊 Session Dashboard (stats)
Example output:

yaml
Copy
Edit
🧠 Session Summary:
Commands executed: 12
Time active: 04m 18s
Most used command: cd
Longest command: git commit -am "refactor: shell parser"
💻 Developer Notes
All source files use consistent header shell.h

Use MAX_INPUT to adjust shell buffer size

Modular design: each component has a single responsibility

🧪 Testing Guide
Place test files inside /tests

Write test.c programs and compile them with a local Makefile

Sample test case:

c
Copy
Edit
// tests/test_parser.c
#include "../shell.h"
int main() {
    char *input = "ls -l";
    char **args = tokenize(input);
    printf("First token: %s\n", args[0]);
}
