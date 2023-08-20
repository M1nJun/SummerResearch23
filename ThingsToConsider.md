Everything that you need to know is already in the README.md. The purpose of this is to make your life easy and not having to skim through the whole README to know what to do.

I'll assume that you have a Python3 installed OSX.
You need to create a Search.exe to run the program.
Run this command on your terminal.

```
g++ -std=c++17 -Ofast -flto src/*.cpp -o Search.exe
```

Remember to update(re-create) the Search.exe when you've made a change to the code.(Ex: hardcoded new curve configurations)

With the Search.exe you've created, you can run the test file(should be located in the Tests directory).
Run this command on your terminal.

```
./Search.exe Tests/<test>.txt
```

You can see the progress on the console. After the program finishes computing, it automatically creates a jsonl file(in the jsonl directory) after the test file you used.(Ex: 1111.txt -> 1111.jsonl)

That jsonl file is not meant to be human readable. There is a Display program.
Run this command on your terminal.

```
python3 Display.py
```

Open the corresponding .jsonl file with the open file button.
