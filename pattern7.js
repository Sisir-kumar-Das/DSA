const pattern7 = (n) => {
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n - i + 1; j++) {
      process.stdout.write(String(j) + " ");
    }
    console.log("");
  }
};
//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern7(n);
};
main();
