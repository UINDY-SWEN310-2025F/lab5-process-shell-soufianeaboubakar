echo "Running tests..."

CUR=$(pwd)
echo $CUR
SCRIPT_DIR=$CUR"/script_test"
TEST_DIR=$CUR"/tests"
ANS_DIR=$CUR"/answer"
echo $SCRIPT_DIR


output1=$(./psh1 <<EOF
ps
EOF
)
PSH1_OUT=$TEST_DIR"/psh1_out"
echo "output----"
echo $output1
echo $output1 > $PSH1_OUT


# output2=$(./psh2 <<EOF
#   ls
#   -lt
#   ^C
# EOF
# )
# PSH1_OUT=$TEST_DIR"/psh2_out"
# echo $output2 > $PSH1_OUT

echo "Output prepared."

exit 0