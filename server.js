const express = require("express");
const { spawn } = require("child_process");

const app = express();
app.use(express.json());
app.use(express.static(".")); 

app.post("/solve", (req, res) => {
  const input = req.body.input;

  const solver = spawn("./sudoku.exe"); 

  let output = "";

  solver.stdout.on("data", data => {
    output += data.toString();
  });

  solver.stdin.write(input);
  solver.stdin.end();

  solver.on("close", () => {
    res.send(output);
  });
});

app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});