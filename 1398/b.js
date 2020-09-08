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
        var s = readline();
        var lengths = [];
        var count = 0;
        for (var _i = 0, s_1 = s; _i < s_1.length; _i++) {
            var c = s_1[_i];
            if (c == "1") {
                count++;
            }
            else if (count > 0) {
                lengths.push(count);
                count = 0;
            }
        }
        if (count > 0)
            lengths.push(count);
        lengths.sort(function (a, b) { return a - b; });
        var answer = 0;
        for (var j = lengths.length - 1; j >= 0; j -= 2) {
            answer += lengths[j];
        }
        console.log(answer);
    }
}
