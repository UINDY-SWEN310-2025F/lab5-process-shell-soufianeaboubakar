echo "Running tests..."

CUR=$(pwd)
echo $CUR
SCRIPT_DIR=$CUR"/script_test"
ANS_DIR_MYPS=$CUR"/answer/myps.sh"
echo $SCRIPT_DIR


output1=$($ANS_DIR_MYPS)

echo "This myps output is $output1"

if [ "$output1" != "" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output1' but got: $output1"
  exit 1
fi


echo "Test2s passed."

exit 0