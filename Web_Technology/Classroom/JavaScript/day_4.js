// Assignment
// Qsn1:
function greatest(num1, num2, num3){
    if(num1 > num2 && num1 > num3){
        return num1;
    } else if(num2 > num1 && num2 > num3){
        return num2;
    } else {
        return num3;
    }
}
var a = parseInt(prompt("Enter first number: "));
var b = parseInt(prompt("Enter second number: "));
var c = parseInt(prompt("Enter third number: "));

document.write("The greatest number is: " + greatest(a, b, c));


// Qsn2:
function fibonacci(n) {
    var a = 0, b = 1, c;
    document.write(a + " " + b + " ");
    for (var i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        document.write(c + " ");
    }
}
fibonacci(15);


// Qsn3:
function series(n) {
    for (var i = 2; i < n; i++) {
        if (i % 2 == 0) {
            document.write(i * i * i + " ");
        } else {
            document.write(i * i + " ");
        }
    }
}
series(10);


// Qsn4:
function sumArray(arr) {
    var sum = 0;
    for (var i = 0; i < arr.length; i++) {
        sum += arr[i];
    }
    return sum;
}
var numbers = [];
for (var i = 0; i < 10; i++) {
    var a = parseInt(prompt("Enter number " + (i + 1)+ ": "));
    numbers.push(a);
}

document.write("The sum of the array is: " + sumArray(numbers));




// Qsn 5
function fullname() {
    var firstNames = [];
    var lastNames = [];
    firstNames.push(prompt("Enter first name: "));
    lastNames.push(prompt("Enter last name: "));
    return firstNames[0] + " " + lastNames[0];
}
document.write("The full name is: " + fullname());


//Qsn 6
function avg(a,b,c){
    return (a+b+c)/3;
}
function avg1(a,b,c,d){
    return (a+b+c+d)/4;
}
function agg(a,b,c,d){
    return avg(a,b,c) * avg1(a,b,c,d);
}
var a = parseInt(prompt("Enter first number: "));
var b = parseInt(prompt("Enter second number: "));
var c = parseInt(prompt("Enter third number: "));
var d = parseInt(prompt("Enter fourth number: "));
document.write("The product of the two functions is: " + agg(a,b,c,d));




// Qsn 7
function add(a,b){
    return a+b;
}
function sub(a,b){
    return a-b;
}
function mul(a,b){
    return a*b;
}
function div(a,b){
    return a/b;
}
var choice = parseInt(prompt("Enter your choice: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division"));
var a = parseInt(prompt("Enter first number: "));
var b = parseInt(prompt("Enter second number: "));

switch(choice){
    case 1:
        document.write("The sum is: " + add(a,b));
        break;
    case 2:
        document.write("The difference is: " + sub(a,b));
        break;
    case 3:
        document.write("The product is: " + mul(a,b));
        break;
    case 4:
        document.write("The division is: " + div(a,b));
        break;
    default:
        document.write("Invalid choice");
}

// Qsn 8
function isPrime(n) {
    if (n < 2) return "Neither Prime nor Composite"; 
    for (var i = 2; i <= n/2; i++) { 
        if (n % i == 0) {
            return "Composite";
        }
    }
    return "Prime";
}
var num = parseInt(prompt("Enter a number: "));
document.write("The number is: " + isPrime(num));


// Qsn 9
function isPrime(n) {
    if (n < 2) return false;
    for (var i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
var count = 0;
var i = 2;
while (count < 50) {
    if (isPrime(i)) {
        document.write(i + " ");
        count++;
    }
    i++;
}



//  Qsn 10
function incometax(income, isFemale, isMarried) {
    var tax = 0;
    var minTaxable = 500000;

    if (isFemale && isMarried) {
        minTaxable = 600000;
    }

    if (income < minTaxable) {
        tax = income * 0.01;
    } else if (income >= minTaxable && income < 800000) {
        tax = minTaxable * 0.01 + (income - minTaxable) * 0.1;
    } else if (income >= 800000 && income < 1500000) {
        tax = minTaxable * 0.01 + 30000 + (income - 800000) * 0.2;
    } else if (income >= 1500000 && income < 2400000) {
        tax = minTaxable * 0.01 + 30000 + 140000 + (income - 1500000) * 0.3;
    } else {
        tax = minTaxable * 0.01 + 30000 + 140000 + 270000 + (income - 2400000) * 0.39;
    }
    return tax;
}
var income = parseInt(prompt("Enter your income: "));
var isFemale = confirm("Are you female?");
var isMarried = confirm("Are you married?");
document.write("The income tax is: " + incometax(income, isFemale, isMarried));

