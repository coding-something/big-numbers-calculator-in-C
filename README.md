# Caclculator for multiplication of big numbers in C.

## Highlights

- Info about the program and how it was created.
- Tutorial on how to use the calculator.

## ℹ️ Info about the program and how it was made

This program was originally a solution for a codewars problem, I derived the code from my previous program used for factorial: 
https://github.com/coding-something/factorial-of-big-numbers.
<br> However I realized it can be made into an actual calculator where you can multiply numbers in C without having to worry about integer overflow. This calculator can only multiply, but it has room for improvement which I am willing to explore and in the future I may merge this with the factorial calculator and other parts to make a fully working calculator in C.

## ❓ How to use the calculator

It is simple, just open the exe file or compile the master file and then run it. A terminal window will appear and you can input any numbers, then you will get the result and the program will give you an option to either exit or do another multiplication. It really is that simple, just please be aware that it is fragile and if you input anything else than pure numbers, you will get either a bug (ASCII values for letter for example) or the program will crash. Also there is still a limit for how big the numbers can be, but I am planning to fix that later on.
