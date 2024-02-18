var TurndownService = require("turndown");

var htmlPath = process.argv[2];
var html = require("fs").readFileSync(htmlPath, "utf8");

var turndownService = new TurndownService();
var markdown = turndownService.turndown(html);

var markdownPath = htmlPath.replace(/\.html$/, ".md");
require("fs").writeFileSync(markdownPath, markdown);