# pa02 - this again??
What race condition?
Have you hit the wall yet?
Time for tunnel vision!

# How it should play
[![asciicast](https://asciinema.org/a/366397.svg)](https://asciinema.org/a/366397)

* `a` then `enter` for left, `d` then `enter` for right.
* any other input gets ignored in terms of left-rigth movement, but the game keeps going forward.

# Clearing the screen
Clearing the screen enables you to make continuous seeming drawings that "move".
We gave you the syntax for clearing the screen, in the template code.
Your game should play like the video above.

# ASCII ART and map
We have given you the art and track for the race.

# How to get the car on the track?
Hint:
```py
bigstring = 'bigstring'
insert_pos = 3
bigbigstring = bigstring[0:insert_pos] + 'big' + bigstring[insert_pos:]
```

# How to keep playing round after round
Recall:
A while loop lets you repeat a sequence of code until the user tells you to quit().
Check toy examples from class code!

# Where to program?
Program this at the Linux terminal, in the class Linux VM, or via the other options illustrated in the past lectures.
Programming this in your Windows or Mac host may work, or may break.

# How to program
Don't tackle the whole game first. 
Work from the outside in.
Program in incremental chunks.
Do NOT try to write the whole program and then debug it into submission.
Start early. 
Something always comes up!

# Do your own work
This is independent work.
We have great methods of determining whether your code is like your friend's.

# How to diff
If you can't figure out what text differs, do this for one file:
```sh
diff -y --color "sample_outputs/victory_output.txt" "your_outputs/victory.txt"

vim -d "sample_outputs/victory_output.txt" "your_outputs/victory.txt"
# To exit vim, type esc followed by :q

meld --diff "sample_outputs/victory_output.txt" "your_outputs/victory.txt"
```

# Have fun and good luck!
