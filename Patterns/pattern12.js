const pattern12 = (n) => {
  let start = 1;
  for (let i = 0; i < n; i++) {
    i % 2 === 0 ? (start = 1) : (start = 0);
    for (let j = 0; j <= i; j++) {
      process.stdout.write(String(start));
      start = 1 - start;
    }
    console.log("");
  }
};

//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern12(n);
};
main();
