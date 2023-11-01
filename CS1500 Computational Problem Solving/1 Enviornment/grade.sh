#!/bin/bash

######## Variable globals -> ########
# The file containing the "main" entry point for the program.
# In C or C++, this is the file containing the main() function
# In Python, this is whichever file you run via python3 whatever.py
# In Bash, this is whichever file you run via python3 whatever.sh
main_file="hello_python.py"

# Any arguments you want passed to the main driver, upon excution.
# If you do not have any arguments, just leave as an empty string, ""
main_file_arguments=""

# The language that the assignment is written in.  Currently supported
# options are "cpp", "python", "bash"
language="python"

# Whether or not to score the student using a static analyzer.
# For Python, this is the mypy type-checker.
# For C or C++, this is cppcheck.
# For Bash, this is shellcheck
enable_static_analysis=true

# Whether or not to score the student using an autoformatter (dock points
# if not formatted correctly).
# For Python, this is black.
# For C++, this is clang-format.
# For Bash, this is shfmt
enable_format_check=true

# Whether or not to use fuzzy or ridig diffs
# If you choose true, fuzzy diffs will give partial credit.
# This can be helpful for string-heavy assignments,
# where correctness is reasonable to estimate statistically.
# If you choose false, rigid diffs will be all-or-none.
# This is helpful when the assignment is mathy,
# where correctness is not reasonable to estimate statistically.
fuzzy_partial_credit=false

######## <- Variable globals ########

######## Custom tests -> ########
# Any tests other than the unit tests and the stdout diff tests belong here,
# and must be bash functions whose names begin with "custom_test".
# Custom tests should report their score by assigning their result (0-100)
# to the custom_test_score, e.g.:
# custom_test_score=100

custom_test_tracing_pudb() {
    custom_test_score=0
    [ -f 'tracing_pudb.png' ] && file tracing_pudb.png | grep "PNG image data" >/dev/null 2>&1 && custom_test_score=100
}

custom_test_tracing_spyder() {
    custom_test_score=0
    [ -f 'tracing_spyder.png' ] && file tracing_spyder.png | grep "PNG image data" >/dev/null 2>&1 && custom_test_score=100
}

custom_test_stdio_diff() {
    custom_test_score=0
    diff your_name.txt your_name_given.txt && diff your_output_py.txt your_output_given.txt && diff your_output_sh.txt your_output_given.txt && custom_test_score=100
}

custom_test_sh_stdio_diff() {
    custom_test_score=0
    for i in {1..30}; do
        rm -f test_out.txt temp_out.txt temp_correct.txt
        random_str=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1)
        echo "Enter your name:" >temp_correct.txt
        echo Hello "$random_str" >>temp_correct.txt
        echo "We're running: bash hello_shell.sh with a random string input!"
        echo "$random_str" | bash hello_shell.sh >temp_out.txt
        if diff temp_out.txt temp_correct.txt; then
            custom_test_score=100
        else
            custom_test_score=0
            if [ "$annoying_nodebug" = "onlydothisaftercompletingthebasics" ] || grep 'docker\|lxc' /proc/1/cgroup >/dev/null 2>&1; then
                echo Run this script locally with debugging details.
            else
                echo "Enter to see your diffs, and then :qa to exit Vim"
                read -r
                vim -d temp_out.txt temp_correct.txt
            fi
            rm -f test_out.txt temp_out.txt temp_correct.txt
            break
        fi
        rm -f test_out.txt temp_out.txt temp_correct.txt
    done
}
######## <- Custom tests ########

source .admin_files/grade_backend.sh
