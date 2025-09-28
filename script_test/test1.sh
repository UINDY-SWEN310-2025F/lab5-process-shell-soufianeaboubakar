echo "Running tests..."

CUR=$(pwd)
echo $CUR
SCRIPT_DIR=$CUR"/script_test"
echo $SCRIPT_DIR


if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi


echo "Test1 passed."

exit 0