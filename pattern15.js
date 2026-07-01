const pattern15 = (n) => {
  let number = 1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      process.stdout.write(String.fromCharCode(65 + j) + " ");
    }
    console.log("");
  }
};

//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern15(n);
};
main();
