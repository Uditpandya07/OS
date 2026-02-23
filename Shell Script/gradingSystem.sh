echo "enter the marks out of 100 of a student:"
read marks
if (($marks >= 90)); then
  echo "Grade - 0"
elif (($marks >= 80 && $marks <=89)); then
  echo "Grade - E"
elif (($marks >= 70 && $marks <=79)); then
  echo "Grade - A"
elif (($marks >= 60 && $marks <=69)); then
  echo "Grade - B"
elif (($marks >= 50 && $marks <=59)); then
  echo "Grade - C"
elif (($marks >= 40 && $marks <=49)); then
  echo "Grade - D"
else
  echo "Grade - F"
fi

