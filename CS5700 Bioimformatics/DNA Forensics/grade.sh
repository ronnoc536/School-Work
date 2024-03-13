#!/bin/bash
# Do not edit this file.
# It is easy to cheat this assignment... please don't.

rm results.txt ./*.fasta
python3 gen.py
timeout 3600 python3 phylogen.py fam_unknown.fasta regen.fasta
grade=0
diff fam_key.fasta regen.fasta && ((grade = 90))
mypy --strict --disallow-any-explicit ./*.py && ((grade = grade + 5))
black --check ./*.py && ((grade = grade + 5))
echo "$grade" >results.txt
echo "Your base grade is: $grade"
if ((grade > 70)); then
    echo "You're passing."
    echo "If you have questions about how grading happens, just look at this script."
    exit 0
else
    exit 1
fi
