<?php
// Source code to be analyzed
$sourceCode = "x = 10 + y";

// Token rules using regular expressions
$pattern = '/([a-zA-Z_][a-zA-Z0-9_]*)|([0-9]+)|(\+)|(\=)|(\s+)/';

// Matching the rules with the source code
preg_match_all($pattern, $sourceCode, $matches, PREG_SET_ORDER);

// List of recognized tokens
$tokens = array(
    'IDENTIFIER',
    'NUMBER',
    'PLUS',
    'EQUALS',
    'SPACE',
);

// Identifying tokens and printing them
foreach ($matches as $match) {
    foreach ($match as $key => $value) {
        if (!empty($value) && isset($tokens[$key])) {
            echo $tokens[$key] . ': ' . $value . PHP_EOL;
        }
    }
}
?>
