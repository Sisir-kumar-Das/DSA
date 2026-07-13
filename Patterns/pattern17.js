const pattern16 = (n) => {
  let start = n;
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= i; j++) {
      process.stdout.write(String.fromCharCode(64 + i) + " ");
      start--;
    }
    console.log("");
  }
};

//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern16(n);
};
main();
