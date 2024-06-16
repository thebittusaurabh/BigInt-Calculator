# BigInt-Calculator
The BigInt Calculator is a command-line application designed to perform arithmetic operations on arbitrarily large integers. Traditional data types in programming languages often have limitations on the size of numbers they can handle. This calculator leverages a custom 'BigInt' class to overcome these limitations, allowing for accurate computation with extremely large numbers that would otherwise exceed standard data type limits.

Features ->
Addition: Adds two large integers and returns the result.
Subtraction: Subtracts the second large integer from the first and returns the result.
Multiplication: Multiplies two large integers and returns the product.
Division: Divides the first large integer by the second and returns the quotient. (Note: Division by zero is handled with an error message.)
Comparison: Compares two large integers and determines if they are equal, or if one is greater than or less than the other.

How It Works ->
BigInt Class: The core of the calculator is the BigInt class, which represents large integers as strings and provides methods for arithmetic operations. The class manages the sign (positive or negative) and performs operations digit by digit, mimicking manual arithmetic.

User Interface:  
               The user interacts with the calculator through a simple text-based interface. Users are prompted to enter their choice of operation and the large integers they wish to operate on.

Error Handling:
              The calculator includes basic error handling. For instance, it prevents division by zero and notifies the user with an appropriate error message.

Example Usage->
Starting the Calculator: When the program runs, the user is presented with a menu of options.
Choosing an Operation: The user selects an arithmetic operation (addition, subtraction, multiplication, division, or comparison).
Inputting Numbers: The user inputs the large integers they wish to calculate.
Displaying Results: The calculator processes the input and displays the result on the screen.

Conclusion->
The BigInt Calculator provides a practical solution for handling large integer arithmetic that exceeds the capabilities of standard data types. Its implementation using the BigInt class ensures accuracy and efficiency, making it a valuable tool for applications requiring manipulation of large numbers, such as cryptographic computations, scientific calculations, and financial analysis. This project also serves as an excellent example for learning about object-oriented programming and algorithm design in C++.
