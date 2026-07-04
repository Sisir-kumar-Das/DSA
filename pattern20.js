const pattern20 = (n) => {
  for (let i = 0; i < n; i++) {
    //stars
    for (let j = 0; j < n; j++) {
      if (i === 0 || i === n - 1 || j === 0 || j === n - 1) {
        process.stdout.write("*");
      } else {
        process.stdout.write(" ");
      }
    }
    console.log("");
    //
  }
};
//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern20(n);
};
main();
