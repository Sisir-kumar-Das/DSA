const pattern19 = (n) => {
  for (let i = 0; i < n; i++) {
    //stars
    for (let j = 0; j < n - i; j++) {
      process.stdout.write("*");
    }
    //space
    for (let j = 0; j < 2 * i; j++) {
      process.stdout.write(" ");
    }
    //stars
    for (let j = 0; j < n - i; j++) {
      process.stdout.write("*");
    }
    console.log("");
  }
  let initialSpace = 2 * n - 2;
  for (let i = 1; i <= n; i++) {
    //stars
    for (let j = 1; j <= i; j++) {
      process.stdout.write("*");
    }
    //space
    for (let j = 0; j < initialSpace; j++) {
      process.stdout.write(" ");
    }
    //stars
    for (let j = 1; j <= i; j++) {
      process.stdout.write("*");
    }
    initialSpace -= 2;
    console.log("");
  }
};
//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern19(n);
};
main();
