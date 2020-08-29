'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString.trim().split('\n').map(string => {
    return string.trim();
  });

  main();
});

function readline() {
  return inputString[currentLine++];
}

function main() {
  const t = parseInt(readline());
  for (let i=0; i<t; i++) {
    const [n, k] = readline().split(" ").map(x => parseInt(x));
    const s = readline();
    let cooldown = 0,
      vacancy = 0;
    for (let j=0; j<s.length; j++) {
      if (s[j] === "0") {
        if (cooldown == 0) {
          vacancy++;
          cooldown = k;
        } else {
          cooldown--;
        }     
      } else {
        // s[j] === "1"
        if (cooldown > 0) {
          vacancy--;
        }
        cooldown = k;
      }
    }
    console.log(vacancy);
  }
}
