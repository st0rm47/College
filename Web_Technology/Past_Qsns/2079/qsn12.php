<?php

function createAndPrintIntArray(){
    $a = array(1,2,3,4,5,6);

    foreach($a as $i){
        echo " $i ";
    }
}

createAndPrintIntArray();
?>