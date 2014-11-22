#Wat Is Code
"A dumber way to program."
"I don't know"
"Wat?"

##No Really, what is this?
We decided there wasn't a coding language stupid enough for beginners.
So we decided to make one!

This language is Turing-complete, and supports most of the features you'd expect in any programming language.

##Under the Hood
Since the compiler was written in C++, we decided to parse the Wat Is Code source file into a C++ source file.
You must compile the supplied *compiler.cc* file, and name the executable as "wiccompiler".

After that, simply run the supplied *wicc* bash script with the format "./wicc <myfile.wic>".
This will compile your supplied *myfile.wic* into a binary executable ("./a.out" by default).

We've only provided a compiler, so you must run "./a.out" to experience the fun!

##Language

###Comments
Usage: UMM *comments*
Notes: You can add an UMM at any point in the program. Anything after this will be ignored, till the end of the line.

###Include
Usage: DO I NEED **library_name**
Notes: Since we compile into C++ source, you can include any C or C++ type library.

###Variables
###Declaration
Usage: I NEED A **type** CALLED **name**
Notes: Declares **name** as a variable of type specified by **type**.
The **type** can be any type accepted in C++. There is no support for enumerated types yet.

###Assignment
Usage: **name** SHOULD BE **value**
Notes: Sets the variable **name** to have a value specified by **value**.

###Operators
Notes: Same as C/C++ (+, -, /, etc...)

###Conditionals
Usage: I THINK **condition**
Notes: If condition

Usage: OR MAYBE **another condition**
Notes: Need to have an "I THINK" before "OR MAYBE".

Usage: I LIED
Notes: Equivalent of an "else"

Usage: RIGHT?
Notes: Required. Ends the if statement.

###Loops
Usage: WATER WATER WATER
Notes: Starts a loop,

Usage: LOOP LOOP LOOP
Notes: Ends a loop.

Usage: RUN FROM GEESE
Notes: Exits from a loop.

###Functions
###Declaration
Usage: **name** FINDS A **type**
Notes: Start a function called **name** that returns type **type**. No input parameters.

Usage: **name** FINDS A **type** FROM A **type** CALLED **name** (AND A **type** CALLED **name** ...)
Notes: Start a function called **name** that returns type **type**.
For the first set of parameters, use "FROM A ..", and for additional parameters, use "AND A ..".
###End
Usage: PLEASE WORK
Notes: Needs to be there to end a function!

###Returns
Usage: I CALCULATED **expression**
Notes: Returns **expression**

###Input
Usage: ASK ABOUT **name**
Notes: Gets value from standard input and puts it into **name**.

###Output
Usage: SHOW ME **expression**
Notes: Outputs an expression (string, variable, number, etc).

#Extras

We now have syntax highlighting support (for Vim).

To use the file, copy `wic.vim` into `~/.vim/syntax/` (and create any needed folders).

Then add the following line into your `.vimrc` file:

```vimscript
au BufRead,BufNewFile *.wic set filetype=wic
```

#Authors
Created by Sameer Chitley, Jami Boy Mohammad and Geoffrey Yu for #SEHackDay 2014.
