<?php
ini_set("display_error", false); 
error_reporting(0); 
highlight_file(__FILE__);
$file_handle = fopen("/data/flag","r");
if ($file_handle){
    //接着采用while循环一行行地读取文件，然后输出每行的文字
    while (!feof($file_handle)) {
        $line = fgets($file_handle);
        echo $line;
        echo "<br />";
    }
}
fclose($file_handle);
?>