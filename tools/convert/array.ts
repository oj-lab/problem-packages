var arrayStringPath = process.argv[2];
var arrayString = require("fs").readFileSync(arrayStringPath, "utf8");

arrayString = arrayString.replace(/\[/, "").replace(/\]/, "").replace(/ /g, "");
var array = arrayString.split(",");

console.log(array.length);
console.log(array.join(" "));