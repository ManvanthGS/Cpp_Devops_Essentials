Below is a **clean, professional, complete README** for your project.
It includes:

✔ CMake
✔ CMakePresets
✔ clang-format
✔ clang-tidy
✔ editorconfig
✔ VS Code setup
✔ Required extensions
✔ Best practices
✔ Tips for maintaining a clean C++ project

You can copy this directly as your project’s `README.md`.

---

# 📘 Modern C++ Starter Template

### **CMake + clang-format + clang-tidy + EditorConfig + VS Code**

This project provides a clean, modern, production-ready starting point for any C++20 application.
The goal is to enforce:

* consistent formatting
* strict static analysis
* editor-independent indentation rules
* reproducible builds
* clean project structure

Everything is already configured and ready to use in VS Code.

---

# 📁 Project Structure

```
my-cpp-project/
├── CMakeLists.txt
├── CMakePresets.json
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── .gitignore
├── .vscode/
│   ├── settings.json
│   ├── tasks.json
│   ├── launch.json
│   └── extensions.json
└── src/
    └── main.cpp
```

No tests are included (minimal setup).

---

# 🚀 Getting Started

## 1. Install Dependencies

### Required:

* **CMake ≥ 3.15**
* **Clang / LLVM (clang-format + clang-tidy)**
* **VS Code**
* **C/C++ Build Tools** (gcc/clang/MSVC)

### Optional but recommended:

* **Ninja** (faster builds)

---

## 2. Configure the Project

Using CMake presets:

```bash
cmake --preset default
```

This generates:

```
build/
    compile_commands.json
    ...
```

---

## 3. Build the Project

```bash
cmake --build --preset build
```

The executable will be:

```
build/my_app
```

Run:

```bash
./build/my_app
```

---

# 🧹 Code Formatting (clang-format)

The project includes a configured `.clang-format` file.

### Format automatically in VS Code

Enabled via:

```json
"editor.formatOnSave": true
```

### Format manually:

```bash
clang-format -i src/main.cpp
```

---

# 🔍 Static Analysis (clang-tidy)

clang-tidy enforces:

* naming conventions
* readability improvements
* modern C++ rules
* bug warnings
* performance suggestions

### Runs automatically in VS Code

Configured via:

```json
"C_Cpp.codeAnalysis.clangTidy.enabled": true
```

### Optional: enable during build

```bash
cmake --preset with-tidy
cmake --build --preset build-with-tidy
```

### Run manually:

```bash
clang-tidy src/main.cpp --config-file=.clang-tidy
```

---

# 📝 EditorConfig Support

`.editorconfig` ensures consistent formatting **across all editors**, defining:

* indentation
* charset
* trimming whitespace
* max line length
* newline rules

VS Code reads this automatically using the EditorConfig extension.

---

# 🧩 VS Code Integration

VS Code settings are pre-configured to:

* Format with clang-format on save
* Run clang-tidy for diagnostics
* Use CMake Tools with presets
* Detect compile commands
* Provide proper IntelliSense

`code .` from project root will automatically load everything.

---

# 🔌 Recommended Extensions (auto-suggested via `.vscode/extensions.json`)

| Extension                      | Why                                       |
| ------------------------------ | ----------------------------------------- |
| **C/C++ (ms-vscode.cpptools)** | IntelliSense + debugging                  |
| **CMake Tools**                | Configure/Build/Debug targets via VS Code |
| **CMake Syntax (twxs.cmake)**  | CMake highlighting                        |
| **clang-format**               | Required for formatting                   |
| **clang-tidy**                 | Static analysis UI                        |
| **GitLens**                    | Git history & blame                       |
| **EditorConfig**               | Enforce `.editorconfig` rules             |
| **Spell Checker**              | Avoid variable-name typos                 |

VS Code will prompt you to install them automatically.

---

# 🧠 Best Practices for a Clean C++ Project

## ✔ 1. Keep all source files inside `src/`

Avoid mixing headers, CMake files, and tooling settings.

## ✔ 2. Always use presets for builds

Avoid `cmake .`, use:

```
cmake --preset default
cmake --preset with-tidy
```

Ensures reproducible builds across machines.

## ✔ 3. Do not manually edit generated files

Never touch files inside `/build`.

## ✔ 4. Use clang-format before every commit

Run automatically:

```bash
clang-format -i src/*.cpp
```

or enable a Git pre-commit hook.

## ✔ 5. Fix clang-tidy warnings early

Letting warnings accumulate leads to “lint debt”.

## ✔ 6. Organize larger projects into libraries

Example future structure:

```
src/
  algorithms/
  ds/
  utils/
  core/
```

## ✔ 7. Use a compiler with sanitizers for debugging

E.g.:

```
-fsanitize=address,undefined
```

We can integrate this into CMake later.

## ✔ 8. Avoid global variables and singletons

Enable clang-tidy checks to warn on these patterns.

## ✔ 9. Prefer C++ standard library utilities by default

Let clang-tidy warn when you're reinventing STL containers.

## ✔ 10. Use EditorConfig + clang-format consistently

Consistency across machines is the biggest win.

---

# 💡 Useful Tips

### 🔸 Use VS Code preset buttons

Click “Configure Project” → “Build” without using terminal.

### 🔸 Use “Go to Definition” via clangd or cpptools

Better indexing = faster navigation.

### 🔸 Enable autosave for smoother formatting

VS Code → Settings → `files.autoSave = "onFocusChange"`

### 🔸 Keep dependencies minimal

Less noise → cleaner template.

### 🔸 Add a CI pipeline later

We can add GitHub Actions to run:

* clang-format check
* clang-tidy
* CMake build

---

# 🎉 You’re Ready to Code

This template is now:

* clean
* modern
* reproducible
* well-formatted
* well-analyzed
* editor-independent
* VS Code optimized

As next steps, I can help you add:

* GoogleTest integration
* Sanitizers (`ASAN`, `UBSAN`)
* GitHub Actions CI
* A modular library architecture
* Custom clang-tidy rules
* Conan package manager integration

Just tell me!