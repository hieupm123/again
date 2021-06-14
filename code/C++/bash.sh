set -e
g++ -std=c++17 e.cpp -o e
g++ -std=c++17 c.cpp -o c
g++ -std=c++17 A.cpp -o A
for((i = 0; ; ++i)); do
    ./c $i > in
    ./A < in > out
    ./e < in > out2
    diff -Z out out2 > /dev/null || break
    # diff -Z out2 out3 > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat in
echo ""
echo "Your answer is:"
cat out
echo "Correct answer is:"
cat out2