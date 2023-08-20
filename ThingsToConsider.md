Everything that you need to know is already in the README.md. The purpose of this is to make your life easy and not having to skim through the whole README to know what to do.

I'll assume that you have a Python installed OSX.
To check your python version, run this command on your terminal.
```
python --version
```

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
![Screenshot 2023-08-19 at 8 16 17 PM](https://github.com/M1nJun/SummerResearch23/assets/125623542/8f39a504-41c7-4d66-b404-8d3d2293a1c3)
(8989.txt is a very light test file. Sometimes when you run a test file that runs very quick, you might not see the progress display(percentage) fully updated even though it says its "Done!". This was in fact successfully compiled. This is just because the the program finished compiling faster than the progress update.)
You can see the progress on the console. After the program finishes computing, it automatically creates a jsonl file(in the jsonl directory) after the test file you used.(Ex: 1111.txt -> 1111.jsonl)

That jsonl file is not meant to be human readable. There is a Display program. To use this program you need to install Tkinter(A Graphic User Interface for Python)
If you have python2, run this command on your terminal.
```
pip install tk
```
If this doesn't work, you probably have python 3, try this command instead.
```
pip3 install tk
```

After you've installed Tkinter, run this command on your terminal.
```
./Display.py
```
If you have python3, run this command instead.
```
python3 Display.py
```
A window should appear.
![Screenshot 2023-08-19 at 8 13 27 PM](https://github.com/M1nJun/SummerResearch23/assets/125623542/e2376f5b-3c09-43d3-a688-f996271b6654)

Open the corresponding .jsonl file with the open file button.
![Screenshot 2023-08-19 at 8 33 43 PM](https://github.com/M1nJun/SummerResearch23/assets/125623542/6d0e6ab1-211f-45d5-8c97-be2749629dc1)

It should say on the display that the file was loaded.
![Screenshot 2023-08-19 at 8 35 13 PM](https://github.com/M1nJun/SummerResearch23/assets/125623542/0a59ca2e-560e-426b-b3bd-8e80f3a73599)


When you compiled the test file using the Search.exe, you should have received an "n" number of examples did the program found.
(From my example with the 8989.txt file, recall that it "found 2 examples.")
That "n" is the number of IDs with the range of 1 ~ n you can use on the display.
Enter the ID number on the blank text field to see the examples that were found.
![Screenshot 2023-08-19 at 8 14 27 PM](https://github.com/M1nJun/SummerResearch23/assets/125623542/dfee853b-6893-4098-8226-251482ef2b8d)
You can use the left and right arrow key on your keyboard to go back and forth between your examples. Keep in mind, when you go out of bounds, it will throw you an error.
