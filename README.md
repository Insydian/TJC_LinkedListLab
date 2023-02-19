# TJC_LinkedListLab
The goal of this lab is to use a Song struct provided by the instructor and use it in the provided linked list class

### Problems encountered
I had several problems that I encountered. 
- I dumped several hours into my randomSongGenerator() class because I was setting the srand() to the current time and calling it a lot.
- I could not directly compare items in search
- I had a compiler error with the != operator
- I could not directly use the deleteNode function because of it directly printing the object to the console
### Solutions
Here are my Solutions:
- randomSongGenerator()
This took the most time probably. The main problem is that it worked well in my ""debuger"" but did not work during runtime. I spent hours on this, srand() sets the initial seed of random which is common practice to get fairly random results. Common practice dictates that srand is passed in the current time as the seed. Which is fine if you are only using random once a second. However I was calling it many times a microsecond. This resulted in the same number being used for all the calls to rand() that I used. It worked fine on the debugger because I would make a call to random more than every second. So in the debugger I could not tell what was wrong. This was solved through a couple hours of trial and error widdling down the variables. I eliminated LinkedList.h as a suspect when I used std::forward_list and still got the same problem. I used a different implementation of my rand() function instead of calling the '%' operator as mod I used an implementation that is supposedly more random that takes the max random number + a single bit and divides it by 'n' where 'n' is the ceiling for the random number generator. I still got the same answer when running it though. So my last ditch effort was to remove the srand() function and it worked!
- Overloading the '==' operator
I overloaded the '==' operator to compare Songs by the checking to make sure that both fields equal each other. 
- Overloading the '!=' operator
I read the '==' operator will need to be overloaded but I did not expect to need to overload the '!=' operator. I found the need for this through the compiler when it failed because it was looking for an implementation of it in the deleteNode method. It was not hard to implement as I only needed to copy the '==' operator overload and switch the return values.
- DeleteNode tries to print the whole object
I have not had to overload the '<<' operator before and I figured it was that because the compiler was yelling at me because it did not have an implementation of '<<' that took in a Song. This makes sense so I attempted make an operator overload of '<<' that returned a string. This did not work because it the compiler needs an *std::basic_ostream<char>* and not a string. I then tried to raw(c style) cast into *std::basic_ostream<char>* but I found out that no method existed for converting strings to std::basic_ostream<char>. I researched for a while and found out that I can add into a basic_ostream with '<<' operator.... I thought. It turns out that metod is protected and I need to use *ostream* which is a child class of basic_ostream<char>. Now I was like "I got this!" I did not have this. Back to research... I found that I need to pass in the ostream that was already instantiated natively from where it was being called. But my LSP was giving me an error telling me I did not have enough objects being passed in and needed 3 objects. So when you pass more than the object itself being overloaded you have to pass in the 'this' pointer. Or move the function out to global scope. I chose the latter option and just moved the function out to global scope and now the compiler was asking for it to be an Rvalue which is a fairly easy fix by adding the '&' to the end of the function to declare that it will return an Rvalue. After I recompiled it worked with no errors!!

### What I Learned
I have a couple key takeaways from this lab. 
- do not use srand() if you are going to use random many times in succession
- Overloading output streams need to be of type std::ostream and an Rvalue


