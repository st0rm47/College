// Program to demonstrate all different JSON data types

const jsonData = {
    stringType: "Hello, World!", // String
    numberType: 42,             // Number
    booleanType: true,          // Boolean
    nullType: null,             // Null
    arrayType: [1, 2, 3, 4],    // Array
    objectType: {               // Object
        key1: "value1",
        key2: "value2"
    }
};

// Display the JSON data
console.log("JSON Data Types Example:");
console.log(JSON.stringify(jsonData, null, 2));
