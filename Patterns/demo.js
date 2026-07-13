const fs = require("fs");
const input = fs.readFileSync(0, "utf8").trim().split("\n");
// parse your input
const n = parseInt(input[0]);
const arr = input[1].split(" ").map(Number);

// write output
console.log(arr.reverse().join(" "));
