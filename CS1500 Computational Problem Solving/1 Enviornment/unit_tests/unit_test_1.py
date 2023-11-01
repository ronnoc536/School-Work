#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys

# Temporarily add the current path to the system path for importing the student's source code.
sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), ".admin_files"
    )
)
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
# python3 seemingly respects only abspaths, while ipython3 is ok with relative, like '..' here.
import test_utils

from hello_python import hello
from string import ascii_letters, whitespace
import random


@test_utils.test_wrapper
def test() -> bool:
    # To debug in pudb3, highlight just below this line, hit 't', then 'n' or 's' as you want
    for _ in range(50):
        your_name = "".join(random.choice(ascii_letters + " ") for i in range(20))
        your_output = hello(your_name)
        if your_output != "Hello " + your_name:
            return False
    return True


if __name__ == "__main__":
    test()
