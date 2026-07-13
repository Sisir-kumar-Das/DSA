const pattern18 = (n) => {
  for (let i = 0; i < n; i++) {
    //space
    for (let j = 0; j < n - i - 1; j++) {
      process.stdout.write(" ");
    }
    //star
    let breakPoint = Math.floor((2 * i + 1) / 2);
    let start = 0;
    for (let j = 0; j < 2 * i + 1; j++) {
      process.stdout.write(String.fromCharCode(65 + start));
      j < breakPoint ? start++ : start--;
    }
    //space
    for (let j = 0; j < n - i - 1; j++) {
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
  pattern18(n);
};
main();
