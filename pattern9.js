const pattern9 = (n) => {
  for (let i = 0; i < n; i++) {
    //space
    for (let j = 0; j < i; j++) {
      process.stdout.write(" ");
    }
    //star
    for (let j = 0; j < 2 * n - (2 * i + 1); j++) {
      process.stdout.write("*");
    }
    //space
    for (let j = 0; j < i; j++) {
      process.stdout.write(" ");
    }
    console.log("");
  }
};
//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern9(n);
};
main();
