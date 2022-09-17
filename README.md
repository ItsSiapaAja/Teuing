# Teuing : Fun Programming Language
## Run a Program
You can download the source code and the executable too in the Releases. After download it, you can put the bin directory in a PATH, then run this command at your shell :
```
Teuing --r (yourfilename).teu
```
Then it will run your `.teu` program.
## What's New In 0.0.5?
- New datatype (`float`, `double`)
## "Hello World" Program
For making a Hello World program, you just need a 2 line of code : 
```
new text abc "Hello World";
print text abc;
```
This line `new text abc "Hello World;` is for making a new data with a name "abc" and having a text type, and `print text abc;` is for print a data named "abc" with a text type. Every data is saved in different type, so you can actually having a same data name but the types are must be different.
## Data Type
There are a 3 different data type (and remember, every different data type has its own storage), the data types are `text`, `integer`, `bool`, `float`, and `double`.
## Data Modifier
| Keyword | Description                                                     |
|---------|-----------------------------------------------------------------|
|`new`    |Making a new data                                                |
|`+`      |Adding a text/integer                                            |
|`-`      |For decreasing an integer data                                   |
|`*`      |Multiply an integer data                                         |
|`/`      |Divide an integer data                                           |
|`change` |Change a value of data                                           |
|`erase`  |Erase a data                                                     |
|`delete` |For clearing all data in specified type                          |

Example code :

```
- Concate a string
new text abc "Hello";
print text abc;
+ text abc " World";
print text abc;

- Increase, decrease, multiply and divide a data with another number
new integer abb 10;
print integer abb;

- Increase
+ integer abb 5;
print integer abb;

- Decrease
- integer abb 5;
print integer abb;

- Multiply
* integer abb 5;
print integer abb;

- Divide
/ integer abb 5;
print integer abb;

- Change a value
change text abc "Halo Semua";
print text abc;

- Erase a data
erase text abc;

- Delete a data
delete text;
```
We dont use a normal evaluation.
## Loop
Its not a loop like any language, its just for showing a number in range.
For Example :
```
loop range(10 until 90) in N outSpace;

loop(range(1 until 10)) start;
print text abc;
```
There are a three different output (`out`, `outSpace`, and `outLine`).
## `label` and `goto` Keyword
`label` will record some of line before they read a `goto` keyword.
For Example:
```
new text abc "Hello World";
new integer abc 10;
new text spc " ";

label a1;

print text abc;
+ text abc ", Teuing is fun";
print text abc;

print text spc;
goto a1;
```
remember you can't use a `label` key when the first `label` is in recording process.
## Other Keywords
The other keyword is for outputing something, for example is `print`, `printspace`, and `show`. `print` is used for showing a data value with a new line, `printspace` is same as `print` but it show a space and not a newline (btw, the boolean output is number, not a string), and `show` is for showing all data have been made before.
```
print text abc;
show;
```
## Section
The `section` is on development, so it must be a lot of bugs (will be updated at 0.0.7)
## Using a Semicolon!
Dont forget to use a semicolon in end of line;
## There's No Error!
Its for fun, dont be stressed:) (actually i'm too lazy for making an error message).