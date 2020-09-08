'use strict';
process.stdin.resume();
process.stdin.setEncoding('utf-8');
var inputString = '';
var inputArray = [];
var currentLine = 0;
process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});
process.stdin.on('end', function (_) {
    inputArray = inputString.trim().split('\n').map(function (string) {
        return string.trim();
    });
    main();
});
function readline() {
    return inputArray[currentLine++];
}
function main() {
    var t = parseInt(readline());
    for (var i = 0; i < t; i++) {
        var n = parseInt(readline());
        var nums = readline().split(" ").map(function (x) { return parseInt(x); });
        if (nums[0] + nums[1] <= nums[n - 1]) {
            console.log(1, 2, n);
        }
        else {
            console.log(-1);
        }
    }
}
