#!/bin/bash
echo "Compiling Q10_PrerequisiteCourses.cpp..."
g++ -o Q10_PrerequisiteCourses Q10_PrerequisiteCourses.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q10_PrerequisiteCourses..."
./Q10_PrerequisiteCourses

echo ""
echo "Comparing Q10_output.txt with Q10_expected_output.txt..."
if diff -q Q10_output.txt Q10_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q10_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q10_output.txt
fi
