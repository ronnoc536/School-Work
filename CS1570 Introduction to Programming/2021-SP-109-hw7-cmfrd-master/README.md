
# Homework 6

link to the assignment page:
https://sites.google.com/a/mst.edu/price/courses/cs-1570/hw/2020/fall/assignment-06

### Some helpful tips:
1) 2 space indents for your indentation scheme.
2) Use constants for numbers that are important and won't change.
   e.g. my_int % 2 for testing if a number is even is not important (don't need a const for 2)
        Homer's IQ (from HW1) was assigned in the HW and represents something, so it's important (should have been a const)
3) You can use loops and if/else statements for this assignment.
4) You can use switch statements in this assignment
5) You can use functions in this assignment
6) Remember to include <cstdlib> when using random numbers.

### Some Grading Info:
1) -1 for every literal you have that should be a constant (max 15)
2) -5 for not validating your inputs (-5 for not doing it in a reasonable manner)
3) -5 for not using 2 space indents
4) -5 for not having pre/post/desc on each function prototype
5) -5 for each missing function prototype (max -15)
6) -5 for each missing function (max -30)
7) -30 for non-compiling code. -15 for code that throws compiler warnings
8) -10 for not having the correct output formatting (since there is random number usage, your output will not be standardized
      so there will be no "correct" output.)
9) -5 for using things you have not been taught in class (e.g. pointers)

### Partners:
If you are going to have a partner, please do the following:
1) Choose one of you. That person will be the repo you use. Only submit code to THAT repository
2) Send me a message so I can add your partner to your repo (you may be able to do this by going into your repo on 
      git-classes.mst.edu and going to the members tab. If you can, great. If you can't, send me the message)
3) Add your USERNAME and your partner's USERNAME to a file called PARTNERS.txt. If you don't, I won't know who
      your partner is when I grade.

All that being said, people mess this up every year. If you do, you can send me a message after the grades go in. I'm
not going to penalize you for this, but it makes my life a lot easier. So please.


### Git Help

Some of you may not be familiar with git still, so here are the basic steps:

* Clone the repo using the "clone/download" and copy the link in the HTTPS box.
* Create a cs1570 folder in your SDRIVE if you don't have one already: mkdir cs1570 and cd cs1570 so you're inside the folder.
* git clone the-link-you-copied
* This should create a folder called 2020-SP-CS1570-hwX. You can now cd into that folder.
* Whenever you create a new file git will track your changes and you can add your file to the repo by doing git add filename.ext
* Now we can "commit" our file! You need to add a message with your commit to briefly explain what your changes are. git commit -m "I made a file with my name in it!". The message will show up in your git repo, so be careful of what you write.
* Finally you can "push" your changes to the git repo! git push  is all you need to do, it'll ask you to login with your info so once you login you'll be done.
