const pattern2 = (n) => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i + 1; j++) {
      process.stdout.write("* ");
    }
    console.log("");
  }
};

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern2(n);
};
main();
