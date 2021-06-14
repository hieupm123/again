set -e
g++ A.cpp -o A
g++ c.cpp -o c
g++ a.cpp -o a
for((i = 1; ; ++i)); do
    # ./c $i > in
    ./A < test$i.txt > out
    ./a < test$i.txt > out2
    diff -Z out out2 > /dev/null || break
    # diff -Z out2 out3 > /dev/null || break
    echo "Passed test: "  $i
done
# echo "WA on the following test:"
# cat in
# echo ""
# echo "Your answer is:"
# cat out
# echo "Correct answer is:"
# cat out2