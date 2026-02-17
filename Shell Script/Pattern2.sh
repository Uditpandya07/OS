echo "Pattern-2"
for ((i=1; i<=5; i++))
do
    for ((s=5; s>i; s--))
    do
        echo -n " "
    done

    for ((j=i; j>=1; j--))
    do
        echo -n "$j"
    done
    echo
done


