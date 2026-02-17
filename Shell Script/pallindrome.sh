echo "Enter any number(greater than 9):"
read a
b=$a
rev=0
rem=0
while (($b != 0))
 do
  rem=$((b%10))
  rev=$((rev*10 + rem))
  b=$((b/10))
done
if (($a == $rev)); then
  echo "$a is a palindrome number"
else
  echo "$a is not a palindrome number"
fi
