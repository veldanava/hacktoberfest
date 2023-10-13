<?php

// Define a function to implement Fisher-Yates Shuffle
function fisher_yates_shuffle(&$arr) {
    // Get the count of elements in the array
    $count = count($arr);
    // Initialize $i to the index of the last element
    $i = $count - 1;
    
    // Use a while loop to shuffle elements
    while ($i > 0) {
        // Generate a random index $j between 0 and $i
        $j = mt_rand(0, $i);
        // Swap elements at indices $i and $j
        list($arr[$i], $arr[$j]) = array($arr[$j], $arr[$i]);
        // Decrease $i to work on the next set of elements
        $i--;
    }
}

// Example of how to use the function
$array_saya = ["elemen1", "elemen2", "elemen3", "elemen4", "elemen5"];

// Call the Fisher-Yates Shuffle function
fisher_yates_shuffle($array_saya);

// Iterate through the shuffled array and print the elements
foreach ($array_saya as $elemen) {
    echo $elemen . " ";
}
?>

