const pattern13 = (n) => {
  let space = 2 * (n - 1);
  for (let i = 1; i <= n; i++) {
    //numbers correct order
    for (let j = 1; j <= i; j++) {
      process.stdout.write(String(j));
    }
    //spaces
    for (let j = 1; j <= space; j++) {
      process.stdout.write(" ");
    }
    //numbers reverse order
    for (let j = i; j >= 1; j--) {
      process.stdout.write(String(j));
    }
    console.log("");
    space = space - 2;
  }
};

//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern13(n);
};
main();
