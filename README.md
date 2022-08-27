# Teuing : Fun Programming Language
## Run a Program
You can download the source code and the executable too in the Releases. After download it, run the executable file at bin folder and just write this at the shell : 
```
[1] >> -c
[2] >> "yourfilename".teu
```
There is a file for example of the code. The file extentions are `.teu`, for the exit command just follow you can write it too like this : 
```
[1] >> exit
[2] >> yes
```
then it will be showing a "Goodbye" text for a second.
## "Hello World" Program
For making a Hello World program, you just need a 2 line of code : 
```
new text abc "Hello World";
print text abc;
```
This line `new text abc "Hello World;` is for making a new data with a name "abc" and having a text type, and `print text abc;` is for print a data named "abc" with a text type. Every data is saved in different type, so you can actually having a same data name but the types are must be different.
## Data Manipulate
| Keyword | Description                                |
|---------|--------------------------------------------|
|`new`    |Making a new data                           |
|`add`    |Adding a text/integer                       |
|`min`    |For decreasing an integer data              |
|`mul`    |Multiply an integer data                    |
|`div`    |Divide an integer data                      |
|`change` |Change a value of data                      |

Example code :

```
- Concate a string
new text abc "Hello";
print text abc;
add text abc " World";
print text abc;

- Increase, decrease, multiply and divide a data with another number
new integer abb 10;
print integer abb;

- Increase
add integer abb 5;
print integer abb;

- Decrease
min integer abb 5;
print integer abb;

- Multiply
mul integer abb 5;
print integer abb;

- Divide
div integer abb 5;
print integer abb;
```
We dont use a normal evaluation.
## Loop
Its not a loop like any language, its just for showing a number in range.
For Example :
```
loop range(10 until 90) in N outSpace;
```
There are a three different output (`out`, `outSpace`, and `outLine`).
## Other Keywords
The other keyword is for outputing something, for example is `print`, and `show`. `print` is used for showing a data value, and `show` is for showing all data have been made before.
```
print text abc;
show;
```
## Using a Semicolon!
Dont forget to use a semicolon in end of line;
## There's No Error!
Its for fun, dont be stressed:) (actually i'm too lazy for making an error message).