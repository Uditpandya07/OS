add() {
    echo "Sum = $(( $1 + $2 ))"
}
sub() {
    echo "Difference = $(( $1 - $2 ))"
}
mul() {
    echo "Product = $(( $1 * $2 ))"
}

# Function for division
div() {
    if [ $2 -eq 0 ]; then
        echo "Division by zero not possible"
    else
        echo "Quotient = $(( $1 / $2 ))"
    fi
}

# Take input from user
echo "Enter first number:"
read a
echo "Enter second number:"
read b

# Call functions
add $a $b
sub $a $b
mul $a $b
div $a $b
