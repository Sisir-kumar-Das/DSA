const pattern11 = (n) => {
  for (let i = 1; i <= 2 * n - 1; i++) {
    //space
    let stars;
    i >= n ? (stars = 2 * n - i) : (stars = i);
    for (let j = 0; j < stars; j++) {
      process.stdout.write("*");
    }
    console.log("");
  }
};

//

const main = () => {
  const fs = require("fs");
  const input = fs.readFileSync(0, "utf8").trim().split("\n");

  const n = parseInt(input[0]);
  pattern11(n);
};
main();
