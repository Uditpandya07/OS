echo "Pattern-3"
for ((i=1; i<=4; i++))
do
    for ((s=4; s>i; s--))
    do
        echo -n " "
    done

    for ((j=1; j<=i; j++))
    do
        echo -n "* "
    done
    echo
done
