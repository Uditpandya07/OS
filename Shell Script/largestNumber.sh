echo "enter 3 numbers"
read a b c
if (($a > $b)); then
  if (($a > $c)); then
    echo "$a is the largest"
 else
    echo "$c is the largest"
 fi
else
  if (($b > $c)); then
    echo "$b is the largest"
 else
    echo "$c is the largest"
 fi
fi

