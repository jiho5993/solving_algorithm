### vscode setting

* setting.json - window ver
```{.json}
{ 
    "terminal.integrated.shell.windows": "C:\\Program Files\\Git\\bin\\bash.exe",
    "code-runner.executorMap": {
        "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
        // input.txt로 바로 입력.
        "cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe < input.txt > output.txt && rm $fileNameWithoutExt.exe"
    },
    "code-runner.runInTerminal": true,
    "workbench.colorTheme": "Monokai Pro (Filter Spectrum)",
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}",
    "window.zoomLevel": 0,
}
```

* settings.json - mac ver
```{.json}
{
    "editor.tabSize": 4,
    "editor.formatOnPaste": true,
    "editor.formatOnSave": true,
    "editor.insertSpaces": true,
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}",
    "code-runner.executorMap": {
        "javascript": "cd $dir && node $fileName",
        "ocaml": "cd $dir && ocaml $fileName",
        "c": "cd $dir && gcc $fileName -o test.exe && ./test.exe < input.txt > output.txt && echo  && echo ----done---- && rm ./test.exe",
        "cpp": "cd $dir && g++ $fileName -o test.exe && ./test.exe < input.txt > output.txt && echo  && echo ----done---- && rm ./test.exe"
    },
    "code-runner.runInTerminal": true
}
```

* Extention
<pre><code>
    Braket Pair Colorizer
    C/C++ (MingW)
    Code Runner
    Korean Language Pack for Visual Studio Code
    Monokai Pro
    * settings sync
</code></pre>
