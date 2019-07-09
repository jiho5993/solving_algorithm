### vscode setting

* setting.json
```{.json}
{ 
    "terminal.integrated.shell.windows": "C:\\Program Files\\Git\\bin\\bash.exe",
    "code-runner.executorMap": {
        "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
        // input.txt로 바로 입력.
        "cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe < input.txt > output.txt"
    },
    "code-runner.runInTerminal": true,
    "workbench.colorTheme": "Monokai Pro (Filter Spectrum)",
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}",
}
```

* Extention
<pre><code>
    Braket Pair Colorizer
    C/C++ (MingW)
    Code Runner
    Korean Language Pack for Visual Studio Code
    Monokai Pro
</code></pre>
